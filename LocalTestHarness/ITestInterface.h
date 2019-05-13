#pragma once
#include <Windows.h>
#include <iostream>
#include "Logger.h"

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
protected:
	Logger log; //passed from TestHarness.cpp to record dll running process
	bool result = false; //to record dll running result
public:
	void set_logger (Logger _log) { log = _log; }
	virtual bool test() = 0;
};

class DivideTestDriver : public ITestInterface
{
public:
	bool test()
	{
		HINSTANCE hGetProcIDDLL = LoadLibraryA("DivideTestDll.dll");

		if (!hGetProcIDDLL)
		{
			log.Error("Library -- DivideTestDll.dll -- was unable to be loaded");
			return EXIT_FAILURE;
		}

		log.Debug("Library -- DivideTestDll.dll -- correctly loaded. Extracting Test()...");
		f_funci funci = (f_funci)GetProcAddress(hGetProcIDDLL, "Test");

		if (funci != NULL)
		{
			log.Debug("TestHarness::TestLibrary: Calling extracted Test() function:");
			try
			{
				result = funci();
			}
			catch (const char* msg) {
				log.Error("Caught an exception!");
				log.Error(msg);
				return false;
			}
			return result;
		}
		log.Debug("Library -- DivideTestDll.dll -- has no Test() function");
		return false;
	}
};

class LambdaTestDriver : public ITestInterface
{
public:
	bool test()
	{
		HINSTANCE hGetProcIDDLL2 = LoadLibraryA("LambdaTestDll.dll");

		if (!hGetProcIDDLL2)
		{
			log.Error("Library -- LambdaTestDll.dll -- was unable to be loaded");
			return EXIT_FAILURE;
		}

		log.Debug("Library -- LambdaTestDll.dll -- correctly loaded. Extracting Test()...");
		f_funci funci2 = (f_funci)GetProcAddress(hGetProcIDDLL2, "Test");

		if (funci2 != NULL)
		{
			log.Debug("TestHarness::TestLibrary: Calling extracted Test() function:");
			try
			{
				result = funci2();
			}
			catch (const char* msg) {
				log.Error("Caught an exception!");
				log.Error(msg);
				return false;
			}
			return result;
		}
		log.Debug("Library -- LambdaTestDll.dll -- has no Test() function");
		return false;
	}
};