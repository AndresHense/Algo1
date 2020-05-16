#include "ejercicios.h"


// Ejercicio 1
bool existePico(vector<int> v){
	int longi=v.size();
	if(v.size()<3){
		cerr<<"Por lo menos 3 elementos tiene que haber."<<endl;
		return false;
	}
	bool res=false;
	for(int i=1;i<longi-1;i++){
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
	int res=l;
	for(int i=l;i<=r;i++){
		if(v[i]<=v[res])
			res=i;
	}
	return res;
}

// Ejercicio 4

vector<int> ordenarUltimo(vector<int> v, int n){
	vector<int> res;
	for(unsigned int i=0;i<v.size();i++){
		if(v[i]>=n)
			res.push_back(n);
		else
			res.push_back(v[i]);
	}
	return res;
}
void ordenar1(vector<int>& v){
	vector<int> v2=v;
	for(unsigned int i=0;i<v.size();i++){
		vector<int> temp;
		if(i==0)
			temp.push_back(v[0]);

		bool metioAi=false;
		for(unsigned int j=0;j<i;j++){
			if(v2[j]>=v2[i]&&!metioAi){
				temp.push_back(v2[i]);
				temp.push_back(v2[j]);
				metioAi=true;
			}
			else if(!metioAi&&j==i-1){
				temp.push_back(v2[j]);
				temp.push_back(v2[i]);
			}
			else
				temp.push_back(v2[j]);
		}
		v2.clear();
		for(unsigned int k=0;k<v.size();k++){
			if(k<=i)
				v2.push_back(temp[k]);
			else
				v2.push_back(v[k]);
		}
	}
	v=v2;
	return;
}

// Ejercicio 5
void ordenar2(vector<int>& v){
	ordenar1(v);
	return;
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
	tuple<int,int> fwe =make_tuple(n,d);
	int i=get<0>(fwe);
	i++;
	return make_tuple(0,0);
}
