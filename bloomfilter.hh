#ifndef _BLOOMFILTER_HH
#define _BLOOMFILTER_HH

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

class bloomfilter {
	private:
		int n_hashes; //numero de funciones de hash que utiliza el filtro
		int size;   //tamaño del filtro de bloom
		int falsePositives; //numero de falsos positivos
		vector<bool> bf;
		vector<long> primes;

	public:

		bloomfilter(int size, int n_hashes);

		void output();

		void add_div(string key);
		
		void add_mul(string key);
};

#endif
