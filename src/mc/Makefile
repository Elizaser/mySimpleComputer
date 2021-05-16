#Makefile for myConsole

CC = gcc

CFLAGS = -Wall -Werror -std=c99 
FLAGS = -o
BUILD = build/

all: build lib mca

lib:
	make mka
	make msa

mka:
	cd ../mk && make

msa:
	cd ../ms && make

mca: $(BUILD)main_console.o $(BUILD)mc.a
	$(CC) $(FLAGS) mca $(BUILD)main_console.o -L. $(BUILD)mc.a ../mt/build/mt.a ../msc/build/msc.a ../mk/build/mk.a ../mbg/build/mbg.a ../ms/build/ms.a

$(BUILD)main_console.o: main_console.c
	$(CC) $(CFLAGS) -c main_console.c -o $@

$(BUILD)mc.a: $(BUILD)myConsole.o
	ar cr $(BUILD)mc.a $(BUILD)myConsole.o

$(BUILD)myConsole.o: myConsole.c myConsole.h
	$(CC) $(CFLAGS) -c myConsole.c -o $@

build:
	mkdir build

clear:
	-rm -rf build
	-rm mca
	cd ../ms && make clear
	cd ../mk && make clear
