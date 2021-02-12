
//cd P-STUDY/DSA/Tree/BST/Balanced BSTs/

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
node * height;
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
    std::cout<<root->data<<" ";
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
    if(root == NULL)
        return 0;
    return (1 + max( height(root->left),height(root->right) ) );
}

int balanceFactor(node * root)
{
  return (height(root->left) - height(root->right));
}

int rightRotate(node * y)
{
  node * x = y->left;
  node * t = x->right;

  x->right=y;
  y->left = t;

 
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;

}

int leftRotate(node * x)
{
  node * y = x->right;
  node * t = y->left;

  y->left = x;
  x->right = t;

 
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return x;

}

node * insertion(node * root, int item )
{

  // normal insertion 
  if(!root)
    return newNode(item);
  if(item < root->data)
    root->left = insertion(root->left , item);
  if(item > root->data)
    root->right = insertion(root->right , item);
  else
    return root;



}


int main() 
{  

  // struct node * root1 = newNode(120);
  //   root1->left=newNode(80);
  //   root1->right =newNode(150);
  //   root1->left->left = newNode(50);
  //   root1->left->right = newNode(90);
  //   root1->right->left = newNode(140);
  //   root1->right->right = newNode(160);
  //   root1->left->left->left = newNode(20);
	


   

}