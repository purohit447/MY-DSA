#include<bits/stdc++.h>
using namespace std;
class trie
{
public:
  class node
  {
  public:
    node* next[26];
    bool end;

    node()
    {
      end=false;
      for(int i=0;i<26;i++)
      {
        next[i]=NULL;
      }
    }
  };
  node* root;

  trie()
  {
    root=new node();
  }

  void insert(string word)
  {
    node* it = root;
    int index=0;
    while(index<word.size())
    {
      if(it->next[word[index]-'a']==NULL)
      {
        it->next[word[index]-'a']=new node(); 
      }
      it=it->next[word[index]-'a'];
      index++;
    }
    it->end=true;
  }

  bool search(string word)
  {
    node* it = root;
    int index=0;
    while(index<word.size())
    {
      if(it->next[word[index]-'a']==NULL)
      {
        return false;
      }
      it=it->next[word[index]-'a'];
      index++;
    }
    return it->end;
  }

};

int main()
{
  trie* head = new trie();
  head->insert("karan");
  head->insert("raghav");
  head->insert("cats");
  head->insert("caterpiller");
  head->insert("cat");
  cout<<head->search("karan")<<endl;
  cout<<head->search("cat")<<endl;
  cout<<head->search("ca")<<endl;
  cout<<head->search("judo")<<endl;
  cout<<head->search("caterpiller")<<endl;
}