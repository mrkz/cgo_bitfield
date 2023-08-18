#ifndef CGO_BITFIELD
#define CGO_BITFIELD

#include <stdint.h>
#include <stdlib.h>

#include "libbitfield/bitfield.h"


struct cgo_content {
    uint8_t first;
    uint8_t second;
    uint16_t third;
    uint16_t fourth;
    uint32_t fifth;
    uint64_t sixth;
};

struct cgo_content* to_cgo_content(const struct content* c);
struct content* to_content(const struct cgo_content* cgo_c);

#endif /* ifndef CGO_BITFIELD */
