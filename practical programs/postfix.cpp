#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    char data;
    Node *left,*right;

    Node(char value){
        data = value;
        left = right = NULL;
    }
};

bool isOperator(char c){
    return(c=='+' || c=='-' || c=='*' || c=='/');
}

Node *construcTree(string postfix){
    stack<Node*> st;

    for(char ch:postfix){
        Node *node = new Node(ch);
        if(isOperator(ch)){
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
        }
        st.push(node);
    }
    return st.top();

}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    string postfix = "ab+c*";
    Node *root = construcTree(postfix);
    cout<<"Inorder Expression: ";
    inorder(root);
}