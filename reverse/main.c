#include "reverse.h"

void print_usage() {
    printf("Usage:\n");
    printf("rev [SHOW LINE NUMBERS] files...\n");
}

int main(int argc, char* argv[]) {
    if(argc < 3){
        print_usage();
        return 1;
    }

    int showLineNumbers = 0;

    if (strcmp(argv[1], "linenums") == 0) {
        showLineNumbers = 1;
    } else if(strcmp(argv[1], "nolinenums") != 0) {
        print_usage();
        return 1;
    }
    LineArray lineArray = { .count = 0};
    for (int i = 2; i < argc; ++i){
        if(read_file(argv[i], &lineArray) != 0) {
            printf("File opening unseccesful: $s\n", argv[i]);
            continue;
        }
        print_lines(&lineArray, showLineNumbers);
        for(int j = 0; j < lineArray.count; ++j) {
            free(lineArray.lines[j]);
        }
        lineArray.count = 0;
    }
    return 0;
}