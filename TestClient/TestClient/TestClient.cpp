// TestClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>
#include "ITestInterface.h"

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

int main()
{

	DivideTestDriver dtestDriver;
	if (dtestDriver.test())
		std::cout << "Passed\n";
	else
		std::cout << "Failed\n";

	LambdaTestDriver ltestDriver;
	if (ltestDriver.test())
		std::cout << "Passed\n";
	else
		std::cout << "Failed\n";


	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
