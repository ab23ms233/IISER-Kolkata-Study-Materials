// QUESTION
// Part a
// Write a C function to find the postorder traversal of a given binary tree
// Part b
// Using the follow function, find the postorder traversal of the following tree
    //        10
    //    /       \
    //   20       30
    //  /  \     /  \
    // 40   50  60  70


#include <stdio.h>
#include <stdlib.h>
// Creating node structure
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

// Function to create a new node
node *createNode(int data)
{
    node *n = (node *) malloc(sizeof(node));
    n->data = data;
    n->right = n->left = NULL;
    return n;
}
// Function to perform postorder traversal
void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void main() 
{
    // Creating the tree as shown in the question
    // 1st level
    node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    // 2nd level
    root->left->right = createNode(50);
    root->left->left = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(70);
    // Postorder traversal
    postorder(root);
    printf("\n");
}
