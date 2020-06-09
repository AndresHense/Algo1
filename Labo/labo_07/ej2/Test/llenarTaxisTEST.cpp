#include "../llenarTaxis.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(llenarTaxis1Test,mismoValor){
	int g1=2,g2=2,g3=2;
	EXPECT_EQ(3,llenarTaxis1(g1,g2,g3));
}

TEST(llenarTaxis2Test,mismoValor){
	int g1=2,g2=2,g3=2;
	EXPECT_EQ(3,llenarTaxis2(g1,g2,g3));
}

TEST(llenarTaxis3Test,mismoValor){
	int g1=2,g2=2,g3=2;
	EXPECT_EQ(3,llenarTaxis3(g1,g2,g3));
}

TEST(llenarTaxis1Test,g2Par){
	int g1=1,g2=2,g3=1;
	EXPECT_EQ(2,llenarTaxis1(g1,g2,g3));
}

TEST(llenarTaxis2Test,g2par){
	int g1=1,g2=2,g3=1;
	EXPECT_EQ(2,llenarTaxis2(g1,g2,g3));
}

TEST(llenarTaxis3Test,g2Par){
	int g1=1,g2=2,g3=1;
	EXPECT_EQ(2,llenarTaxis3(g1,g2,g3));
}

TEST(llenarTaxis1Test,g2Impar){
	int g1=1,g2=3,g3=1;
	EXPECT_EQ(3,llenarTaxis1(g1,g2,g3));
}

TEST(llenarTaxis2Test,g2Impar){
	int g1=1,g2=3,g3=1;
	EXPECT_EQ(3,llenarTaxis2(g1,g2,g3));
}

TEST(llenarTaxis3Test,g2Impar){
	int g1=1,g2=3,g3=1;
	EXPECT_EQ(3,llenarTaxis3(g1,g2,g3));
}


