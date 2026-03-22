// QUESTION
// Name functions as RollaCosta, Dominos, and Bawarchi – three restaurants in Kalyani. Every time you call a function, a message will be printed indicating the visit number of that function (restaurant). E.g., if you call RollaCosta, it will print “Welcome to Rolla Costa! This is your visit number 2” (assuming this is your 2nd call of the function). Implement this scheme using C programming language by using i) global variables and ii) static variables.

#include <stdio.h>


// PART 1 - Global Variables (Run only 1 part at once)

// int visit_rollacosta = 0;
// int visit_bawarchi = 0;
// int visit_dominos = 0;

// void RollaCosta() {
//     visit_rollacosta++;
//     printf("Welcome to Rolla Costa! This is your visit number %d\n", visit_rollacosta);
// }

// void Bawarchi() {
//     visit_bawarchi++;
//     printf("Welcome to Bawarchi! This is your visit number %d\n", visit_bawarchi);
// }

// void Dominos() {
//     visit_dominos++;
//     printf("Welcome to Dominos! This is your visit number %d\n", visit_dominos);
// }



// PART 2 - Static Variables (Run only 1 part at once)

void RollaCosta() {
    static int visit = 0;
    visit++;
    printf("Welcome to Rolla Costa! This is your visit number %d\n", visit);
}

void Dominos() {
    static int visit = 0;
    visit++;
    printf("Welcome to Dominos! This is your visit number %d\n", visit);
}

void Bawarchi() {
    static int visit = 0;
    visit++;
    printf("Welcome to Bawarchi! This is your visit number %d\n", visit);
}


// main is called at the end

void main() {
    Bawarchi();
    Dominos();
    RollaCosta();

    Dominos();
    Bawarchi();
    Bawarchi();

    RollaCosta();
    Dominos();
    RollaCosta();
}
