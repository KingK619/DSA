
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stack>
#define V 7
#define pb push_back

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(vector<int> adj[], int u, int disc[], int low[], int parent[])
{

    static int count = 0;
    disc[u] = low[u] = count, count++;
    for (auto v : adj[u])
    {

        if (disc[v] == -1)
        {

            parent[v] = u;
            DFS(adj, v, disc, low, parent);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
            {

                cout << u << " --> " << v << endl;
            }
        }
        else if (v != parent[u])
        {

            low[u] = min(low[u], disc[v]);
        }
    }
}

void bridges(vector<int> adj[])
{
    int disc[V], low[V], parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = disc[i] = low[i] = -1;
    }

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
            DFS(adj, i, disc, low, parent);
    }
}

int main()
{
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 6);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    bridges(adj);
}
