#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void usage (){
	cout << "El parametro 1 debe ser el nombre del archivo, y el 2 el numero de randoms" << endl;
}
int main(int argc, char* argv[]){
	if(argc < 3){
		usage();
		exit(1);
	}
	ofstream file;
	file.open(argv[1], ios::out|ios::app);
	for(int i = 0; i!= atoi(argv[2]); ++i)	
		file << rand() << endl;
	file.close();
}