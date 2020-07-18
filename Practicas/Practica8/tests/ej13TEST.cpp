#include "../src/ej13.h"
#include "gtest/gtest.h"

TEST(ej13, elDelAyudante){
	std::vector<std::vector<int>> v =
	{
	{1,2,1},
	{1,10,1},
	{10,10,1}
	};
	
	int res=minimoCosto2(v);
	ASSERT_EQ(6,res);
}


TEST(ej13, elDeVicky){
	std::vector<std::vector<int>> v =
	{
	{6,3,1},
	{0,5,7},
	{10,3,2}
	};
	
	int res=minimoCosto2(v);
	ASSERT_EQ(16,res);
}


TEST(ej13, elDeVicky2){
	std::vector<std::vector<int>> v =
	{
	{6,3,1},
	{0,5,7},
	{2,3,2}
	};
	
	int res=minimoCosto2(v);
	ASSERT_EQ(13,res);
}