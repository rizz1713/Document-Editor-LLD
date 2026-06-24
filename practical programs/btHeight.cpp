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

int height(Node *root){
    if(root==NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight>rightHeight){
        return leftHeight+1;
    }
    else{
        return rightHeight+1;
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout<<"Height of the tree:"<<height(root)<<endl;
    return 0;
}