// QUESTION
// Please write a C program to create a tree whose inorder sequence is 
// 40 20 10 30 and the root key is 10.

// Structure of tree is like
    //     10
    //    /  \
    //   20  30
    //  /
    // 40  

#include <stdio.h>
#include "trees.h"

void main()
{
    // Root node
    node *root = createNode(10);
    // 1st level
    root->left = createNode(20);
    root->right = createNode(30);
    // 2nd level
    root->left->left = createNode(40);

    // Printing inorder traversal
    inorder(root);
}