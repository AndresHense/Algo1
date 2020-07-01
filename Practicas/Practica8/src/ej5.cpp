vector<int> hacerAlgo(vector<int> &v) {	//|v|=n
	vector<int> res;	//1
	for (int i = 0; i < 100; i++) {		//init: 1, guarda: 2, incremento: 1, 100 iteraciones
		res.push_back(contarApariciones(v, i+1));	//4+5+9n
	}		//t(n)=4+(3+9+9n)*100
	return res; // copia el vector
}		//t(n)=125+900n	 -> O(n)

int contarApariciones(vector<int> &v, int elem) {
	int cantAp = 0;		//1
	for (int i = 0; i < v.size(); i++) {//init: 1, guarda: 3, incremento: 1, n iteraciones
		if (v[i] == elem) {	//4
			cantAp++;		//1
		}		
	}			//t(n)=4+ (4+5)n
}		//t(n)=5+9n	->O(n)