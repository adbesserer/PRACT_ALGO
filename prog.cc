#include <iostream>
#include <vector>
#include "bloomfilter.hh"
using namespace std;


int main(){
	int size,nhashes;
	cout << "Enter the size of the bloom filter and the number of hash functions" << endl;
	cin >> size >> nhashes;
	bloomfilter bf = bloomfilter(size,nhashes);

	string s;
	cout << "Enter the number of keys to hash." << endl;
	int nkeys; cin >> nkeys;
	for(int i=0; i<nkeys; ++i){
		cin >> s;
		bf.add(s);
	}

	bf.output();
}
