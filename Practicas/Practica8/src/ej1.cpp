int ultimo1(vector<int> &v){	
	return v[v.size()-1];		//4 op
}										//total 4

int ultimo2(vector<int> &v){
	int i=v.size();				//3 op
	return v[i-1];					//3 op
}										//total 6

int ultimo3(vector<int> &v){	//v.size()=n
	int i=0;					//2 op
	while(i<v.size()){	//2 op 
		i++;					//2 op
	}							//4n op
	return v[i-1];			//3 op
}								//total 4n +5