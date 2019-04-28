#include <iostream>
#include <cstdarg>
#include <initializer_list>
#include "TestHarness.h"


// Default constructor
TestHarness::TestHarness() {
	logLevel = 0;
}

// Constructor
TestHarness::TestHarness(int level) {
	logLevel = level;
}

// Destructor
TestHarness::~TestHarness() {};