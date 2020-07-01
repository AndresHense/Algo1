int mesetaMasLarga(vector<int> &v) {	//|v|=n
	int i = 0;					//1
	int maxMeseta = 0;		//1
	int meseta;					//1
	while (i < v.size()) {	//3, n iteraciones
		int j = i + 1;				//3
		while (j < v.size() && v[i] == v[j]) {	//9, n-j iteraciones
			j++;						//1
		}							//t(n)= 9+10(n-j) ESTE J ME HACE RUIDO AAAAH
		meseta = j - i;		//3
		i = j;					//1
		if (meseta > maxMeseta) {	//3
			maxMeseta = meseta;			//1
		}
	}					//t(n)=3+ (3+9+10(n-j)+3+1+3+1)n
	return maxMeseta;
}					//t(n)=3+3+20n+10n(n-j) 