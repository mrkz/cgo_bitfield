build: bitfield

bitfield:
	@rm -rf builddir @> /dev/null
	meson setup builddir libbitfield
	ninja -C builddir
	cp builddir/libbitfield.so .
