#include<iostream>
#include<vector>
#include <unordered_map>
#include <map>
using namespace std;
// undirected graph 
unordered_map<int,vector<int>> adj;
void addEdge( int e1,int e2){
	
	adj[e1].push_back(e2);
	adj[e2].push_back(e1);

}

void addVertex(int vertex){
	vector<int> v;
	adj.insert(make_pair(vertex,v));

}


void displayVector(vector<int> v){
	for(auto x : v){
		cout<<x<<" ";
	}
	cout<<endl;
}

void display(){
	
	for(auto x : adj){
		cout<<x.first<<"-->"; displayVector(x.second);
	}
	
}



int main(){
	
	addVertex(1);
	addVertex(2);
	addEdge(1,2);
	addVertex(3);
	addVertex(4);
	addEdge(1,3);
	addEdge(4,2);
	addVertex(5);
	display();

}
