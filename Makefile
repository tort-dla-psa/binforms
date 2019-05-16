blddir := build
libdir := lib
incdir := include
srcdir := src
extra = 
cxx := g++
cxxflags := -ffast-math $(extra)


.DEFAULT_GOAL = all

prepare:
	@mkdir -p $(blddir) $(libdir)
clean:
	@rm -rf $(blddir) $(libdir)

binforms_trg := $(libdir)/libbinforms.so
binforms_src := $(wildcard  src/*.cpp)
binforms_hdr := $(incdir)/*.h

$(binforms_trg): $(binforms_src) $(binforms_hdr)
	@echo "compile $< $@"
	@$(cxx) $(cxxflags) $(binforms_src) -I $(incdir) -o $(binforms_trg) --shared -fPIC

all: prepare \
	$(binforms_trg)
