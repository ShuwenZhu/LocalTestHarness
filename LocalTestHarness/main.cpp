#include <iostream>
#include <initializer_list>
#include <functional>

#include "../XmlDocument/XmlParser/XmlParser.h"
#include "../XmlDocument/XmlElementParts/xmlElementParts.h"
#include "../XmlDocument/XmlDocument/XmlDocument.h"
#include "../XmlDocument/XmlElement/XmlElement.h"
#include "../XmlDocument/XmlElementParts/Tokenizer.h"

#include "DivideTest.h"
#include "TestHarness.h"
#include "Logger.h"

using sPtr = std::shared_ptr < XmlProcessing::AbstractXmlElement >;
//total number of testcase
const int TESTNUM = 5;

int main(void) {
	DivideTest myTest(0);
	Logger log(info);
	TestHarness harness(log);
	log.Debug("This is an Debug level statement.");
	log.Info("This is an info level statement.");
	log.Warning("This is an warning level statement.");
	log.Error("This is an error level statement.");
	log.Critical("This is an critical level statement.");

	bool result = false;
	log.Info("Calling our TestHarness with incrementing division failures: First should pass, the rest fail.");
	log.Info("============================================================================");
	for (int i = 0; i < TESTNUM; i++) {
		myTest.setValue(i);
		harness.testCallableObj(myTest);
	}
	log.Info("============================================================================");

	// Show Lamdas work as well
	std::function<int(void)> f1 = []() { return 1; };
	std::function<int(void)> f2 = []() { throw "Oh no! My lamda threw an exception!";  return 2; };
	log.Info("Calling our TestHarness with lamdas: First should pass, second should fail.");
	log.Info("============================================================================");
	result = harness.testCallableObj(f1);
	result = harness.testCallableObj(f2);
	log.Info("============================================================================");

	DivideTest t1(1);
	DivideTest t2(2);
	DivideTest t3(3);
	DivideTest t4(0);
	log.Info("Now calling our TestHanress with 4 Callable objects at once: 3 should pass, 1 should fail.");
	log.Info("============================================================================");
	result = harness.testCallableObjs({ t1, t2, t3, t4 });
	log.Info("============================================================================");
	// Now call on both lamdas!

	log.Info("Now calling our TestHanress with 2 lamdas: 1 should pass, 1 should fail.");
	log.Info("============================================================================");
	result = harness.testCallableObjs({ f1, f2 });
	log.Info("============================================================================");

	log.Info("Using the professors library to parse XML:");
	// Initial XML start
	std::string src = "../XmlDocument/XmlElementParts/LectureNote.xml";
	XmlProcessing::XmlParser parser(src);
	XmlProcessing::XmlDocument* pDoc = parser.buildDocument();
	log.Info("============================================================================");
	log.Info(pDoc->toString());
	log.Info("============================================================================");
	log.Info("Inspecting various elements:");
	log.Info("============================================================================");
	std::function<void(XmlProcessing::AbstractXmlElement&)> f;
	f = [](XmlProcessing::AbstractXmlElement & Elem) {
		if (Elem.tag().size() > 0)
			std::cout << "\n  " << Elem.value();
	};
	pDoc->DFS(pDoc->xmlRoot(), f);
	log.Info("============================================================================");
	std::string testTag = "title"; //Has an element
	//std::string testTag = "note";// Has nothing
	std::vector<sPtr> found = pDoc->element(testTag).descendents().select();
	if (found.size() > 0) {
		for (auto pElem : found) {
			std::cout << "My Elm:" << pElem -> toString() << "\n";
			std::cout << "My tag:" << pElem -> tag() << "\n";
			std::cout << "My val:" << pElem -> value() << "\n";
		}
	} else {
		std::cout << "\n  couldn't find " << testTag;
	}
	return 0;
}