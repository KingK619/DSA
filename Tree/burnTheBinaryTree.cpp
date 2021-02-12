#include<iostream>
#include<queue>
#include <bits/stdc++.h>
#include <unordered_map> 



struct node{
int data;
node * left;
node * right;
};
unordered_map<node*,node*>hashT;
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
        std::cout<<temp->data<<" ";
        if(temp->left)
            Queue.push(temp->left);
        if(temp->right)
            Queue.push(temp->right);
    }
}

void preOrder(struct node * root){
    if(root==NULL)
        return;
    std::cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(struct node * root ){
    if(root==NULL)
        return;
    preOrder(root->left);
    preOrder(root->right);
    std::cout<<root->data<<" ";
}

void inOrder(struct node * root ){
    if(root==NULL)
        return;
    preOrder(root->left);
    std::cout<<root->data<<" ";
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
    std::cout<<"LEVEL ORDER : ";levelOrder(root);std::cout<<endl;
    std::cout<<"PRE ORDER : ";preOrder(root);std::cout<<endl;
    std::cout<<"POST ORDER : ";postOrder(root);std::cout<<endl;
    std::cout<<"IN ORDER : ";inOrder(root);std::cout<<endl;
}

void  pcTable(node * root)
{
    if(root)
    {
        if(root->left)
            hashT[root->left]=root; 
        if(root->right)
            hashT[root->right]=root; 

    
    pcTable(root->left);
    pcTable(root->right);
    }  

}

node * kNode(node * root,unordered_map<node*,node*>hash)
{
    
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
    root1->left->left->left = newNode(80);
    root1->left->right->left = newNode(90);

   
   pcTable(root1);
   for (auto itr = hashT.begin(); itr != hashT.end(); itr++) 
    { 
        std::cout << itr->first << "  " << itr->second << endl; 
    } 

   node* knode = kNode(root,hash);


}