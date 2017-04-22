makefile: all

all: prog

prog: prog.o bloomfilter.o
	g++ -lgmpxx -lgmp -std=c++11 -g -o prog prog.o bloomfilter.o
	rm *.o *.hh.gch

prog.o: prog.cc
	g++ -lgmpxx -lgmp -std=c++11 -g -c prog.cc

bloomfilter.o: bloomfilter.cc bloomfilter.hh
	g++ -lgmpxx -lgmp -std=c++11 -g -c bloomfilter.cc bloomfilter.hh
