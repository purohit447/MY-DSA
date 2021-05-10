// MY DSA-1.2
// DOUBLY LINKED LISTS
// by Karan Purohit


// What's inside?

// Content:
// Declaration of Doubly linked list;
// Inserting node (at top, at tail, at random);
// Deletion of node (at head, at random, at tail);
// Calculate length of an linked list;
// Append K nodes;

// Source Code :
#include<iostream>
using namespace std;

class node  // Declaration of data type;
{
public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;  // Doubly has an extra previous pointer;
    }
};

void top(node* &head,int val) // Insert at top node;
{
    node* n= new node(val);
    node* temp=head;
    n->next=head;
    if(head!=NULL) temp->prev=n; 
    head=n; 
}

void tail(node* &head,int val)  // Insert at tail;
{
    node* temp=head; 
    node* n=new node(val);

    if(head==NULL) // Special case for no node;
    {
        head=n; return; // Must use return after special cases;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void in_ran(node* &head,int n,int pos)  // To insert at random positions;
{
    node* temp=head;
    node* val= new node(n); pos-=2;
    while(pos--)
    {
        temp=temp->next;
    }
    val->next=temp->next;
    temp->next=val;
}

void display(node* head) // To diaplay the linked list;
{
    node* temp=head;
    while(head!=NULL)
    {
        cout<<head->data<<" <-> "; // for understanding refrence;
        head=head->next;
    } cout<<"NULL"<<endl;   // for understanding refrence;
}

void del_head(node* &head) // To delete the head node;
{
    if(head==NULL) return;  // Corner Case
    
    node* deleq=head;

    if(head->next==NULL)   // Special Case
    {
        head=head->next;
        delete deleq; return;
    }  
    head=head->next;
    head->prev=NULL;
    delete deleq;
}

void del(node* &head, int pos) // To delete any given node;
{
    node* temp=head;
    int count=1;

    while(temp!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL) temp->next->prev=temp->prev;
    delete temp;
}

int length(node* head) // To calculate the length of a linked list;
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    } return l;
}

node* append(node* &head,int pos) // To append given nodes of linked list;
{
    node* new_tail=head;
    node* new_head;
    node* tail=head;

    int l=length(head);
    int count=1;
    while(tail->next!=NULL)
    {
        if(count==l-pos) new_tail=tail;
        if(count==l-pos+1) new_head=tail;
        tail=tail->next; count++;
    }
    
    new_tail->next=NULL;
    tail->next=head;
   
    return new_head;

}

int main()
{
    node* head=NULL;   // initiating first node;
    
    top(head,1);    // head inserting;     results(NULL<-> 1 <->NULL);

    del_head(head);  // deleting head;     results(NULL);
    tail(head,4);    // inserting at tail  results(NULL<-> 4 <->NULL);
    tail(head,5);    // inserting at tail  results(NULL<-> 4 <-> 5 <->NULL);
    tail(head,6);    // inserting at tail  results(NULL<-> 4 <-> 5 <-> 6 <->NULL);
    tail(head,7);    // inserting at tail  results(NULL<-> 4 <-> 5 <-> 6 <-> 7 <->NULL);
    tail(head,8);    // inserting at tail  results(NULL<-> 4 <-> 5 <-> 6 <-> 7 <-> 8 <->NULL);

    in_ran(head,1,4);   // inserting at tail  results(NULL<-> 4 <-> 5 <-> 6 <-> 1 <-> 7 <-> 8 <->NULL);

    display(head);   // display list     output :   4 <-> 5 <-> 6 <-> 1 <-> 7 <-> 8 <-> NULL;

    node* new_head = append(head,3);  // appending last K nodes to the top;   results(NULL<-> 1 <-> 7 <-> 8 <-> 4 <-> 5 <-> 6 <->NULL)

    display(new_head); // display list   output :  1 <-> 7 <-> 8 <-> 4 <-> 5 <-> 6 <-> NULL

    return 0;
}