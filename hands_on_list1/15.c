/*
============================================================================
Name :15.c
Author : Swarnim Kukreti
Description :Write a program to display the environmental variable of the user (use environ). 
Date: 9th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}

