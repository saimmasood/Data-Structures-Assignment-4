#include <iostream>
using namespace std;

// AVL Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Function to get height
int getHeight(Node* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

// Function to get maximum
int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

// Function to get balance factor
int getBalance(Node* node)
{
    if (node == NULL)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

// Right Rotation
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotation
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert Function
Node* insert(Node* node, int value)
{
    // Normal BST insertion
    if (node == NULL)
        return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);

    else if (value > node->data)
        node->right = insert(node->right, value);

    else
        return node;

    // Update height
    node->height = 1 + max(getHeight(node->left),
        getHeight(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;

    // Insert values
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Display inorder traversal
    cout << "Inorder Traversal of AVL Tree: ";
    inorder(root);

    return 0;
}