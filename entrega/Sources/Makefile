makefile: all

all: prog 

prog: prog.o bloomfilter.o sha256.o
	g++ -lgmpxx -lgmp -std=c++11 -g -o prog prog.o bloomfilter.o sha256.o

prog.o: prog.cc
	g++ -lgmpxx -lgmp -std=c++11 -g -c prog.cc

bloomfilter.o: bloomfilter.cc bloomfilter.hh
	g++ -lgmpxx -lgmp -std=c++11 -g -c bloomfilter.cc bloomfilter.hh

sha256.o: sha256.cc sha256.h
	g++ -std=c++11 -g -c sha256.cc sha256.h

rndm: randomgen.cc
	g++ -o rndm randomgen.cc

clean: 
	rm *.o prog 