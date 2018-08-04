#include "deps.hpp"
#include "cte.hpp"

//	NOT included in the main project, only in the test suite
#include "tests/errornumbers.hpp"
#include "tests/units.hpp"
#include "testsuite/testsuite.hpp"

int main(int argc, char *argv[])
{
	cout << "===\tStarting Units\t===" << endl;

	testSuite cte("units.csv");

	testGroup textGroup("Text class");
	testGroup elementGroup("Element class");
	testGroup spanGroup("Span class");
    testGroup paragraphGroup("Paragraph group");

	testText(textGroup);
	testElement(elementGroup);
	testSpan(spanGroup);
    testParagraph(paragraphGroup);

	textGroup.run();
	elementGroup.run();
    spanGroup.run();
    paragraphGroup.run();

	cte.addGroup(textGroup);
	cte.addGroup(elementGroup);
	cte.addGroup(spanGroup);
    cte.addGroup(paragraphGroup);

	cte.write();

	/*ofstream output("units.csv");
	output << "Message" << ", " << "Number" << ", " << "Time" << endl;

	if(testText(output))
	{
		output << "textElement class passed all tests" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	else
	{
		output << "textElement class failed to pass" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	if(testElement(output))
	{
		output << "Element class passed all tests" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	else
	{
		output << "Element class failed to pass" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	if(testSpan(output))
	{
		output << "Span class passed all tests" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	else
	{
		output << "Span class failed to pass" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	if(testParagraph(output))
	{
		output << "Paragraph class passed all tests" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	else
	{
		output << "Paragraph class failed to pass" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	if(testPage(output))
	{
		output << "Page class passed all tests" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	else
	{
		output << "Page class failed to pass" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	if(testDiv(output))
	{
		output << "Div class passed all tests" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	else
	{
		output << "Div class failed to pass" << "," << "0" << "," << (double(clock()) / CLOCKS_PER_SEC) << endl;
	}

	output.close();*/

	cout << "===\tEnding Units\t===" << endl;

	return 0;
}



//	TODO:
//
//	HTML elements should have their own class, and it probably makes sense to develop a class heiarchy, and let them interact with the page class through a
//	wrapper class, pageElement?, which is probably also templatized.  The element class would probably also be responsible for mananging element data like
//	ID and possibly also be responsible for opening/closing tags as well depending on how the element heiarchy is implemented
//
//	C Template Engine.
//	Should probably be CPPTE (Or something better)
//
//	Text element
//
//	Since classes now extend the Element class, unit should be written to test that the behavior is properly extended.
//
//	Refer back to the PGE project and implement something similar to the Unit class here.
//	Should be able to encapsulate most of the boilerplate code in the unit tests and also keep track of infomation like number of tests and number failed.
//
//	This file should use the standard
//
//



/*
	testSuite cte("units.csv");

	testGroup div;
	cte.addGroup(div);

	Assert equals<string>("==", "==");
	equals.assertEquals();

	div.addAssert(equals);

	cte.run();
*/



//  TODO:
//  Probably going to need some kind of string processing library including
//  substring matching
//
//
//
//
