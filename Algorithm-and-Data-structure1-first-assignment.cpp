#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct node
{
    bool isEndOfWord;
    node *child[26];
    vector<string> syno;

}*head;

node *newnode()
    {
        node *current = new node;
        for (int i = 0; i < 26; i++)
            current->child[i] = NULL;

        current->isEndOfWord = false;
        return current;
}

void insert1(const string &word,const string &meaning)
{
    if(head==NULL)
    {
        head = newnode();
    }
    node *current = head;
    for(int i=0; i<word.length(); i++)
    {
        int letter = (int)word[i] - (int)'a';
        if(current->child[letter]==NULL)
            current->child[letter] = newnode();
        current=current->child[letter];
    }
    current->isEndOfWord=true;
    current->syno.push_back(meaning);

}

void print(const string &word)
{
    node *current = head;
    for(int i=0; i<word.length(); i++)
    {
        int letter = (int)word[i] - (int)'a';
        if(current->child[letter]==NULL)
            return;
        current = current->child[letter];

    }
    if(current->isEndOfWord)
    {
        for(auto &&i : current->syno)
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int x;
    int Q;
    cin>>Q;
    string word;
    string meaning;
    for(int i=0; i<Q; i++)
    {
        cin>>x;
        if(x==1)
        {
            cin>>word>>meaning;
            insert1(word,meaning);
        }
        else if(x==2)
        {
            cin>>word;
            print(word);
            i++;
        }
    }
}
