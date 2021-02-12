#include<iostream>
#include<queue>
#include <bits/stdc++.h>
using namespace std; 

struct node{
int data;
node * left;
node * right;
};

//--------------- Intiliazing a New Node.------------------
struct node* newNode(int data) 
{ 
     struct node* node = (struct node*) 
                                  malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 

// -------------------------TRAVERSALS--------------------------

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

// recursive approach for searching and returning address of the node

node * searchAnElement(node * root , int item)
{
  
    if(root == NULL)
        return NULL;
    if(root->data == item)
    {
        return root;
    }
    node * temp= NULL;
    temp = searchAnElement(root->left,item);
    if(temp == NULL)
    {
        return searchAnElement(root->right,item);
    }
    return temp;

}

// iterative approach for searching and returning address of the node

node * searchAnElement2(node * root , int item){
    if(root == NULL)
        return NULL;
    queue <node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        node * temp = Q.front();
        Q.pop();
        if(temp->data == item)
            return temp;
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
    return NULL;
}

// IFEXISTS() : Checks if element exists in a tree or not. (Recursive Approach)

bool ifExists(node * root , int item){
      
    if(root == NULL)
        return 0;
    if(root->data == item)
    {
        return 1;
    }
    return (ifExists(root->right,item) || ifExists(root->left,item));

}

// insertion of a new node ( Recursive Approach)

void insertion(struct node *root, int item){
  static bool flag = false;
  if (root->left==NULL || root->right==NULL)
  {
    struct node* node = (struct node*)malloc(sizeof(struct node));  
    node->data = item; 
    node->left = NULL; 
    node->right = NULL; 
    if(root->left==NULL){
      root->left= node;
      flag=true;
    }
    else{
      root->right=node;
      flag=true;
    }
    return;
  }
  insertion(root->left, item);
  if(flag==false)
    insertion(root->right, item);
}

// Updating a node

void update(struct node *root,int target, int item){
    node * found = searchAnElement(root,target);
    found->data = item;
}

// Size of a binary tree ( recursive) -- No of nodes in the tree.

int sizeOfTree(node * root)
{
    if(root == NULL)
        return 0;
    return ( sizeOfTree(root->left) + 1 + sizeOfTree(root->right) ); 
}


// ----------------- DISPLAY -----------------
void display(struct node * root)
{
    cout<<"LEVEL ORDER : ";levelOrder(root);cout<<endl;
    cout<<"PRE ORDER : ";preOrder(root);cout<<endl;
    cout<<"POST ORDER : ";postOrder(root);cout<<endl;
    cout<<"IN ORDER : ";inOrder(root);cout<<endl;
}

// Deepest Node in the tree. ( iterative)
node * deepestNode2(node * root)
{
    if(root == NULL)
        return NULL;
    queue <node*> Q;
    node * temp=NULL;
    Q.push(root);
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
    return temp;

}

// Deepest Node (recursive)
void findDeep(node * root , int level , int &maxlevel , int &value)
{
    if(root!=NULL)
    {
        findDeep(root->left,++level,maxlevel,value);
        if(level > maxlevel)
        {
            maxlevel = level;
            value = root->data;
        }
        findDeep(root->right,level,maxlevel,value);
    }
}
int deepestNode(node * root)
{
    int value = -1;
    int maxlevel=-1;
    int level =0;
    findDeep(root,level,maxlevel,value);
    return value;
}


// (TODO : deep = NULL) Deleting an Element ( without maintaing any order in the tree)
void deleteAnElement(node * root,int item)
{
    node * target = searchAnElement(root,item);
    node * deep = deepestNode2(root);
    target->data = deep->data;
    deep= NULL;

}


// leave nodes in a binary tree ( recursion)
int leaveNodes(node * root)
{
    if(root==NULL)
        return 0;
    if(!root->left && !root->right)
    {
        return 1;
    }
    return (leaveNodes(root->left) + leaveNodes(root->right));
}

// leave nodes in a binary tree (iterative)
int leaveNodes2(node * root)
{   int count=0;
    if(root==NULL)
        return 0;
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        node * temp = Q.front();
        Q.pop();
        if(!temp->left && !temp->right)
        {
            count++;
        }
        else
        {
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }

    }
    return count;
}

// full nodes and half nodes of a binary tree -- same way 

// structurally identical

bool isIdentical(node * root1 , node * root2)
{
    if(!root1 && !root2) return true;
    if(!root1 || !root2 ) return false;
    return (root1->data == root2->data && 
            isIdentical(root1->left,root2->left) && 
            isIdentical(root1->right,root2->right) );
}

