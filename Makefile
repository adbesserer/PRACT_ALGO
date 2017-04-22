makefile: all

all: prog

prog: prog.o bloomfilter.o
	g++ -lgmpxx -lgmp -std=c++11 -o prog prog.o bloomfilter.o
	rm *.o *.hh.gch

prog.o: prog.cc
	g++ -lgmpxx -lgmp -std=c++11 -c prog.cc

bloomfilter.o: bloomfilter.cc bloomfilter.hh
	g++ -lgmpxx -lgmp -lgmpxx -lgmp -std=c++11 -c bloomfilter.cc bloomfilter.hh 
