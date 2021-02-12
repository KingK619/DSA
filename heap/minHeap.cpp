
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

int main() 
{  int capacity,size=0;
    cout<<"Enter capacity of heap :";  cin>>capacity;
   int heapArray[capacity];
   while(capacity!=0)
   {
    
    cout<<"1. insert"<<endl<<"2. Display"<<endl<<"0. Quit"<<endl;
    cout<<"Enter Choice : ";
    int choice;
    cin>>choice;
    switch(choice){
        case 1 : 
                int value;
                cout<<"Enter Value : "; cin >> value;
                insert(value,heapArray,size,capacity);  
                break;

        case 2: display(heapArray,size); break;
        case 0 : capacity = 0; break;
        default : cout<<"Wrong Input!";
    }
   }


}



