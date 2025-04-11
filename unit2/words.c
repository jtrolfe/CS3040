#include <stdio.h>
#include <string.h>

int main()
{
    char word1[20];
    char word2[20] = "odd";
    char word3[]   = "weird";
    char word4[5]  = "test";

    printf("word1 = %s,\tsize %li,\tlength %li\n", word1, sizeof(word1), strlen(word1));
    printf("word2 = %s,\tsize %li,\tlength %li\n", word2, sizeof(word2), strlen(word2));
    printf("word3 = %s,\tsize %li,\t\tlength %li\n", word3, sizeof(word3), strlen(word3));
    printf("word4 = %s,\tsize %li,\t\tlength %li\n", word4, sizeof(word4), strlen(word4));

    return 0;
}
