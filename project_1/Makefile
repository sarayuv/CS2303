# This makefile is used as follows to regenerate files for the race program.
#	make animals.o	--	Regenerates animals.o by compiling
#	make race.o		--	Regenerates race.o by compiling
#	make theRace	--	Regenerates the executable theRace file by compiling 

theRace: animals.o race.o
	gcc -g -Wall race.o animals.o -lm -o theRace

animals.o: animals.h animals.c
	gcc -g -Wall -c animals.c

race.o: animals.h race.c
	gcc -g -Wall -c race.c
