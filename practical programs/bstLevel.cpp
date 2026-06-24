#include<iostream>
#include<queue>
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

void levelOrder(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}

int main(){
    Node *root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);

    cout<<"Level order traversal: ";
    levelOrder(root);
    
}