
#include<iostream>
#include<queue>
#include <bits/stdc++.h>
#include<cmath>
using namespace std; 

void display(int * array,int size){
    for(int i=0;i < size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
 }

void sortK(int * arr,int size,int k)
{
    priority_queue<int,vector<int>,greater<int>> Q;
    for(int i=0;i<=k;i++)
    {
        Q.push(arr[i]);
    }
    int index=0;
    for (int i = k+1; i < size; ++i)
    {
        arr[index++]= Q.top();
        Q.pop();
        Q.push(arr[i]);
    }
    while(!Q.empty())
    {
        arr[index++]=Q.top();
        Q.pop();
    }
}



int main() 
{   
  
    int arr[]={15,54,23,61,11,33,51};
    sortK(arr,7,4);
    display(arr,7);

}
   






