# This makefile is used as follows to regenerate files for the coffee shop program.
#	make register.o	--	Regenerates register.o by compiling
#	make coffee_shop.o		--	Regenerates coffee_shop.o by compiling
#	make register.exe	--	Regenerates the executable register file by compiling 

register.exe: register.o coffee_shop.o
	gcc -g -Wall coffee_shop.o register.o -lm -o register.exe

register.o: register.h register.c
	gcc -g -Wall -c register.c

coffee_shop.o: register.h coffee_shop.c
	gcc -g -Wall -c coffee_shop.c
