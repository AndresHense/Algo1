void f1(vector<int> &vec){		//v.size()=n
	i=vec.size()/2;				//3
	while(i>=0){					//2, n/2 iteraciones
		vec[vec.size()/2-i]=i;		//6
		vec[vec.size()/2+i]=i;		//6
		i--;								//1
	}									//t(n)=2+ 7n
}										//t(n)=5+7n -> O(n)

//	pre:	|vec|>20000
void f2(vector<int> &vec){
	i=0;								//3
	while(i<10000){				//2, n/2 iteraciones
		vec[vec.size()/2-i]=i;		//6
		vec[vec.size()/2+i]=i;		//6
		i++;								//1
	}									//t(n)=2+7n
}										//t(n)=5+7n -> O(n)

// pre: e pertenece a v1
int f3(vector<int> &v1, int e){
	int i = 0;					//1
	while (v1[i] != e){		//4, n iteraciones
		i++;							//1
	}								//t(n)=4+5n
	return i ;					//1
}									//t(n)=6+5n -> O(n)

void f4(vector<int> &vec){
	int rec = 0;					//1
	int max_iter = 1000;			//1
	if (max_iter > vec.size()){	//3
		max_iter = vec.size();	//3
	}						

	for(int i=0; i < max_iter; i++){	//init: 1, guarda: 3, incremento: 1, max_iter iteraciones
		for(int j=0; j < max_iter; j++){	//init: 1, guarda: 3, incremento: 1, max_iter iteraciones
			res += vec[i] * vec[j];				//7
		}											//t(n)=4+11n
	}											//t(n)=4+(4+4+11n)n
}										//t(n)=12+8n+11n^2 -> O(n^2)

void f5(vector<int> &v1, vector<int> &v2){//|v1|=n |v2|=m
	vector<int> res(v1.size()+v2.size(),0);	//4
	// inicializa vector en O(|a|+|b|)
	for(int i=0; i < v1.size(); i ++){		//init: 1, guarda: 3, incremento: 1, n iteraciones
		res[i]=v1[i]; 							// 4			
	}										//t(n)=4+8n
	for(int i=0; i < v2.size(); i ++){		//init: 1, guarda: 3, incremento: 1, m iteraciones
		res[v1.size()+i]=v2[i];				 // 7
	}									//t(n)=4+11n
	return;								//0
}								//t(n)=4+4+4+0+8n+11n -> O(n)