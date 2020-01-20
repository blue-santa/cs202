/*
 * main.cpp
 * CS 202
 * January 19, 2020
 * Bryan Beus
 * Main file for winter-break project in hw0
 */

int main(int argc, char *argv[]) { 

    // Check for the appropriate number of command prompts
    if (argc < 3) {
        cout << "Please provide a character for which to test the memory" << endl;
        exit(EXIT_FAILURE);
    }

    // Inform user of the nature of the software
    clearConsole();
    cout << "This program displays the memory location details for the value provided at the command prompt." << endl;

    // Iniate values and make calls to functions
    double x = c_ctof(argv[1]);
    double y = cpp_ftoc(argv[1]);

    // Print results
    cout << "Using C Function: " << std::setprecision(8) << x << endl;
    cout << "Using CPP Function: " << std::setprecision(8) << y << endl;

    return 0;

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
