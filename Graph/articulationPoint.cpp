
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void articulationPoint(vector<int> adj[], int V, int parent[], int sourceVertex, int disc[], int low[], bool ap[])
{
    static int count = 0; // discovery time
    int child = 0;        // current node's child

    count++;                    // discoverd
    disc[sourceVertex] = count; // discovery time of the node
    low[sourceVertex] = count;  // current lowest possible node that can be visited

    for (auto u : adj[sourceVertex])
    {

        if (disc[u] == -1)
        {
            cout << endl;
            child++;
            parent[u] = sourceVertex;
            articulationPoint(adj, V, parent, u, disc, low, ap);
            low[sourceVertex] = min(low[sourceVertex], low[u]); // if through its child node, we can visit the ancestors, we'll mark it as current-vertex Low!

            // first condition of being an articulation point
            // check for the root

            if (parent[sourceVertex] == -1 && child > 1)
                ap[sourceVertex] = true;

            // 2nd : if we can't reach the ancestors throgh the child, then its an AP.
            if (parent[sourceVertex] != -1 && low[u] >= disc[sourceVertex])
                ap[sourceVertex] = true;
        }
        // settting up low of the current vertex. Checking if the child nodes have any back-edge or 'low' less than the current.
        else if (u != parent[sourceVertex])
        {
            low[sourceVertex] = min(disc[u], low[sourceVertex]);
        }
    }
}

void AP(vector<int> adj[], int V)
{

    int disc[V];
    int low[V];
    int parent[V];
    bool ap[V];

    memset(ap, false, V);
    for (int i = 0; i < V; i++)
    {
        parent[i] = disc[i] = low[i] = -1;
    }

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
        {
            articulationPoint(adj, V, parent, i, disc, low, ap);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (ap[i] == true)
            cout << i << " ";
    }

    // for (int i = 0; i < V; i++)
    // {
    //     cout << disc[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < V; i++)
    // {
    //     cout << low[i] << " ";
    // }
}

int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 6);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    AP(adj, V);
}
