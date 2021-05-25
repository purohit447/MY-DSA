// MY DSA-3.1
// QUEUES AND STACKS
// by Karan Purohit


// What's inside?

// Content:
// (Queue data structure uses FIFO mechanism);
// Queues using stack (itratively and recursively);
// Stack using queues (complex pop);
// Stack using queues (complex push);



// Source code:
#include<iostream>
#include<queue>     
#include<stack>
using namespace std;

// Itrative meathod:
class Queue  // declaration of data type;
{ 
    stack<int>s1;  // itrative meathod uses 2 stacks;
    stack<int>s2;
public:
    void push(int x)  // to push element
    {
        s1.push(x);
    }

    int pop()  // to pop element
    {
        if(s1.empty() and s2.empty())  // corner case; 
        {
            cout<<"queue is empty\n";
            return -1;
        }

        if(s2.empty())  
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;   // to show which value has been poped;
    }

    bool empty()  // to check the stack empty;
    {
        if(s1.empty() and s2.empty()) 
        {
            return true;
        }
        else 
        {
            false;
        }
    }
};


// Recursively meathod:
class re_queue    // decration of data type;
{
    stack<int>s1;   // recursive meathod uses just single stack;
public:
    void re_push(int x)   // to push element;
    {
        s1.push(x);
    }

    int re_pop()   // to pop element;
    {
        if(s1.empty())  // special case;
        {
            cout<<"queue is empty\n";
            return -1;
        }

        int top_element = s1.top(); 
        s1.pop();
        if(s1.empty())
        {
            return top_element;
        }
        int item=re_pop();
        s1.push(top_element);    
        return item;     // to show which element is poped;
    }

    bool re_empty()  // to check empty;
    {
        if(s1.empty())
        {
            return true;
        }
        else 
        {
            false;
        }
    }
};


// Complex pop:
class Stack    // declaration of data type;
{
    int n;
    queue<int>q1;
    queue<int>q2;
public:
    Stack()  // constructor;
    {
        n=0;
    }

    void pop()  // to pop element;
    {
        if(q1.empty())  // corner case;
        {
            return;
        }

        while(q1.size()!=1)  
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        n--;    // n-- because size of stack decreases with pop;

        queue<int> temp=q1;  // swaping q1 and q2;
        q1=q2;
        q2=temp;
    }

    void push(int val)  // to push elements;
    {
        q1.push(val);
        n++;     // n++ because size of stack increases with push;
    }

    int top()  // to read top value;
    { 
        if(q1.empty())  // corner case;
        {
            return -1;
        }

        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ans=q1.front();
        q1.pop();
        q2.push(ans);  // we have to re-push this to avoid deletion of top;

        queue<int> temp=q1;  // swaping of q1 and q2;
        q1=q2;
        q2=temp;

        return ans; 
    }

    int size()  // to check size of stack;
    {
        return n;
    }
};


// Complex push:
class Stack_2    // declaration of data type;
{
    int n;
    queue<int> q1;
    queue<int> q2;
public:
    Stack_2()  // constructor;
    {
        n=0;
    }

    void push(int val)  // to push element;
    {
        q2.push(val);
        n++;   // n++ because size of stack increases with push;

        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp=q1;  // swaping of q1 and q2;
        q1=q2;
        q2=temp;
    }

    void pop()  // to pop element;
    {
        q1.pop();
        n--;     // n-- because size of stack decreases with pop;
    }

    int top() // to read top element;
    {
        return q1.front();
    }

    int size()  // to read size of stack;
    {
        return n;
    }
};

int main()
{

    // Itrative meathod
    Queue q;     // object q;
    q.push(1);   // push 1;
    q.push(2);   // push 2;
    q.push(3);   // push 3;

    cout<<q.pop()<<endl;   // poped 1;      output : 1

    q.push(7);  // push 7;

    cout<<q.pop()<<endl;   // poped 2       output : 2
    cout<<q.pop()<<endl;   // poped 3       output : 3
    cout<<q.pop()<<endl;   // poped 7       output : 7
    cout<<q.pop()<<endl;   // no elements to pop       output : queue is empty -1

    cout<<endl;  // new line;


    // Recursive Meathod
    re_queue qu;      // object qu;
    qu.re_push(1);    // push 1;
    qu.re_push(2);    // push 2;
    qu.re_push(3);    // push 3;

    cout<<qu.re_pop()<<endl;    // poped 1;         output : 1

    qu.re_push(7);     // push 7;

    cout<<qu.re_pop()<<endl;   // poped 2           output : 2
    cout<<qu.re_pop()<<endl;   // poped 3           output : 3
    cout<<qu.re_pop()<<endl;   // poped 7           output : 7
    cout<<qu.re_pop()<<endl;   // no elements to pop      output : queue is empty -1   

    cout<<endl;     // new line;


    // Complex pop:
    Stack st;     // object st; 
    st.push(1);   // push 1;
    st.push(2);   // push 2;
    st.push(3);   // push 3;
    st.push(4);   // push 4;

    cout<<st.top()<<endl;   // read top         output :  4

    st.pop();  // poped 4      output : 3

    cout<<st.top()<<endl;   // read top          output : 3

    cout<<st.size()<<endl;  // read size          output : 3 

    cout<<endl;      // next line;


    // Complex push:
    Stack_2 st2;   // object st2;
    st2.push(1);   // push 1;
    st2.push(2);   // push 2;
    st2.push(3);   // push 3;
    st2.push(4);   // push 4;

    cout<<st2.top()<<endl;   // read top            output : 4

    st2.pop();    // poped 4;

    cout<<st2.top()<<endl;    // read top           output : 3

    cout<<st2.size()<<endl;   // reas size          output : 3

    return 0;
}