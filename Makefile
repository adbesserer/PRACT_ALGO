makefile:

all: prog

prog: prog.o bloomfilter.o
	g++ -std=c++11 -o prog.exe prog.o bloomfilter.o
	rm *.o *.hh.gch

prog.o: prog.cc
	g++ -std=c++11 -c prog.cc

bloomfilter.o: bloomfilter.cc bloomfilter.hh
	g++ -std=c++11 -c bloomfilter.cc bloomfilter.hh
