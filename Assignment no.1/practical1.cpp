#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* createnode(int value){
    node* newnode = new node();
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insert(node* root, int value){
    if(root == NULL){     
        return createnode(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    return root;             
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){
    node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the given tree: ";
    inorder(root);

    return 0;
}
