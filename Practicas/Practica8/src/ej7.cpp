int sumarPotenciaHasta(int n) {
	int res = 0;		//1
	int i = 1;			//1
	while(i < n) {		//3, n iteraciones
		res = res + i;		//3
		i = i * 2;			//3
	}						//t(n)=3+9n
	return res;			//1
}							//t(n)= 6+9n  -> O(n)