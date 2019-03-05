blddir := build
libdir := lib
incdir := include
srcdir := src
extra = 
cxx := g++
cxxflags := -ffast-math $(extra)

prepare:
	mkdir -p $(blddir)
	mkdir -p $(libdir)
clean:
	rm -rf $(blddir) $(libdir)

binforms_trg := $(libdir)/binforms.so
binforms_src := $(wildcard  src/*.cpp)
binforms_hdr := $(incdir)/*.h

$(binforms_trg): $(binforms_src) $(binforms_hdr)
	$(cxx) $(cxxflags) $(binforms_src) -I $(incdir) -o $(binforms_trg) --shared -fPIC

all: prepare \
	$(binforms_trg)
