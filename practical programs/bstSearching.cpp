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

void search(Node *root,int key){
    if(root==NULL){
        cout<<"Element not found";
        return;
    }
    if(root->data==key){
        cout<<"Element fount:"<<key;
        return;
    }
    if(key<root->data){
        search(root->left,key);
    }
    else{
        search(root->right,key);
    }

}
int main(){
    Node* root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);
    int key;
    cout<<"Enter element to search:";
    cin>>key;
    search(root,key);
}