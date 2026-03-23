#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int coeff;
    int exp;
    struct NODE *link;
} node;

// Function for adding element at the end of the list 
node *insert_s(node *start, int coeff, int exp)
{
    node *p, *tmp;
    // coefficient = 0
    if (coeff == 0)
    {
        return start;
    }

    // Creating a Temporary Node
    tmp = (node *) malloc(sizeof(node));
    tmp->coeff = coeff;
    tmp->exp = exp;

    // If list is empty, or insert node at the beginning
    if (start == NULL || start->exp < exp)
    {
        tmp->link = start;
        start = tmp;
        return start;
    }
    
    // Else, traversing the list until the right exponent is found (less than the current one)
    p = start;
    while (p->link != NULL)
    {
        // Inserting node at the right position
        if (p->link->exp < exp)
        {
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        else if (p->exp == exp)     // Add coefficients if exponents are equal 
        {
            p->coeff += coeff;
            free(tmp);
            return start;
        }
        
        p = p->link;
    }

    // If the while loop terminates normally, and exponents are equal.
    if (p->exp == exp)
    {
        p->coeff += coeff;
        free(tmp);
        return start;
    }
    // Else, add tmp at end
    tmp->link = NULL;
    p->link = tmp;

    return start;
}

// Function for printing elements of linked list. 
void print_list(node *start)
{
    node *p = start;

    while (p != NULL)
    {
        if (p->link == NULL)
        {
            printf("%d %d", p->coeff, p->exp);
        }
        else
        {
            printf("%d %d -> ", p->coeff, p->exp);
        }
        p = p->link;
    }
    printf("\n");
}

// Function for addition of two polynomials. 
node *addition(node *start1, node *start2)
{
    // Defining pointers 
    node *p1 = start1, *p2 = start2;
    node *start = NULL;

    // Traversing list and checking for correct order of exponents for addition
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp < p2->exp)
        {
            start = insert_s(start, p2->coeff, p2->exp);
            p2 = p2->link;
        }
        else if (p2->exp < p1->exp)
        {
            start = insert_s(start, p1->coeff, p1->exp);
            p1 = p1->link;
        }
        else
        {
            start = insert_s(start, p1->coeff+p2->coeff, p1->exp);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    // Inserting remaining elements in case the lengths of the 2 lists are not equal 
    while (p1 != NULL)
    {
        start = insert_s(start, p1->coeff, p1->exp);
        p1 = p1->link;
    }
    while (p2 != NULL)
    {
        start = insert_s(start, p2->coeff, p2->exp);
        p2 = p2->link;
    }

    return start;
}

// Function for multiplication of two polynomials 
node *multiplication(node *start1, node*start2)
{
    node *p1 = start1, *p2 = start2;
    node *start = NULL;

    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            start = insert_s(start, p1->coeff*p2->coeff, p1->exp+p2->exp);
            p2 = p2->link;
        }
        p1 = p1->link;
        p2 = start2;
    }
    return start;
}


void main()
{
    node *start[] = {NULL, NULL};

    // Defining the two polynomials for operations 
    int c1[] = {2, 7, 3};
    int e1[] = {2, 1, 0};
    int c2[] = {3, 4, 2};
    int e2[] = {3, 1, 0};
    int num1 = sizeof(c1)/sizeof(c1[0]);
    int num2 = sizeof(c2)/sizeof(c2[0]);

    int *c[] = {c1, c2};
    int *e[] = {e1, e2};
    int nums[] = {num1, num2};

    int coeff, exp, num;
    int *poly;

    // Making two singly linked lists out of the polynomial arrays 
    for (int i = 0; i < 2; i++)
    {
        num = nums[i];

        for (int j = 0; j < num; j++)
        {
            coeff = c[i][j];
            exp = e[i][j];
            start[i] = insert_s(start[i], coeff, exp);
        }

        printf("Polynomial %d: ", i+1);
        print_list(start[i]);
    }
    printf("\n");
    
    // Addition
    node *add_start = addition(start[0], start[1]);
    printf("Addition: ");
    print_list(add_start);

    // Multiplication
    node *mul_start = multiplication(start[0], start[1]);
    printf("Multiplication: ");
    print_list(mul_start);
}