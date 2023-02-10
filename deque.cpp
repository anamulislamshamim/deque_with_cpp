// deque -> double ended queue
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node* prev;
    int data;
    Node* next;
};

class Deque
{
public:
    Node* head = new Node;
    int sz;
    int rev;
    Node* tail = new Node;
    Deque ()
    {
        head = NULL;
        sz=0;
        rev=0;
        tail = NULL;
    }
    Node * createNewNode(int value)
    {
        Node * newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    void InsertAtHead (int value)
    {
         Node * newNode = createNewNode(value);
         if(sz==0)
         {
             head = newNode;
             tail = newNode;
             sz++;
             return;
         }
         newNode->next = head;
         head->prev = newNode;
         head = newNode;
         sz++;
    }
    void InsertAtTail (int value)
    {
        Node* newNode = createNewNode(value);
        if(sz==0)
        {
            head = newNode;
            tail = newNode;
            sz++;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        sz++;
    }
    void popAtFront ()
    {
        if(sz==0)
            return;
        Node* prevHead = head;
        head = prevHead->next;
        head->prev = NULL;
        delete prevHead;
        sz--;
        if(sz==0)
        {
            head = NULL;
            tail = NULL;
        }
    }
    void popAtBack ()
    {
        if(sz==0)
            return;
        Node* prevTail = tail;
        tail = prevTail->prev;
        tail->next = NULL;
        delete prevTail;
        sz--;
        if(sz==0)
        {
            head = NULL;
            tail = NULL;
        }
    }
    int Front()
    {
        if(sz==0)
        {
            return -1;
        }
        return head->data;
    }
    int Back()
    {
        if(sz==0)
        {
            return -1;
        }
        return tail->data;
    }
    void Reverse ()
    {
        if(rev == 0)
            rev=1;
        else
            rev=0;
    }
    void Push_back (int value)
    {
        if(rev == 0)
            InsertAtTail( value );
        else
            InsertAtHead( value );
    }
    void Push_front (int value)
    {
        if(rev==0)
            InsertAtHead(value);
        else
            InsertAtTail(value);
    }
    int dfront ()
    {
        if(rev == 0)
            return Front();
        else
            return Back();
    }
    void dback()
    {
        if(rev == 0)
            Back();
        else
            Front();
    }
    void dpop_back()
    {
        if(rev==0)
            popAtBack();
        else
            popAtFront();
    }
    void dpop_front()
    {
        if(rev==0)
            popAtFront();
        else
            popAtBack();
    }
};

int main()
{
    Deque d;
    d.Push_back(1);
    d.Push_back(2);
    d.Push_back(3);
    d.Reverse();
    for(int i=0;i<3;i++)
    {
        cout << d.dfront() << " ";
        d.dpop_front();
    }
    cout << "\n";
    return 0;
}

