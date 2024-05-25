#ifndef REVERSE_H
#define REVERSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char* lines[MAX_LINES];
    int count;
} LineArray;

void reverse(char* str);
int read_file(char* filename, LineArray* lineArray);
void print_lines(LineArray* lineArray, int showLineNumbers);

#endif