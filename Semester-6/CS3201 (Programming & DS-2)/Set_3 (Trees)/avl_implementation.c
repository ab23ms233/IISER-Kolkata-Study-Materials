#include <stdio.h>
#include "avl.h"

void main()
{
    int arr[] = {12, 8, 7, 15, 13};
    int count = sizeof(arr)/sizeof(arr[0]);
    node *root = NULL;

    for (int i = 0; i < count; i++)
    {
        root = insertNode(root, arr[i]);
        inorder(root);
        printf("\n");
    }
}