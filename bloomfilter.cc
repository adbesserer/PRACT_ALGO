#include "bloomfilter.hh"

bloomfilter::bloomfilter(int size, int n_hashes){
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
	this->falsePositives = 0;
}

void bloomfilter::output(){
	cout << bf[0];
	for(int i=1; i<bf.size(); ++i) cout << " " << bf[i];
	cout << endl;
}

void bloomfilter::add(string key){
	//aqui ha de pasar todos los hashes
	int m=size;
	for(int i = 0; i!= n_hashes;++i){
		int aux = string2num(key)%m;
		if(bf[aux]) ++falsePositives;
		else this->bf[aux]=true;
	}
}
