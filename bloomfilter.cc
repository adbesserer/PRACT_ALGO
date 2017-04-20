#include "bloomfilter.hh"
#include <math.h>

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
	cout << "False Positives: " << this->falsePositives << endl;
}

void bloomfilter::add(string key){
	//aqui ha de pasar todos los hashes
	int m=size;
	double integral;
	int index = 0;
	for(int i = 1; i <= n_hashes;++i){
		float floatKey = stringToNum(key);
		float valueOfA = (1.0/(((float)this->n_hashes)+1.0))*i;

		//Son valores correctos tanto floatKey como valueOfA
		//cout.precision(17);
		//cout << fixed << floatKey << "           " << valueOfA << endl;
		
		float aux = modf(floatKey*valueOfA, &integral);

		//Tambien correcto
		//cout.precision(17);
		//cout << fixed << floatKey*valueOfA << "        " << aux << endl;

		index += (int)floor((float)this->size*aux);
	}
	if(bf[index%size]) ++falsePositives;
	else this->bf[index%size]=true;
}
