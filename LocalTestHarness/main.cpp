#include <iostream>
#include <initializer_list>
#include <functional>
#include <sstream>

// XML files from the professors library
#include "../XmlDocument/XmlParser/XmlParser.h"
#include "../XmlDocument/XmlElementParts/xmlElementParts.h"
#include "../XmlDocument/XmlDocument/XmlDocument.h"
#include "../XmlDocument/XmlElement/XmlElement.h"
#include "../XmlDocument/XmlElementParts/Tokenizer.h"

//Our own files
#include "TestHarness.h"
#include "Logger.h"

using sPtr = std::shared_ptr < XmlProcessing::AbstractXmlElement >;

int main(void) {


	// Start the logger and harness
	Logger log(info);
	TestHarness harness(log);

	log.Debug("This is an Debug level statement.");
	log.Info("This is an info level statement.");
	log.Warning("This is an warning level statement.");
	log.Error("This is an error level statement.");
	log.Critical("This is an critical level statement.");

	// This is where our test xml file is.
	std::string src = "../LocalTestHarness/xmlFiles/test1.xml";

	log.Info("Using the professors library to parse XML:");

	// Instansiate xml parser, parse our xml to a file
	XmlProcessing::XmlParser parser(src);
	XmlProcessing::XmlDocument* pDoc = parser.buildDocument();

	// Find all children of "TestRequest", which should be "test" elements with DLL names inside.
	std::string testTag = "TestRequest";
	std::vector<sPtr> found = pDoc->element(testTag).descendents().select();
	std::ostringstream os;
	if (found.size() > 0) {
		for (auto pElem : found) {
			// "test" are the outside containers of our dll names. Skip em.
			if (pElem->value() == "test") {continue;}
			os.str("");
			os << "Dynamically loading and evalutating the dll named: --" << pElem->value() <<  "--.";
			log.Info("============================================================================");
			log.Info(os.str());
			// Here is where we call our harness on a DLL name. Harness will load the DLL, then execute the itest function
			//      inside the DLL. Should return us pass/fail here!
			log.Info("============================================================================");
		}
	} else {
		os.str("");
		os << "No element called " << testTag << " found.";
		log.Critical(os.str());
	}

	log.Info("All done!");

	system("pause");
	return 0;
}