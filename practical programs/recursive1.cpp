#include<iostream>
using namespace std;
class Node{
    public:
    char data;
    Node *left,*right;
    Node(char value){
        data = value;
        left = right = NULL;
    }
};

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    Node *root = new Node('*');
    root->left = new Node('+');
    root->right = new Node('c');

    root->left->left = new Node('a');
    root->left->right = new Node('b');

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);
}