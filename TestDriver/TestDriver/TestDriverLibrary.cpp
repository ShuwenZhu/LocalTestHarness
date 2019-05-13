// TestDriverLibrary.cpp: Defines the exported functions for the DLL

#include "pch.h"
#include "TestDriverLibrary.h"
#include "CallableTest.h"

//to test if the dll is working (not needed now) keep it until  the final version :)
bool test()
{
	return true;
}


//for single object call:
bool testCallableObj(std::string content)
{
	//unpack xml string to extract the callable object
		//callable obj type
		//logging level

	//test with logging num = 0 level = info;

	//declear releated callable obj
	DivideTestDriver dtestDriver;

	//run test
	bool result = dtestDriver.testDriver(0, info);

	//if we want another kind of callable objects, we need to:
	//1. include callable type header file in callableTest.h
	//2. declear a new child class of CallableTest class, 
	//3. implement virtual method testDriver(int, int log level) in the new class


	//return running result
	return result;
}

//for mutiple object calls:
//I have not find an ideal way to implement it. If you can make the xml
//into a linked list or a vector, I might be able to work on that part
