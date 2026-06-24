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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh,rh)+1;
}

bool isBalanced(Node *root){
    if(root==NULL){
        return true;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
        return true;
    }

    return false;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    if(isBalanced(root)){
        cout<<"The tree is balanced";
    }
    else{
        cout<<"The tree is not balanced";
    }

}