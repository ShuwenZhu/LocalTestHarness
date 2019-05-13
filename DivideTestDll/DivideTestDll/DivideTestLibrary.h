// DivideTestLirbary.h - Contains declarations of DivideTest
#pragma once


#ifdef DIVIDETESTLIBRARY_EXPORTS
#define DIVIDETESTLIBRARY_API __declspec(dllexport)
#else
#define DIVIDETESTLIBRARY_API __declspec(dllimport)
#endif

extern "C" DIVIDETESTLIBRARY_API void test();