#include "ej13.h"

int minimoCosto(vector<vector<int>> m){ // |m| = n
 
    vector<vector<int>> aux{{m[0][0]}};
    int sumFilaPrimera=m[0][0];
    int sumColPrimera=m[0][0];
    for(int i=1;i<m[0].size();i++){
    	sumFilaPrimera+=m[0][i];
    	aux[0].push_back(sumFilaPrimera);
    }
    for(int i=1;i<m.size();i++){
    	sumColPrimera+=m[i][0];
    	aux[i].push_back(sumColPrimera);
    }
    
    for(int i=1;i<m.size();i++){
    	for(int j=1;j<m[0].size();j++){
    		if(aux[i-1][j]>aux[i][j-1])
    			aux[i].push_back(m[i][j]+aux[i][j-1]);
    		else
    			aux[i].push_back(m[i][j]+aux[i-1][j]);
    	}
    }
    int n=m.size();
    return aux[n][n];
}

int minimoCosto2(vector<vector<int>> m){
    vector<vector<int>> copia = m;
    int f = 0;
    int c = 0;
    while(f < m.size() - 1){
        f++;
        copia[f][c] = copia[f][c] + copia[f-1][c];
    }
    f = 0;
    while(c < m.size() - 1){
        c++;
        copia[f][c] = copia[f][c] + copia[f][c-1];
    }
    for(int i = 1; i < m.size(); i++){
        for(int j = 1; j < m.size(); j++){
            if(copia[i-1][j] < copia[i][j-1]){
                copia[i][j] = copia[i][j] + copia[i-1][j];
            } else {
                copia[i][j] = copia[i][j] + copia[i][j-1];
            }
        }
    }
    return copia[m.size() - 1][m.size() - 1];
}