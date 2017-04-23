#include <iostream>
#include <vector>
#include "bloomfilter.hh"
#include "sha256.h"
#include <gmp.h>
#include <gmpxx.h>
#include <ctime>
#include <set>
#include <fstream>

using namespace std;


int main(){
	int size,nhashes;
	cout << "Enter the size of the bloom filter and the number of hash functions" << endl;
	cin >> size >> nhashes;

	set<string> elements; //set que guarda las keys que añadimos al bloom filter

	bloomfilter bf = bloomfilter(size,nhashes);
	bloomfilter bfSHA = bloomfilter(size,nhashes);

	cout << "Enter the name of the file containing the keys." << endl 
			<< "(This file must be in the same directory as this program)" << endl;
	int nkeys = 0;
	ifstream keyFile;
	string fileName,line;
	cin >> fileName;
	keyFile.open(fileName, ios::in);
	clock_t begin = clock();	
	while(getline(keyFile,line)){
		cout << line << endl;
		if(line != "\n" and line[0] != '#'){
			elements.insert(line);
			
			bf.add_div(line);
			bfSHA.add_div(sha256(line));
		}
	}
	keyFile.close();
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  	cout << "--------------------------------------------" << endl;
  	cout << "Total time to fill bloom filter: " << elapsed_secs << endl;
  	cout << "--------------------------------------------" << endl << endl;

  	ifstream testFile;
  	cout << "Enter the name of the file containing the tests" << endl;
  	while(1){
  		string fileName;
  		cin >> fileName;
  		testFile.open(fileName,ios::in);
  		int fpCounter = 0;
	  	int fpCounter_sha = 0;
	  	int not_founds = 0;
	  	int not_founds_sha = 0;
	  	while(getline(testFile,line)){
			if(line != "\n" and line[0] != '#'){

		  		if(bf.find(line)){
		  			if(elements.find(line) == elements.end()){
						cout << "FALSE POSITIVE" << endl;
						++fpCounter;
					}
		  			else cout << line <<" is in the bloom filter." << endl;
		  		}
		  		else {
		  			cout << line <<"is not in the bloomfilter." << endl;
		  			not_founds++;
		  		}


		  		if(bfSHA.find(sha256(line))){
		  			if(elements.find(line) == elements.end()) {
		  				cout << "FALSE POSITIVE" << endl;
		  				++fpCounter_sha;
		  			}
		  			else cout << line <<" is in the SHA bloomfilter." << endl;
		  		}
		  		else{
		  		cout << line <<" is not in the SHA bloomfilter." << endl;
		  		not_founds_sha++;
		  		}
		  	}
	  	}

		bf.output();
		bfSHA.output();
		cout << "-------------------------------------------------------------------" << endl <<
				"False positives in the normie bloomfilter: " << fpCounter << endl <<
				"False positives in the CS theory (sha256) bloomfilter: " << fpCounter_sha << endl<<endl;
		cout << "Number of failed searches in the normie bloomfilter: " << not_founds << endl;		
		cout << "Number of failed searches in the CS theory (sha256) bloomfilter: " << not_founds_sha << endl
			 << "-------------------------------------------------------------------" << endl;		
		cout << "\nTest finalized. Enter the name of another test file to run another test,"
				<<"\nor press Ctrl + C to exit" << endl;
	}
}
