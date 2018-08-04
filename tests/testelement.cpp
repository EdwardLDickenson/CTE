#include "testelement.hpp"

bool testElement(testGroup &elementgroup)
{
	Element empty;

	Assert<string> testempty("Content of Element is unexpectedly non-empty for an empty constructor", empty.getContent(), "");
	testempty.equal();
	elementgroup.addAssertion(testempty);

	Assert<string> testemptytype("Type of Element is unexpectedly non-empty for an empty constructor", empty.getContent(), "");
	testemptytype.equal();
	elementgroup.addAssertion(testemptytype);

	Assert<string> testemptyid("Id of Element is unexpectedly non-empty for an empty constructor", empty.getId(), "");
	testemptyid.equal();
	elementgroup.addAssertion(testemptyid);

	Assert<string> testemptyclass("CSS Class of Element is unexpectedly non-empty for an empty constructor", empty.getClass(), "");
	testemptyclass.equal();
	elementgroup.addAssertion(testemptyclass);

	Assert<int> testEmptyListSize("Length of Element list is incorrect for an empty constructor", 0, empty.getElements().size());
	testEmptyListSize.equal();
	elementgroup.addAssertion(testEmptyListSize);

	Assert<bool> testEmptyHasAttributes("Element unexpectedly has attributes for an empty constructor", false, empty.hasAttributes());
	testEmptyHasAttributes.equal();
	elementgroup.addAssertion(testEmptyHasAttributes);

	Assert<string> testEmptyFormattedAttributes("Formatted Attribute list for Element is non-empty for an empty constructor", "", empty.getFormattedAttributes());
	testEmptyFormattedAttributes.equal();
	elementgroup.addAssertion(testEmptyFormattedAttributes);

	//	Testsuite does not like to use the std::list type for formatted output(expected/unexpecetd results)
	//Assert<list<string>> testEmptyAttributes("Size of Attribute list for Element is unexpectedly non-zero for an empty constructor", 0, empty.getAttributes().size());
	//testEmptyAttributes.equal();
	//elementgroup.addAssertion(testEmptyAttributes);

	Text words("This is a test of the Element class");
	empty.setElement(words);

	Assert<string> testsetwords("Element content is incorrect after setting an empty element with a Text class", empty.getContent(), words.getContent());
	testsetwords.equal();
	elementgroup.addAssertion(testsetwords);

	Assert<string> typestillblank("Element type is unexectedly non-empty after setting an empty element with a Text class", empty.getType(), "");
	typestillblank.equal();
	elementgroup.addAssertion(typestillblank);

	Assert<string> testnoid("Element id is unexpectedly non-empty after setting an empty element with a Text class", empty.getId(), "");
	testnoid.equal();
	elementgroup.addAssertion(testnoid);

	Assert<string> testnoclass("Element CSS Class is unexpectedly non-empty after passing a Text class to Element", empty.getClass(), "");
	testnoclass.equal();
	elementgroup.addAssertion(testnoclass);
	
	Assert<bool> testdoesnothaveattributes("Element unexpectedly claims to have attributes after assigning a Text class to the element", false, empty.hasAttributes());
	testdoesnothaveattributes.equal();
	elementgroup.addAssertion(testdoesnothaveattributes);
	
	empty.setType("Made up type");
	Assert<string> testmadeuptype("Element type is incorrect after setting it to an nonsense type(expected to get nonsense)", empty.getType(), "Made up type");
	testmadeuptype.equal();
	elementgroup.addAssertion(testmadeuptype);

	Element copy(empty);

	Assert<string> testcopycontent("Content of Element is incorrect for a copy constructor of a well-formatted Element", empty.getContent(), copy.getContent());
	testcopycontent.equal();
	elementgroup.addAssertion(testcopycontent);
	
	Assert<string> testcopytype("Type of Element is incorrect for a copy constructor of a well-formatted Element", empty.getType(), copy.getType());
	testcopytype.equal();
	elementgroup.addAssertion(testcopytype);

	Assert<string> testcopyid("Id of Element is unexpectedly non-empty for a copy constructor of a well formatted Element", copy.getId(), empty.getId());
	testcopyid.equal();
	elementgroup.addAssertion(testcopyid);

	Assert<string> testcopyclass("CSS Class of Element is unexpectedly non-empty for a constructor of a well formatted Element", copy.getClass(), empty.getClass());
	testcopyclass.equal();
	elementgroup.addAssertion(testcopyclass);

	Assert<bool> testcopyhasattributes("Element class unexpectedly claims to have attributes for a constructor of a well formatted Element", copy.hasAttributes(), empty.hasAttributes());
	testcopyhasattributes.equal();
	elementgroup.addAssertion(testcopyhasattributes);

	Assert<string> testcopyformat("Formatted attribute list of Element is incorrect for copy constructor of well formatted Element", copy.getFormattedAttributes(), empty.getFormattedAttributes());
	testcopyformat.equal();
	elementgroup.addAssertion(testcopyformat);

	return true;

	/*bool result = true;
	Element empty;

	if(empty.getContent() != "")
	{
		string errmsg = "Element constructor failed to initialize content properly";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getType() != "")
	{
		string errmsg = "Empty Element constructor failed to initialize type properly";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getId() != "")
	{
		string errmsg = "Empty Element constructir failed to initialize id properly";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getClass() != "")
	{
		string errmsg = "Empty Element constructor failed to initialize class properly";
		logError(errmsg, output);

		result = false;
	}

	Text words("This is a test");
	empty.setElement(words);

	//	This should really machine generated. Also there should be differences between a variable content test and a machine generated one
	if(empty.getContent() != words.getContent())
	{
		string errmsg = "setElement failed to set the proper content";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getElements().size() != 1)
	{
		string errmsg = "getElements failed to return a list of the approppriate size";
		logError(errmsg, output);

		result = false;
	}

	empty.setType("Made up type");
	if(empty.getType() != "Made up type")
	{
		string errmsg = "Element failed to set type";
		logError(errmsg, output);

		result = false;
	}

	return result;*/
}



//	TODO:
//
//
//
