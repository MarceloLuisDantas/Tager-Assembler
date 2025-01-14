#include <stdlib.h>
#include <stdio.h>
#include "files.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("incorrect arguments\n");
        return 0;
    }

    const char *path = argv[1];
    File *file = loadFile(path);
    
    for (int i = 0; i < file->len; i++)
        printf("%s\n", file->lines[i]);

    return 0;
}
