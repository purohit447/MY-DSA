// MY DSA-1.0
// SINGLY LINKED LISTS
// by Karan Purohit


// What's inside?

// Content:
// Traversing (singly linked lists can't be traverse backwards) becasue of single pointers pointing unidirectionally;
// Insert Items (at Head, at tail, at Random)
// Delete Items (at Head, at random, at Tail) 
// Search Items (linear searching) a singly list can't access elements at random so binary/logrithmic search isn't possible; 
// Reversed Linked List (iteratively and recusively)
// Clear/delete List (all data lost/erased) 

// source code: 
#include<iostream>
using namespace std;
class node    //declarartion of user-define data type;
{ 
public:
  int data;
  node* next;

  node(int val)
  {
    data=val;
    next=NULL;
  }
};

void tail(node* &head,int val)  // insert elements at tail of a linked list;
{
  node* n = new node(val); 

  if(head==NULL)   // special case if no node has been established;
  {
    head=n;
    return;
  }

  node* temp=head;
  while(temp->next!=NULL)  // same can be done by for loop :: for(node* temp=head ; temp->next!=NULL; temp=temp->next)
  {
    temp=temp->next;
  }
  temp->next=n;
}

void display(node* head) //printing a link list
{
  node* temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }cout<<"NULL\n"; //just for linking refrences (no atchuall need);
}

void top(node* &head,int n) //insert at top node;
{
  node* val= new node(n); 
  val->next=head; 
  head=val;
}

void ins_ran(node* &head,int val,int n) // insert element at random positions;
{
  node* temp= head, * new_node= new node(val); n-=2; // n-2 because of indexing starts from 0 and need previous node;
  while(n--)
  {
    temp=temp->next;
  }
  new_node->next=temp->next;
  temp->next=new_node;
}

void top_del(node* &head) // delete head element;
{
  node* dele=head;
  head=head->next;
  delete dele;
}

void del(node* &head, int n) // delete any linked node by value;
{
  if(head==NULL)return;  // corner case 1 (if no node is present); 
  if((head->next==NULL)) // corner case 2 (if a single node is present);
  {
    node* dele=head;
    head=head->next;
    delete dele; return;
  }
  node* karan= head; 
  while(karan->next->data!=n)
  {
    karan=karan->next;
  }
  node* deleq=karan->next; // deleq is a node pointer that will terminate the memory later;
  karan->next=karan->next->next; // at this point the particular linked node has became inaccessible;
  delete deleq;
}

node* rev(node* & head)  // for reversing a linked list iteratively;
{
  node* pre=NULL;  
  node* cur= head;
  node* nex;
  while(cur!=NULL)
  {
    nex=cur->next;
    cur->next=pre;
    pre=cur;
    cur=nex;
  }
  return pre; // pre will be the new head to start with;
}

node* recv(node* &head) // for reversing  a linked list recursively;
{
  if(head==NULL || head->next==NULL) return head; // tail will be the new_head of reversed list;
  node* new_head = recv(head->next);
  head->next->next=head; // recusively adding reverse links;
  head->next=NULL;
  return new_head; // this will be the new head to begin with;
}

void dele_list(node* &head) // for deleting the list;
{
  node* temp;
  while(head!=NULL)
  {
    temp=head;
    head=head->next;
    delete temp; // deleting memory while iterating;
  }  
}

int main()
{
  //first node can be defined as global node to avoid sending head with refrence whenever needed;
  node* head=NULL; // initiating first node;     result(NULL);

  tail(head,4); // inserting at tail (corner case tail is head because head==null);     result(4->NULL);
  tail(head,6); // inserting at tail;    result(4->6->NULL);
  tail(head,9); // inserting at tail;    result(4->6->9->NULL);
  top(head,7); // inserting at head;     result(7->4->6->9->NULL);
  
  display(head); // printing list;     output: 7->4->6->9->NULL;

  del(head,4); // delete node with value 4;      result(7->6->9->NULL);
  top_del(head); // delete head value;        result(6->9->NULL);

  ins_ran(head,8,2); // inserted at 3 position on a list;    result(6->8->9->NULL);

  node* new_head= recv(head); // reversing list;      result(9->8->6->NULL);      
  
  display(new_head);       // output: 9->8->6->NULL; 

  dele_list(new_head); //whole list terminated;    results(NULL);

  display(new_head); // printing updated list;     output:  NULL;   

  return 0;  
}
