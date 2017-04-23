#include <iostream>
#include <vector>
#include "bloomfilter.hh"
#include "sha256.h"
#include <gmp.h>
#include <gmpxx.h>
#include <ctime>
#include <set>

using namespace std;


int main(){
	int size,nhashes;
	cout << "Enter the size of the bloom filter and the number of hash functions" << endl;
	cin >> size >> nhashes;

	set<string> elements; //set que guarda las keys que añadimos al bloom filter

	bloomfilter bf = bloomfilter(size,nhashes);
	bloomfilter bfSHA = bloomfilter(size,nhashes);

	cout << "Enter the number of keys to hash." << endl;
	int nkeys; cin >> nkeys;
	clock_t begin = clock();
	for(int i=0; i <nkeys; ++i){
		string s; cin >> s;

		if(s.size() < 3) s+="FF"; 
		elements.insert(s);
		
		bf.add_div(s);
		bfSHA.add_div(sha256(s));
	}
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  	cout << "Total time: " << elapsed_secs << endl;

  	cout << "Enter the number of keys to search." << endl;
  	cin >> nkeys;
  	for(int i=0; i < nkeys; ++i){
  		string s; cin >> s;
  		if(s.size() < 3) s+="FF";

  		if(bf.find(s)){
  			if(elements.find(s) == elements.end()) cout << "FALSE POSITIVE" << endl;
  			else cout << "It is in the bloomfilter." << endl;
  		}
  		else cout << "It is not in the bloomfilter." << endl;


  		if(bfSHA.find(sha256(s))){
  			if(elements.find(s) == elements.end()) cout << "FALSE POSITIVE" << endl;
  			else cout << "It is in the SHA bloomfilter." << endl;
  		}
  		else cout << "It is not in the SHA bloomfilter." << endl;
  	}

	bf.output();
	bfSHA.output();
}
