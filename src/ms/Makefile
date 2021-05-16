
#Makefile for signal

CC = gcc

CFLAGS = -Werror -Wall -std=c99
FLAGS = -o
BUILD = build/

all: build msa

msa: $(BUILD)ms.a

$(BUILD)ms.a: $(BUILD)signal.o
	ar cr $(BUILD)ms.a $(BUILD)signal.o

$(BUILD)signal.o: signal.c signal.h
	$(CC) $(CFLAGS) -c signal.c -o $@

build:
	mkdir build
	
clear:
	-rm -rf build
