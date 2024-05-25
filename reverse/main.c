/*
Implementation of the reverse command
In this task, we implement the reverse command which prints the contents of the files received as command line arguments, with or without numbering, in reverse order, and the lines are written to the standard output mirrored. E.g. if the content of test.txt is as follows, and we also request serial numbering:

apple
peach
plum

...then the result of the reverse command is the following:

3 mulp
2 hcaep
1 elppa

An example of processing multiple files: if the test.txt file is given twice as a command line parameter and no serial numbering is requested, then the output is as follows:

mulp
hcaep
elppa
mulp
hcaep
elppa

(Note: the task is based on the rev Unix utility, which writes the contents of the received input(s) in original order, but without serial numbering and with the lines reversed.)
Task

The program reads as the first command line argument whether we want to see the serial numbers printed on the screen as well! The two possible values of the parameter should be "linenums" and "nolinenums", do not accept any other string.

The remaining command line arguments are text file names. The content of these files should be processed.
This command should print the lines of the files first.txt and second.txt in reverse order, and the characters of each line should also be mirrored like in the example above. If the first command line argument is "linenums", the serial numbers should also be printed to the beginning of each line.

If the user does not enter at least two command-line arguments, display the following instructions and terminate the program:
Usage:
rev [SHOW LINE NUMBERS] files...
Create a function named reverse() which gets a string as parameter. The function should reverse the characters of the given string in-place.

Iterate over the files in the command line arguments and process their content. In order to print their lines in a reverse order, the lines need to be stored in an array first. The array size should be a constant number (e.g. 1000) given by a macro value. The elements of the array are pointers to the heap memory where the lines should be stored. Make sure to deallocate them at the end of the program in order to avoid memory leak.

If a file can't be opened then print the following error message:

File opening unsuccessful: <file name>

Since the files may contain different number of lines, we need to store, how many elements of the array is actually used. So group the array of lines and the number of actually inserted elements in a struct.

Separate the solution into multiple translation units! The main() function should be placed in the main.c file, all other function implementations should be placed in a separate translation unit, for which a header file should be prepared. Protect the header file with header guard.

*/

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