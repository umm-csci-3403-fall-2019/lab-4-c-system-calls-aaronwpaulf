#include <stdio.h>
#include <stdbool.h>

#include "disemvowel.h"

#define BUF_SIZE 1024

bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
}

void disemvowel_file(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */

    char buffer[BUF_SIZE];

    while(fgets(buffer, sizeof(buffer), inputFile)) {
        char* disemvoweled = disemvowel(buffer);
        fputs(disemvoweled, outputFile);
    }

}

int main(int argc, char *argv[]) {
    // You should set these to `stdin` and `stdout` by default
    // and then set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile;
    FILE *outputFile;


    if(argc == 1) {
        inputFile = stdin;
        outputFile = stdout;
    } else if (argc == 2) {
        inputFile = fopen(argv[1], "r");
        outputFile = stdout;
    } else {
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
    }

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel_file(inputFile, outputFile);

    return 0;
}