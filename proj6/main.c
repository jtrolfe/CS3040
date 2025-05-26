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
#include <errno.h>
#include <string.h>
#include "shift.h"

#define BUFFER_SIZE 1024
#define BASE_10     10

// constants


// return codes
#define SUCCESS        0
#define ENCODE         1
#define DECODE         2
#define ERROR          -1

// ----------------------------------------------------------------------
// ------------------------ P R O T O T Y P E S -------------------------
// ----------------------------------------------------------------------
int get_input(int argc,char *argv[],int *key, char *in_file[],char *out_file[]);


// **********************************************************************
// **************************  M  A  I  N  ******************************
// **********************************************************************
int main(int argc, char *argv[])
{
    int result = 0;
    int key = -1;
    FILE *inputFile, *outputFile;
    char buffer[BUFFER_SIZE];
    char* in_file = NULL;
    char* out_file = NULL;

    result = get_input(argc, argv, &key, &in_file, &out_file);
    if(result == ERROR){
        fprintf(stderr,"An error occurred with processing inputs\n");
        return EXIT_FAILURE;
    } 

    // Open input file for reading
    inputFile = fopen(in_file, "r");
    if (inputFile == NULL) {
        perror("Error opening input.txt");
        return EXIT_FAILURE;
    }

    // Open output file for writing
    outputFile = fopen(out_file, "w");
    if (outputFile == NULL) {
        perror("Error opening output.txt");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    printf("%i\n", result);
    if(result == ENCODE){
        // Read from input, encode and write to output
        result = encode(key, buffer, inputFile, outputFile);
    }
    printf("%i\n", result);
    if(result == DECODE){
        // Read from input, decode and write to output
        result = decode(key, buffer, inputFile, outputFile);
    }
    printf("%i\n", result);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    if(result == 0){
        printf("Operation successfull.\n");
    }else{
        fprintf(stderr,"An unknown error has occurred");
    }

    return result;
} //End of main

// ---------------------------------------------------------------------
// Function:
//     get_input
// Inputs:
//     argc
//         The value passed to main
//     argv
//         The value passed to main
// Outputs:
//      in_file - string of the input file name
//      out_file - string of the output file name   
//      key - the key value to be used for encoding/decoding
//
//
//      returns
//         0 - if user requested encode
//         1 - if user requested decode
//         -1 - if there was an error processing inputs
// Description:
//     This function verifies that the user provided good input. 
// ---------------------------------------------------------------------
int get_input(int argc,char *argv[],int *key, char *in_file[],char *out_file[])
{
    char* my_pointer = NULL; //Pointer used for error detection in strtol()
    int my_ret_val =0;
    int num = -1;
    FILE *fp = NULL;

    if (argc != 5) {            //Check number of arguments
        fprintf(stderr, "Error: %s\n", "Expected 4 arguments \nExample: shift -e|-d key input outpu");
        my_ret_val = ERROR;
    }

// Check if the first argument is -e or -d
// strcmp does not set errno
    if (strcmp(argv[1], "-e") == 0) {
        my_ret_val = ENCODE;
    } else if (strcmp(argv[1], "-d") == 0) {
        my_ret_val = DECODE;
    } else {
        fprintf(stderr, "Error: First argument must be '-e' (encode) or '-d' (decode)\n");
        my_ret_val = ERROR;
    }


    errno = 0;
    num = strtol(argv[2], &my_pointer, BASE_10);
    if (errno != 0) {           //strtol error handling
        fprintf(stderr,"Error: Please enter a valid key");
        my_ret_val = ERROR;
    }

    if (*my_pointer != '\0') {  //Check for non numeriacl input
        fprintf(stderr, "A non-digit character was encountered in argument: %c\n", *my_pointer);
        my_ret_val = ERROR;
    }

    *key = num;

    if(*key<0 || *key >255){
        printf("%i\n",*key);
        fprintf(stderr,"Error: Please enter a valid key");
        my_ret_val = ERROR;
    }
    
    //Check if file names are valid
    fp = fopen(argv[3], "a");
    if (fp) {
        *in_file = argv[3];
        fclose(fp);
    } else {
        perror("INPUT fopen failed");
        my_ret_val = ERROR;
    }

    fp = fopen(argv[4], "a");
    if (fp) {
        *out_file = argv[4];
        fclose(fp);
    } else {
        perror("OUTPUT fopen failed");
        my_ret_val = ERROR;
    }

    //Check if files have the same name
    if (strcmp(*in_file, *out_file) == 0){
        fprintf(stderr, "Input and output files are not allowed to have the same name");
        my_ret_val = ERROR;
    }

    return my_ret_val;
} // end get_input