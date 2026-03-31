#include <stdio.h>
#include <stdlib.h>

// Creating a structure for a node in the binary tree
typedef struct NODE
{
    struct NODE *left;
    int data;
    struct NODE *right;
} node;

// Function to create a new node with the given data
node *createNode(int data)
{
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to perform preorder traversal of the binary tree (root -> left -> right)
void preorder(node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);  // Visit the root node first
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
    printf("%d ", root->data);  // Finally, visit the root node
}

// Function to perform inorder traversal of the binary tree (left -> root -> right)
void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);    // Traverse the left subtree first
    printf("%d ", root->data);      // Then visit the root node
    inorder(root->right);    // Finally, traverse the right subtree
}