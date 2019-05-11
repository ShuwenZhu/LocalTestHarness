#ifndef _DIVIDETEST_H_
#define _DIVIDETEST_H_

#include <iostream>

class DivideTest {
	int dividend = 30; // Hard-coded dividend number
	int divisor;
public:
	void setValue(int x);
	int getValue();
	DivideTest(int a);
	int operator () ();
};

#endif // !_DIVIDETEST_H_
