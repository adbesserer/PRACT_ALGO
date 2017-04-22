#ifndef _BLOOMFILTER_HH
#define _BLOOMFILTER_HH

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

class bloomfilter {
	private:
		int n_hashes; //numero de funciones de hash que utiliza el filtro
		int size;   //tamaño del filtro de bloom
		int falsePositives; //numero de falsos positivos
		vector<bool> bf;

		//Pre: key es un string
		//Post: el resultat es el valor dels caracters concatenats a->10 A->36
		double keyToDouble(string key){
			double result = 0.0;
			int i = key.size()-1;
			for(char c : key){
				if(c >= '0' && c <= '9') result += (c-'0')*pow(36,i);
				else if(c >= 'a' && c <= 'z') result += (c-'a'+10)*pow(36, i);
				else if(c >= 'A' && c <= 'Z') result += (c-'A'+10)*pow(36, i);
				else{
					cout << "The key has to be alphanumerical." << endl;
					return -1.0;
				}
			}
			return result;
		}

	public:
		bloomfilter(int size, int n_hashes);

		void output();
		
		void add(string key);
};

#endif
