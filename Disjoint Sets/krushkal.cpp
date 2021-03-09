#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int source, des, weight;
};

vector<Edge> mst;
bool comparator(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    parent[x] = find(parent[x], parent); // path compression ( optimize)
    return parent[x];
}

void Union(vector<int> &parent, vector<int> &rank, int x, int y)
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

bool isCycle(int x, int y, vector<int> &parent)
{
    return find(x, parent) == find(y, parent) ? true : false;
}

void krushkals(vector<Edge> edge_list, int V, int E, vector<int> &parent, vector<int> &rank)
{

    // sorting the edge list according to the edge weights
    sort(edge_list.begin(), edge_list.end(), comparator);

    int i = 0, j = 0;

    while (i < V - 1 && j < E)
    {

        if (isCycle(edge_list[j].source, edge_list[j].des, parent))
        {

            j++;
            continue;
        }

        Union(parent, rank, edge_list[j].source, edge_list[j].des);
        mst.push_back(edge_list[j]);
        i++;
    }
}

void printMST(vector<Edge> mst)
{
    for (auto e : mst)
    {
        cout << e.source << " " << e.des << " " << e.weight << endl;
    }
}

int main()
{
    int E = 5, V = 4;

    vector<int> parent = {
        0,
        1,
        2,
        3,
    };
    vector<int> rank(V, 0);

    vector<Edge> edge_list;

    edge_list.push_back({0, 1, 10});
    edge_list.push_back({0, 2, 6});
    edge_list.push_back({0, 3, 5});
    edge_list.push_back({1, 3, 15});
    edge_list.push_back({2, 3, 4});

    krushkals(edge_list, V, E, parent, rank);
    printMST(mst);
}