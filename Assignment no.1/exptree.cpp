#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


Node* constructTree(string postfix) {
    stack<Node*> st;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (!isOperator(ch)) {
            st.push(new Node(ch));
        } else {
            Node* node = new Node(ch);
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();

            node->left = left;
            node->right = right;

            st.push(node);
        }
    }
    return st.top();
}



void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

void inorderNonRec(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data;
        curr = curr->right;
    }
}


void preorderNonRec(Node* root) {
    if (!root) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        cout << curr->data;

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}

void postorderNonRec(Node* root) {
    if (!root) return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data;
        st2.pop();
    }
}


int main() {
    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    Node* root = constructTree(postfix);

    cout << "\n\n--- Recursive Traversals ---\n";
    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n\n--- Non-Recursive Traversals ---\n";
    cout << "Inorder: ";
    inorderNonRec(root);

    cout << "\nPreorder: ";
    preorderNonRec(root);

    cout << "\nPostorder: ";
    postorderNonRec(root);

    return 0;
}