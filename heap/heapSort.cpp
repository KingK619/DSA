
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


void maxHeapify(int * array , int i,int size)
{
    int lt = left(i);
    int rt = right(i); 
    int largest = i;
    if(lt < size && array[lt] > array[i])
    {
        largest = lt;
    }

    if(rt < size && array[rt] > array[largest])
    {
        largest = rt;
    }

    if(largest != i)
    {
        swap(array[i],array[largest]);
        maxHeapify(array,largest,size);
    }
}

void buildHeap(int * array , int size)
{
    for(int i = (size-1)-1/2;i>=0;i--)
    {
        maxHeapify(array,i,size);
    }
}

void heapSort(int * array,int size)
{
    buildHeap(array,size);
    for(int i=size-1;i>=1;i--)
    {
        swap(array[0],array[i]);
        maxHeapify(array,0,i);
    }
}

int main() 
{   
    // 1 . build a max Heap from an array
    // 2.  then swap first and last node , and maxHeapify them.
    // 3. in this way , every largrgest node will move to last as we'll pass only the unsorted indices.
    int array[]= {10,15,50,4,20,11,15,12,111,23,45};
    heapSort(array,11);
    display(array,11);


}