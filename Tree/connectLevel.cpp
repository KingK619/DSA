
//D:\P-STUDY\DSA\Tree\BST\Balance BSTs

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
node * next;

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


void connect(node * root){
  queue<node *> Q; node * prev = NULL;
  int currNodes = 1;
  int nextNodes = 0;
  if(!root)
    return;
  Q.push(root);
  while(!Q.empty())
  {
    node * temp = Q.front();
    Q.pop();
    if(temp->left){
      Q.push(temp->left);
      nextNodes++;
    }
    if(temp->right){
      Q.push(temp->right);
      nextNodes++;
    }
    if(prev)
    {
      prev->next=temp;
      
    }
    currNodes--; 
    prev = temp;
    if(!currNodes)
    {
      currNodes = nextNodes;
      nextNodes = 0;
      prev = NULL;
    }
  }
}



int main() 
{  

struct node *root = newNode(24);  
    root->left  = newNode(16); 
    root->right = newNode(56); 
    root->left->left = newNode(14); 
    root->left->right = newNode(20);
    root->right->left = newNode(30);
    root->right->right = newNode(70);
    root->right->left->left = newNode(28);
    //root->right->left->left->left = newNode(26);

struct node *root1 = newNode(40);  
    root1->left  = newNode(10); 
    root1->left->left  = newNode(1); 
    root1->right = newNode(60);  
    root1->left->right = newNode(30);
    root1->left->right->left = newNode(20);
    root1->right->left = newNode(50);

connect(root);
levelOrder(root->left);

}