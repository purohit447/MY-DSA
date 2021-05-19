// MY DSA-3.0
// INTRODUCTION TO QUEUES
// by Karan Purohit


// What's inside?

// Content:
// (Queue data structure uses FIFO mechanism);
// Implementation of queues in array;
// Implementation of queues in linked lists;



// Source code:
#include<iostream>
using namespace std;
# define m 20

class Queue     // defining Queue;
{
    int* arr;
    int front;
    int back;
public:

    Queue()
    {
        arr=new int[m];
        front=-1;       
        back=-1;
    }

    void push(int x)  // to push in array;
    {
        if(back==m-1)
        {
            cout<<"Queue overflown"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1) // special case when the queue is empty;
        {
            front++;
        }
    }

    void pop() // to pop from array;
    {
        if(front==-1 || front>back)
        {
            cout<<"No elements in Queue"<<endl;
            return;
        }
        front++;
    }

    int peek() // to access front of queue;
    {
        if(front==-1 || front>back)
        {
            cout<<"No elements in Queue"<<endl;
            return -1;
        }
        return arr[front];  
    }

    bool empty()  // to check if queue is empty;
    {
        if(front==-1 || front>back)
        {
            cout<<"No elements in Queue"<<endl;
            return true;
        }
        return false;
    }
};

class node // defining linked list;
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

class queue  // implementing queue in linked list; 
{
    node* front;
    node* back;
public:
    queue()
    {
        front=NULL;
        back=NULL;
    }

    void push_list(int x) // push node into queue;
    {
        node* n=new node(x);
        if(front==NULL)
        {
            back=n; front=n;
        }
        back->next=n;
        back=n;
    }

    void pop_list() // pop node from queue;
    {
        if(front==NULL)
        {
            cout<<"queue underflown";
            return;
        }
        node* deleq=front;
        front=front->next;
        delete deleq;
    }

    int peek_list() // to access the front;
    {
        if(front==NULL)
        {
            cout<<"no element in queue";
            return -1;
        }
        return front->data;
    }

    bool empty_list() // to check empty queue;
    {
        if(front==NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q; // initializing queue; 

    q.push(1); // push 1 to queue;
    q.push(2); // push 2 to queue;
    q.push(3); // push 3 to queue;
    q.push(4); // push 4 to queue;
    q.push(5); // push 5 to queue;
    q.push(6); // push 6 to queue;
    q.push(7); // push 7 to queue;

    q.pop(); // poping front;      results(2,3,4,5,6,7);

    cout<<q.peek()<<endl; // accesing front element        output : 2

    cout<<q.empty()<<endl; // checking empty queue         output : false

    queue qu;  // initializing queue;

    qu.push_list(7); // push 7 to queue;
    qu.push_list(6); // push 6 to queue;
    qu.push_list(5); // push 5 to queue;
    qu.push_list(4); // push 4 to queue;
    qu.push_list(3); // push 3 to queue;
    qu.push_list(2); // push 2 to queue;
    qu.push_list(1); // push 1 to queue;

    qu.pop_list(); // poping front;      results(6,5,4,3,2,1);

    cout<<qu.peek_list()<<endl; // acessing front node        output : 6; 

    cout<<qu.empty_list()<<endl; // checking empty queue      output : false;
    
    return 0;
}