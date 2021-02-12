
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

int result = INT_MIN;
int PathSum(TreeNode * root)
    {
        if(!root)
              return 0;

            int left = PathSum(root->left);
            int right =PathSum(root->right);
        
            int single = max( max(left,right) + root->val, root->val);
            int sum = max(single,left+right+root->val);
            result = max(result,sum);
            return single;
    }
int maxPathSum(TreeNode* root) {
    PathSum(root);
    return result;
    }

int main() 
{  
    struct node * root2 = newNode(10);
    root2->left=newNode(20);
    root2->right =newNode(30);
    root2->left->left = newNode(40);
    root2->left->right = newNode(50);
    root2->right->left = newNode(60);
    root2->right->right = newNode(70);

    node * root = newNode(-10);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    node * curr = newNode(1);
    curr->left = newNode(2);
    curr->right = newNode(3);

    maxSumPath(curr);
    cout<<sum;
}