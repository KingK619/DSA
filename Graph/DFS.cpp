
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include<queue>
using namespace std;

void addEdge(vector <int> adj[], int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);

}

void printGraph(vector <int> adj[], int V){
  for(int i=0;i<V;i++){
      cout<<i<<"-->";
    for(int x: adj[i])
      cout<<x<<" ";

    cout<<endl;
  }
  
}

void DFS(vector <int> adj[], int V,int sourceVertex,bool visited[]){
  visited[sourceVertex]=true;
  cout<<sourceVertex<<" ";
  for(auto u : adj[sourceVertex]){
  	if(visited[u]==false){
  		DFS(adj,V,u,visited);
  	}
  }
}

void DFSDis(vector<int> adj[],int V){
  int count=0;
    bool visited[V];
    memset(visited, false, V);
    for(int i=0;i<V;i++){
      if(visited[i] == false){
        DFS(adj,V,i,visited); count++;
      }
      
    }
cout<<"Count: "<<count;
}


int main() {
  int V = 5;
  vector <int> adj[V];
  addEdge(adj, 0,2);
  addEdge(adj, 0,1);
  addEdge(adj, 1,4);
  addEdge(adj, 2,3);
  addEdge(adj, 1,3);
  addEdge(adj, 4,3);

 

  printGraph(adj, V);
  cout<<endl;
  DFSDis(adj,V);
}
