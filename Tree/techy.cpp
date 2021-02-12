#include<iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
struct node  
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
struct node* newNode(int data) 
{   
struct node* node = (struct node*)malloc(sizeof(struct node));  
node->data = data; 
node->left = NULL; 
node->right = NULL; 
return(node); 
} 
int preIndex=0;
struct node *treeConstruct(int inarr[], int prearr[], int is, int ie)
{
    if (is>ie)
    return NULL;
    // if(preIndex>6)
    // return NULL;
    struct node *root = newNode(prearr[preIndex++]);
      int inIndex=0;
    for(int i=is;i<=ie;i++){
      if(inarr[i]==root->data)
          inIndex=i;
          // break;
    }
    root->left = treeConstruct(inarr,prearr,is,inIndex-1);
    root->right = treeConstruct(inarr,prearr,inIndex+1,ie);
    return root;
}
void pretra(struct node * root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    pretra(root->left);
    pretra(root->right);
}
int main() 
{ 
    int preOrder[] = {10,20,40,50,30,60,70};
    int inOrder[] = {40,20,50,10,60,30,70};
    node * root = treeConstruct(inOrder,preOrder, 0,6);
    pretra(root);
    return 0; 
}