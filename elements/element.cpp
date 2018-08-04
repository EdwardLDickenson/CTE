#include "element.hpp"

Element::Element()
{
	content = "";
	type = "";
	id = "";
	cssClass = "";
}

//	Copy constructor leads to bugs
Element::Element(const Element &copy)
{
	content = copy.content;
	elementList = copy.elementList;
	type = copy.type;
	attributes = copy.attributes;
	attributeTags = copy.attributeTags;
}

bool Element::hasAttributes()
{
	//	This is castable to an integer
	if(attributes.size() > 0)
	{
		return true;
	}

	return false;
}

string Element::getFormattedAttributes()
{
	string result = "";

	list<string>::iterator tagIt;
	list<string>::iterator attIt;
	for(tagIt = attributeTags.begin(); tagIt != attributeTags.end(); ++tagIt)
	{
		result += (*tagIt) + "=\"" + (*attIt) + "\"";
		++attIt;
	}

	return result;
}

list<string> Element::getAttributes()
{
	return attributes;
}

string Element::getContentHelper(Element node)
{
	list<Element> nodeList = node.getElements();

	//	Indicates atomocity
	if(nodeList.size() == 0)
	{
		return node.content;
	}

	string result = "";

	if(node.getType() != "")
	{
		result += "<" + node.getType();

		if(node.hasAttributes())
		{
			result += node.getFormattedAttributes();
		}

		result += ">";
	}

	list<Element>::iterator elementIterator;
	for(elementIterator = nodeList.begin(); elementIterator != nodeList.end(); ++elementIterator)
	{
		result += node.getContentHelper((*elementIterator));
	}

	if(node.getType() != "")
	{
		result += "</" + node.getType() + ">";
	}

	return result;
}

string Element::getContent()
{
	string result = "";

	if(elementList.size() == 0)
	{
		return content;
	}

	if(type != "")
	{
		result +=  "<" + type;

		if(hasAttributes())
		{
			result += getFormattedAttributes();
		}

		result += ">";
	}

	list<Element>::iterator elementIterator;
	for(elementIterator = elementList.begin(); elementIterator != elementList.end(); ++elementIterator)
	{
		result += getContentHelper((*elementIterator));
	}

	if(type != "")
	{
		result +=  "</" + type + ">";
	}

	return result;
}

string Element::getType()
{
	return type;
}

string Element::getId()
{
	return id;
}

string Element::getClass()
{
	return cssClass;
}

list<Element> Element::getElements()
{
	return elementList;
}

void Element::setContent(string newContent)
{
	content = newContent;
}

void Element::setType(string newType)
{
	type = newType;
}

void Element::setId(string newId)
{
	id = newId;
}

void Element::setClass(string newCssClass)
{
	cssClass = newCssClass;
}

void Element::setElements(list<Element> list)
{
	elementList = list;
}

/*void Element::setAttributes(string newAttributes)
{
	attributes = newAttributes;
}*/

void Element::setAttributes(list<string> attribs)
{
	attributes = attribs;
}

void Element::addAttribute(string newAttribute)
{

}

void Element::addElement(Element element)
{
	elementList.push_back(element);
}

void Element::setElement(Text textarg)
{
	content = textarg.getContent();
	type = "";
}

//	TODO:
//
//	The Copy constructor seems to override the default constructor, which then obviously fails the unit tests.
//
//
//
