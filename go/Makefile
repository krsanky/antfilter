# need $GOROOT set

# run make go-env
include $(GOROOT)/src/Make.inc

PROJ = antfilter

# source files in package, order matters
GOFILES=\
	my_package.go \
	$(PROJ).go

# build "antfilter" executable
$(PROJ): $(GOFILES)
	$(GC) my_package.go
	$(GC) $(PROJ).go
	$(LD) -o $@ $(PROJ).$O
	@echo "Done. Executable is: $@"

clean:
	rm -rf *.[$(OS)o] *.a [$(OS)].out $(PROJ)

.phony: clean $(PROJ)
