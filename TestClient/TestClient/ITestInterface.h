#pragma once
#include <Windows.h>
#include <iostream>

/* Define a function pointer for our imported
 * function.
 * This reads as "introduce the new type f_funci as the type:
 *                pointer to a function returning an int and
 *                taking no arguments.
 *
 * Make sure to use matching calling convention (__cdecl, __stdcall, ...)
 * with the exported function. __stdcall is the convention used by the WinAPI
 */
typedef int(__stdcall* f_funci)();

class ITestInterface
{
public:
	virtual bool test() = 0;
};

class DivideTestDriver : public ITestInterface
{
public:
	bool test()
	{
		HINSTANCE hGetProcIDDLL = LoadLibraryA("..\\..\\DivideTestDll\\Debug\\DivideTestDll.dll");

		if (!hGetProcIDDLL)
		{
			std::cout << "cannot find file\n";
			return EXIT_FAILURE;
		}

		f_funci funci = (f_funci)GetProcAddress(hGetProcIDDLL, "test");

		try
		{
			funci();
		}
		catch (const char* msg) {
			std::string str(msg);
			std::cout << "\tCaught Exception: " << str<< std::endl;
			return false;
		}
		return true;
	}
};

class LambdaTestDriver : public ITestInterface
{
public:
	bool test()
	{
		HINSTANCE hGetProcIDDLL2 = LoadLibraryA("..\\..\\LambdaTestDll\\Debug\\LambdaTestDll.dll");

		if (!hGetProcIDDLL2)
		{
			std::cout << "cannot find file\n";
			return EXIT_FAILURE;
		}

		f_funci funci2 = (f_funci)GetProcAddress(hGetProcIDDLL2, "test");

		if (!funci2) {
			std::cout << "could not locate the function" << std::endl;
			return EXIT_FAILURE;
		}

		try
		{
			funci2();
		}
		catch (const char* msg) {
			std::string str(msg);
			std::cout << "\tCaught Exception: " << str << std::endl;
			return false;
		}
		return true;
	}
};