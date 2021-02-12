
#include<iostream>
#include<queue>
#include <bits/stdc++.h>
#include<cmath>
using namespace std; 

int left(int i) { return (2*(i)+1); }
int right(int i) { return (2*(i)+2); }
int parent(int i) { return floor((i-1)/2); } 
void swap(int * arr,int i,int j){ 
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
 }
void display(int * array,int size){
    for(int i=0;i < size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
 }

void insert(int value , int * array , int &size, int capacity)
{
    if(size == capacity) return;
    size++;
    array[size-1]=value;

    for(int i=size-1; i!=0 && array[parent(i)] > array[i]; i= parent(i))
    {
        swap(array[parent(i)],array[i]);
    }
}

void decreaseKey(int * array , int value ,int index,  int size)
{
    array[index] = value;
    while(index!=0 && array[parent(index)] > array[index])
    {
        swap(array[i],array[parent(i)]);
        index = parent(index);
    }
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

int extractMin(int * harr,int heap_size) 
{ 
    if (heap_size <= 0) 
        return INT_MAX; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 
  
    int root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    MinHeapify(0); 
  
    return root; 
} 

void deleteOp(int  * array , int size , int index)
{
    decreaseKey(array,INT_MIN,index,size);
    extractMin(array,size);
}

void buildHeap(int * array , int size)
{
    for(int i = (size-1)-1/2;i>=0;i--)
    {
        minHeapify(array,i,size);
    }
}


int main() 
{   
    int size=10;

    int heapArray[20]={40,20,30,35,25,80,32,100,70,60};

    display(heapArray,size);
    minHeapify(heapArray,0,size);
    display(heapArray,size);



}
   