// height of a tree (recursive)
int height(node * root)
{
    if(root == NULL)
        return 0;
    return (1 + max( height(root->left),height(root->right) ) );
}

// diameter of a tree. ( recursive)

int diameter(node * root)
{
    if(root == NULL)
        return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    int d1 = diameter(root->left);
    int d2 = diameter(root->right);

    return max( h1+1+h2 , max(d1,d2) ); 
}

// max level sum (iterative)

int maxLevelSum(node * root)
{   
    int sum=0;
    int maxSum = -2;

    if(root == NULL )
        return 0;
    
    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty())
    {
        node * temp = Q.front();
        Q.pop();
        if(temp == NULL)
           { 
                if(sum > maxSum)
                    maxSum = sum;
                sum=0;

                if(!Q.empty())
                    Q.push(NULL);
           }   
        else
        {
        sum = sum + temp->data;
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
        }
 
    }

    return maxSum;
}

// Print all paths feom root to leave nodes
printArray(int array[],int len)
{
    for(int i=0;i<len;i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void allPaths(node * root , int array[], int index){
    array[index] = root->data;
    index++;
    if(!root->left && !root->right){
        printArray(array,index);
    }
    else
    {
        if(root->left)
            allPaths(root->left,array,index);
        if(root->right)
            allPaths(root->right,array,index);
    }

}

// existenec of a path for given sum

bool hasPathSum(node * root, int sum)
{
    if(root == NULL )
        return (sum==0);
    else{
        
        int remainingSum = sum - root->data;
        if((root->left && root->right) || (!root->left && !root->right))
            return (hasPathSum(root->left,remainingSum) || hasPathSum(root->right,remainingSum));
        else if(root->left)
            return  hasPathSum(root->left,remainingSum);
        else
            return hasPathSum(root->right,remainingSum);
    }
    
}

// mirror a tree 

node * mirror(node * root)
{
    node * temp;
    if(root)
    {
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

// Least Common Ancestor

node * lca(node * root,int a , int b)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == a || root->data == b)
    {
        return root;
    }
    node * left = lca(root->left,a,b);
    node * right = lca(root->right,a,b);
    if(left && right)
        return root;
    else if(left)
        return left;
    else 
        return right;
}

// TODO constructing a tree from given preorder and inorder

// print all ancestor

int printAncestors(node * root, int a)
{
    if(root==NULL)
        return 0; 
    if( root->left->data == a || root->right->data == a 
                || printAncestors(root->left,a) || printAncestors(root->right,a))
        {
            cout<<root->data<<" ";
            return 1;
        }
    return 0;
    
}


// MAIN 
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

    display(root1);

    // node * found = searchAnElement(root1,80);
    // if(found!=NULL)
    //     cout<<found->data;
    // else
    //     cout<<"NULL!"<<endl;

    // node * found2 = searchAnElement2(root1,80);
    // if(found2!=NULL)
    //     cout<<found2->data;
    // else
    //     cout<<"NULL!"<<endl;
    

    // cout<<"if node exists or not :"<<ifExists(root1,80)<<endl;
    // cout<<"Size of Tree : "<<sizeOfTree(root1)<<endl;

    // insertion(root1,80);

    // cout<<"if node exists or not :"<<ifExists(root1,80)<<endl;
    // cout<<"Size of Tree : "<<sizeOfTree(root1)<<endl;

    // display(root1);
    // update(root1,80,100);
    // display(root1);

    // cout<<deepestNode(root1)->data<<endl;
    
    // deleteAnElement(root1,30);
    
    // cout<<deepestNode(root1)->data<<endl;

    // display(root1);

    // cout<<leaveNodes2(root1)<<endl;
    
    // insertion(root1,80);
    // insertion(root1,100);

    // cout<<leaveNodes2(root1)<<endl;
    //cout<<boolalpha;
    // cout<<isIdentical(root1,root2)<<endl;
    // insertion(root1,80);
    // cout<<isIdentical(root1,root2)<<endl;
    // insertion(root2,80);
    // cout<<isIdentical(root1,root2)<<endl;

    //cout<<deepestNode(root1);

    //cout<<diameter(root1)<<endl;
    //cout<<maxLevelSum(root1)<<endl;
    // int array[sizeOfTree(root1)];
    // allPaths(root1,array,0);
    // cout<<hasPathSum(root1,60);

    display(mirror(root1));
    //cout<<lca(root1,40,30)->data;
    //cout<<printAncestors(root1,60);
}