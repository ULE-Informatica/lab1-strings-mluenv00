#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

// This is the correct function without memory leaks problems
// Only extra comprobations are added
void optionOne(){

    // It`s neccesary to ensure that we reserve the correct memory
    char exampleString[]="Welcome Sanitizer!";
    int memoryNeeded=sizeof(exampleString);

    long int reservedMemory=100*sizeof(char); //tam of reserved memory (100 chars)
    char *s = (char *) malloc(reservedMemory);

    if (reservedMemory >= memoryNeeded){
        strcpy(s, "Welcome Sanitizer!");
        printf("string is: %s\n", s);
        free(s); // the memory is liberated after the last use.
    }
    else
    {
        fprintf(stderr, "%s\n", "Error => Not enought reserved memory");
        free(s); // the memory is liberated after the last use.
        exit(-1);
    }

    
}

// This is the function with memory leaks problems
void optionTwo(){

    // It`s neccesary to ensure that we reserve the correct memory
    char exampleString[]="Welcome Sanitizer!";
    int memoryNeeded=sizeof(exampleString);

    long int reservedMemory=100*sizeof(char); //tam of reserved memory (100 chars)
    char *s = (char *) malloc(reservedMemory);

    if (reservedMemory >= memoryNeeded){
        strcpy(s, "Welcome Sanitizer!");
        printf("string is: %s\n", s);
        free(s); // the memory is liberated after the last use.
    }
    else
    {
        fprintf(stderr, "%s\n", "Error => Not enought reserved memory");
        free(s); // the memory is liberated after the last use.
        exit(-1);
    }

}

// This is the function with heap use after free
void optionThree(){
    // When we use malloc, we will request a block of memory from the heap. 
    //char *s = (char *) malloc(100);
    //free(s); // the memory is liberated after the memory reservation
    
    // Then, try to modify and read the heap
    //strcpy(s, "Welcome Sanitizer!");
    //printf("string is: %s\n", s);

    // It`s neccesary to ensure that we reserve the correct memory
    char exampleString[]="Welcome Sanitizer!";
    int memoryNeeded=sizeof(exampleString);

    long int reservedMemory=100*sizeof(char); //tam of reserved memory (100 chars)
    char *s = (char *) malloc(reservedMemory);

    if (reservedMemory >= memoryNeeded){
        strcpy(s, "Welcome Sanitizer!");
        printf("string is: %s\n", s);
        free(s); // the memory is liberated after the last use.
    }
    else
    {
        fprintf(stderr, "%s\n", "Error => Not enought reserved memory");
        free(s); // the memory is liberated after the last use.
        exit(-1);
    }
}

// This is the function with memory reservation problems that produces a heap overflow
void optionFour()
{   
    //char *s = (char *) malloc(18); // we need 19 instead 18 because the '\0' character
    
    // It`s neccesary to ensure that we reserve the correct memory
    char exampleString[]="Welcome Sanitizer!";
    int memoryNeeded=sizeof(exampleString);

    //long int reservedMemory=18*sizeof(char); //Incorrect tam of reserved memory (18 chars)
    long int reservedMemory=19*sizeof(char); //Correct tam of reserved memory (19 chars)
    char *s = (char *) malloc(reservedMemory);

    if (reservedMemory >= memoryNeeded){
        strcpy(s, "Welcome Sanitizer!");
        printf("string is: %s\n", s);
        free(s); // the memory is liberated after the last use.
    }
    else
    {
        fprintf(stderr, "%s\n", "Error => Not enought reserved memory");
        free(s); // the memory is liberated after the last use.
        exit(-1);
    }
    
}

int main(int argc, const char *argv[]) {

    int expression;
    char* p;
    errno = 0; 
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        exit(1);
    }

    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) {
        return 1; 
    }

    if (arg < INT_MIN || arg > INT_MAX) {
        return 1;
    }

    expression = arg;
 

    switch (expression)
    {
        case 1:
            optionOne();
            break;
        case 2:
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        default:
            printf("\n");
            break;
    }

    return 0;
}