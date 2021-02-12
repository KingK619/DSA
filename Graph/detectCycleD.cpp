
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include<queue>
using namespace std;

void addEdge(vector <int> adj[], int u, int v){
  adj[u].push_back(v);
}

void printGraph(vector <int> adj[], int V){
  for(int i=0;i<V;i++){
      cout<<i<<"-->";
    for(int x: adj[i])
      cout<<x<<" ";

    cout<<endl;
  }
  
}

bool ifCycleDis(vector<int> adj[],int V,bool visited[],bool recS[],int sourceVertex){
  visited[sourceVertex]=true;
  recS[sourceVertex]=true;

  for(auto x: adj[sourceVertex]){
    if(visited[x]==false && ifCycleDis(adj,V,visited,recS,x)){
      return true;
    }
    else if(recS[x] == true){
      return true;
    }
  }
  recS[sourceVertex]=false;
  return false;

}

bool ifCycle(vector<int>adj[],int V){
  bool visited[V];
  bool recS[V];
  memset(visited,false,V);
  memset(recS,false,V);

  for(int i=0;i<V;i++){
    if(visited[i]==false){
      if(ifCycleDis(adj,V,visited,recS,i) == true)
        return true;   
    }
  }
  return false;
}

int main() {
  int V = 6;
  vector <int> adj[V];
  addEdge(adj, 0,1);
  addEdge(adj, 2,1);
  addEdge(adj, 2,3);
  addEdge(adj, 3,4);
  addEdge(adj, 4,5);
  addEdge(adj, 5,3);

  printGraph(adj, V);
  cout<<endl<<ifCycle(adj,V);
}
