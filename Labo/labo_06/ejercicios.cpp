#include "ejercicios.h"

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
	
	vector<vector<int> > res;

	for(unsigned int i=0;i<u.size();i++){
			std::vector<int> temp;
			res.push_back(temp);
		for (unsigned int j = 0; j < v.size(); j++){
			res[i].push_back(u[i]*v[j]);
		}
	}
	
	return res;
}

void swp(vector<vector<int> > &m,int i, int j, const vector<vector<int> > &v){
	m[i][j]=v[j][i];
}

void trasponer(vector<vector<int> > &m) {
	const std::vector<std::vector<int> > v=m;

	for(unsigned int i=0;i<m.size();i++){
			
		for (unsigned int j = 0; j < m[i].size(); j++){
			swp(m,i,j,v);
		}
	}
	return;
}

std::vector<int> productoUnoAUno(std::vector<int> m1,std::vector<int> m2){
	std::vector<int> res;
	for (unsigned int i = 0; i < m1.size(); i++){
		res.push_back(m1[i]*m2[i]);
	}
	return res;
}

int sumaV(const vector<int> &m){
	int sum=0;
	for (unsigned int j = 0; j < m.size(); j++){
			sum+=m[j];
		}
	return sum;
}

vector<vector<int> > reflejar(vector<vector<int> > &m) {
	const std::vector<std::vector<int> > v=m;

	vector<vector<int> > res;
	//cout<<"Quiero yo que el length sea: "<<m[0].size()<<endl;
	for(unsigned int i=0;i<m[0].size();i++){
		std::vector<int> temp;
		res.push_back(temp);
		for (unsigned int j = 0; j < m.size(); j++){
			//cout<<m[j][i]<<", ";
			res[i].push_back(m[j][i]);

		}
		//cout<<endl;
	}
	return res;
}

vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
	std::vector<vector<int>> transM2=reflejar(m2);

	std::vector<vector<int>> res;
	for(unsigned int i=0;i<m1.size();i++){	
		std::vector<int> temp;
		res.push_back(temp);	
		for (unsigned int j = 0; j < transM2.size(); j++){
			if(m1[i].size()!=transM2[j].size())
				cout<<"Apa, no tienen los mismos long"<<endl;
			res[i].push_back(sumaV(productoUnoAUno(m1[i],transM2[j])));
		}
	}

	return res;
}

void imprimirMatriz(const vector<vector<int>> &m){
	cout<<"\n\n{\n";
	for(unsigned int i=0;i<m.size();i++){
		for(unsigned int j=0;j<m[0].size();j++){
			cout<<m[i][j]<<", ";
		}
		cout<<endl;
	}
	cout<<"}\n\n";
}

int sumaVecinosLinea(int i,int j,const vector<vector<int>> &m,int &cantVecinos){
	int longM=m.size();
	int longMi=m[i].size();
	if(i<0 || i>=longM)
		return 0;
	else{
		int suma=0;
		int tope=j+3;
		for(int k=j;k<tope;k++){
			if(k<0 || k>=longMi){
				;
			}else{
				suma+=m[i][k];
				cantVecinos++;
			}
		}
		return suma;
	}
}

vector<vector<int> > promediar(vector<vector<int> > m){
	vector<vector<int> > res;
	int longM=m.size();
	int longMi=m[0].size();
	for (int i=0;i<longM;i++){
		vector<int> temp;
		res.push_back(temp);
		for(int j=0;j<longMi;j++){
			int lugar=0;
			int cantVecinos=0;
			lugar+=sumaVecinosLinea(i-1,j-1,m,cantVecinos);
			lugar+=sumaVecinosLinea(i,j-1,m,cantVecinos);
			lugar+=sumaVecinosLinea(i+1,j-1,m,cantVecinos);
			res[i].push_back(lugar/cantVecinos);
		}
	}
	//imprimirMatriz(m);
	//imprimirMatriz(res);
	return res;

}


bool mayorQueVecinosLinea(int i,int j,const vector<vector<int>> &m,const int u,const int l){
	int longM=m.size();
	int longMi=m[i].size();
	if(i<0 || i>=longM)
		return true;
	else{
		bool res=true;
		int tope=j+3;
		for(int k=j;k<tope;k++){
			if(k<0 || k>=longMi || (i==u &&k==l)){
				;
			}else{
				res&=m[u][l]>m[i][k];
				
			}
		}
		return res;
	}
}

int contarPicos(vector<vector<int> > m){
	int res=0;
	int longM=m.size();
	int longMi=m[0].size();
	for (int i=0;i<longM;i++){
		for(int j=0;j<longMi;j++){
			bool lugar=true;
			lugar&=mayorQueVecinosLinea(i-1,j-1,m,i,j);
			lugar&=mayorQueVecinosLinea(i,j-1,m,i,j);
			lugar&=mayorQueVecinosLinea(i+1,j-1,m,i,j);
			if(lugar)
				res++;
		}
	}
	//imprimirMatriz(m);
	//imprimirMatriz(res);
	return res;

}

bool esTriangularInferior(const vector<vector<int> >& m){
	bool res=true;
	for(unsigned int i=0;i<m.size();i++){
		for(unsigned int j=0;j<m[0].size();j++){
			if(i>j)
				res&=m[i][j]==0;
		}
	}
	return res;
}

bool esTriangular(vector<vector<int> > m){
	bool res=true;
	//cout<<"La matriz "<<endl;
	//imprimirMatriz(m);

	res&=esTriangularInferior(m);
	//cout<<"es "<<((res==true) ?"verdadero":"false")<<" que es triangular"<<endl;
	trasponer(m);
	//imprimirMatriz(m);
	res|=esTriangularInferior(m);
	//cout<<"es "<<((res==true) ?"verdadero":"false")<<" que es triangular"<<endl;
	return res;
}

bool hayAmenaza(vector<vector<int> > m){
	//COMPLETAR
	m.clear();
	return true;
}

int diferenciaDiagonales(vector<vector<int> > m) {
    //COMPLETAR
    m.clear();
    return 0;
}
