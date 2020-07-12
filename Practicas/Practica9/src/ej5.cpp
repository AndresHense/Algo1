#include<vector>


//a)
//pre: todas las filas tienen el mismo largo
//hay una sola aparicion(devuelve 1 o 0)
//esta ordenado de forma creciente las filas y columnas

int busquedaA(std::vector<std::vector<int>> v,int x){
	int i=0,j=v[0].size()-1;
	while(i<v.size() && j>=0){
		if(v[i][j]==x)
			return 1;
		(v[i][j]>x)? j-- : i++;
	}	
	return 0;
}

//b)
int busquedaB(std::vector<std::vector<int>> v,int x){
	int res=0;
	int i=0,j=v[0].size()-1;
	while(i<v.size() && j>=0){
		if(v[i][j]==x){
			res++;i++;
			while(i<v.size() && v[i][j]==x){
				res++;
				i++;
			}
			break;
		}
			
		(v[i][j]>x)? j-- : i++;
	}	
	return res;
}


