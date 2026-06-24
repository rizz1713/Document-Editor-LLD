#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root,int data){
    if(root==NULL){
        return createNode(data);
    }
    else if(data < root->data){
        root->left = insert(root->left,data);
    }
    else if(data > root->data){
        root->right = insert(root->right,data);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int depth(Node* root){
    if(root==NULL){
        return 0;
    }
    int ld = depth(root->left);
    int rd = depth(root->right);
    return max(ld,rd)+1;
}

void leafNode(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    leafNode(root->left);
    leafNode(root->right);
}

Node* copyofTree(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* newNode = createNode(root->data);
    newNode->left = copyofTree(root->left);
    newNode->right = copyofTree(root->right);
    return newNode;
}

int main(){
    Node* root = NULL;
    Node* copiedTree = NULL;
    int choice, value;

    do{
        cout<<"\n===== Binary Search Tree Menu =====";
        cout<<"\n1. Insert Element";
        cout<<"\n2. Inorder Traversal";
        cout<<"\n3. Find Depth";
        cout<<"\n4. Print Leaf Nodes";
        cout<<"\n5. Copy Tree";
        cout<<"\n6. Inorder of Copied Tree";
        cout<<"\n7. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                cout<<"Enter value to insert: ";
                cin>>value;
                root = insert(root,value);
                cout<<"Element Inserted Successfully!\n";
                break;

            case 2:
                cout<<"Inorder Traversal: ";
                inorder(root);
                cout<<endl;
                break;

            case 3:
                cout<<"Depth of Tree: "<<depth(root)<<endl;
                break;

            case 4:
                cout<<"Leaf Nodes: ";
                leafNode(root);
                cout<<endl;
                break;

            case 5:
                copiedTree = copyofTree(root);
                cout<<"Tree Copied Successfully!\n";
                break;

            case 6:
                cout<<"Inorder Traversal of Copied Tree: ";
                inorder(copiedTree);
                cout<<endl;
                break;

            case 7:
                cout<<"Exiting Program...\n";
                break;

            default:
                cout<<"Invalid Choice! Try Again.\n";
        }

    }while(choice != 7);

    return 0;
}