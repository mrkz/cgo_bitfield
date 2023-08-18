
.PHONY: build bitfield clean
build: bitfield

bitfield:
	@rm -rf builddir &> /dev/null
	meson setup builddir libbitfield
	ninja -C builddir
	cp builddir/libbitfield.so libbitfield

clean:
	@rm -rf builddir &> /dev/null
	@rm -f libbitfield/libbitfield.so &> /dev/null
	@rm -f bitfield &> /dev/null
	@rm -f file_from_go.bin || true &> /dev/null

