// MY DSA-1.3
// ADVANCED LINKED LISTS
// by Karan Purohit


// What's inside?

// Content:
// Sorting Doubly linked list (Merge Sort);
// Merging two sorted linked lists;
// Circular linked list (creating circular linked list, inserting at head, inserting at tail);
// Diplay circular linked list;

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
        prev=NULL;
    }
};

node* split(node* head)  // To split the list for merge sorting (divide and conquer); 
{
    node *fast=head, *slow=head; // floyd's algorithm;
    while(fast->next!=NULL && fast->next->next!=NULL) 
    {
        fast=fast->next->next;
        slow=slow->next;
    } 
    node* temp=slow->next;
    slow->next=NULL;
    return temp;
}

node* merge(node* first,node* second) // To merge to sorted or sorting linked lists;
{
    if(!first)return second; 
    if(!second)return first;

    if(first->data < second->data)
    {
        first->next=merge(first->next,second);
        first->next->prev=first;
        first->prev=NULL;
        return first;
    }
    else
    {
        second->next=merge(first,second->next);
        second->next->prev=second;
        second->prev=NULL;
        return second;
    }
}

node* merge_sort(node* head) // Merge sorting algorithm for linked list;
{
    if(!head || !head->next) return head;

    node* second=split(head);

    head=merge_sort(head);
    second=merge_sort(second);

    return merge(head,second);
}

void display(node* head)  // To display linked list;
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

void make_circular(node* &head)  // To make linked list circular; 
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
}

void insert_at_circular_head(node* &head,int val)  // To insert node at head of a circular linked list; 
{
    node* n=new node(val);

    if(head==NULL) // special case when no node is present;
    {
        head=n;
        n->next=n;
        n->prev=n;
    }

    n->prev=head->prev;
    head->prev->next=n;
    head->prev=n;
    n->next=head;
    head=n;
}

void insert_at_circular_tail(node* &head,int val) // To insert node at tail of a circular linked list; 
{
    node* n=new node(val);
    if(head==NULL) // special case when no node is present;
    {
        head=n;
        n->next=n;
        n->prev=n;
    }
    node* temp= head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    n->next=head;
    head->prev=n;
}

void circular_display(node* head) // To display circular linked list (otherwise it'll be infinite loop);
{
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
}

int main()
{
    node* head=NULL;  // initiating head node;

    head=new node(8);  // first node          results(8->NULL);
    head->next=new node(2);  // next node     results(8->2->NULL); 
    head->next->prev=head;
    head->next->next=new node(1); // next node    results(8->2->1->NULL);
    head->next->next->prev=head->next;
    head->next->next->next=new node(9);  // next node    results(8->2->1->9->NULL);
    head->next->next->next->prev= head->next->next;
    head->next->next->next->next=new node(5);  // next node    results(8->2->1->9->5->NULL);
    head->next->next->next->next->prev=head->next->next->next;

    display(head); // to display list       output : 8 2 1 9 5 

    node* head_2=NULL;  // initiating second linked list;

    head_2=new node(6); // first node       results(6->NULL);
    head_2->next=new node(9); // next node      results(6->9->NULL);
    head_2->next->prev=head_2;
    head_2->next->next=new node(3); // next node      results(6->9->3->NULL);
    head_2->next->next->prev=head_2->next;
    head_2->next->next->next=new node(5); // next node      results(6->9->3->5->NULL);
    head_2->next->next->next->prev= head_2->next->next;
    head_2->next->next->next->next=new node(1);  // next node      results(6->9->3->5->1->NULL);
    head_2->next->next->next->next->prev=head_2->next->next->next;

    display(head_2); // dispay second liked list       output : 6 9 3 5 1 


    head=merge_sort(head);// merge sorting the list;
    head_2=merge_sort(head_2); // merge sorting the second list;
 
    display(head); // display first list     output : 1 2 5 8 9
    display(head_2); // display second list   output : 1 3 5 6 9 

    head=merge(head,head_2);  // merging both sorted list in a first list;

    display(head); // diaplay new merged linked list      output :   1 1 2 3 5 5 6 8 9 9 

    make_circular(head);  // making linked list circular;   results(1->1->2->3->5->5->6->8->9->9->7......) infinite loop;

    insert_at_circular_tail(head,7); // inserting at tail of circular linked list;       results(1->1->2->3->5->5->6->8->9->9->7......)
    insert_at_circular_head(head,0); // inserting at head of circulat linked list;       results(0->1->1->2->3->5->5->6->8->9->9->7......)

    circular_display(head); // special display for circular linked list        output :  0 1 1 2 3 5 5 6 8 9 9 7 

    return 0;
}