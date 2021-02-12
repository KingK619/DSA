#include<iostream>
#include<queue>
#include <bits/stdc++.h>
#include <unordered_map> 
#include<vector>
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

void preOrder(struct node * root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void levelOrder(node * root){
    if(root==NULL) return;
    queue <node *> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        node * temp = Queue.front();
        Queue.pop();
        std::cout<<temp->data<<" ";
        if(temp->left)
            Queue.push(temp->left);
        if(temp->right)
            Queue.push(temp->right);
    }
  }


void inOrder(struct node * root ){
    if(root==NULL)
        return;
    preOrder(root->left);
    std::cout<<root->data<<" ";
    preOrder(root->right);
   
}

bool ifExists(node * root , int item){
      
    if(!root)
      return 0;
    if(root->data == item)
      return 1;

  return  ( ifExists(root->left,item) || ifExists(root->right,item) ); 


}

int sizeOfTree(node * root)
{
    if(root == NULL)
        return 0;
    return ( sizeOfTree(root->left) + 1 + sizeOfTree(root->right) ); 
}

int height(node * root)
{
  if(!root)
    return 0;
  return height(root->left) + height(root->right) + 1;
}

void printRange(node * root , int k1, int k2)
{
  if(!root)
    return;
   if(root->data >= k1)
    printRange(root->left,k1,k2);

  if(root->data <= k2 && root->data >= k1)
    cout<<root->data<<endl;

   if(root->data <= k2)
    printRange(root->right,k1,k2);

}

int main() 
{  
    struct node * root1 = newNode(120);
    root1->left=newNode(80);
    root1->right =newNode(150);
    root1->left->left = newNode(50);
    root1->left->right = newNode(90);
    root1->right->left = newNode(140);
    root1->right->right = newNode(160);
    root1->left->left->left = newNode(20);

    struct node * root2 = newNode(3); 
    root2->left=newNode(2);
    root2->right =newNode(5);
    root2->left->left = newNode(1);
    root2->left->right = newNode(4);
 
    printRange(root1 ,30 , 120 );
    
}