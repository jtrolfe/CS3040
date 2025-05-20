// ----------------------------------------------------------------------
// File: shift.c
//
// Name: John Rolfe
//
// Description: This program encrpyts and decrypts the input file with a 
// simple ceasar's cypher using the common ASCII values (0-255). The 
// encryption output is based on the given key, which determines the 
// amount the cypher shifts. A valid key is between 0 and inclusive.
// a key of zero will not shift the text resulting in a unchanged file 
// being copied to the output.
//
// Syntax:
//     ./shift -e|-d key input output
//          option “-e” or “-d” specifies encryption or decryption
//          key is the amount of the shift (values between 0 and 255, inclusive)
//          input is the name of the file to encrypt or decrypt
//          output is the name of the file where the results will be stored
// ----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// constants

// ----------------------------------------------------------------------
// ------------------------ P R O T O T Y P E S -------------------------
// ----------------------------------------------------------------------

// **********************************************************************
// **************************  M  A  I  N  ******************************
// **********************************************************************
int main(int argc, char *argv[])
{
    FILE *inputFile, *outputFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input.txt");
        return 1;
    }

    // Open output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output.txt");
        fclose(inputFile);
        return 1;
    }

    // Read from input and write to output
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        for(int i= 0; i < sizeof(buffer);i++){
            printf("%i\n",buffer[i]);
            buffer[i] = (buffer[i] + 3)%255;
            printf("%i TEST PRINT\n", buffer[i]);
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("File copied successfully.\n");

    return 0;
} //End of main