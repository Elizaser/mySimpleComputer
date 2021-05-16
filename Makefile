#Makefile for Static Library
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
CFLAGS=-Wall -Werror

.PHONY: clean

all: libs

myComputer: libs src/main.o src/mc/build/mc.a  src/msc/build/msc.a src/mt/build/mt.a src/mbg/build/mbg.a src/mk/build/mk.a 
	$(CC) src/main.o -L. src/mc/build/mc.a src/msc/build/msc.a src/mt/build/mt.a src/mbg/build/mbg.a  src/mk/build/mk.a  -o $@

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o $@

libs: 
	make msca
	make mta
	make mbga
	make mca

msca: 
	cd src/msc/ && make all
mta: 
	cd src/mt/ && make all
mbga: 
	cd src/mbg/ && make all
mca: 
	cd src/mc/ && make all

clear:
	-rm src/main.o
	cd src/msc/ && make clear
	cd src/mt/ && make clear
	cd src/mbg/ && make clear
	cd src/mc/ && make clear
	-rm myComputer
