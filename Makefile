PROGRAM  = antfilter

INCLUDE  = include
SRC      = src
BIN      = bin
OBJDIR   = obj

CC       = gcc
CXX      = g++
CFLAGS   = -O2
CFLAGS  += -Wall -I$(INCLUDE)
DEFS     =
LIBS     =

OBJS     = filter_set.o filter_target.o

vpath %.h   include
vpath %.c   src
vpath %.cpp src
vpath %.o   obj


all: $(PROGRAM)

test: init test.o
	$(CXX) $(CFLAGS) $(DEFS) -o $(BIN)/$(@) $(LIBS) \
	$(OBJDIR)/$(@).o  

$(PROGRAM): init $(OBJS) $(PROGRAM).o 
	$(CXX) $(CFLAGS) $(DEFS) -o $(BIN)/$(@) $(LIBS) \
	$(OBJDIR)/$(@).o \
        $(OBJDIR)/filter_set.o $(OBJDIR)/filter_target.o 

filter_set.o: filter_set.h filter_set.cpp
	$(CXX) $(CFLAGS) $(DEFS) -c $(SRC)/filter_set.cpp -o $(OBJDIR)/$(@)

filter_target.o: filter_target.h filter_target.cpp
	$(CXX) $(CFLAGS) $(DEFS) -c $(SRC)/filter_target.cpp -o $(OBJDIR)/$(@)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(DEFS) -c $(<) -o $(OBJDIR)/$(@)

.PHONY  : clean  init                              
init:
	mkdir -p $(OBJDIR) $(BIN)
	mkdir -p $(TARGET)
clean   :
	-rm -rf $(BIN) $(OBJDIR)
	-rm -rf $(TARGET)

## tar
TARGET = target
VERSION = 0.1
TARNAME = $(PROGRAM)-$(VERSION).tar.gz
CP = cp -a

target: init copy_src copy_include copy_makefile


copy_src: init
	$(CP) $(SRC) $(TARGET)

copy_include: init  
	$(CP) $(INCLUDE) $(TARGET)/

copy_makefile:  init
	$(CP) Makefile $(TARGET)/

tar: target
	@printf "\n>> making $(TARNAME) >>\n"
	(cd $(TARGET) ; tar -cz --exclude-from="../exclude-pats" -f $(TARNAME) * ; pwd )

