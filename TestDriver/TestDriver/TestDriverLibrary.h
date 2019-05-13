// TestDriverLibrary.h - contains declarations of test functions
#pragma once

#ifdef TESTDRIVERLIBRARY_EXPORTS
#define TESTDRIVERLIBRARY_API __declspec(dllexport)
#else
#define TESTDRIVERLIBRARY_API __declspec(dllimport)
#endif

#include<string>

//to test if the dll is working
extern "C" TESTDRIVERLIBRARY_API bool test();

extern "C" TESTDRIVERLIBRARY_API
bool testCallableObj(std::string content);