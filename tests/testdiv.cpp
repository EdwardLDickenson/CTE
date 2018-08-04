#include "testdiv.hpp"

bool testDiv(ofstream &output)
{
	bool result = true;
	Div empty;

	if(empty.getContent() != "")
	{
		string errmsg = "Div content is unexpectedly non-empty for an empty constructor";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getType() != "div")
	{
		string errmsg = "Div type is incorrect for empty type";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getClass() != "")
	{
		string errmsg = "CSS Class of Div with empty constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getId() != "")
	{
		string errmsg = "Id of Div with empty constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getAlignment() != "")
	{
		string errmsg = "Alignment of Div with empty constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;
	}

	Text firstText("This is in a div");
	empty.addElement(firstText);

	if(empty.getContent() != "<" + empty.getType() + ">" + firstText.getContent() + "</" + empty.getType() + ">")
	{
		string errmsg = "Content of Div is incorrect after adding new element";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getAlignment() != "")
	{
		string errmsg = "Alignment of Div with empty constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;
	}

	Div param(firstText);
	if(param.getType() != "div")
	{
		string errmsg = "Type of Div with parameterized constructor is incorrect";
		logError(errmsg, output);

		result = false;
	}

	if(param.getContent() != "<" + param.getType() + ">" + firstText.getContent() + "</" + param.getType() + ">")
	{
		string errmsg = "Content for Div with parameterized constructor is incorrect";
		logError(errmsg, output);

		result = false;
	}

	if(param.getId() != "")
	{
		string errmsg = "Id of Div with parameterized constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;
	}

	if(param.getClass() != "")
	{
		string errmsg = "CSS Class of Div with parameterized constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;	
	}

	if(param.getAlignment() != "")
	{
		string errmsg = "Alignment of Div with parameterizezd constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;
	}

	Text secondText("This is the second Text element");

	Element firstElement;
	Element secondElement;

	firstElement.addElement(firstText);
	secondElement.addElement(secondText);

	list<Element> parameters;
	parameters.push_back(firstElement);
	parameters.push_back(secondElement);
	
	Div paramList(parameters);
	if(paramList.getType() != "div")
	{
		string errmsg = "Type of parameter list is incorrect for constructor with parameter list";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getContent() != "<" + paramList.getType() + ">" + firstElement.getContent() + secondElement.getContent() + "</" + paramList.getType() + ">")
	{
		string errmsg = "Content of Div with parameter list is incorrectly formatted for constructor with parameter list";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getClass() != "")
	{
		string errmsg = "CSS class of Div is unexpectedly non-empty for constructor with parameter list";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getId() != "")
	{
		string errmsg = "Id of Div is unexpectedly non-empty for constructor with parameter list";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getAlignment() != "")
	{
		string errmsg = "Alignment of Div with parameter list is unexpectedly non-empty for constructor with parameter list";
		logError(errmsg, output);

		result = false;
	}

	Div outside;
	Div inside;
	
	inside.addElement(firstElement);
	outside.addElement(inside);
	outside.addElement(secondElement);

	if(outside.getContent() != "<" + outside.getType() + ">" + "<" + inside.getType() + ">" + firstElement.getContent() + "</" + inside.getType() + ">" + secondElement.getContent() + "</" + outside.getType() + ">")
	{
		string errmsg = "Content of Div with nested element is incorrect";
		logError(errmsg, output);

		result = false;
	}

	Div elementParam(firstElement);
	if(elementParam.getType() != "div")
	{
		string errmsg = "Type of Div with Element constructor is incorrect";
		logError(errmsg, output);

		result = false;
	}

	if(elementParam.getContent() != "<" + elementParam.getType() + ">" + firstElement.getContent() + "</" + elementParam.getType() + ">")
	{
		string errmsg = "Content of Divv with Element constructor is incorrect";
		logError(errmsg, output);

		result = false;
	}

	if(elementParam.getId() != "")
	{
		string errmsg = "Id of Div with Element constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;
	}

	if(elementParam.getClass() != "")
	{
		string errmsg = "CSS class of Div with Element constructor is unexpectedly non-empty";
		logError(errmsg, output);

		result = false;
	}

	elementParam.setAlignment("Any valid string");
	if(elementParam.getAlignment() != "")
	{
		string errmsg = "Alignment of Div is unexpectedly non-empty after calling mutator with unrecognized alignment";
		logError(errmsg, output);

		result = false;
	}

	bool alignmentIsValid = false;
	string validAlignments[] = {"left", "center", "right", "justify"};

	for(size_t i = 0; i < sizeof(validAlignments) / sizeof(*validAlignments); ++i)
	{
		elementParam.setAlignment(validAlignments[i]);
		if(elementParam.getAlignment() == validAlignments[i])
		{
			alignmentIsValid = true;
		}
	}

	if(!alignmentIsValid)
	{
		string errmsg = "Div does not accept valid alignment arguments";
		logError(errmsg, output);

		result = false;
	}

	if(!elementParam.hasAttributes())
	{
		string errmsg = "Div does not have attributes after providing valid input";
		logError(errmsg, output);

		result = false;
	}

	if(elementParam.getContent() != "<" + elementParam.getType() + " align=\"justify\"" + ">" + firstElement.getContent() + "</" + elementParam.getType() + ">")
	{
		string errmsg = "Div alignment is incorrect or not present";
		logError(errmsg, output);

		result = false;
	}

	return result;
}



//	TODO:
//
//
//


