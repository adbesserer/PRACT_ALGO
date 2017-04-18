#ifndef _BLOOMFILTER_HH
#define _BLOOMFILTER_HH

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class bloomfilter {
	private:
		int n_hashes; //numero de funciones de hash que utiliza el filtro
		int size;   //tamaño del filtro de bloom
		vector<bool> bf;
		
	public:
		bloomfilter(int size, int n_hashes){  //creadora
			if(size>0){
				this->size=size;
				bf = vector<bool>(size,false);
			}
			else{
				cerr <<  "the size must be a positive integer" << endl;
				exit(1);
			 }
			if(n_hashes>0)
				this->n_hashes=n_hashes;
			else{
				cerr << "the number of hashes must be positive" << endl;		
				exit(1);
			}
		}
		
		void add(string key){
			//aqui ha de pasar todos los hashes
			int m=size;
			for(int i = 0; i!= n_hashes;++i){
				bf[string2num(key)%m]=true;
			}
		}
};

#endif
