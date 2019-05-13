#pragma once
#ifndef TESTHARNESS_H
#define TESTHARNESS_H

#include <initializer_list>
#include "Logger.h"

class TestHarness {
private:
	int logLevel; // 0 = Only pass/no pass; 1 = 0 + show exception message; 2 = 1 + time tag with running details
	Logger log; //Logger package
	//Exec method!
	template <class CallObj>
	bool execObj(CallObj& obj) {
		try {
			obj();
		}
		catch (const char* msg) {
			log.Error("Caught Exception: " + std::string(msg));
			return false;
		}
		return true;
	}

	template <class CallObj>
	bool execObjs(std::initializer_list<CallObj> objs) {
		bool result = true;
		for (auto elem : objs) {
			if (!this->testCallableObj(elem)) {
				result = false;
			}
		}
		return result;
	}

public:
	TestHarness(Logger myLogger);
	template <class CallObj>
	inline bool testCallableObjs(std::initializer_list<CallObj> objs) {
		log.Debug("testCallableObjs: Calling execObjs");
		bool result = execObjs(objs);
		if (result)
			log.Info("Test Passeed");
		else
			log.Info("Test Failed");
		return result;
	}

	template <class CallObj>
	inline bool testCallableObj(CallObj& Objpointer) {
		log.Debug("testCallableObj: Calling execObj");
		bool result = execObj(Objpointer);
		if (result)
			log.Info("Test Passeed");
		else
			log.Info("Test Failed");
		return result;
	}

	//destructor
	~TestHarness();
};

#endif