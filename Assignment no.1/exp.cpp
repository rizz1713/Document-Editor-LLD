#include<iostream>
#include<cctype>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

class Stack {
public:
    Node* arr[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(Node* node) {
        arr[++top] = node;
    }

    Node* pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

Node* constructTree(string postfix) {
    Stack st;

    for(int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if(isalnum(ch)) {
            st.push(createNode(ch));
        }
        else {
            Node* right = st.pop();
            Node* left = st.pop();

            Node* node = createNode(ch);
            node->left = left;
            node->right = right;

            st.push(node);
        }
    }
    return st.pop();
}


void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root){
        cout<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data;
    }
}

void inorderNR(Node* root) {
    Stack st;
    Node* curr = root;

    while(curr != NULL || !st.isEmpty()) {
        while(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.pop();
        cout << curr->data;
        curr = curr->right;
    }
}

void preorderNR(Node* root) {
    if(root == NULL) return;

    Stack st;
    st.push(root);

    while(!st.isEmpty()) {
        Node* temp = st.pop();
        cout << temp->data;

        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}


int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    Node* root = constructTree(postfix);

    cout << "\nRecursive Traversals:\n";
    cout << "Inorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n\nNon-Recursive Traversals:\n";
    cout << "Inorder: ";
    inorderNR(root);
    cout << "\nPreorder: ";
    preorderNR(root);

    return 0;
}