// QUESTION
// Write a program to simulate the updation process of the current stock for three books 1, 2, and 3 handled by a librarian through three functions updateStockbook_i (i = 1, 2, 3) using a) global variables, b) static variables. The update is an increment of 1 in the stock of that book at a time. Print the current stock within the corresponding function after the update.

#include <stdio.h>


// PART 1 - Global Variables (Run only 1 part at once)

// int book_1 = 0;
// int book_2 = 0;
// int book_3 = 0;

// void updateStockbook_1() {
//     book_1++;
//     printf("Book 1 stock: %d\n", book_1);
// }

// void updateStockbook_2() {
//     book_2++;
//     printf("Book 2 stock: %d\n", book_2);
// }

// void updateStockbook_3() {
//     book_3++;
//     printf("Book 3 stock: %d\n", book_3);
// }



// PART 2 - Static Variables (Run only 1 part at once)

void updateStockbook_1() {
    static int book_1;
    book_1++;
    printf("Book 1 stock: %d\n", book_1);
}

void updateStockbook_2() {
    static int book_2;
    book_2++;
    printf("Book 2 stock: %d\n", book_2);
}

void updateStockbook_3() {
    static int book_3;
    book_3++;
    printf("Book 3 stock: %d\n", book_3);
}


// main is called at the end

void main() {
    updateStockbook_1();
    updateStockbook_2();
    updateStockbook_2();

    updateStockbook_3();
    updateStockbook_3();
    updateStockbook_3();

    updateStockbook_2();
    updateStockbook_1();
    updateStockbook_1();
}
