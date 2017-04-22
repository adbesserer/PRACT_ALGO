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
	int sum = 0;
	cout << bf[0];
	sum += bf[0];
	for(int i=1; i<bf.size(); ++i) {
		cout << " " << bf[i];
		sum+=bf[i];
	}
	cout << endl;
	cout << "False Positives: " << this->falsePositives << endl;
	cout << "nª de unos xdlol: " << sum << endl;
}

void bloomfilter::add_mul(string key){
	cout.precision(10);
	for(long i = 1; i<=n_hashes; ++i){
		mpf_t K;
		mpf_init(K);
		mpf_set_str (K, key.c_str(), 36);
		
		mpf_set_default_prec(128);
		mpf_t A,fracPart,one,n,aux,hashval;
		mpf_inits(A,fracPart,one,n,aux,hashval,NULL); //n = i en formato mpf
		
		mpf_set_ui(n,i);
		mpf_set_si(A,(long)n_hashes);
		mpf_set_ui(one,1);

		mpf_add(A,A,one);//A = A+1
		mpf_div(A,one,A); //A = 1/A
		mpf_mul(A,A,n); //A = A*i
		cout << "A: " << mpf_get_d(A)<<endl;
		mpf_mul(aux,K,A); // aux = K*A
		mpf_set(fracPart,aux); // fracPart = aux
		mpf_floor(aux,aux); // aux = floor(aux)
		cout << "floor: " << mpf_get_d(aux);
		mpf_sub(fracPart, fracPart, aux); //fracpart = parte fraccional de K*A

		cout << "integral: " << mpf_get_d(aux)<< endl;
		cout << "fract: " << mpf_get_d(fracPart)<< endl;

		mpf_set_ui(aux,pow(i,9));
		mpf_mul(hashval,fracPart, aux); // hashval= fracpart * 2^32
		mpf_floor(hashval,hashval);

		mpz_t result;
		mpz_init(result);
		mpz_set_f(result,hashval);
		mpz_mod_ui(result,result,(long)size);

		unsigned long casilla = mpz_get_ui(result);

		cout << "result: " << casilla << endl;

		if(bf[casilla])++falsePositives;
		bf[casilla]=true;

		mpf_clear(aux);
		mpf_clear(A);
		mpf_clear(n);
		mpf_clear(one);
		mpf_clear(K);
		mpf_clear(hashval);
		mpf_clear(fracPart);
	}

}

bool isPrime(int n){
	for(int i = 2; i<=sqrt(n); ++i) if(!(n%i)) return false;
	return true;
}

vector<int> takeNprimes(int n){
	int index = 0;
	int i = 2;
	vector<int> v(n);
	while(index != n){
		if(isPrime(i)){
			v[index] = i;
			++index;
		}
		++i;
	}
	return v;
}

void bloomfilter::add_div(string key){
	double doubleKey = keyToDouble(key);
	for(int i=0; i<n_hashes; ++i){
		int prime = this->primes[i];
		int index = (int)fmod(fmod(doubleKey, prime), bf.size());
		//cout << "aqui!  " << index << "   " << prime << endl;
		if(bf[index]) ++falsePositives;
		else bf[index] = true;
	}
}
