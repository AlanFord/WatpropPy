GCC    = gcc
GPP = g++
CFLAGS       = -std=gnu99 -fPIC -pedantic -Wall -Wextra -march=native -ggdb3
CPPFLAGS       = -std=gnu++11 -fPIC -pedantic -Wall -Wextra -march=native -ggdb3
LDFLAGS = -shared
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

TARGET_LIB = libtarget.so  # target lib
APP_CPP_FILES = $(wildcard *.cpp)
APP_C_FILES = $(wildcard *.c)
APP_H_FILES = $(wildcard *.cpp)
CPP_OBJECTS = $(APP_CPP_FILES:.cpp=.o)
C_OBJECTS = $(APP_C_FILES:.c=.o)
OBJECTS = $(CPP_OBJECTS) $(C_OBJECTS)

.PHONY: all
all: $(TARGET_LIB)

cython:
	-rm -r build watprop.c watprop.cpp
	python setup.py build_ext -if

$(TARGET_LIB): $(OBJECTS)
	$(GPP) $(LDFLAGS) -o $(TARGET_LIB) $(OBJECTS)

%.o: %.cpp $(APP_H_FILES)
	$(GPP) -c -o $@ $< $(CPPFLAGS)

%.o: %.c $(APP_H_FILES)
	$(GCC) -c -o $@ $< $(CFLAGS)

clean:
	-rm -r *.o watprop.c watprop.cpp 
