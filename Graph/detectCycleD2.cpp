
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include<queue>
using namespace std;
//kahn's theorem
//if there exists any cycle , at some time there will be no 
//0 indegree vertices to pop out from the queue.
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

bool isCycle(vector<int>adj[],int V){
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
  
  int count=0;
  while(!Q.empty()){
    int temp = Q.front();
    Q.pop();
    for(auto x : adj[temp]){
      indegree[x]--;
      if(indegree[x]==0)
        Q.push(x);
    } 
    count++;
  }
  if(count!=V)
    return true;
  else
    return false;

}

int main() {
  int V = 5;
  vector <int> adj[V];
  addEdge(adj, 0,1);
  addEdge(adj, 4,1);
  addEdge(adj, 1,2);
  addEdge(adj, 2,4);
  addEdge(adj, 3,1);


  printGraph(adj, V);
  cout<<boolalpha<<isCycle(adj,V);
}
