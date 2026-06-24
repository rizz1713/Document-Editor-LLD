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
int main(){

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    cout<<"Root Node:"<<root->data<<endl;
    cout<<"Left child:"<<root->left->data<<endl;
    cout<<"Right child:"<<root->right->data<<endl;
    return 0;
}