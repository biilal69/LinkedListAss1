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
    Node * NewNode = new Node();
    head = tail =NewNode;

 for(int i = 0  ; i < s.length()-1;i++)
    {
        insertCH(s[i],i);
    }
}

void insertCH(char c , int pos)
{
   Node* newNode = new Node;
   newNode->letter = c;
   
   
   
     if(pos == 0 )
    {newNode->next=head;
    head->prev=newNode;
    newNode->prev=nullptr;
    head=newNode;
    }
    else if (pos==s.length())
    {
        newNode->prev=tail;
        newNode->next=nullptr;
        tail->next=newNode;
        tail=newNode;
    }
    else 
    {
        Node* cur = new Node;
        for(int i = 0 ; i<pos ;i++)
        {
            cur=cur->next;
        }
        newNode->next=cur;
        newNode->prev=cur->prev;
        cur->prev=newNode;
    }
    

}
void display()
    {
        Node * cur = head;
       cout<<cur->letter;
       
        while(cur!=nullptr){
            cout<<cur->letter<<" ";
            cur = cur ->next;
            
        }
    }

};

int main() {
   Dll obj("hello");
   cout << "Doubly Linked List contents: ";
   obj.display( );
    return 0;
}