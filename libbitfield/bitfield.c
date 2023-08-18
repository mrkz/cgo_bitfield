#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "bitfield.h"

/*
 * saves the struct content from |c| into a file |filename|
 */
int save_to_file(const char* filename, struct content* c)
{
    FILE* f;
    printf("saving struct to file %s\n", filename);
    printf("%d %d %d %d %d %lu\n",c->first, c->second, c->third, c->fourth, c->fifth, c->sixth);
    f = fopen(filename, "wb");
    if (f == NULL){
        perror("Failed to create file");
        return EXIT_FAILURE;
    }
    fwrite(c, sizeof(struct content), 1, f);
    fclose(f);
    return EXIT_SUCCESS;
}

/*
 * reads content from |filename| and return a struct content at |c|
 */
int read_from_file(const char* filename, struct content* c){
    FILE* f;
    printf("reading struct from file %s\n", filename);
    f = fopen(filename, "rb");
    if (f == NULL){
        perror("Failed to read file");
        return EXIT_FAILURE;
    }
    fread(c, sizeof(struct content), 1, f);
    printf("%d %d %d %d %d %lu\n",c->first, c->second, c->third, c->fourth, c->fifth, c->sixth);
    fclose(f);
    return EXIT_SUCCESS;
}
