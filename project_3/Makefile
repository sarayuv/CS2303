# WRITTEN BY: Sarayu Vijayanagaram (svijayanagaram@wpi.edu), Oct 1, 2023

# This makefile is used as follows to regenerate files for the Word Counter program.
#	make count_words.o	--	Regenerates count_words.o by compiling
#	make binaryTree.o	--	Regenerates binaryTree.o by compiling
#	make countWords	--	Regenerates the executable countWords file by compiling 

countWords: count_words.o binaryTree.o
	gcc -g -Wall binaryTree.o count_words.o -lm -o countWords

count_words.o: count_words.h count_words.c
	gcc -g -Wall -c count_words.c

binaryTree.o: binaryTree.h binaryTree.c
	gcc -g -Wall -c binaryTree.c

clean:
	rm -f binaryTree.o count_words.o countWords

all: countWords
