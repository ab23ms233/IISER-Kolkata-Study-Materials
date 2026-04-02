// QUESTION
// Create a C program to check whether a given AVL tree is valid or not. If valid, print "The AVL tree is valid", else print "The AVL tree needs rebalancing".

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

// Function to fund the maximum of 2 integers
int max(int n1, int n2)
{
    return n1>n2?n1:n2;
}

// Function to update the height of all nodes of the tree
void updateHeight(node *root)
{
    if (root == NULL)
        return;
    
    updateHeight(root->left);
    updateHeight(root->right);
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

// Function to perform postorder traversal
void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d %d  ", root->key, root->height);
}

// Function to check whether the AVL tree is valid or not
int isAVL(node *root)
{
    // If we reach a leaf node or root is NULL
    if (root == NULL)
        return 1;
    
    // Check whether the left and right subtrees are valid AVL trees or not
    if (!isAVL(root->left) || !isAVL(root->right))
        return 0;

    // Check the balance factor of the current node
    int bf =  getBalanceFactor(root);
    // If the balance factor is less than -1 or greater than 1, then the AVL tree is not valid
    if (bf<-1 || bf>1)      
        return 0;

    return 1;
}

void main()
{
    // Creating the AVL tree
    node *root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(24);

    root->left->left = createNode(8);
    root->left->right = createNode(18);
    // root->right->left = createNode(21);
    root->left->right->left = createNode(14);

    // Update the height of all nodes of the tree 
    updateHeight(root);
    postorder(root);
    printf("\n");

    // Checking validity
    int result = isAVL(root);
    if (result == 0)
        printf("The AVL tree needs rebalancing\n");
    else
        printf("The AVL tree is valid\n");
}