CC=gcc
CXX=g++
RM=rm -f
CXXFLAGS=-Wall -Wextra -pedantic -std=c++14 -O3 -DCMD_OUT
LDLIBS=libc++  ### -stdlib=libc++

CPPFILES=$(shell find . -name "*.cpp")
OBJS=$(patsubst %.cpp, %.o, $(CPPFILES))

all: coculture

coculture: $(OBJS)
	    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
	    $(RM) $(OBJS)

cleanjunk:
		$(RM) 1.out
