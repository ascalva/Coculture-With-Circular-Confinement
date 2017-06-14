CC=gcc
CXX=g++
RM=rm -f
###CPPFLAGS=-g $(shell root-config --cflags)
###LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=libc++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++14 -O3

CPPFILES=$(shell find . -name "*.cpp")
OBJS=$(patsubst %.cpp, %.o, $(CPPFILES))

all: coculture

coculture: $(OBJS)
	    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
	    $(RM) $(OBJS)

cleanjunk:
		$(RM) 1.out
