// DivideTestLibrary.cpp : defines the exported functions for the DLL

#include "pch.h"
#include "DivideTestLibrary.h"
#include "DivideTest.h"

void test()
{
	DivideTest divideTest;
	divideTest.setValue(0);

	divideTest();
}