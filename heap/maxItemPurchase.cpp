
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

void minHeapify(int * array , int i,int size)
{
    int lt = left(i);
    int rt = right(i); 
    int smallest = i;
    if(lt < size && array[lt] < array[i])
    {
        smallest = lt;
    }

    if(rt < size && array[rt] < array[smallest])
    {
        smallest = rt;
    }

    if(smallest != i)
    {
        swap(array[i],array[smallest]);
        minHeapify(array,smallest,size);
    }
}

void buildHeap(int * array , int size)
{
    for(int i = (size-1)-1/2;i>=0;i--)
    {
        minHeapify(array,i,size);
    }
}


int maxItemPurchase(int * array ,int size, int sum)
{
    int res=0;
    priority_queue<int,vector<int>,greater<int>>Q;

    for(int i=0;i<size;i++){
        Q.push(array[i]);
    }

    while(!Q.empty())
    {
        if(Q.top() <=sum )
        {

            sum-=Q.top();
            Q.pop();
            res++;
            
        }
        else
            break;

    }
    return res;
}


int main() 
{   
  
    int arr[]={15,54,23,61,11,33,51};
    cout<<maxItemPurchase(arr,7,74);

}
   






