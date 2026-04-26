#include <stdio.h>

// Egge structure
typedef struct
{
    int start, end, weight;
} edge;
// Node structure
typedef struct Node
{
    int distance;
    int parent;
} node;

// Bellman-Ford algorithm
int bellman(node nodes[], int nV, edge edges[], int nE, int source)
{
    int u, v, w;
    // Step 1: Initialize graph
    for (int i = 0; i < nV; i++)
    {
        nodes[i].distance = 999;
        nodes[i].parent = -1;
    }
    nodes[source].distance = 0;
    // Step 2: Relax edges repeatedly
    for (int i = 0; i < nV-1; i++)
    {
        for (int j = 0; j < nE; j++)
        {
            u = edges[i].start;
            v = edges[i].end;
            w = edges[i].weight;

            if (nodes[v].distance > nodes[u].distance + w)
            {
                nodes[v].distance = nodes[u].distance + w;
                nodes[v].parent = u;
            }
        }
    }
    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < nE; i++)
    {
        u = edges[i].start;
        v = edges[i].end;
        w = edges[i].weight;

        if (nodes[v].distance > nodes[u].distance + w)
        {
            printf("There exists a negative weight cycle\n");
            return 0;
        }
    return 1;
    } 
}

void main()
{
    // Parameters for the graph
    int nV = 5;
    int nE = 8;
    int source = 0;
    node nodes[nV];
    // Edges of the graph
    edge edges[] = {
        {0,1,6}, {0,2,7}, {1,2,8}, {1,3,5},
        {1,4,-4}, {2,3,-3}, {2,4,9}, {3,1,-2}
    };

    // Implmenting Bellman-Ford algorithm
    int result = bellman(nodes, nV, edges, nE, source);

    if (result)
    {
        printf("Vertex Distance Parent\n");
        for (int i = 0; i < nV; i++)
            printf("%d\t%d\t%d\n", i, nodes[i].distance, nodes[i].parent);
    }
}