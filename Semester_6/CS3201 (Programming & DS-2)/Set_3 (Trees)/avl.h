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

// Function to get the height of the node
int getHeight(node *curr)
{
    if (curr == NULL)
        return 0;
    
    return curr->height;
}

// Function to get the balance factor of the tree
int getBalanceFactor(node *curr)
{
    if (curr == NULL)
        return 0;
    
    return getHeight(curr->left) - getHeight(curr->right);
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

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
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

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
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
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    int bf = getBalanceFactor(root);

    // Left left case
    if (bf>1 && key<root->left->key)
        return rightRotate(root);
    // Right right case
    else if (bf<-1 && key>root->right->key)
        return leftRotate(root);
    // Left right case
    else if (bf>1 && key>root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right left case
    else if (bf<-1 && key<root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform preorder traversal of the binary tree (root -> left -> right)
void preorder(node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->key);  // Visit the root node first
    preorder(root->left);   // Then traverse the left subtree
    preorder(root->right);  // Finally, traverse the right subtree
}

// Function to perform postorder traversal of the binary tree (left -> right -> root)
void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);  // Traverse the left subtree first
    postorder(root->right); // Then traverse the right subtree
    printf("%d ", root->key);  // Finally, visit the root node
}

// Function to perform inorder traversal of the binary tree (left -> root -> right)
void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);    // Traverse the left subtree first
    printf("%d ", root->key);      // Then visit the root node
    inorder(root->right);    // Finally, traverse the right subtree
}