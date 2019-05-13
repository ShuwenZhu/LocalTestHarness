# Project #2 - Local Test Harness
[Project #2](https://ecs.syr.edu/faculty/fawcett/handouts/CSE687-OnLine/SynchronousLectures/Project2.htm) takes the project 1 test harness, and modifies it to take in an XML file. This XML file contains DLL names, which the harness dynamically loads and executes the embeded test function with the signature "bool Test()". 

## Authors
Shuwen Zhu, Kevin Wren

# How to Run
Using the git plugin in Visual Studio, pull the project down.
Then Build & Run the project! By default, the project will run the xml file "test1.xml" contained inside LocalTestHarness\xmlFiles\test1.xml. This test will run two valid DLLs and one invalid DLL to demonstrate our TestHarness.

## File Descriptions

### LocalTestHarness/main.cpp
This file is our main entry point into our harness. It instanstates the Logger and TestHarness, then reads in the XML passed in, and parses out the dll names. He then parses the dll names into the test harness, and prints the results of the test harness call.

### LocalTestHarness/Logger.cpp & Logger.h.
This is the logger package. The logger package works by takeing a log level (debug, info, warning, error, critical) and prints out messages at the passed in logging level as desired.

```	Logger log(info);
	log.Debug("This is an Debug level statement."); //Wont print
	log.Info("This is an info level statement.");
	log.Warning("This is an warning level statement.");
	log.Error("This is an error level statement.");
	log.Critical("This is an critical level statement.");
	```
	This allows us to have a standardized output for all of our printing.

### LocalTestHarness/TestHarness.cpp & TestHarness.h

This is the main Test Harness class. A test Harness is instanciate with a logger, and provides dynamical library loading and error checking while running the embded "Test()" function.

### DivideTestDll & LamdaTestDll
These are two DLLs we use to test our TestHarness. Our project builds them (doesnt link them) and then we load them explictely and execute the "Test()" function inside.

### XmlDocument/*
[XmlDocument is located here.](https://ecs.syr.edu/faculty/fawcett/handouts/CSE687-OnLine/Repository/XmlDocument/) It is a suite of tools written by professor Fawcett for creating, parsing and understanding XML. We use the XmlParser module to read and understand our xml file, then XmlDocument to parse through our created abstract syntax tree.

### Requirements
Your Local TestHarness Project:

    1. Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
    2. Shall use Visual Studio, Community Edition available at no cost.
    3. Shall provide packages for an Executive, TestHarness, Logger, and FileManager.
    4. Shall accept a TestRequest XML string defining one or more test elements. naming dynamic link libraries.
    5. Each test element shall contain a testDriver element and one or more testedCode elements, naming dynamic link libraries.
    6. TestDrivers shall implement an ITest interface1 that declares a test method taking no arguments and returning a boolean value indicating test pass or failure.
    7. The TestDriver library shall also define a factory method of creating instances of the test driver.
    8. On receiving a TestRequest, the TestHarness shall parse the request, load the corresponding libraries, sequentially create instances of each TestDriver using its factory method, and log pass-fail status of each test, along with a time-date stamp.
    9. Shall provide one or more TestRequests that conduct testing of at least three of your project packages.
    10. The Executive package shall provide processing to demonstrate that these requirements are met, by using facilities of the TestHarness.
