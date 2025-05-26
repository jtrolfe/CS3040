#include <stdio.h>
#include <stdlib.h>


int encode(int key, char *buffer, FILE *inputFile, FILE *outputFile)
    {// Read from input, encode and write to output
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
            for(int i= 0; i < bytesRead;i++){
                buffer[i] = (buffer[i] + key)%256;
            }
            fwrite(buffer, 1, bytesRead, outputFile);
        }

        if (ferror(inputFile) || ferror(outputFile)) {
            fprintf(stderr, "An error occurred while reading/writing the file.\n");
            return EXIT_FAILURE;
        }else{       
            return EXIT_SUCCESS;
        }
    }


int decode(int key, char *buffer, FILE *inputFile, FILE *outputFile)
    {// Read from input, decode and write to output
        key = (256 - key);
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
            for(int i= 0; i < bytesRead;i++){
                buffer[i] = (buffer[i] + key)%256;
            }
            fwrite(buffer, 1, bytesRead, outputFile);
        }

        if (ferror(inputFile) || ferror(outputFile)) {
            fprintf(stderr, "An error occurred while reading/writing the file.\n");
            return EXIT_FAILURE;
        }else{         
            return EXIT_SUCCESS;
        }
    }