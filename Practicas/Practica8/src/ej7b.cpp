int sumarPotenciaHasta(int n) {
	int res = 0;		//1
	int x = 0;			//1
	while(pow(2,x) < n) {		//3, log(n) iteraciones		//3
		x++;			//1
	}						//t(n)=3+4log(n)
	return pow(2,x-1)-1;			//1
}							//t(n)= 6+4log(n)  -> O(log(n))