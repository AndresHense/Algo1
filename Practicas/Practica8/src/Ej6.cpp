bool f(vector<float> s) {
	float p;				//1
	float res = 0;		//1
	for (int i = 0; i < s.size(); i++) {	//init: 1, guarda: 3, incremento: 1, n iteraciones
		p = g(h(s, i)));		//1+(10+11w)(6+8i)???????
		if (p > res) {			//3
			res = p;				//2
		}
	}						//t(n)= 4+
	return res;			//1
}							//t(n)=

float g(vector<float> v) {
	float p = 1;		//1
	for (int i = 0; i < v.size(); i++) {	//init: 1, guarda: 3, incremento: 1, n iteraciones
		p = p * v[i];			//4
	}						//t(n)=4+8n
	return p;			//1
}							//t(n)=6+8n	-> O(n)


//Item 2:
// Pre: n <= v.size()
vector<float> h(vector<float> w, int n) {
	vector<float> res;		//1
	int i = 0;					//1
	while (i < n && w[i] > 0) {	//7, n iteraciones
		res.push_back(w[i]);		//3
		i++;							//1
	}								//7+11n
	return res;					//1
}									//t(n)=10 + 11n	-> O(n)