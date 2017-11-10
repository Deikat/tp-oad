#!/bin/makefile

CC = g++

CFLAGS = -Wall -Wextra -pedantic

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

EXEC = build.out

all:$(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(EXEC) *.o
