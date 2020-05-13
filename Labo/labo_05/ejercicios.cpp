#include "ejercicios.h"


// Ejercicio 1
bool existePico(vector<int> v){
	if(v.size()<3){
		cerr<<"Por lo menos 3 elementos tiene que haber."<<endl;
		return false;
	}
	bool res=false;
	for(int i=1;i<v.size()-1;i++){
		res |= (v[i]>v[i-1])&&(v[i]>v[i+1]);
	}
	return res;
}

// Ejercicio 2
int maximo(int x, int y){
  if(x<0)
    x=-x;
  if(y<0)
    y=-y;
  if(x>y)
    return x;
  else
    return y;
}

int minimo(int x, int y){
  if(x<0)
    x=-x;
  if(y<0)
    y=-y;
  if(x<y)
    return x;
  else
    return y;
}

int mcd(int m, int n){
  int a = maximo(m,n);
  int b = minimo(m,n);
  int resto;
  while((b!=0) && (b!=1)){
    resto = a%b;
    a = b;
    b = resto;
  }
  if(b==0)
    return a;
  else
    return 1;
 }


// Ejercicio 3
int indiceMinSubsec(vector<int> v, int l, int r){
	return 0;
}

// Ejercicio 4
void ordenar1(vector<int>& v){
	return;
}

// Ejercicio 5
void ordenar2(vector<int>& v){
	return;
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
	return make_tuple(0,0);
}
