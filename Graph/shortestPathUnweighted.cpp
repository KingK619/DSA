
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

void shortestPath(vector<int> adj[],int V,int sourceVertex){
  int distance[V];
  memset(distance,INT_MAX,V);
  distance[sourceVertex]=0;
  bool visited[V];
  memset(visited,false,V);
  queue<int> Q;
  Q.push(sourceVertex);
  while(!Q.empty()){
    int temp = Q.front();
    Q.pop();
    for(auto i : adj[temp]){
      if(visited[i]==false){
        distance[i]=distance[temp]+1;
        visited[i]=true;
        Q.push(i);
      }
    }
  }
  for(int i=0;i<V;i++){
    cout<<distance[i]<<" ";
  }
}

int main() {
  int V = 4;
  vector <int> adj[V];
  addEdge(adj, 0,2);
  addEdge(adj, 0,1);
  addEdge(adj, 1,3);
  addEdge(adj, 2,3);


  printGraph(adj, V);
  shortestPath(adj,V,0);
}
