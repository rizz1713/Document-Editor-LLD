#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}


bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}


Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;

        
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void inorderIter(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}


void bfs(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int height(Node* root) {
    if (root == NULL)
        return -1;

    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node* root) {
    if (root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    return abs(lh - rh) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);
}

int main() {
    Node* root = NULL;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nIterative Inorder: ";
    inorderIter(root);

    cout << "\nBFS (Level wise): ";
    bfs(root);

    cout << "\nHeight: " << height(root) << endl;

    if (isBalanced(root))
        cout << "Tree is height balanced\n";
    else
        cout << "Tree is NOT height balanced\n";

    int s;
    cout << "Enter value to search: ";
    cin >> s;
    cout << (search(root, s) ? "Found\n" : "Not Found\n");

    int d;
    cout << "Enter value to delete: ";
    cin >> d;
    root = deleteNode(root, d);

    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}