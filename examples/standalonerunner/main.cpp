// From the wild: https://github.com/gordonwatts/cppunit.nuget/issues/1

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestListener.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/Outputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class BlaTest : public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE(BlaTest);
	CPPUNIT_TEST(test);
	CPPUNIT_TEST_SUITE_END();

public:

	BlaTest() {}
	virtual ~BlaTest() {}

	virtual void test()
	{
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION(BlaTest);

int main(int argc, char **argv)
{

	bool wasSuccessful = false;
#ifdef BREAKS
	std::auto_ptr<CppUnit::TestListener> listener(new CppUnit::BriefTestProgressListener);

	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());

	// Shows a message as each test starts
	if (listener.get() != NULL)
	{
		runner.eventManager().addListener(listener.get());
	}

	wasSuccessful = runner.run("", false);
	return !wasSuccessful;
#else
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	// Adds the test to the list of test to run
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);

	// Run the test.
	bool wasSucessful = runner.run();

	// Return error code 1 if the one of test failed.
	return wasSucessful ? 0 : 1;
#endif
}
