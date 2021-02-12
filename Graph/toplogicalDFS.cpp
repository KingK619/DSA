
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

void printGraph(vector<int> adj[], int V)
{
  for (int i = 0; i < V; i++)
  {
    cout << i << "-->";
    for (int x : adj[i])
      cout << x << " ";

    cout << endl;
  }
}
stack<int> s;
void topological(vector<int> adj[], int V, int sourceVertex, bool visited[])
{
  visited[sourceVertex] = true;

  for (auto u : adj[sourceVertex])
  {
    if (visited[u] == false)
    {
      topological(adj, V, u, visited);
    }
  }
  s.push(sourceVertex);
}

void topologicalDis(vector<int> adj[], int V)
{

  bool visited[V];
  memset(visited, false, V);
  for (int i = 0; i < V; i++)
  {
    if (visited[i] == false)
    {
      topological(adj, V, i, visited);
    }
  }
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
}

int main()
{
  int V = 5;
  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 3);
  addEdge(adj, 2, 4);
  addEdge(adj, 3, 4);

  printGraph(adj, V);
  cout << endl;
  topologicalDis(adj, V);
}
