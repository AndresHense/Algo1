int mesetaMasLarga(vector<int> &v) {	//|v|=n
	int i = 0;					//1
	int maxMeseta = 0;		//1
	int meseta;					//1
	while (i < v.size()) {	//3, n iteraciones
		int j = i + 1;				//3
		while (j < v.size() && v[i] == v[j]) {	//9, n-i-1 iteraciones
			j++;						//1
		}							//t(n)= 9+10(n-i-1) 
		meseta = j - i;		//3
		i = j;					//1
		if (meseta > maxMeseta) {	//3
			maxMeseta = meseta;			//1
		}
	}					//t(n)=3+ 8n+ suma(i=0,n-1)(9+10(n-i-1))
	return maxMeseta;			//1
}					//t(n)=7+17n+10n^2 -n -n(n-1)/2 -> O(n^2) 