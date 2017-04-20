makefile:

all: prog

prog: prog.o bloomfilter.o
	g++ -o prog.exe prog.o bloomfilter.o
	rm *.o *.hh.gch

prog.o: prog.cc
	g++ -c prog.cc

bloomfilter.o: bloomfilter.cc bloomfilter.hh
	g++ -c bloomfilter.cc bloomfilter.hh
