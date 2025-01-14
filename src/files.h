#ifndef FILES_H
#define FILES_H

#include <stdlib.h>

typedef struct File {
    char **lines;
    size_t len;
} File;

File *loadFile(const char *path);

#endif