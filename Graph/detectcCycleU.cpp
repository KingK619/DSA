
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

bool ifCycleDis(vector<int> adj[],int V,bool visited[],int sourceVertex,int parent){
  visited[sourceVertex]=true;
 
  for(auto x : adj[sourceVertex]){
    if(visited[x]==false){
      if( ifCycleDis(adj,V,visited,x,sourceVertex) == true )
        return true;
    }
    else if(x!=parent){
      return true;
    }
  }
  return false;
}

bool ifCycle(vector<int>adj[],int V){
  bool visited[V];
  memset(visited,false,V);
  for(int i=0;i<V;i++){
    if(visited[i]==false){
      if(ifCycleDis(adj,V,visited,i,-1) == true)
        return true;
      else
        return false;
    }
  }
}

int main() {
  int V = 6;
  vector <int> adj[V];
  addEdge(adj, 0,1);
  addEdge(adj, 2,1);
  addEdge(adj, 1,3);
  // addEdge(adj, 2,3);
  addEdge(adj, 2,4);
  addEdge(adj, 4,5);

  




  printGraph(adj, V);
  cout<<endl<<ifCycle(adj,V);
}
