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

int height(node* root)  
{  
    if (root == NULL)  
        return 0;  
    else
    {  
       
        int lDepth = maxDepth(root->left);  
        int rDepth = maxDepth(root->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  


node * toBST(node * head,int size)
{

  if(size<=0)
    return NULL;

  node * left = toBST(head,size/2);
  node * root=head;
  root->left = left;
  head = head->right;
  root->right = toBST(head,size - (size/2) -1);
  return root;

}


int main() 
{  

  node * head = newNode(10);
  node * temp = head;
  node * prev = NULL;
  for(int i=20; i < 80 ; i+=10)
  {
    node * curr = newNode(i);
    temp->right = curr;
    temp->left = prev;
    prev = temp;
    temp = temp->right;
  }
    
  // pass more than one node 
     while(head)
    {
      cout<<head->data<<" ";
      head=head->right;
    }
    inOrder(toBST(head,7));

   

}