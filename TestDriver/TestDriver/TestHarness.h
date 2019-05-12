#pragma once
#ifndef TESTHARNESS_H
#define TESTHARNESS_H

#include <initializer_list>
#include <iostream>
#include <cstdarg>
#include "Logger.h"

class TestHarness {
private:
	Logger logger;

	//Exec method!
	template <class CallObj>
	bool execObj(CallObj& obj) {
		try {
			obj();
		}
		catch (const char* msg) {
			std::string str(msg);
			logger.Critical("\tCaught Exception: " + str);
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
	TestHarness() { }

	TestHarness(int level)
	{
		logger.setLogLevel(level);
	}

	template <class CallObj>
	inline bool testCallableObjs(std::initializer_list<CallObj> objs) {
		
		std::cout << "***********************************************************\n";
		//std::cout << "[" << currentDateTime() << "] ";
		logger.Info("Now calling with multiple object calls:");
		std::cout << "***********************************************************\n";
		
		bool result = execObjs(objs);
		if (result)
			//std::cout << "Passed\n";
			logger.Debug("Passed\n");
		else
			//std::cout << "Failed\n";
			logger.Debug("Failed\n");
		std::cout << "================================================\n";
		return result;
	}

	template <class CallObj>
	inline bool testCallableObj(CallObj& Objpointer) {

		std::cout << "================================================\n";
		//std::cout << "[" << currentDateTime() << "] ";
		logger.Info("Calling execObj");
		
		bool result = execObj(Objpointer);
		//std::cout << "\tResult: --" << result << "--\n";
		if (result)
			//std::cout << "Passed\n";
			logger.Debug("Passed\n");
		else
			//std::cout << "Failed\n";
			logger.Debug("Failed\n");
		std::cout << "================================================\n";
		return result;
	}

	//destructor
	~TestHarness() {}

};

#endif