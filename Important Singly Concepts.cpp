// MY DSA-1.1
// IMPORTANT CONCEPTS OF SINGLY LINKED LISTS
// by Karan Purohit
             


// What's inside?

// Content (important): 
// Reversing K. Nodes;
// Cycle in linked list (creating, detection and removal);
// Hare and Tortoise algorithm  (Floyd's algorithm);



//Source Code 
#include<iostream>
using namespace std;

class node  // declaration of linked list
{
public:
	int data;
	node* next;

	node(int val) // constructor;
	{
		data=val;
		next=NULL;
	}
};


void tail(node* &head, int val);  // to create a linked list by tail insterting;
void display(node* head); // to display link list;

node* rever_K(node* &head,int k) // to reverse K nodes of a Linked List. 
{
   node* pre=NULL;  
   node* cur= head;
   node* nex; 
   int count=0;
   while(cur!=NULL && count<k) // iterate till the required index
   {
    	nex=cur->next;
    	cur->next=pre;
    	pre=cur;
    	cur=nex;
    	count++;
   }
   if(nex!=NULL) head->next=rever_K(nex,k); // each tail will be linked to rest of list;
   return pre; // pre will be the new head to begin with;  
}


void create_cycle(node* &head,int pos)  // to crete cycle in linked list; 
{
	node* temp=head;
	node* start_cyl;

	int count=1;  // to find out previous node to operate with;
	while(temp->next!=NULL)
	{
		if(pos==count) start_cyl=temp;  // setting pos for cycle; 

		temp=temp->next;
		count++;
	}

	temp->next=start_cyl; // tail's NULL *ptr is now pointing pos results cycling; 
}


bool dect_cycle(node* &head)  // to detect cycle in linked list;
{
	node* tortoise= head;
	node* hare= head;

	while(hare!=NULL && hare->next!=NULL)
	{
		tortoise=tortoise->next;
		hare=hare->next->next;

		if(hare==tortoise)
		{
			return true;
		}
	} 
	return false;
}


void remove_cycle(node* &head) // to remove cycle form linked list;
{
	node* tortoise=head;
	node* hare=head;

	do
	{
		tortoise=tortoise->next;
		hare=hare->next->next;
	} while(tortoise!=hare);

	hare=head;
	while(tortoise->next!=hare->next)
	{
		tortoise=tortoise->next;
		hare=hare->next;
	}
	tortoise->next=NULL;
}


//-------------------------------------- MAIN FUNCTION LIES HERE -----------------------------------------//

int main()
{
	node* head= NULL; // initiating first node;

	tail(head,1);   // insert at tail    results(1->null);
	tail(head,2);	// insert at tail    results(1->2->null);
	tail(head,3);	// insert at tail    results(1->2->3->null);
	tail(head,4);	// insert at tail    results(1->2->3->4->null);
	tail(head,5);	// insert at tail    results(1->2->3->4->5->null);
	tail(head,6);	// insert at tail    results(1->2->3->4->5->6->null);
	tail(head,7);	// insert at tail    results(1->2->3->4->5->6->7->null);

	node* new_head=rever_K(head,3); // reversing k nodes of Linked list
	display(new_head); // Display list    output :  3->2->1->6->5->4->7->NULL

	new_head=rever_K(new_head,3); // re-reversing k nodes of list
	display(new_head); // Display list    output :  1->2->3->4->5->6->7->NULL

	create_cycle(new_head,3); // cycle created at 3rd node;     results(infinite loop form node 3);
	//display(new_head); // Display list    output:  1->2->3->4->5->6->7->3->4->5->6->7->3->4->5->6->7->3->4->.........NULL
	
	if(dect_cycle(new_head)) cout<<"List is cycling\n"; // detecting cycle;    output: List is cycling;
	else cout<<"List isn't cycling\n";

	remove_cycle(new_head); // removing cycle from singly linked list;

	if(dect_cycle(new_head)) cout<<"List is cycling\n"; // detecting cycle;    output: List isn't cycling;
	else cout<<"List isn't cycling\n";

	display(new_head); // Display list   output:  1->2->3->4->5->6->7->NULL;

	return 0;
}



// FUNCTIONS FOR CREATING AND DISPLAY LINKED LIST.
//--------------------------------------------------------------------------------------------------------------------------------//

void tail(node* &head,int val)  // insert elements at tail of a link list;
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


void display(node* head) //printing an link list
{
  node* temp=head; int count =20;
  while(temp!=NULL && count>1)
  {
    cout<<temp->data<<"->";
    temp=temp->next; count--;
  }
  cout<<"NULL\n"; //just for linking refrences (no atchuall need);
}
