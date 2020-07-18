#include <iostream>
#include "gtest/gtest.h"
#include "ej13.h"

int main(int argc, char **argv) {
    std::cout << "Implementando GTest!!" << std::endl;
    testing::InitGoogleTest(&argc, argv);

	//std::vector<int> v=construir_vector(100000,"asc");

	//clock_t begin=clock();
	//int res=buscar(v,v[v.size()-2]);
	//clock_t end=clock();
	//double eltm=double(end-begin)/CLOCKS_PER_SEC * 1000;
	//std::cout<<"El tiempo de busqueda es de: "<<eltm<<"ms"<<std::endl;
    return RUN_ALL_TESTS();
	//return 0;
}
