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

void  leftmost(node * root , stack<int> &s1)
{
  if(!root)
    return;

  if(!root->left)
    stack.push_back(root->data);

  leftmost(root->left);
}

insertUntill(node * root , stack <int> &s1)
{
  if(!root)
    return;

  s1.push_back(root->data);

  insertUntill(root->left,s1);
}

vector<int> mergeBST(node * root1, node * root2 )
{
  std::vector<int> v;
  stack<int> s1,s2;
  insertUntill(root1,s1);
  insertUntill(root2,s2);

  while(!s1.empty() || !s2.empty())
  {
    if(s1.top() > s2.top())
      v.push_back(s2);
    else
      v.push_back(s1);

    leftmost(root1->right,s1);
    leftmost(root2->right,s2);

    

  }

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
  
    cout<<leftmost(root1)->data;
   
    
}