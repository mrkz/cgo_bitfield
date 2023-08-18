package main

// #cgo CFLAGS: -I${SRCDIR}/libbitfield
// #cgo LDFLAGS: -L${SRCDIR}/libbitfield -lbitfield
// #include "cgo_bitfield.h"
import "C"
import (
	"errors"
	"fmt"
	"unsafe"
)

type content struct {
	first  uint8
	second uint8
	third  uint16
	fourth uint16
	fifth  uint32
	sixth  uint64
}

func to_content(cgo_c *C.struct_cgo_content) *content {
	c := &content{}
	c.first = uint8(cgo_c.first)
	c.second = uint8(cgo_c.second)
	c.third = uint16(cgo_c.third)
	c.fourth = uint16(cgo_c.fourth)
	c.fifth = uint32(cgo_c.fifth)
	c.sixth = uint64(cgo_c.sixth)
	return c
}

func to_cgo_content(c *content) C.struct_cgo_content {
	cgo_c := C.struct_cgo_content{}
	cgo_c.first = C.uint8_t(c.first)
	cgo_c.second = C.uint8_t(c.second)
	cgo_c.third = C.uint16_t(c.third)
	cgo_c.fourth = C.uint16_t(c.fourth)
	cgo_c.fifth = C.uint32_t(c.fifth)
	cgo_c.sixth = C.uint64_t(c.sixth)
	return cgo_c
}

func saveToFile(filename string, c *content) error {
	cgo_content := to_cgo_content(c)
	c_filename := C.CString(filename)
	defer C.free(unsafe.Pointer(c_filename))
	c_bitfield_content := C.to_content(&cgo_content)
	defer C.free(unsafe.Pointer(c_bitfield_content))
	ret := C.save_to_file(c_filename, c_bitfield_content)
	if ret != 0 {
		return errors.New("failed to save to file")
	}
	return nil
}

func readFromFile(filename string) (*content, error) {
	c_filename := C.CString(filename)
	defer C.free(unsafe.Pointer(c_filename))
	c_bitfield_content := &C.struct_content{}
	ret := C.read_from_file(c_filename, c_bitfield_content)
	if ret != 0 {
		return nil, errors.New("failed to read from file")
	}
	cgo_content := C.to_cgo_content(c_bitfield_content)
	defer C.free(unsafe.Pointer(cgo_content))
	var c *content = to_content(cgo_content)
	return c, nil

}

func main() {
	filename := "file_from_go.bin"
	c := &content{
		first:  0x4,
		second: 0x0,
		third:  0x1BD,
		fourth: 0x276E,
		fifth:  0x61502074,
		sixth:  0x323420202163696E,
	}
	fmt.Printf("Saving %#v into %v\n", c, filename)
	if err := saveToFile(filename, c); err != nil {
		fmt.Printf("error saving the file: %v\n", err)
	}
	new_c, err := readFromFile(filename)
	if err != nil {
		fmt.Printf("error reading from file: %v\n", err)
		return
	}
	fmt.Printf("Read values from golang struct content: %#v\n", new_c)
}
