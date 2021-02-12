#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
}

void printGraph(vector<int> adj[])
{
  cout << "Graph: ";
  cout << endl;
  for (int i = 0; i < V; i++)
  {
    cout << i << "--->";
    for (int x : adj[i])
      cout << x << " ";

    cout << endl;
  }
}

void DFS1(int i, vector<bool> &visited, vector<int> adj[V], stack<int> &s)
{
  visited[i] = true;
  for (int j : adj[i])
  {
    if (visited[j] == false)
      DFS1(j, visited, adj, s);
  }
  s.push(i);
}

void reverse(vector<int> rev[], vector<int> adj[])
{
  for (int i = 0; i < V; i++)
  {
    for (auto j : adj[i])
      rev[j].push_back(i);
  }
}

void DFS2(int i, vector<bool> &visited, vector<int> adj[V])
{
  cout << i << " ";
  visited[i] = true;
  for (int j : adj[i])
  {
    if (visited[j] == false)
      DFS2(j, visited, adj);
  }
}

void findSCC(vector<int> adj[])
{
  stack<int> s;
  vector<int> rev[V];
  vector<bool> visited(V, false);

  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
      DFS1(i, visited, adj, s);
  }

  reverse(rev, adj);

  for (int i = 0; i < V; i++)
    visited[i] = false;

  cout << "Strongly Connected Components: ";
  cout << endl;
  while (!s.empty())
  {
    int tmp = s.top();
    s.pop();
    if (visited[tmp] == false)
    {
      DFS2(tmp, visited, rev);
      cout << endl;
    }
  }
}

int main()
{
  vector<int> adj[V];
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  printGraph(adj);
  findSCC(adj);
}
