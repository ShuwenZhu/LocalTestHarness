#include <iostream>
#include <cstdarg>
#include <initializer_list>

#include <windows.h>

#include "TestHarness.h"
#include "Logger.h"

// Default constructor
TestHarness::TestHarness(Logger myLogger) {
	log = myLogger;
}

typedef void (*iTest)(void);
bool TestHarness::TestLibrary(::std::string libname) {
	log.Info("I got passed a value!");
	log.Info(libname);
	HINSTANCE hDLL;
	hDLL = LoadLibraryEx(libname.c_str(), NULL, NULL);
	if (hDLL != NULL) {
		log.Info("Yay Loaded a library");
		iTest myTest = (iTest)GetProcAddress(hDLL, "Test");

		if (myTest != NULL) {
			log.Info("Calling test function:");
			try {
				myTest();
			} catch (const char* msg) {
				log.Error("Caught an exception!");
				log.Error(msg);
			}
		} else {
			log.Error("Loaded in Library is missing test function");
		}
	} else {
		log.Error("Unable to load  passed in Library");
	}
	FreeLibrary(hDLL);         // Free the library
	return true;
}

// Destructor
TestHarness::~TestHarness() {};