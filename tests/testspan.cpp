#include "testspan.hpp"

bool testSpan(testGroup &spanGroup)
{
	Span empty;
	Text spanText("Inside of the span");

	Assert<string> testempty("Content of Span is unexpectedly non-empty for an empty constructor", empty.getContent(), "");
	testempty.equal();
	spanGroup.addAssertion(testempty);

    Assert<string> testtype("Type of Span is not equal to span", empty.getType(), "span");
	testtype.equal();
	spanGroup.addAssertion(testtype);

	Assert<string> testClass("CSS Class of Span was unexpectedly non-empty", empty.getClass(), "");
	testClass.equal();
	spanGroup.addAssertion(testClass);

	Assert<string> testId("Id of Span is unexpectedly non-empty", empty.getId(), "");
	testId.equal();
	spanGroup.addAssertion(testId);

	empty.addElement(spanText);

	Assert<string> testAddedContentType("Type of Span is incorrect after appending a text element", "span", empty.getType());
	testAddedContentType.equal();
	spanGroup.addAssertion(testAddedContentType);

	Assert<string> testAddedContent("Content of Span is not correct after appending a text element", "<" + empty.getType() + ">" + spanText.getContent() + "</" + empty.getType() + ">", empty.getContent());
	testAddedContent.equal();
	spanGroup.addAssertion(testAddedContent);

	Assert<string> testAddContentClass("CSS Class of Span is incorrect after appending a text element", "", empty.getClass());
	testAddContentClass.equal();
	spanGroup.addAssertion(testAddContentClass);

	Assert<string> testAddContentId("Id of Span is incorrect after appending a text element", "", empty.getId());
	testAddContentId.equal();
	spanGroup.addAssertion(testAddContentId);

	Text recursiveText("<span>Inside of a recursive span</span>");

	Span recursive;
	recursive.addElement(recursiveText);

	Assert<string> testRecursiveType("Type of Span is incorrect for a recursive definition", "span", recursive.getType());
	testRecursiveType.equal();
	spanGroup.addAssertion(testRecursiveType);

	Assert<string> testRecursiveContent("Content of Span is incorrect for a recursive Span (Span tags for inside of text)", recursive.getContent(), "<" + recursive.getType() + ">" + "&#60;span&#62;Inside of a recursive span&#60;&#47;span&#62;" + "</" + recursive.getType() + ">");
	testRecursiveContent.equal();
	spanGroup.addAssertion(testRecursiveContent);

	Assert<string> testRecursiveClass("CSS Class of Span is unexpectedly non-empty for a recursive Span", "", recursive.getClass());
	testRecursiveClass.equal();
	spanGroup.addAssertion(testRecursiveClass);

	Assert<string> testRecursiveId("Id of Span is unexpectedly non-empty for a recursive Span", "", recursive.getId());
	testRecursiveId.equal();
	spanGroup.addAssertion(testRecursiveId);

	Span param(spanText);

	Assert<string> testParamType("Type of Span is incorrect for a parameterized constructor", "span", param.getType());
	testParamType.equal();
	spanGroup.addAssertion(testParamType);

	Assert<string> testParamClass("CSS Class of Span is unexpectedly non-empty for a parameterized constructor", "", param.getClass());
	testParamClass.equal();
	spanGroup.addAssertion(testParamClass);

	Assert<string> testParamId("Id of Span is unexpectedly non-empty for a parameterized constructor", "", param.getId());
	testParamId.equal();
	spanGroup.addAssertion(testParamId);

	Assert<string> testParamContent("Content of Span is incorrect for a parameterized constructor", "<" + param.getType() + ">" + spanText.getContent() + "</" + param.getType() + ">", param.getContent());
	testParamContent.equal();
	spanGroup.addAssertion(testParamContent);

	Span copy(param);

	Assert<string> testCopyType("Type of Span is incorrect for a copy constructor", "span", copy.getType());
	testCopyType.equal();
	spanGroup.addAssertion(testCopyType);

	Assert<string> testCopyId("Id of Span is incorrect for a copy constructor", "", copy.getId());
	testCopyId.equal();
	spanGroup.addAssertion(testCopyId);

	Assert<string> testCopyClass("CSS Class of Span is incorrect for a copy constructor", "", copy.getClass());
	testCopyClass.equal();
	spanGroup.addAssertion(testCopyClass);
    
	Assert<string> testCopyContent("Content of Span is incorrect for a copy constructor", copy.getContent(), "<" + copy.getType() + ">" + spanText.getContent() + "</" + copy.getType() + ">");
	testCopyContent.equal();
	spanGroup.addAssertion(testCopyContent);

	return true;

	/*bool result = true;

	Text spannedText("This text is in a span element");
	Span empty;
	Element tmp;

	tmp.setElement(spannedText);

	if(empty.getContent() != "")
	{
		string errmsg = "Content of Span was improperly initialized for empty constructor";
		logError(errmsg, output);
		cout << empty.getContent() << endl;

		result = false;
	}

	if(empty.getType() != "span")
	{
		string errmsg = "Type of Span was improperly initialized for empty constructor";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getClass() != "")
	{
		string errmsg = "CSS Class of Span was improperly initialized for empty constructor";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getId() != "")
	{
		string errmsg = "Id of Span was improperly initialized for empty constructor";
		logError(errmsg, output);

		result = false;
	}

	empty.addElement(tmp);
	if(empty.getContent() != "<" + empty.getType() + ">" + spannedText.getContent() + "</" + empty.getType() + ">")
	{
		string errmsg = "Content of Span was improperly formatted after adding element";
		logError(errmsg, output);

		result = false;
	}

	//	Results should be exactly the same as above
	Span param(tmp);
	if(param.getType() != "span")
	{
		string errmsg = "Type for parameterized Span was improperly initialized";
		logError(errmsg, output);

		result = false;
	}

	if(param.getContent() != "<" + empty.getType() + ">" + spannedText.getContent() + "</" + empty.getType() + ">")
	{
		string errmsg = "Content for parameterized Span was improperly initialized";
		logError(errmsg, output);

		result = false;
	}

	if(param.getClass() != "")
	{
		string errmsg = "CSS Class for parameterized Span was improperly initialized";
		logError(errmsg, output);

		result = false;
	}

	if(param.getId() != "")
	{
		string errmsg = "Id for parameterized Span was improperly initialized";
		logError(errmsg, output);

		result = false;
	}

	Text anotherText("Simply another span");
	Element another;
	another.setElement(anotherText);

	list<Element> tmpList;
	tmpList.push_back(tmp);
	tmpList.push_back(another);
	
	//	Unit test is wrongly conceptualized. Reevaluate
	Span paramList(tmpList);

	if(paramList.getContent() != "<" + empty.getType() + ">" + tmp.getContent() + another.getContent() + "</" + empty.getType() + ">")
	{
		string errmsg = "Content for parameterized list Span was improperly initialized";
		logError(errmsg, output);
		cout << paramList.getContent() << endl;
		cout << "<" + empty.getType() + ">" + tmp.getContent() + another.getContent() + "</" + empty.getType() + ">" << endl;

		result = false;
	}

	if(paramList.getType() != "span")
	{
		string errmsg = "Type for parameterized list Span was improperly initialized";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getClass() != "")
	{
		string errmsg = "CSS Class for parameterized list Span was improperly initialized";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getId() != "")
	{
		string errmsg = "Id for parameterized list Span was improperly initialized";
		logError(errmsg, output);

		result = false;
	}

	//	Testing nested Spans
	Text plain("Just text");
	Span outside;
	Span inside;

	Element first;
	Element second;
	Element third;

	third.setElement(spannedText);
	inside.addElement(third);
	first.setElement(inside);

	second.setElement(plain);
	
	outside.addElement(first);
	outside.addElement(second);

	//	Even though we are using Text and other classes here, we will not be testing them

	//	Make sure that the nested span did not change 
	if(inside.getContent() != "<" + inside.getType() + ">" + spannedText.getContent() + "</" + inside.getType() + ">")
	{
		string errmsg = "Inside content of nested Span and Text was improperly formatted";
		logError(errmsg, output);

		result = false;
	}

	if(outside.getContent() != "<" + outside.getType() + ">" + "<" + inside.getType() + ">" + spannedText.getContent() + "</" + inside.getType() + ">" + plain.getContent() + "</" + outside.getType() + ">")
	{
		string errmsg = "Outside content of nested Span and Text was improperly formatted";
		logError(errmsg, output);

		result = false;
	}

	Text aggregation("Testing aggregated constructors");
	Span nested;
	nested.addElement(aggregation);

	if(nested.getContent() != "<" + nested.getType() + ">" + aggregation.getContent() + "</" + nested.getType() + ">")
	{
		string errmsg = "Templatized Span constructor does not return the correct content";
		logError(errmsg, output);

		result = false;
	}

	//	Now checking to make sure that this constructed instance can accept hand-made Elements
	nested.addElement(inside);
	//	Testing against third  instead of inside since third is the content of inside and testing inside would only yeild an extra span
	if(nested.getContent() != "<" + nested.getType() + ">" + aggregation.getContent() + "<" + inside.getType() + ">" + third.getContent() + "</" + inside.getType() + ">" "</" + nested.getType() + ">")
	{
		string errmsg = "Templatized Span does not format existing content correctly";
		logError(errmsg, output);

		result = false;
	}

	return result;*/
}



//	TODO:
//	Id will be implemented with an Id list which checks weather an element already exists with that Id(map) and optionally either overrides the existing element or does nothing
//
//	As the current project goals stand. I believe this class to be done.
//
//	Some of the constructors are untested
//


