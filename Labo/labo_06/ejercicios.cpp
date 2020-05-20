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

vector<vector<int> > promediar(vector<vector<int> > m){
	//COMPLETAR
	m.clear();
	vector<vector<int> > res;
	return res;
}

int contarPicos(vector<vector<int> > m){
	//COMPLETAR
	m.clear();
	return true;
}

bool esTriangular(vector<vector<int> > m){
	//COMPLETAR
	m.clear();
	return true;
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