#define ROW 4
#define COL 3
#include <iostream>
using namespace std;
struct TrieNode
{
    TrieNode *child[2] = {nullptr};
    bool isEnd = false;
};

bool insert(TrieNode *root, int M[ROW][COL], int row, int col)
{

    if (root == nullptr)
        root = new TrieNode();

    if (col < COL)
    {
        return insert(root->child[M[row][col]], M, row, col + 1);
    }

    if (root->isEnd == true)
        return false;
    else
    {
        root->isEnd = true;
        return true;
    }
}

int countUnique(TrieNode *root, int M[ROW][COL])
{
    int count = 0;
    for (int row = 0; row < ROW; row++)
    {
        if (insert(root, M, row, 0) == true)
            count++;
    }

    return count;
}

int main()
{
    TrieNode *root = new TrieNode();
    int matrix[ROW][COL] = {{0, 1, 0},
                            {1, 0, 1},
                            {0, 1, 0},
                            {1, 0, 1}};

    cout << countUnique(root, matrix);
}