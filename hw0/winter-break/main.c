/*
 * main.c
 * CS 202
 * January 19, 2020
 * Bryan Beus
 * Main file for winter-break project in hw0
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int main(int argc, char *argv[]) { 
    if (argc < 2) {
        printf("Please provide a character as an input\n");
        return 0;
    }
    char* command = argv[1];
    char letter = command[0];
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
