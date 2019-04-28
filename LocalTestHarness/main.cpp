#include <iostream>
#include <initializer_list>
#include <functional>
#include "DivideTest.h"
#include "TestHarness.h"


//total number of testcase
const int TESTNUM = 5;

int main(void) {
	TestHarness harness(2);
	DivideTest myTest(0);
	bool result = false;
	for (int i = 0; i < TESTNUM; i++) {
		myTest.setValue(i);
		harness.testCallableObj(myTest);
	}

	// Show Lamdas work as well
	std::function<int(void)> f1 = []() { return 1; };
	std::function<int(void)> f2 = []() { throw "Oh no! My lamda threw an exception!";  return 2; };
	result = harness.testCallableObj(f1);
	result = harness.testCallableObj(f2);

	DivideTest t1(1);
	DivideTest t2(2);
	DivideTest t3(3);
	DivideTest t4(0);
	result = harness.testCallableObjs({ t1, t2, t3, t4 });

	// Now call on both lamdas!
	result = harness.testCallableObjs({ f1, f2 });
	return 0;
}