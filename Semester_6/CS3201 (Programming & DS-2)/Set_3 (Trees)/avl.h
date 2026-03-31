#include <stdio.h>
#include <stdlib.h>

// Creating a structure for a node in the AVL tree
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} node;

// Function to create a new node with the given key
node *createNode(int key)
{
    node *k = (node *) malloc(sizeof(node));
    k->key = key;
    k->height = 1;
    k->right = k->left = NULL;
    return k;
}

// Function to get the height of the tree
int getBalanceFactor(node *curr)
{
    if (curr == NULL)
        return 0;
    
    return curr->left->height - curr->right->height;
}

// Function to find the maximum of two integers
int max(int n1, int n2)
{
    if (n1 >= n2)
        return n1;
    else
        return n2;
}

// Function to perform right rotation on the subtree rooted with y
// Tree looks like this before rotation:
//         y
//        / \
//       x   T3
//      / \
//     T1  T2
// After rotation:
//         x
//        / \
//       T1  y
//          / \
//         T2  T3
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(y->right->height, y->left->height) + 1;
    x->height = max(x->right->height, x->left->height) + 1;
    return x;
}

// Function to perform left rotation on the subtree rooted with x
// Tree looks like this before rotation:
//         x
//        / \
//       T1  y
//          / \
//         T2  T3
//         y
//        / \
//       x   T3
//      / \
//     T1  T2
node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(y->right->height, y->left->height) + 1;
    x->height = max(x->right->height, x->left->height) + 1;
    return y;
}

// Function to insert a new node with the given key
node *insertNode(node *root, int key)
{
    // Code for node insertion in BST
    if (root == NULL)
        return createNode(key);
    
    if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        root->left = insertNode(root->left, key);
    
    // Start updating the height of the all nodes from the current one to the root
    root->height = 1 + max(root->left->height, root->right->height);
}