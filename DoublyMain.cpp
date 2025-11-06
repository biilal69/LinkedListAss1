#include <iostream>
#include <string>
using namespace std;

struct Node {
    char letter;
    Node* prev;
    Node* next;
};

class Dll{
    Node * head ;
    Node * tail;
    string s;
    int count;

public:
    Dll():head(nullptr) , tail (nullptr) ,s(" "){}
    Dll(string str):head(nullptr),tail(nullptr),s{str}{listInitialize();}
    ~Dll(){}

    void listInitialize()
    {
    count=s.length();

        for(int i = s.length(); i>=0 ;i--)
        {
            insertFront(s[i]);
        }
    }
    void insertFront(char c)
    { if(head==nullptr)
    {
        Node* newNode = new Node;
        newNode->letter = c;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head=newNode;
        tail=newNode;
        return;
    }
    else
    {Node* newNode = new Node;
        newNode->letter = c;
        newNode->next=head;
        newNode->prev=nullptr;
        head->prev=newNode;
        head=newNode;}
    }

    void insertCH(char c , int pos)
    {
        Node* newNode = new Node;
        newNode->letter = c;



        if(pos == 0 )
        {
            newNode->next=head;
            head->prev=newNode;
            newNode->prev=nullptr;
            head=newNode;
        }
        else if (pos==count)
        {

           newNode->prev=tail;
            tail->next=newNode;
            newNode->next=nullptr;
            tail=newNode;

        }

        else
        {
            Node* cur = head;
            for(int i = 0 ; i<pos ;i++)
            {
                cur=cur->next;
            }
            newNode->next=cur;
            cur->prev->next=newNode;
            newNode->prev=cur->prev;
            cur->prev=newNode;
        }
    count++;

    }
    void display()
    {
        Node * cur = head;

        while(cur!=nullptr){
            cout<<cur->letter;
            cur = cur ->next;

        }
    cout<<endl;
    }

};

int main() {
    Dll obj("hello");
    cout << "Doubly Linked List contents: ";
    obj.display( );
    // obj.insertCH('z',0);
    // obj.insertCH('z',0);
     obj.insertCH('z',1);
     obj.insertCH('z',5);
     obj.insertCH('P',5);
      obj.insertCH('7',4);
    obj.display( );
    return 0;
}