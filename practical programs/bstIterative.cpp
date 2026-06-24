#include<iostream>
#include<stack>
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

Node *insert(Node *root,int value){
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

void inorder(Node *root){
    stack<Node*> s;
    Node *curr = root;

    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

void preorder(Node *root){

    if(root==NULL){
        return;
    }
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node *temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }

    stack<Node*> s1,s2;
    s1.push(root);

    while(!s1.empty()){
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }

    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
       
    }
}

int main(){
    Node *root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);

    cout<<"Iterative inorder:";
    inorder(root);
    cout<<"\nIterative preorder:";
    preorder(root);
    cout<<"\nIterative postorder:";
    postorder(root);
    return 0;
}