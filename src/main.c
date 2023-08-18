#include <stdlib.h>

#include "bitfield.h"


int main(int argc, char *argv[])
{
    const char * filename = "file.out";
    struct content c = {
        .first = 1,
        .second = 2,
        .third = 3,
        .fourth = 4,
        .fifth = 5,
        .sixth = 6,
    };
    struct content* new_c = malloc(sizeof(struct content));
    save_to_file(filename, &c);
    read_from_file(filename, new_c);
    return 0;
}
