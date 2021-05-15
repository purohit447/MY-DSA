// MY DSA-2.0
// INTRODUCTION TO STACKS
// by Karan Purohit


// What's inside?

// Content:
// (stack is a linear data structure);
// Implementation of stack using array (top(), pop(), push(), empty()); 
// Reversing a sentence using stack; 
// Inserting element at bottom in a stack; 
// Reversing a stack (by recursion);



// ------------------------------------------------------------------------------------------------- //


// Implementation of stack using array (SOURCE);
// #include<iostream>
// using namespace std;
// #define n 300 
// class stack      // declaration of Stack in array;
// {
//     int* arr;
//     int top;

// public:
//     stack()
//     {
//         arr=new int[n];
//         top=-1;
//     }

//     void push(int x)        // push function leads you insert elements in stack;
//     {
//         if(top == n-1)     // special case when stack is empty;
//         {
//             cout<<"stack overflown\n";   return;  
//         } 
//         top++;
//         arr[top]=x;
//     }

//     void pop()          // pop function leads you delete items from the stack;
//     {
//         if(top==-1)
//         {
//             cout<<"no elements to pop\n";  return;
//         }
//         top--;
//     }

//     int fn_top()       // top function leads you access the element on the top of stack;
//     {
//         if(top==-1)
//         {
//             cout<<"no elements in stack\n"; return -1;
//         }
//         return arr[top];
//     }

//     bool empty()      // empty function leads you check the stack is empty or not; 
//     {
//         return top==-1;
//     }
// };

// int main()
// {
//     stack st;       // initiating stack named st;

//     st.push(1);     // pushing 1 onto stack;         results(1);
//     st.push(2);     // pushing 2 onto stack;         results(2 1);
//     st.push(3);     // pushing 3 onto stack;         results(3 2 1);

//     cout<<st.fn_top()<<endl;   // accessing the top element;         output : 3

//     st.pop();      // poping the top element;        results(2 1);
//     st.pop();      // poping the top element;        results(1);
//     st.pop();      // poping the top element;        results(empty);
//     st.pop();`     // poping the top element;        results( no element left for poping );

//     return 0; 
// }

// -------------------------------------------------------------------------------------------------------- //




// Source Code :
#include<iostream> 
#include<stack>     // The predefined stack Header file;
using namespace std;

void rev_string(string str)  // To reverse a string or sentance;
{
    stack<string> st;
    for (int i = 0; i <str.length(); ++i)
    {
        string word="";
        while(str[i]!=' ' && i<str.length())
        {
            word+=str[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

void insert_at_bottom(stack<int> &st, int element)      // To insert element at bottom;
{
    if(st.empty()) 
    {
        st.push(element);  return;
    }
    int top_element=st.top();
    st.pop();
    insert_at_bottom(st,element);
    st.push(top_element);
}

void reverse_stack(stack<int> &st)      // To reverse a stack;
{
    if(st.empty())  return;
    int element=st.top();
    st.pop();
    reverse_stack(st);
    insert_at_bottom(st,element);
}

void display(stack<int> st)  // To display the stack;
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}  

int main()
{
    string str="what a lovely morning!";  // declared a string;
    rev_string(str); cout<<endl;   // to reverse the sring;         output : morning! lovely a what

    stack<int> st;   // declaring stack named st;
    st.push(1);      // pushed 1 onto stack;        results(1);
    st.push(2);      // pushed 2 onto stack;        results(2 1);
    st.push(3);      // pushed 3 onto stack;        results(3 2 1);
    st.push(4);      // pushed 4 onto stack;        results(4 3 2 1);
    st.push(5);      // pushed 1 onto stack;        results(5 4 3 2 1);
    st.push(6);      // pushed 6 onto stack;        results(6 5 4 3 2 1);

    insert_at_bottom(st,0); // inserting at bottom;     results(6 5 4 3 2 1 0);       

    display(st);     // display the stack;        output : 6 5 4 3 2 1 0

    reverse_stack(st);   // reversing a stack;

    display(st);   // display the stack;          output : 0 1 2 3 4 5 6

    return 0;
}