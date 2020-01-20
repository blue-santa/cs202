/*
 * main.cpp
 * CS 201
 * December 6, 2019
 * Bryan Beus
 * Main file for themostat main project in hw8
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int main(int argc, char *argv[]) { 
    char letter = 'C';
    char *pLetter = NULL;

    printf("Value of letter: %c\n", letter);
    printf("Address of letter: %p\n\n", &letter);

    pLetter = &letter;

    printf("pLetter's address: %p\n", (void*)&pLetter); 
    printf("Size of pLetter: %zd\n", sizeof(pLetter));
    printf("Value of pLetter: %p\n", pLetter);
    printf("Value pLetter points to: %c\n", *pLetter);

    return 0; 
}
