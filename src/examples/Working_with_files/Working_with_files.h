#pragma once

#include <stdio.h>
#include <stdlib.h>

// c style working with files
void c_write_sentence_in_a_file()
{
    char sentence[1000];
    FILE *filePtr;

    // w - create a new empty file
    // if file with the same name exist - it deletes everything in it
    filePtr = fopen("src/examples/Working_with_files/sentence.txt", "w");
    if ( filePtr == NULL)
    {
        printf("There is an error with opening the file.");
        exit(1);
    }

    printf("Enter a sentence: \n");
    // read input from user and put it in sentence
    scanf("%[^\n]", sentence);

    // write it in the file
    fprintf(filePtr, "%s", sentence);
    // close the file
    fclose(filePtr);
}

void c_read_sentence_from_a_file()
{

}