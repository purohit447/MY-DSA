// MY DSA-2.1
// APPLICATIONS OF STACKS
// by Karan Purohit


// What's inside?

// Content:
// (stack is a linear data structure uses LIFO mechanism);
// Prefix evaluation;
// Postfix evaluation;
// Precedence of operators;
// Infix to postfix; 
// Infix to prefix;
// Balanced paranthesis;



// Source code:
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int prefix_evel(string s)   // prefix evaluation of an given string; 
{
    stack<int>st;
    for (int i = s.length()-1; i >=0; --i)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        } 
        else 
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }

    return st.top();
}

int postfix_evel(string s)   // postfix evaluation of an given string;
{
    stack<int> st;
    for (int i = 0; i <s.length(); ++i)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int op1,op2;

            op2=st.top();     // OP2 = top element postfix nature;
            st.pop();
            op1=st.top();
            st.pop(); 

             switch(s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            }     
        }
    }

    return st.top();
}

int precedence(char c)     // to check precedence of operators;
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else return -1;  // for brackets;
}

string infix_to_postfix(string s)   // to convert infix to postfix; 
{
    stack<char> st;
    string res;

    for (int i = 0; i <s.length(); ++i)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && precedence(st.top())>precedence(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }

    return res;
}

string infix_to_prefix(string s)  // to convert infix to prefix;
{
    reverse(s.begin(),s.end());  // reversing the string; 
    stack<char> st;
    string res;

    for (int i = 0; i <s.length(); ++i)  // just because we reversed the string;
    {
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }

    res=infix_to_postfix(s);  // the peice of code is same for postfix and prefix;

    reverse(res.begin(),res.end()); // reversing the string again;
    return res;
}

void balanced_paranthesis(string s)  // to check the string of paranthesis is balanced or not;
{
    stack<char> st;
    bool ans=true;
    for (int i = 0; i <s.length(); ++i)
    {
        if(s[i]=='{' || s[i]=='(' || s[i]=='[')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(!st.empty() && st.top()=='(') st.pop();
            else
            {
                ans=false;
                break;
            }
        }
        else if(s[i]=='}')
        {
            if(!st.empty() && st.top()=='{') st.pop();
            else
            {
               ans=false; break;  
            } 
        }
        else if(s[i]==']')
        {
            if(!st.empty() && st.top()=='[') st.pop();
            else
            {
                ans=false; break;
            }
        }
    }

    if(!st.empty())
    {
        ans=false;
    }

    if(ans)
    {
        cout<<"VALID STRING"<<endl;
    }
    else
    {
        cout<<"INVALID STRING"<<endl;
    }
}

int main()
{
    cout<<prefix_evel("-+7*45+20")<<endl;  // computing the prefix expression          results( 25 );  
    cout<<postfix_evel("46+2/5*7+")<<endl; // computing the postfix expression          results( 32 );

    cout<<infix_to_postfix("(a-b/c)*(a/k-l)")<<endl; // converting infix to postfix      results( abc/-ak/l-* );
    cout<<infix_to_prefix("(a-b/c)*(a/k-l)")<<endl;  // converting infix to prefix      results( *-a/bc-/akl );

    balanced_paranthesis("{()}[]]"); // checking balanced paranthesis           output : INVALID STRING
    balanced_paranthesis("{()[]}"); // checking balanced paranthesis           output : VALID STRING

    return 0;
}