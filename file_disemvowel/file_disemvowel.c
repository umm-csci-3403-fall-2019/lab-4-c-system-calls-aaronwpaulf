#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "disemvowel.h"

#define BUF_SIZE 1024


void disemvowel_file(FILE* inputFile, FILE* outputFile) {

    // Allocate array of chars with size BUF_SIZE
    char buffer[BUF_SIZE];

    // While fgets hasn't gotten to the end of the file
    while(fgets(buffer, sizeof(buffer), inputFile)) {
        // Pass the current string in the buffer to our existing disemvowel function
        char* disemvoweled = disemvowel(buffer);
        // Write the disemvoweled string to the output file
        fputs(disemvoweled, outputFile);
        free(disemvoweled);
    }

}

int main(int argc, char *argv[]) {
    // You should set these to `stdin` and `stdout` by default
    // and then set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile;
    FILE *outputFile;


    if(argc == 1) {
        // If no arguments, use stdin and stdout
        inputFile = stdin;
        outputFile = stdout;
    } else if (argc == 2) {
        // If one argument use the file provided as input and stdout for output
        inputFile = fopen(argv[1], "r");
        outputFile = stdout;
    } else {
        // If two arguments use the first file as input and the second file as output
        // If there are more than 2 arguments the remaining are ignored
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
    }

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel_file(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
