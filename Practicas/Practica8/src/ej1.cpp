int ultimo1(vector<int> &v){	
	return v[v.size()-1];		//3 
}										//t(n)=3 -> O(1)

int ultimo2(vector<int> &v){
	int i=v.size();				//2 
	return v[i-1];					//3 
}										//t(n)=5 -> O(1)

int ultimo3(vector<int> &v){	//v.size()=n
	int i=0;						//1
	while(i<v.size()){		//3, n iteraciones 
		i++;						//1 
	}								//t(n)= 3+4n
	return v[i-1];				//3 
}									//t(n)= 4n +7 -> O(n)