CXX = g++

# o2	: standard optimization (medium between code length vs cache)
# std	: c++ version
# Wall	: show all warnings
CFLAGS = -O2 -std=c++11 -Wall

# -MMP	: generates .d files
DEPFLAGS = -MMD

# add into LIBDIRS if more lib directory needed
LIBDIR0 = /usr/local/lib/
LIBDIRS = -L${LIBDIR0}

# flag for json library
LIBJSONCPP = -ljsoncpp
LDFLAGS = $(LIBJSONCPP)

INC0 = /usr/local/include/
INC1 = /usr/include
INCDIRS = -I${INC0} -I${INC1}

# name of output binary
BIN = generatecsv

# source cpp
SRC = $(wildcard *.cpp)

# obj files named by source files
OBJ = $(SRC:%.cpp=%.o)

DEPENDS = ${SRC:%.cpp=%.d}

.SUFFIXES : .exe .CC
# $@	: all
# #<	: first dependency (.cpp file in this case)
.CXX.exe: $(CXX) $(CFLAGS) $@ $<

# $^	: all dependency list
generatecsv : $(SRC)
		$(CXX) $(CFLAGS) ${DEPFLAGS} $(INCDIRS) -o $(BIN) $^ $(LIBDIRS) $(LDFLAGS)

clean :
		rm -f *.o
		rm $(BIN)
