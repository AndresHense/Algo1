int sumarPotenciaHasta(int n) {
	int res = 0;		//1
	int x = log(n-1)-log(2);			//O(1)
	res=pow(2,x-1)-1;					//O(1)					
	return res;			//1
}							//t(n)= 1+O(1)+O(1)  -> O(1)