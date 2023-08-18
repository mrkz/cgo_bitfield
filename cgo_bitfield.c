#include <stdint.h>
#include <stdlib.h>

#include "bitfield.h"
#include "cgo_bitfield.h"

struct cgo_content* to_cgo_content(const struct content* c){

    struct cgo_content *cgo_c = malloc(sizeof(struct cgo_content));

    cgo_c->first = ((uint8_t) c->first);
    cgo_c->second = ((uint8_t) c->second);
    cgo_c->third = ((uint16_t) c->third);
    cgo_c->fourth = ((uint16_t) c->fourth);
    cgo_c->fifth = ((uint32_t) c->fifth);
    cgo_c->sixth = ((uint64_t) c->sixth);

    return cgo_c;
}

struct content* to_content(const struct cgo_content* cgo_c){

    struct content *c = malloc(sizeof(struct content));

    c->first = cgo_c->first;
    c->second = cgo_c->second;
    c->third = cgo_c->third;
    c->fourth = cgo_c->fourth;
    c->fifth = cgo_c->fifth;
    c->sixth = cgo_c->sixth;

    return c;
}
