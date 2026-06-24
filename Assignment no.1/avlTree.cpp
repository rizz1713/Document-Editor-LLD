#include<iostream>
using namespace std;
struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};
int max(int a,int b){
    return (a>b)?a:b;
}

int getHeight(Node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

struct Node *createNode(int key)
{
    struct Node* node = new  Node;
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
};

int getBalancefactor(Node* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* t2 = x->right;
    x->right=y;
    y->left=t2;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    return x;
}

struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* t2 = y->left;
    y->left=x;
    x->right=t2;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    return y;
}

struct Node* insert(struct  Node* node,int key)
{
   if(node==NULL){
    return createNode(key);
   }
   if(key<node->key){
    node->left = insert(node->left,key);
   }
   else if(key>node->key){
    node->right = insert(node->right,key);
   }
   
   node->height = 1 + max(getHeight(node->left),getHeight(node->right));
   int bf = getBalancefactor(node);

   if(bf>1 && key<node->left->key){
    return rightRotate(node);
   }

   if(bf<-1 && key>node->right->key){
    return leftRotate(node);
   }

   if(bf>1 && key>node->left->key){
    node->left = leftRotate(node->left);
    return rightRotate(node);
   }

   if(bf<-1 && key<node->right->key){
    node->right = rightRotate(node->right);
    return leftRotate(node);
   }

   return node;

};

void preOrder(struct  Node* root)
{
    
    if(root!=NULL){
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
};


int main(){
    struct Node* n = NULL;
    n = insert(n,1);
    n = insert(n,2);
    n = insert(n,4);
    n = insert(n,5);
    n = insert(n,4);
    n = insert(n,6);
    n = insert(n,3);
    preOrder(n);
    
    
    return 0;
}
