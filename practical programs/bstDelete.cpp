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

Node* insert(Node *root,int value){
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
Node *minValueNode(Node *node){
    Node *current = node;
    while(current && current->left!=NULL){
        current = current->left;
    }
    return current;
}
Node* deleteNode(Node *root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right,temp->data);
    }
    
    return root;
}

void inorder(Node *root)
{
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main(){
     Node* root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);

    cout<<"Before deletion:";
    inorder(root);

    deleteNode(root,30);

    cout<<"\nAfter Deletion:";
    inorder(root);
}