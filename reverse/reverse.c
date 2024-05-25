#include "reverse.h"

void reverse(char* str){
    int len = strlen(str);
    for(int i = 0; i < len/2; ++i ){
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int read_file(char* filename, LineArray* lineArray){
    FILE* file = fopen(filename, "r");
    if(!file) {
        return -1;
    }
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        if(lineArray->count >= MAX_LINES){
            break;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        lineArray->lines[lineArray->count] = strdup(buffer);
        reverse(lineArray->lines[lineArray->count]);
        lineArray->count++;
    }
    fclose(file);
    return 0;
}

void print_lines(LineArray* lineArray, int showLineNumbers){
    for (int i = lineArray->count-1; i >= 0; --i) {
        if(showLineNumbers) {
            printf("%d %s\n", i + 1, lineArray->lines[i]);
        } else {
            printf("%s\n", lineArray->lines[i]);
        }
    }
}
