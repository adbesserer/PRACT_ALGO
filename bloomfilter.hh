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
		int falsePositives; //numero de falsos positivos
		vector<bool> bf;

		int pow(int x, int y){
			if(y == 0) return 1;
			else return x*pow(x, y-1);
		}

		float stringToNum(string key){
			float res = 0.0;
			for(int i = 0; i<key.size(); ++i) res += atof(&(key[i]))*(float)pow(10, i);
			return res;
		}
		
	public:
		bloomfilter(int size, int n_hashes);

		void output();
		
		void add(string key);
};

#endif
