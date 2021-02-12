#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class AdjListNode
{
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};

class Graph
{
    int V;
    list<AdjListNode> *adj;

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void shortestPath(int s);
};

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<AdjListNode>[V]; 
} 

void Graph::addEdge(int u, int v, int weight) 
{ 
	AdjListNode node(v, weight); 
	adj[u].push_back(node);  
} 

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) 
{ 
	
	visited[v] = true; 

	list<AdjListNode>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
	{ 
		AdjListNode node = *i; 
		if (!visited[node.getV()]) 
			topologicalSortUtil(node.getV(), visited, Stack); 
	} 

	Stack.push(v); 
} 

void Graph::shortestPath(int s) 
{ 
	
} 