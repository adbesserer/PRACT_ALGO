#include "bloomfilter.hh"
#include <math.h>
#include <string>

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
	//std::string::size_type sz;
	int index = 0;
	double integralPart;
	for(int i = 1; i <= n_hashes; ++i){

		double doubleKey = keyToDouble(key);
		double valueOfA = (1.0/(n_hashes+1.0))*i;
		double fractionalPart = modf(doubleKey*valueOfA, &integralPart);
		long value = fractionalPart*pow(2, 32);

		cout << fractionalPart == 0.0 << endl;
		while(1);

		cout.precision(40);
		cout << fixed << "FP: " << fractionalPart << endl
		<< "doublekey: " << doubleKey << endl 
		<< "valueofa: " << valueOfA << endl
		<< "ip: " << integralPart << endl
		<< "MULT: " << (double)(doubleKey*valueOfA) << endl;

		while(1);
		//Tambien correcto
		//cout.precision(17);
		//cout << fixed << floatKey*valueOfA << "        " << aux << endl;

		//index += (int)floor((float)this->size*aux);
	}
	if(bf[index%size]) ++falsePositives;
	else this->bf[index%size]=true;
}
