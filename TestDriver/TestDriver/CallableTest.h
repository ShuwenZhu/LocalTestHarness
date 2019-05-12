#pragma once
#ifndef CALLABLETEST_H
#define CALLABLETEST_H

#include "DivideTest.h"
#include "TestHarness.h"

class CallableTest
{
public:
	CallableTest() {}
	virtual bool testDriver(int num, int logLvl) = 0;
};

class DivideTestDriver :public CallableTest
{
	DivideTest dtest;
public:
	DivideTestDriver() {}
	bool testDriver(int num, int logLvl)
	{
		TestHarness testh(logLvl);
		dtest.setValue(num);
		bool result = testh.testCallableObj(dtest);
		return result;
	}
};

#endif