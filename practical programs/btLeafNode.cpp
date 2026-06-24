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

void displayLeafNodes(Node *root){
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            cout<<root->data<<" ";
        
        }
        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Leaf nodes are:";
    displayLeafNodes(root);
}