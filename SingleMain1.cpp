#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int id;
    double gpa;
    Student* next;


    Student() : name(""), id(0), gpa(0),next(NULL){}

    Student(const string& name_, int id_, double gpa_)
        : name(name_), id(id_), gpa(gpa_) {}
    Student(const Student& other)
        : name(other.name), id(other.id), gpa(other.gpa), next(nullptr) {}
};



class StudentList  {
private:
    Student* head;
    int count;

public:
    StudentList() : head(nullptr), count(0) {}
    ~StudentList(){}
    

    void insert(const Student& s) {
        
        Student* newNode = new Student(s);
        if (head==nullptr || s.id < head->id) {
            newNode->next = head;
            head = newNode;
        } else {
            Student* cur = head;
            while (cur->next!=NULL && cur->next->id < s.id) {
                cur = cur->next;
            }
            
            newNode->next = cur->next;
            cur->next = newNode;
        }
        count++;
    }

    bool remove(int id1) {
        if (head==NULL) return false;
        if (head->id == id1) {
            Student* temp = head;
            head = head->next;
            delete temp;
            count--;
            return true;
        }
        Student* cur = head;
        while (cur->next !=NULL && cur->next->id != id1) {
            cur = cur->next;
        }
        if (cur->next!=NULL && cur->next->id == id1) {
            Student* temp = cur->next;
            cur->next = temp->next;
            delete temp;
            count--;
            return true;
        }
        return false; 
    }

    Student* search(int id1) {
        Student* cur = head;

        while (cur!=NULL) {
            if (cur->id == id1) {
                Student& d = *cur;
                return &d;
            }
           cur = cur->next;
        }
        return nullptr;
    }

    void display() const {
        cout << "Student List (size=" << count << "):\n";
        Student* cur = head;
        while (cur != NULL) {
            cout << "Name: " << cur->name
                 << ", ID: " << cur->id
                 << ", GPA: " << cur->gpa << "\n";
            cur = cur->next;
        }
    }

    int size() const {
        return count;
    }
};

int main() {
    StudentList list;

    list.insert(Student("Ahmed Ali", 1002, 3.5));
    list.insert(Student("Sara Mohamed", 1001, 3.8));
    list.insert(Student("Omar Youssef", 1004, 2.9));
    list.insert(Student("Laila Hassan", 1003, 3.2));

    cout << "Insertions:\n";
    list.display();

    cout << "\nSearching ID = 1003:\n";
    Student* s = list.search(1003);
    if (s) {
        cout << "Found: Name=" << s->name << ", ID=" << s->id << ", GPA=" << s->gpa << "\n";
    } else {
        cout << "Student with ID 1003 not found.\n";
    }

    cout << "\nDeleting ID = 1002:\n";
    bool removed = list.remove(1002);
    if (removed) {
        cout << "Deleted successfully.\n";
    } else {
        cout << "Delete failed: ID not found.\n";
    }

    cout << "\nFinal list:\n";
    list.display();

    cout << "\nSize of list = " << list.size() << "\n";

    return 0;
}
