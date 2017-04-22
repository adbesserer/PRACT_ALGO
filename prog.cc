#include <iostream>
#include <vector>
#include "bloomfilter.hh"
#include <gmp.h>
#include <gmpxx.h>
using namespace std;


int main(){
	int size,nhashes;
	cout << "Enter the size of the bloom filter and the number of hash functions" << endl;
	cin >> size >> nhashes;
	bloomfilter bf = bloomfilter(size,nhashes);
	bloomfilter bfSHA = bloomfilter(size,nhashes);

	cout << "Enter the number of keys to hash." << endl;
	int nkeys; cin >> nkeys;
	for(int i=0; i <nkeys; ++i){
		string s; cin >> s;
		if(s.size() < 3) s+="FF"; 
		bf.add_div(s);
		bfSHA.add_div(SHA(s));
	}
	
}
