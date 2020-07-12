#include<iostream>

//Pre n>=0
int raizA(int n){
	
	int i=0;
	while(i*i<n){
		i++;
	}
	if(i*i==n)return i;
	return i-1;
}

int raizB(int n){
	if(n==1)
		return n;
	int low=0;
	int high=n;

	while(low+1<high && low*low<n){
		int mid=(low+high)/2;
		if(mid*mid<=n){
			low=mid;
		}else{
			high=mid;
		}
	}
	
	return low;
}

int main(){
	std::cout<<"La raiz entera de 11 es: "<<raizA(11)<<std::endl;
	std::cout<<"La raiz entera de 11 es: "<<raizB(11)<<std::endl;
	std::cout<<"La raiz entera de 9 es: "<<raizA(9)<<std::endl;
	std::cout<<"La raiz entera de 9 es: "<<raizB(9)<<std::endl;
	std::cout<<"La raiz entera de 8 es: "<<raizA(8)<<std::endl;
	std::cout<<"La raiz entera de 8 es: "<<raizB(8)<<std::endl;
	std::cout<<"La raiz entera de 7 es: "<<raizA(7)<<std::endl;
	std::cout<<"La raiz entera de 7 es: "<<raizB(7)<<std::endl;
	std::cout<<"La raiz entera de 5 es: "<<raizA(5)<<std::endl;
	std::cout<<"La raiz entera de 5 es: "<<raizB(5)<<std::endl;
	std::cout<<"La raiz entera de 1 es: "<<raizA(1)<<std::endl;
	std::cout<<"La raiz entera de 1 es: "<<raizB(1)<<std::endl;
	std::cout<<"La raiz entera de 0 es: "<<raizA(0)<<std::endl;
	std::cout<<"La raiz entera de 0 es: "<<raizB(0)<<std::endl;
	
	return 0;
}
