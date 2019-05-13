// LambdaTestLibrary.cpp - Defines the exported functions for the DLL

#include "pch.h"
#include <functional>
#include "LambdaTestLibrary.h"


void test()
{
	//std::function<int(void)> f1 = []() { return 1; };
	std::function<int(void)> f2 = []() { throw "Oh no! My lamda threw an exception!";  return 2; };
	f2();
}