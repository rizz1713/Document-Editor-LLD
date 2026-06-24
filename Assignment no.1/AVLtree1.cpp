#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(Node* n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + getMax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + getMax(getHeight(x->left), getHeight(x->right));

    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + getMax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + getMax(getHeight(y->left), getHeight(y->right));

    return y;
}


Node* insert(Node* root, int key) {

    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->data) {
        cout << "LL Rotation performed\n";
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->data) {
        cout << "RR Rotation performed\n";
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->data) {
        cout << "LR Rotation performed\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->data) {
        cout << "RL Rotation performed\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        if ((root->left == NULL) || (root->right == NULL)) {

            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            delete temp;
        }
        else {

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        cout << "LL Rotation performed\n";
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        cout << "LR Rotation performed\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        cout << "RR Rotation performed\n";
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        cout << "RL Rotation performed\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {

    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "\n--- AVL Tree Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display (Preorder)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;

        case 3:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}