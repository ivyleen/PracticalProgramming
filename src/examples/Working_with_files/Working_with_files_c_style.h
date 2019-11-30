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

void c_read_source_code_of_the_file()
{
    FILE* fileptr;
    char c;

    fileptr = fopen(__FILE__, "r");
    if ( fileptr == NULL)
    {
        cout << "There is a problem with the source file." << endl;
        exit(1);
    }

    do
    {
        c = getc(fileptr);
        putchar(c);
    } while (c != EOF);
    
    fclose(fileptr);
}

void c_read_sentence_from_a_file()
{
    FILE* fileptr;
    char sentence[1000];

    fileptr = fopen("src/examples/Working_with_files/sentence.txt", "r");
    if ( fileptr == NULL)
    {
        cout << "There is a problem with opening the file."  << endl;
        exit(1);
    }
    
    while ( fgets(sentence, 1000, fileptr))
    {
        printf("%s", sentence);
    }

    fclose(fileptr);
        
}

