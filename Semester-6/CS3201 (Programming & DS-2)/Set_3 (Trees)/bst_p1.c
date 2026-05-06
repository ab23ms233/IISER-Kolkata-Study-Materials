// QUESTION
// Task 1.
// Write a BST insert operation in C and insert the following numbers in the 
// given order into a BST: 8, 18, 1, 13, 24, 7, 0, 5, 9.
// Task 2.
// Write a BST search operation in C and search for 0.
// Task 3.
// Write a BST delete operation in C and delete 18

#include <stdio.h>
#include "bst.h"

void main()
{
    // TASK 1 - Inserting keys
    // Creating array for inserting keys into BST
    node *root = NULL;
    int arr[] = {8, 18, 1, 13, 24, 7, 0, 5, 9};
    int count = sizeof(arr)/sizeof(arr[0]);

    // Inserting keys into the BST
    for (int i = 0; i < count; i++)
        root = insertNode(root, arr[i]);
    // Performing inorder traversal of the BST
    inorder(root);
    printf("\n");

    // TASK 2 - Searching for 0 
    node *result = searchNode(root, 0);
    inorder(result);
    printf("\n");

    // TASK 3 - Deleting 18
    root = deleteNode(root, 18);
    inorder(root);
}