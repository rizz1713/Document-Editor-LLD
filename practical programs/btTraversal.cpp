#include<iostream>
using namespace std;
class Node{
    public:
    Node *left,*right;
    int data;

    Node(int value){
        data = value;
        left = right = NULL;
    }

};

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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout<<"Inorder Traversal:";
    inorder(root);
    cout<<"\nPreorder Traversal:";
    preorder(root);
    cout<<"\nPostorder Traversal:";
    postorder(root);
    return 0;
    
}