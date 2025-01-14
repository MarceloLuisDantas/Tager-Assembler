#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include "strings.h"
#include "linked_list.h"

typedef struct File {
    String *lines;
    size_t len;
} File;

// Load all lines of a file
File *loadFile(const char *path) {
    LinkedList *l_lines = newLinkedList();

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Could not load file - %s\n", path);
        exit(0);
    }

    char *line = NULL;
    size_t _n = 0;
    ssize_t len; // Len of the line
    while ((len = getline(&line, &_n, fp)) != -1) {
        String *str = newString(line);
        removeExtraSpaces(str);
        if (str->len != 0) {// Ignore empty lines
            add(l_lines, str);
            // printf("-%s-\n", str->str);
        }
    }

    fclose(fp);
    if (line)
        free(line);


    File *file = (File *)malloc(sizeof(File));
    file->lines = toArray(l_lines);
    file->len = l_lines->len;

    // freeAll(l_lines);

    return file;
}