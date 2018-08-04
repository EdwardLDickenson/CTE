#ifndef TESTSUITE_HPP
#define TESTSUITE_HPP

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <functional>
#include <time.h>
#include <limits.h>
#include <sstream>
#include <stdlib.h>

using namespace std;

//==============================================================================
//===	Definition	============================================================
//==============================================================================

template<class T> class Assert
{
private:

	T a;
	T b;
	bool canCompare;
	char compareType;
	string errmsg;

public:

	Assert(string msg, T x, T y);

	void equal();
	void unequal();

	bool passed();
	bool failed();
	bool getResult();
	char getType();

	string getMessage();
	string getComparison();
	T getA();
	T getB();
};

class testGroup
{
private:
	vector<function<bool()>> assertions;
	vector<string> messages;
	vector<size_t> failedTests;
	vector<clock_t> runtimes;
	vector<string> failedMessages;
	vector<string> failedComparisons;
	vector<string> comparisons;
	string groupName;
	size_t nfailed;
	bool passedAllTests;
	bool executed;

public:
	testGroup(string name);

	size_t getSize();
	size_t nFailed();
	size_t nPassed();
	string getName();
	string getReport();
	clock_t getRuntime();

	template<class T> void addAssertion(Assert<T> assertion);
	void run();

	bool passed();
	bool failed();

	vector<clock_t> getTimes();
	vector<string> getFailedMessages();
	vector<size_t> getFailedIndicies();
	vector<string> getFailedComparisons();
	vector<string> getComparisons();
};

class testSuite
{
private:
	vector<testGroup> groups;
	vector<string> messageList;
	string fname;
	ofstream output;

public:
	testSuite(string fname);

	void setMessageList(vector<string> messages);
	void addGroup(testGroup group);
	void run();
	void run(size_t testNumber);
	void write();
};

//------------------------------------------------------------------------------
//---	Assert	----------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T> Assert<T>::Assert(string msg, T x, T y)
{
	canCompare = false;
	compareType = '?';
	errmsg = msg;

	a = x;
	b = y;
}

template<class T> void Assert<T>::equal()
{
	compareType = '=';
	canCompare = true;
}

template<class T> void Assert<T>::unequal()
{
	compareType = '!';
	canCompare = true;
}

template<class T> bool Assert<T>::getResult()
{
	if(compareType == '=')
	{
		return a == b;
	}

	if(compareType == '!')
	{
		return a != b;
	}
}

template<class T> bool Assert<T>::passed()
{
	if(!canCompare)
	{
		throw 0;
	}

	return false;
}

template<class T> bool Assert<T>::failed()
{
	if(!canCompare)
	{
		throw 0;
	}

	return true;
}

template<class T> string Assert<T>::getMessage()
{
	return errmsg;
}

template<class T> char Assert<T>::getType()
{
	if(!canCompare)
	{
		throw 0;
	}

	return compareType;
}

template<class T> string Assert<T>::getComparison()
{
	stringstream result;

	//cout << a << endl;

	result << "(\"";
	result << a;
	result << "\"";
	result << compareType;
	result << "\"";
	result << b;
	result << "\")";

	return result.str();;
}

template<class T> T Assert<T>::getA()
{
	if(!canCompare)
	{
		throw 0;
	}

	return a;
}

template<class T> T Assert<T>::getB()
{
	if(!canCompare)
	{
		throw 0;
	}

	return b;
}

//------------------------------------------------------------------------------
//---	Test Group -------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T> void testGroup::addAssertion(Assert<T> assertion)
{
	T a = assertion.getA();
	T b = assertion.getB();

	vector<function<bool(T, T)>> test;

	if(assertion.getType() == '=')
	{
		function<bool()> func = [=](){
			return a == b;
		};

		assertions.push_back(func);
		//messages.push_back(assertion.getMessage());
		//comparisons.push_back(assertion.getComparison());
	}

	else if(assertion.getType() == '!')
	{
		function<bool()> func = [=](){
			return a == b;
		};

		assertions.push_back(func);
		//messages.push_back(assertion.getMessage());
		//comparisons.push_back(assertion.getComparison());
	}

	//cout << assertion.getComparison() << endl;
	messages.push_back(assertion.getMessage());
	comparisons.push_back(assertion.getComparison());
}

#endif	//	TESTSUITE_HPP


//	TODO:
//
//	Tried to do lazy evaluation with some function pointer/functional magic but unfortunatly that's nearly impossible or actually impossible with templated functions
//	Definitely a bullet point in the future iterations, but currently unfeasible
//
//	When a test group fails the report does not explain how many units passed.  This is a bug
//
//
