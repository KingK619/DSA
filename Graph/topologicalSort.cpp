
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include<queue>
using namespace std;
//kahn's theorem
// only in case of acyclic graphs....
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

void topological(vector<int>adj[],int V){
  bool visited[V];
  int indegree[V];
  memset(visited,false,V);
  for(int i=0;i<V;i++){
    indegree[i]=0;
  }
  queue<int>Q;
 for (int i = 0; i < V; i++) { 

        for (int x : adj[i]) { 

            indegree[x]++;
        } 
        
  } 

  // for(auto x : indegree){
  //   cout<<x<<" ";
  // }

  cout<<endl;

  for(int i=0;i<V;i++){
    if(indegree[i]==0){
      Q.push(i);
    }
  }
  
  
  while(!Q.empty()){
    int temp = Q.front();
    Q.pop();
    cout<<temp<<" ";
    for(auto x : adj[temp]){
      indegree[x]--;
      if(indegree[x]==0)
        Q.push(x);
    } 
  }

}

int main() {
  int V = 5;
  vector <int> adj[V];
  addEdge(adj, 0,2);
  addEdge(adj, 0,3);
  addEdge(adj, 2,3);
  addEdge(adj, 1,3);
  addEdge(adj, 1,4);


  printGraph(adj, V);
  topological(adj,V);
}
