#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

vector<string> split(string s, char delim){
	vector<string> v;
	string temp{};
	for(int i=0;i<s.size();i++){
		if(s[i]!=delim)
			temp+=s[i];
		else{
			if(temp.size()!=0)
				v.push_back(temp);
			temp="";
		}
	}
	if(temp.size()!=0)
		v.push_back(temp);
	return v;
}

string darVueltaPalabra(string s){
	string res{};
	vector<string> palabras=split(s,' ');
	if(palabras.size()==0)return "";
	if(palabras.size()==1)return palabras[0];
	res+=palabras[palabras.size()-1];
	for(int i=palabras.size()-2;i>=0;i--){
		res+=' '+palabras[i];
	}
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
	int cont = 0;
	for(int i=0;i<s2.size();i++){
		if(s2[i]==s1[cont]&& cont<s1.size())
			cont++;
	}
	return cont==s1.size();
}

bool estaEn(char c,vector<pair<char,int>> const &V){
	bool res=false;
	for(int i=0;i<V.size();i++){
		res|=V[i].first==c;
	}
	return res;
}
int encuentraIndice(char c,vector<pair<char,int>> const &V){
	int res=-1;
	for(int i=0;i<V.size();i++){
		if(c==V[i].first)
			res=i;
	}
	return res;
}
vector<pair<char,int>> generaBanderitas(string const &s){
	vector<pair<char,int>> sV{};
	for(int i=0;i<s.size();i++){
		if(estaEn(s[i],sV))
			sV[encuentraIndice(s[i],sV)].second++;
		else
			sV.push_back(make_pair(s[i],1));
	}
	return sV;
}
bool mismaCantidadDeCaracteres(vector<pair<char,int>> const &s,vector<pair<char,int>> const &r){
	bool res=true;
	for(int i=0;i<s.size();i++){
		int k=encuentraIndice(s[i].first,r);
		if(k==-1)
			res=false;
		else
			res &= s[i].second==r[k].second;
	}
	return res;
}
bool esAnagramaDe(string const &s,string const &r){
	bool res=true;
	vector<pair<char,int>> sV=generaBanderitas(s);
	vector<pair<char,int>> rV=generaBanderitas(r);
	res &= sV.size()==rV.size();
	res &= mismaCantidadDeCaracteres(sV,rV);
	return res;
}
int esAnagramaEn(string const &s, vector<vector<string>> const &res){
	for(int i=0;i<res.size();i++){
		if (esAnagramaDe(s,res[i][0]))
			return i;
	}
	return -1;
}
void insertarEnSuAnagrama(string const &s, vector<vector<string>> &res,int k){
	res[k].push_back(s);
}
// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string> > res;
	if(v.size()==0)return {};
	res.push_back({v[0]});
	for(int i=1;i<v.size();i++){
		int k=esAnagramaEn(v[i],res);
		if(k!=-1)
			insertarEnSuAnagrama(v[i],res,k);
		else{
			vector<string> temp{v[i]};
			res.push_back(temp);
		}
	}
	return res;
}

bool esPalindromo(string s){
	bool cumple = true;
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		cumple &= s[i]==s[j];
	}
	return cumple;
}

bool tieneRepetidos(string s){
	bool apareceUnaVez = true;
	vector<pair<char,int>> sV=generaBanderitas(s);
	for(int i=0;i<sV.size();i++){
		apareceUnaVez &= sV[i].second==1;
	}
	return !apareceUnaVez;
}

string rotar(string s, int j){
	string res(s);
	for(int i=0;i<j;i++){
		auto it=res.begin();
		res.insert(it,res[res.size()-1]);
		res.pop_back();
	}
	return res;
}

// no se puede usar substring
string darVueltaK(string s, int k){
	string res="";
	string temp="";
	for(int i=0,j=0;i<s.size();i++,j++){
		temp+=s[i];
		if(j==k-1){
			res+=rotar(temp,k);
			j=0;
			temp="";
		}
	}
	if((float)s.size()/k!=0){
		string temp="";
		for(int i=s.size()-k;i<s.size();i++)	
			temp+=s[i];
		res+=rotar(temp,k);
	}
	return res;
}

string abueloLaino(string s){
    string res;
    return res;
}

int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

int middleOut(string s, string t){

    return 0;
}
