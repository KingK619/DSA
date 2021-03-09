#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    parent[x] = find(parent[x], parent); // path compression ( optimize)
    return parent[x];
}

void makeFriend(vector<int> &nums, vector<int> &parent, int x, int y)
{
    int p1 = find(x, parent);
    int p2 = find(y, parent);
    if (p1 == p2)
        return;

    parent[p2] = p1;
}

void makeFriendByRank(vector<int> &nums, vector<int> &parent, vector<int> &rank, int x, int y)
{
    int p1 = find(x, parent);
    int p2 = find(y, parent);
    if (p1 == p2)
        return;

    if (rank[p1] > rank[p2])
        parent[p2] = p1;
    if (rank[p1] < rank[p2])
        parent[p1] = p2;
    else
    {
        parent[p2] = p1;
        rank[p1]++;
    }
}

bool areFriends(int x, int y, vector<int> &parent)
{
    return find(x, parent) == find(y, parent) ? true : false;
}

int main()
{
    vector<int> nums = {0, 1, 2, 3};
    vector<int> parent = {0, 1, 2, 3};
    vector<int> rank(4, 0); // optimized
    makeFriendByRank(nums, parent, rank, 0, 2);
    cout << boolalpha;
    cout << areFriends(0, 2, parent) << " " << endl;
    makeFriendByRank(nums, parent, rank, 0, 1);
    cout << areFriends(1, 2, parent) << " " << endl;
    //makeFriendByRank(nums, parent, rank, 3, 1);
    cout << areFriends(3, 2, parent) << " ";
}