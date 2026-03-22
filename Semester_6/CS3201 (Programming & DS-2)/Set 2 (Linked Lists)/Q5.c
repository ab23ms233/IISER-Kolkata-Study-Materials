#include <stdio.h>

typedef struct NODE
{
    int coeff;
    int exp;
    node *link;
} node;

// Function for adding element at the end of the list 
node *addatend(node *start, int coeff, int exp)
{
    node *p, *tmp;

    // If list is empty
    if (start == NULL)
    {
        start = (node *) malloc(sizeof(node));
        start->coeff = coeff;
        start->exp = exp;
        start->link = NULL;

        return start;
    }

    // Else, traversing the list 
    p = start;
    while (p->link != NULL)
    {
        p = p->link;
    }
    // Creating a Temporary Node
    tmp = (node *) malloc(sizeof(node));
    tmp->coeff = coeff;
    tmp->exp = exp;
    tmp->link = NULL;

    // Assigning the temporary node as tail
    p->link = tmp;
    return start;
}

// Function for printing elements of linked list. 
void print_list(node *start)
{
    node *p = start;

    while (p != NULL)
    {
        printf("%d %d -> ", p->coeff, p->exp);
    }
    printf("\n");
}

// Function for addition of two polynomials. 
node *addition(node *start1, node *start2)
{
    node *p1 = start1, *p2 = start2;
    node *start = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        start = addatend(start, p1->coeff+p2->coeff, p1->exp+p2->exp);
        p1 = p1->link;
        p2 = p2->link;
    }
}
void main()
{
    node *start[] = {NULL, NULL};

    // 
    int c1[] = {2, 5, 10};
    int e1[] = {3, 2, 0};
    int num1 = sizeof(c1)/sizeof(c1[0]);
    int c2[] = {3, 7, 9};
    int e2[] = {3, 2, 0};
    int num2 = sizeof(c2)/sizeof(c2[0]);

    int *c[] = {c1, c2};
    int *e[] = {e1, e2};
    int nums[] = {num1, num2};

    int coeff, exp, num;
    int *poly;

    for (int i = 0; i < 2; i++)
    {
        num = nums[i];

        for (int j = 0; j < num; j++)
        {
            coeff = c[i][j];
            exp = e[i][j];
            start[i] = addatend(start[i], coeff, exp);
        }

        printf("Polynomial %d: ", i+1);
        print_list(start[i]);
    }
    

}