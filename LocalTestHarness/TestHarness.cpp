#include <iostream>
#include <cstdarg>
#include <initializer_list>
#include "TestHarness.h"
#include "Logger.h"

// Default constructor
TestHarness::TestHarness(Logger myLogger) {
	log = myLogger;
}

// Destructor
TestHarness::~TestHarness() {};