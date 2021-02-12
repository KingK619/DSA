#include<iostream>
#include<queue>
#include <bits/stdc++.h>
#include <unordered_map> 
#include<vector>
#include <math.h>
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
// flaw 
bool isBinaryTree(node * root)
{
	bool left=true,right=true;
	if(!root)
		return true;

	if(root->left)
		left = (root->left->data < root->data);
	if(root->right)
		right = (root->right->data > root->data);
	
	if( left && right && isBinaryTree(root->left) && isBinaryTree(root->right)) 
		return true;
	
	return false;
	
	 
}

bool isBinaryTree2(node * root,int min,int max)
{
	if(!root)
		return true;
	return root->data > min && root->data < max && isBinaryTree2(root->left,min,root->data) && isBinaryTree2(root->right,root->data,max);
	
}
int maxNode(node * root)
{
	if(!root)
		return INT_MIN;
  
  int curr = root->data;
  int left = maxNode(root->left);
  int right= maxNode(root->right);
  if(curr < left)
    curr= left;
  if(right > curr)
    curr=right;

  return curr;

}

int minNode(node * root)
{
  if(!root)
    return INT_MAX;
  
  int curr = root->data;
  int left = minNode(root->left);
  int right= minNode(root->right);
  if(curr > left)
    curr= left;
  if(right < curr)
    curr=right;

  return curr;
}

bool isBinaryTree3(node * curr)
{
	if(!curr)
		return true;
	if(curr->left && maxNode(curr->left) > curr->data)
	  return false;
	if(curr->right && minNode(curr->right) < curr->data)
	  return false;   

	return ( isBinaryTree3(curr->left) || isBinaryTree3(curr->right) );
}

bool isBST(node * root, node * prev)
{
	if(!root)
		return true;

	if( !isBST(root->left, prev) )
		return false;

	if(prev!=NULL && prev->data >= root->data)
		return false;
  prev = root;
	return isBST(root->right,prev);
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
    root2->left->left = newNode(123);
    root2->left->right = newNode(4);
 
    struct node *root = newNode(24);  
    root->left  = newNode(16); 
    root->right = newNode(56); 
    root->left->left = newNode(14); 
    root->left->right = newNode(20);
    root->right->left = newNode(30);
    root->right->right = newNode(70);
    root->right->left->left = newNode(28);
    // cout<<minNode(root1)<<endl;
    // cout<<minNode(root2);

    //cout<<isBinaryTree2(root2,INT_MIN,INT_MAX);
    cout<<isBST(root2,NULL);
}