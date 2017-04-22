makefile: all

all: prog

prog: prog.o bloomfilter.o
	g++ -std=c++11 -g -o prog prog.o bloomfilter.o
	rm *.o *.hh.gch

prog.o: prog.cc
	g++ -std=c++11 -g -c prog.cc

bloomfilter.o: bloomfilter.cc bloomfilter.hh
	g++ -std=c++11 -g -c bloomfilter.cc bloomfilter.hh
