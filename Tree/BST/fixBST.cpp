//cd P-STUDY/DSA/Tree/BST

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
    inOrder(root->left);
    std::cout<<root->data<<endl;
    inOrder(root->right);
   
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


node * prevN = NULL;
node * first = NULL;
node * second = NULL;


void fixNode(node * root)
{
    if(!root)
      return;

  fixNode(root->left);

    if(prevN  && (root->data < prevN->data) )
    {
      if(!first)
      {
        first = prevN;
      }
      second = root;
    }
    prevN = root;

  fixNode(root->right);

}


int main() 
{  

  struct node *root = newNode(14);  
    root->left  = newNode(16); 
    root->right = newNode(56); 
    root->left->left = newNode(24); 
    root->left->right = newNode(20);
    root->right->left = newNode(30);
    root->right->right = newNode(70);
    root->right->left->left = newNode(28);

    fixNode(root);
    cout<<first->data<<endl<<second->data;


   

}