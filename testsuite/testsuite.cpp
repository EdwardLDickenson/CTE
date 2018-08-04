#include "testsuite.hpp"

//==============================================================================
//===	Implementation	========================================================
//==============================================================================

//------------------------------------------------------------------------------
//---	Test Group -------------------------------------------------------------
//------------------------------------------------------------------------------

testGroup::testGroup(string name)
{
	groupName = name;
	nfailed = 0;
	passedAllTests = true;
	executed = false;
}

size_t testGroup::getSize()
{
	return assertions.size();
}

size_t testGroup::nFailed()
{
	return nfailed;
}

size_t testGroup::nPassed()
{
	return assertions.size() - nfailed;
}

clock_t testGroup::getRuntime()
{
	if(!executed)
	{
		throw 1;
	}

	clock_t sum = 0;

	for(size_t i = 0; i < runtimes.size(); ++i)
	{
		sum += runtimes.at(i);
	}

	return sum;
}

string testGroup::getName()
{
	return groupName;
}

string testGroup::getReport()
{
	if(!executed)
	{
		throw 1;
	}

	if(passed())
	{
		return groupName + " passed all test";
	}

	string result = "";

	for(size_t i = 0; i < failedTests.size(); ++i)
	{
		result += "\"" + messages.at(failedTests.at(i)) + "\"," + to_string(double(runtimes.at(i)) / CLOCKS_PER_SEC) + "\n";
	}

	result += groupName + " failed to pass" + "," + to_string(double(getRuntime()) / CLOCKS_PER_SEC) + "\n";

	return result;
}

bool testGroup::passed()
{
	if(assertions.size() == 0)
	{
		throw 0;
	}

	if(!executed)
	{
		throw 1;
	}

	return passedAllTests;
}

bool testGroup::failed()
{
	if(assertions.size() == 0)
	{
		throw 0;
	}

	if(!executed)
	{
		throw 1;
	}

	return !passedAllTests;
}

void testGroup::run()
{
	executed = true;

	for(size_t i = 0; i < assertions.size(); ++i)
	{
		clock_t tmp = clock();

		if(!assertions[i]())
		{
			passedAllTests = false;
			failedTests.push_back(i);
			failedMessages.push_back(messages[i]);
			failedComparisons.push_back(comparisons[i]);
		}

		clock_t runtime = clock() - tmp;
		runtimes.push_back(runtime);
	}
}

vector<size_t> testGroup::getFailedIndicies()
{
	return failedTests;
}

vector<clock_t> testGroup::getTimes()
{
	return runtimes;
}

vector<string> testGroup::getFailedMessages()
{
	return failedMessages;
}

vector<string> testGroup::getFailedComparisons()
{
	return failedComparisons;
}

vector<string> testGroup::getComparisons()
{
	return comparisons;
}

//------------------------------------------------------------------------------
//---	Test Suite -------------------------------------------------------------
//------------------------------------------------------------------------------

testSuite::testSuite(string fname)
{
	output.open(fname.c_str());
}

void testSuite::setMessageList(vector<string> messages)
{
	messageList = messages;
}

void testSuite::addGroup(testGroup group)
{
	groups.push_back(group);
}

void testSuite::write()
{
	size_t testSum = 0;

	output << "Message,Number,Time,Comparison" << endl;

	for(size_t i = 0; i < groups.size(); ++i)
	{
		vector<string> messageList = groups[i].getFailedMessages();
		vector<string> comparisonList = groups[i].getFailedComparisons();

		//for(size_t j = 0; j < messageList.size(); ++j)
		//{
		//	cout << messageList[i] << endl;
		//	cout << comparisonList[i] << endl;
		//}

		for(size_t j = 0; j < messageList.size(); ++j)
		{
			//cout << groups[i].getComparisons()[j] << endl;
			//output << messageList[j] << "," <<  to_string((double(groups[i].getTimes()[j]) / CLOCKS_PER_SEC)) << "," << groups[i].getComparisons()[j] << "," << (groups[i].getFailedIndicies()[j] + testSum) << endl;
			output << messageList[j] << "," <<  to_string((double(groups[i].getTimes()[j]) / CLOCKS_PER_SEC)) << "," << comparisonList[j] << "," << (groups[i].getFailedIndicies()[j] + testSum) << endl;
		}

		if(messageList.size() == 0)
		{
			output << groups[i].getName() << " passed all " + to_string(groups[i].getSize()) + " tests" << endl;
		}

		else
		{
			output << groups[i].getName() << " failed to pass" << endl;
		}

		testSum += groups[i].getSize();
	}
}

void testSuite::run()
{
	for(size_t i = 0; i < groups.size(); ++i)
	{
		groups[i].run();
	}
}

void testSuite::run(size_t testNumber)
{

}

//	TODO:
//
//	Execution time for faiiled unit tests are slightly out of sync.
//
//	Run-time errors occurr
//
//	Static variables are causing issues in the error logging feature
//
//
