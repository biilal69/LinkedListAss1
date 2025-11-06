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
    void deletion(int pos)
    {
        if(pos==0)
        {
            Node* temp = head;
            head=head->next;
            head->prev=nullptr;
            delete temp;
        }
        else if (pos==count-1)
        {
            Node* temp = tail;
            tail=tail->prev;
            tail->next=nullptr;
            delete temp;
        }
        else
        {
            Node* cur = head;
            for(int i = 0 ; i<pos ;i++)
            {
                cur=cur->next;
            }
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            delete cur;
        }
    }
    void subString(int start , int len)
    {
        Node* cur =head;
        for(int i =0 ; i<start ;i++)
        {
            cur=cur->next;
        }
        for(int i = 0 ; i<len ;i++){
            cout<<cur->letter;
            cur=cur->next;
        }
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
    obj.insertCH('X',5);
    obj.deletion(5);
    obj.display( );
    obj.subString(3,3);
    
    return 0;
}