#include <stdio.h>
#include <stdlib.h>
#include "min_heaps.h"

// Structure for a node in the Huffman tree
typedef struct Node
{
    char C;
    int freq;
} node;

// Extracting the node with minimum frequency from the character table
node* extract_min(node **nodes, int *nodeCnt)
{
    node* min = nodes[0];
    int min_index = 0;

    // Finding the node with minimum frequency
    for (int i = 1; i < *nodeCnt; i++)
    {
        if (nodes[i]->freq < min->freq)
        {
            min = nodes[i];
            min_index = i;
        }   
    }

    // printf("Min char: %c; freq: %d\n", min->C, min->freq);
    // Exchanging the minimum node with the last node
    nodes[min_index] = nodes[*nodeCnt-1];
    // nodes[min_index]->freq = nodes[*nodeCnt-1]->freq;

    // printf("After exchange: %c %d\n", nodes[min_index]->C, nodes[min_index]->freq);
    // free(nodes[*nodeCnt-1]);
    (*nodeCnt)--;   // Reducing the node count
    return min;
}

// Function to print the nodes in the character table
void print_nodes(node **nodes, int nodeCnt)
{
    for (int i = 0; i < nodeCnt; i++)
        printf("%c %d\n", nodes[i]->C, nodes[i]->freq);
}

// Function to create a character table from a given string
node **char_table(char arr[], int *nodeCnt)
{
    // Ignoring characters that are not alphabets
    char ignore[] = {',', '.', ' '};
    int ignore_size = sizeof(ignore)/sizeof(ignore[0]);

    // Indices for character table and input array
    int arrCnt = 0;
    *nodeCnt = 0;

    // Character table to store unique characters and their frequencies
    node **nodes = (node **)malloc(sizeof(node *) * 26);
    int match = 0, ignored = 0;

    // Traversing the input array
    while (arr[arrCnt] != '\0')
    {
        char c = arr[arrCnt];
        // printf("Current character: %c\n", c);

        // Checking if the character is already present in the character table
        for (int i = 0; i < *nodeCnt; i++)
        {
            // If present, increment the frequency
            if (c == nodes[i]->C)
            {
                nodes[i]->freq += 1;
                match = 1;
                // printf("Present in list: %c\n", c);
                break;
            }
        }
        // If not present
        if (match == 0)
        {
            // Checking if the character is in the ignore list
            for (int j = 0; j < ignore_size; j++)
            {
                if (c == ignore[j])
                {
                    ignored = 1;
                    // printf("Ignored: %c\n", c);
                    break;
                }
            }
            // If not in the ignore list, add it to the character table
            if (ignored == 0)
            {
                node *newNode = (node *)malloc(sizeof(node));
                newNode->C = c;
                newNode->freq = 1;

                nodes[*nodeCnt] = newNode;
                // printf("Not present in list: %c\n", c);
                (*nodeCnt)++;
            }
        }

        // Resetting variables for next iteration
        match = 0;
        ignored = 0;
        arrCnt++;
    }

    return nodes;
}

// Function to increase the value of a key at an index in the min heap
void increaseKey(int arr[], int index, int key)
{
    // If new key is smaller than current key, then error
    if (key<arr[index])
    {
        printf("New key is smaller than current key\n");
        return;
    }
    
    arr[index] = key;
    while (index>0 && arr[parent(index)] < arr[index])
    {
        // Swap arr[index] and arr[parent(index)]
        int temp = arr[index];
        arr[index] = arr[parent(index)];
        arr[parent(index)] = temp;
        // Move index to parent index
        index = parent(index);
    }
}

// Function to insert a new key in the max heap
void insert(int arr[], int *size, int key)
{
    (*size)++;
    arr[*size-1] = -999;
    increaseKey(arr, *size-1, key);
}

void huffman_tree(node **charSet, int size)
{
    node *z;

    for (int i = 0; i < size; i++)
    {
        z = extract_min(charSet, &size);
    }
    
}

void main()
{
    char sentence[] = "one thought arises at one time, one idea at one";

    // Creating the character table from the input string
    int nodeCnt;
    node **nodes = char_table(sentence, &nodeCnt);
    printf("Node count: %d\n", nodeCnt);
    printf("Character table\n");
    print_nodes(nodes, nodeCnt);
    printf("\n");

    // Extracting the node with minimum frequency from the character table
    node *min = extract_min(nodes, &nodeCnt);
    printf("Min character: %c with frequency: %d\n", min->C, min->freq);
    printf("Character table after extraction\n");
    print_nodes(nodes, nodeCnt);
}