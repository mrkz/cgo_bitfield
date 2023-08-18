package main

// #cgo CFLAGS: -I${SRCDIR}/libbitfield
// #cgo LDFLAGS: -L${SRCDIR}/ -lbitfield
// #include "cgo_bitfield.h"
import "C"

type content struct {
	first  uint8
	second uint8
	third  uint16
	fourth uint16
	fifth  uint32
	sixth  uint64
}

func save_to_file(*c content) error {

}

func main() {
	filename := "file_from_go.bin"

}
