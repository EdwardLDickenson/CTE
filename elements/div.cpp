#include "div.hpp"

//	Constructors

Div::Div()
{
	Element::setType("div");
}

Div::Div(Text defaultContent)
{
	Element::setType("div");

	Element tmp;//(defaultContent);
	tmp.setElement(defaultContent);

	Element::addElement(tmp);
}

Div::Div(Element defaultContent)
{
	Element::setType("div");
	Element::addElement(defaultContent);
}

Div::Div(list<Element> contentList)
{
	Element::setType("div");
	Element::setElements(contentList);
}

//	Accessors

string Div::getAlignment()
{
	return alignment; 
}

string Div::getAttributes()
{
	return " align=\"" + alignment + "\"";
}

bool Div::hasAttributes()
{
	if(alignment != "")
	{
		return true;
	}

	return false;
}

//	Mutators

void Div::setAlignment(string newAlignment)
{
	//	In the future, attribute lists like these probably should be dynamic and user accessable
	string validAlignments[] = {"left", "center", "right", "justify"};

	for(size_t i = 0; i < sizeof(validAlignments) / sizeof(*validAlignments); ++i)
	{
		if(newAlignment == validAlignments[i])
		{
			alignment = newAlignment;

			//	Attribute system is currently broken in the latest revision
			//Element::setAttributes(getAttributes());
		}
	}
}

//	Operators



//	TODO:
//
//
//


