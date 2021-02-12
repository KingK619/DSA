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

void BFS(vector <int> adj[], int V,int sourceVertex,bool visited[]){
  queue<int> Q;
  Q.push(sourceVertex);
  visited[sourceVertex]=true;
  while(!Q.empty()){
    int temp = Q.front();
    cout<<temp<<" ";

    Q.pop();
    if(visited[temp]!=true){
      visited[temp]=true;
    }
    for(auto v : adj[temp])
    {
      if(visited[v]==false){
        Q.push(v);
        visited[v]=true;
      }

    }
  }
}

void BFSDis(vector<int> adj[],int V){
  int count=0;
    bool visited[V];
    memset(visited, false, V);
    for(int i=0;i<V;i++){
      if(visited[i] == false){
        BFS(adj,V,i,visited); count++;
      }
      
    }
cout<<"Count: "<<count;
}


int main() {
  int V = 7;
  vector <int> adj[V];
  addEdge(adj, 0,1);
  addEdge(adj, 0,2);
  addEdge(adj, 1,2);
  addEdge(adj, 1,3);
  addEdge(adj, 2,3);
  addEdge(adj, 4,5);
  addEdge(adj, 4,6);
  addEdge(adj, 5,6);

  printGraph(adj, V);
  cout<<endl;
  BFSDis(adj,V);
}
