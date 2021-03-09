#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode *child[26];
    int pc;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        pc = 0;
    }
};

void insert(TrieNode *curr, string word)
{

    for (int i = 0; i < word.length(); ++i)
    {
        int index = word[i] - 'a';
        if (curr->child[index] == NULL)
        {

            curr->child[index] = new TrieNode();
                }
        curr->pc++;
        curr = curr->child[index];
    }
}

int prefixCount(TrieNode *curr, string word)
{
    if (curr == NULL)
        return 0;

    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (curr->child[index] == NULL)
            return 0;

        curr = curr->child[index];
    }

    return curr->pc;
}

int main()
{
    TrieNode *root = new TrieNode();
    insert(root, "aabc");
    insert(root, "aacc");
    insert(root, "abbac");
    insert(root, "adb");
    insert(root, "aabcdef");
    // cout << root->child[0]->pc;
    cout << prefixCount(root, "aa");
}