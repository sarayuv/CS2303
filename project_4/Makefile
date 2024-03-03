# WRITTEN BY: Sarayu Vijayanagaram (svijayanagaram@wpi.edu), Oct 8, 2023

# This makefile is used as follows to regenerate files for the Rational Number program.
#	make test_rational.o	--	Regenerates test_rational.o by compiling
#	make Rational.o	--	Regenerates Rational.o by compiling
#	make rational_math	--	Regenerates the executable rational_math file by compiling 

rational_math: Rational.o test_rational.o
	g++ -g -Wall Rational.o test_rational.o -lm -o rational_math

test_rational.o: test_rational.cpp
	g++ -g -Wall -c test_rational.cpp

Rational.o: Rational.h Rational.cpp
	g++ -g -Wall -c Rational.cpp

clean:
	rm -f Rational.o test_rational.o rational_math

all: rational_math
