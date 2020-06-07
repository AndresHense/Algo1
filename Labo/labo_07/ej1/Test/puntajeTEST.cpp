#include "../puntaje.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(puntajeTest,menorA10){
	int n=3;
	int res=puntaje(n);
	EXPECT_EQ(res,16);
}

TEST(puntajeTest,mayorA10){
	int n=13;
	int res=puntaje(n);
	EXPECT_EQ(res,3);
}


