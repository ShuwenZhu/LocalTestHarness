// DivideTestLibrary.cpp : defines the exported functions for the DLL

#include "pch.h"
#include "DivideTestLibrary.h"
#include "DivideTest.h"


void Test(void) {
	DivideTest divideTest;
	divideTest.setValue(0);

	divideTest();
}