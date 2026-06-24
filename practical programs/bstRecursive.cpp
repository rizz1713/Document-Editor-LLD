#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

Node *insert(Node *root,int value){
    if(root==NULL){
        return new Node(value);
    }
    if(value<root->data){
        root->left = insert(root->left,value);
    }
    else if(value>root->data){
        root->right = insert(root->right,value);
    }
    return root;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    Node *root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,30);
    insert(root,20);
    insert(root,40);

    cout<<"Inorder Traversal:";
    inorder(root);
    cout<<"\nPreorder Traversal:";
    preorder(root);
    cout<<"\nPostorder Traversal:";
    postorder(root);
    return 0;
}