# need $GOROOT set

# run make go-env to see some context
include $(GOROOT)/src/Make.inc

PROJ = antfilter

# source files in package, order matters
GOFILES =\
	filter.go \
	target.go \
	write.go \
	$(PROJ).go

# build "antfilter" executable
$(PROJ): $(GOFILES)
	$(GC) filter.go
	$(GC) target.go
	$(GC) write.go
	$(GC) $(PROJ).go
	$(LD) -o $@ $(PROJ).$O
	@echo "Done. Executable is: $@"

clean:
	rm -rf *.[$(OS)o] *.a [$(OS)].out $(PROJ)

.phony: clean $(PROJ)
