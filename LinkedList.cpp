#include <iostream>
using namespace std;

typedef struct Node
{
    int val;
    Node* next;
}Node;
class MyLinkedList {
    Node* head;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index<0||index>=size)
        {
            return -1;
        }
        Node* current = head;
        for(int i=0;i<index;i++)
        {
            current = current->next;
        }
        return current->val;
        
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node;
        newNode->val=val;
        newNode->next=head;
        head=newNode;
        size++;
        
    }
    
    void addAtTail(int val) {
        Node *newNode =new Node;
        newNode->val=val;
        newNode->next=nullptr;
        if(head==nullptr)        {
            head=newNode;
        }
        else
        {
            Node* current = head;
            while(current->next!=nullptr)
            {
                current=current->next;
            }
            current->next=newNode;
        }
        size++;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index<0||index>size)
        {
            return;
        }
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        if(index==size)
        {
            addAtTail(val);
            return;
        }
        Node* newNode = new Node;
        newNode->val=val;
        Node* current = head;
        for(int i=0;i<index-1;i++)
        {
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=size)
        {
            return;
        }
        if(index==0)
        {
            Node* temp = head;
            head=head->next;
            delete temp;
        }
        else
        {
            Node* current = head;
            for(int i=0;i<index-1;i++)
            {
                current=current->next;
            }
            Node* temp = current->next;
            current->next=current->next->next;
            delete temp;
        }
        size--;
        
    }
};