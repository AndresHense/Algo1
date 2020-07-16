#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include <cmath>
#include "stdlib.h"
#include <string>
#include<iostream>
#include<algorithm>
using namespace std;

int busquedaBinaria(vector<int> v, int x){
	
	if(v.size()==0)return {};
	if(v.size()==1){
		return ((v[0]==x) ? 0 :-1);
	}
	//hay que asegurarse de q el elem pertenezca al intervalo de 
	//la lista?
	if(x == v[v.size()-1])
		return v.size()-1;

	int low=0;
	int high=v.size()-1;
	while(low+1<high && v[low] != x){
		int mid= (low+high)/2;

		if(v[0]<=v[v.size()-1]){
			(v[mid]<= x) ? low=mid : high=mid;
		}else{
			(v[mid]>= x) ? low=mid : high=mid;
		}
	}
	return ((v[low]==x) ? low :-1);
}

int busquedaJumpSearch(vector<int> v, int x){
	
	if(v.size()==0)return {};
	if(v.size()==1){
		return ((v[0]==x) ? 0 :-1);
	}
	if(v[0]<=v[v.size()-1]){
		if(x<v[0])
			return -1;
	}else{
		if(x>v[v.size()-1])
			return -1;
	}


	int m=sqrt(v.size());
	int i=0;
	while(i<v.size()){
		if(v[i]==x)
			return i;

		if(v[0]<=v[v.size()-1]){
			if(v[i]>x){
				i-=m;
				while(i<v.size()){
					if(v[i]==x)return i;
					i++;
				}
			}
		}else{
			if(v[i]<x){
				i-=m;
				while(i<v.size()){
					if(v[i]==x)return i;
					i++;
				}

			}
		}
		(i+m >v.size()-1)?i++:i+=m;
	}
	return -1;
}

int buscar(vector<int> v, int x){
	
    //return busquedaBinaria(v, x);
    return busquedaJumpSearch(v, x);
}


double ejemplo_como_calcular_tiempos() {
    clock_t begin = clock();

    for(int i=0 ; i < 100000; i++){
        // nada
    }

    clock_t end = clock();
    double elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en milisegundos
    return elapsed_msecs;
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}



int indicePico(vector<int> v){
	
	if(v.size()==0)return {};
	if(v.size()==1)return 0;
	if(v[0]>=v[1])return 0;

	for(int i=1;i<v.size()-1;i++){
		if(v[i-1]<= v[i] && v[i]>= v[i+1])
			return i;
	}
	if(v[v.size()-2] <= v[v.size()-1])return v[v.size()-1];
	return -1;
}

int puntoFijo(vector<int> v){
	
	if(v.size()==0)return -1;
	if(v.size()==1)return (v[0]==0)?0:-1;
	if(v[v.size()-1]==v.size()-1)return v.size()-1;

	int low=0;
	int high=v.size()-1;
	std::vector<int> res{};
	while(low<=high){
		int mid=low + (high-low)/2;

		if(v[low]==low)
			res.push_back(low);
		
		if(v[mid]<=low){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	if(res.size()==0)return -1;
	int min_res=res[0];
	for(int i=0;i<res.size();i++){
		std::cout<<"res["<<i<<"]: "<<res[i]<<", ";
		if(res[i]<min_res)min_res=res[i];
	}
	return min_res;

}

int encontrarRotado(vector<int> v, int x){
	int res=-1;
	for(int i=0;i<v.size();i++){
		if(v[i]==x)
			return i;
	}
	return -1;
}

int menorMasGrande(vector<int> v, int x){
	
	if(v.size()==0)return -1;
	if(x<=v[0])return 0;
	int low=1;
	int high=v.size()-1;
	
	while(low<=high){
		int m=(low+high)/2;

		if(v[low-1] <= x && v[low]>x)
			return low;
		if(v[m]<=x){
			low=m+1;
		}else{
			high=m-1;
		}
	}
	if(v[low-1] <= x && v[low]>x)
		return low;
	return -1;
}

vector<int> masCercanoK(vector<int> v, int k,  int x){
	return {};
}
