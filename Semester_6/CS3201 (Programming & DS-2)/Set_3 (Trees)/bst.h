#include <stdio.h>
#include <stdlib.h>
#include "treetraversal.h"

// Function to search for a node with the given key
node *searchNode(node *root, int key)
{
    node *x = root;

    // Traversing the tree
    while (x != NULL)
    {
        // If the key is found, return the node
        if (x->data == key)
            return x;
        else if (key > x->data)     // If the key > current node's data, go to the right 
            x = x->right;
        else    // Else, go to the left
            x = x->left;
    }

    // If the key is not found 
    printf("Key not found\n");
    return NULL;
}

// Function to insert a new node with the given key
node *insertNode(node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    // If key > node.data, insert in the right subtree
    if (key > root->data)
        root->right = insertNode(root->right, key);
    else    // Else, insert in the left subtree
        root->left = insertNode(root->left, key);
    
    return root;
}

node *successor(node *curr)
{
    curr = curr->right;

    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

// Function to delete a node with the given key
node *deleteNode(node *root, int key)
{
    // printf("%d\n", root->data);
    // If the tree is empty, return NULL
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    // Searching for key to be deleted
    if (key > root->data)
        root->right = deleteNode(root->right, key);
    else if (key < root->data)
        root->left = deleteNode(root->left, key);
    else    // Key is found
    {
        // Node with 0 or 1 child
        if (root->left == NULL)     // If the left child is NULL, replace the node with its right child
        {
            node *tmp = root->right;
            free(root);
            return tmp;     // Returns ne node up the recursive call stack
        }
        if (root->right == NULL)
        {
            node *tmp = root->left;     // If the right child is NULL, replace the node with its left child
            free(root);
            return tmp;
        }

        // Node with 2 children: Get the inorder successor (smallest in the right subtree)
        node *succ = successor(root);
        root->data = succ->data;    // Copy the successor's data to the current node
        root->right = deleteNode(root->right, succ->data);  // Delete the successor node
    }

    return root;
}

// Function to find the minimum value in the tree
int min(node *root)
{
    node *x = root;

    while (x->left != NULL)
        x = x->left;
    return x->data;
}
// Function to find the maximum value in the tree
int max(node *root)
{
    node *x = root;

    while (x->right != NULL)
        x = x->right;
    return x->data;
}