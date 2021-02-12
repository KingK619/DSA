
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

stack<int> callingStack;

void DFS(vector<int> adj[], int V, int u, int disc[], int low[], bool inStack[])
{
    static int count = 0;
    inStack[u] = true;
    callingStack.push(u);
    disc[u] = count;
    low[u] = count;
    count++;

    for (auto v : adj[u])
    {

        if (disc[v] == -1)
        {
            DFS(adj, V, v, disc, low, inStack);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(disc[v], low[u]);
        }
    }

    if (disc[u] == low[u])
    {
        while (callingStack.top() != u)
        {
            int topEle = callingStack.top();
            cout << topEle << " ";
            callingStack.pop();
            inStack[topEle] = false;
        }
        int topEle = callingStack.top();
        cout << topEle << " ";
        callingStack.pop();
        inStack[topEle] = false;
        cout << endl;
    }
}

void tarjan(vector<int> adj[], int V)
{

    int disc[V];
    int low[V];
    bool inStack[V];
    memset(inStack, false, V);
    for (int i = 0; i < V; i++)
    {
        disc[i] = low[i] = -1;
    }

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
        {
            DFS(adj, V, i, disc, low, inStack);
        }
    }
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    tarjan(adj, V);
}
