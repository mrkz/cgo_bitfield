#ifndef BITFIELD_H
#define BITFIELD_H

#include <stdint.h>

struct content {
    uint64_t first: 4;
    uint64_t second: 2;
    uint64_t third: 10;
    uint64_t fourth: 16;
    uint64_t fifth: 32;
    uint64_t sixth;
} __attribute__((packed));

int save_to_file(const char* filename, struct content* c);
int read_from_file(const char* filename, struct content* c);

#endif /* ifndef BITFIELD_H */
