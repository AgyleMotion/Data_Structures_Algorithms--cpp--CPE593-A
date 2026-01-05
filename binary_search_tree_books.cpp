#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int bookId;
    string title;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* newNode(int id, string title) {
    Node* temp = new Node;
    temp->bookId = id;
    temp->title = title;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node
Node* insert(Node* node, int bookId, string title) {
    if (node == NULL){
        node = newNode(bookId, title);
    }
    else if (bookId <= node->bookId){
        node->left = insert(node->left, bookId, title);
    } else {
        node->right = insert(node->right, bookId, title);
    }
    return node;
}

// Function for pre-order traversal
void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->bookId << " " << root->title << "\n";
    preOrder(root->left);
    preOrder(root->right);
}

// Function for in-order traversal
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->bookId << " " << root->title << "\n";
    inOrder(root->right);
}

// Function for post-order traversal
void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->bookId << " " << root->title << "\n";
}

// Function for level order traversal
void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->bookId << " " << current->title << "\n";
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

// Function to calculate the height of the tree
int height(Node* node) {
    if (node == nullptr) {
        return -1;  // return -1 for empty tree
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum value (book ID) in the tree
int findMin(Node* node) {
    if (node == nullptr) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->bookId;
}

// Function to find the maximum value (book ID) in the tree
int findMax(Node* node) {
    if (node == NULL) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    while (node->right != NULL) {
        node = node->right;
    }
    return node->bookId;
}

// Main function
int main() {
    Node *root = NULL;
    root = insert(root, 4, "The Great Gatsby");
    root = insert(root, 2, "1984");
    root = insert(root, 1, "To Kill a Mockingbird");
    root = insert(root, 3, "The Catcher in the Rye");
    root = insert(root, 6, "Brave New World");
    root = insert(root, 5, "The Hobbit");
    root = insert(root, 7, "Green Mile");

    cout << "Pre-Order Traversal:\n";
    preOrder(root);
    cout << "\nIn-Order Traversal:\n";
    inOrder(root);
    cout << "\nPost-Order Traversal:\n";
    postOrder(root);
    cout << "\nLevel Order Traversal:\n";
    levelOrder(root);
    cout << "\nHeight of the tree: " << height(root) << endl;
    cout << "Minimum book ID: " << findMin(root) << endl;
    cout << "Maximum book ID: " << findMax(root) << endl;

    return 0
};