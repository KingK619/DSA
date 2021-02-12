
#include<iostream>
#include<queue>
#include <bits/stdc++.h>
using namespace std; 

struct node{
int data;
node * left;
node * right;
};

struct node* newNode(int data) 
{ 
     struct node* node = (struct node*) 
                                  malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 

void levelOrder(node * root){
    if(root==NULL) return;
    queue <node *> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        node * temp = Queue.front();
        Queue.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            Queue.push(temp->left);
        if(temp->right)
            Queue.push(temp->right);
    }
}

void preOrder(struct node * root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(struct node * root ){
    if(root==NULL)
        return;
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(struct node * root ){
    if(root==NULL)
        return;
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
   
}

bool ifExists(node * root , int item){
      
    if(root == NULL)
        return 0;
    if(root->data == item)
    {
        return 1;
    }
    return (ifExists(root->right,item) || ifExists(root->left,item));

}

int sizeOfTree(node * root)
{
    if(root == NULL)
        return 0;
    return ( sizeOfTree(root->left) + 1 + sizeOfTree(root->right) ); 
}

void display(struct node * root)
{
    cout<<"LEVEL ORDER : ";levelOrder(root);cout<<endl;
    cout<<"PRE ORDER : ";preOrder(root);cout<<endl;
    cout<<"POST ORDER : ";postOrder(root);cout<<endl;
    cout<<"IN ORDER : ";inOrder(root);cout<<endl;
}

int search(int arr[] , int strt , int end , int value)
{
    int i;  
    for (i = strt; i <= end; i++)  
    {  
        if (arr[i] == value)  
            return i;  
    }  

  
}

node * treeConst(int preOrder[],int inOrder[],int beg,int end)
{
    static int index = 0;
    if(beg > end)   
        return NULL;

    node * root = newNode(preOrder[index++]);

    int inIndex=0;
    int i;  
    for (i = beg; i <= end; i++)  
    {  
        if (inOrder[i] == root->data)  
            inIndex = i;
    }  

   root->left = treeConst(preOrder,inOrder,beg,inIndex-1);
   root->right = treeConst(preOrder,inOrder,inIndex+1,end);

   return root;

}
int main() 
{  
    struct node * root1 = newNode(10);
    root1->left=newNode(20);
    root1->right =newNode(30);
    root1->left->left = newNode(40);
    root1->left->right = newNode(50);
    root1->right->left = newNode(60);
    root1->right->right = newNode(70);

    struct node * root2 = newNode(10);
    root2->left=newNode(20);
    root2->right =newNode(30);
    root2->left->left = newNode(40);
    root2->left->right = newNode(50);
    root2->right->left = newNode(60);
    root2->right->right = newNode(70);

    int preOrder[] = {10,20,40,50,30,60,70};
    int inOrder[] = {40,20,50,10,60,30,70};
    int len = sizeof(inOrder) / sizeof(inOrder[0]); 
    node * tree =treeConst(preOrder,inOrder,0,len-1);
    display(tree); 



}