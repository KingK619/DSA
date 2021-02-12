#include<iostream>
#include<queue>
#include <bits/stdc++.h>
using namespace std; 

struct node{
int data;
node * left;
node * right;
node * nextSibling;
};

struct node* newNode(int data) 
{ 
     struct node* node = (struct node*) 
                                  malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
     node->nextSibling = NULL;
  
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

void nextSibling(node* root)
{
  

    if(root == NULL )
        return ;
    
    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);

    while(Q.size() > 1)
    {
        node * temp = Q.front();
        Q.pop();
        if(temp == NULL) 
             Q.push(NULL);           
        else
        {   
            if(Q.front()!=NULL)
                {
                    cout<<temp->data<<" : "<<Q.front()->data<<endl;

                }
            if(temp->left)
            {
                Q.push(temp->left);

            }
            if(temp->right)
            {
                Q.push(temp->right);
    
            }
        }
 
    }

}

void nextSibling2(node * root)
{
    if(!root)
        return;

    if(root->left)
        root->left->nextSibling = root->right;
    if(root->right)
    {
        if(root->nextSibling)
        {
            root->right->nextSibling = root->nextSibling->left : root->nextSibling->left ? root->nextSibling->right
        }
        else
            root->right->nextSibling = NULL;

        // if parent has a sibling then its left child or right will be theright one's sibling.
    
    }  

    nextSibling2(root->left);
    nextSibling2(root->right);

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

    nextSibling(root1);
    nextSibling2(root1);
    node * temp = root1;
    while(temp)
    {
        cout<<temp->data<<": "<<temp->nextSibling->data<<endl;
    }
;
}