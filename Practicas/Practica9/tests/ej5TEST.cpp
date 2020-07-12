#include "../src/ej5.h"
#include "gtest/gtest.h"
#include <string>


TEST(busquedaA, unElemento){
	std::vector<std::vector<int>> v = {{1,9,15,30,42},
									   {2,12,17,32,48},
									   {4,13,20,35,50},
									   {8,16,21,38,56},
									   {100,101,102,103,104}};
	int x = 16;
	int res =  busquedaA(v, x);
	ASSERT_EQ(1, res);
}

TEST(busquedaA, unElementoNoEsta){
	std::vector<std::vector<int>> v = {{1,9,15,30,42},
									   {2,12,17,32,48},
									   {4,13,20,35,50},
									   {8,16,21,38,56},
									   {100,101,102,103,104}};
	int x = 14;
	int res =  busquedaA(v, x);
	ASSERT_EQ(0, res);
}

TEST(busquedaB, unElemento){
	std::vector<std::vector<int>> v = {{1,9,15,30,42},
									   {2,12,17,32,48},
									   {4,13,20,35,50},
									   {8,16,21,38,56},
									   {100,101,102,103,104}};
	int x = 16;
	int res =  busquedaB(v, x);
	ASSERT_EQ(1, res);
}

TEST(busquedaB, unElementoNoEsta){
	std::vector<std::vector<int>> v = {{1,9,15,30,42},
									   {2,12,17,32,48},
									   {4,13,20,35,50},
									   {8,16,21,38,56},
									   {100,101,102,103,104}};
	int x = 14;
	int res =  busquedaB(v, x);
	ASSERT_EQ(0, res);
}

TEST(busquedaB, dosElementos){
	std::vector<std::vector<int>> v = {{1,9,15,30,42},
									   {2,12,17,32,48},
									   {4,13,20,35,50},
									   {8,16,21,38,56},
									   {9,16,102,103,104}};
	int x = 16;
	int res =  busquedaB(v, x);
	ASSERT_EQ(2, res);
}

