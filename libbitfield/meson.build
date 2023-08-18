project('bitfield', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_BITFIELD']

shlib = library('bitfield', 'bitfield.c',
  install : true,
  c_args : lib_args,
  gnu_symbol_visibility : 'default',
)

# Make this library usable as a Meson subproject.
bitfield_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('bitfield.h', subdir : 'bitfield')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'bitfield',
  filebase : 'bitfield',
  description : 'very dumb bitfield struct example',
  subdirs : 'bitfield',
  libraries : shlib,
  version : '0.1',
)
