#pragma once

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "../deps.hpp"
#include "text.hpp"

class Element
{
private:
	string content;
	string type;
	string id;
	string cssClass;
	list<Element> elementList;
	//string attributes;
	list<string> attributeTags;
	list<string> attributes;

	//	Accessors
	string 	getContentHelper(Element node);
	//	Mutators
	//	Operators

public:
	//	Constructors
	Element();
	Element(const Element &copy);
	Element(Text text);
	//	Additionally, there should be parameterized constructors minimaly for Text
	//	Finally, there should also be a way of storing style here since every element can have a style attribute

	//	Accessors
	string getContent();
	string getType();
	string getId();
	string getClass();
	list<Element> getElements();
	bool hasAttributes();
	list<string> getAttributes();
	string getFormattedAttributes();

	//	Mutators
	void setContent(string newContent);
	void setType(string newType);
	void setId(string newId);
	void setClass(string newCssClass);
	void setElements(list<Element> list);
	template<class T> void setElement(T element);
	template<class T> void addElement(T element);
	void setAttributes(list<string> attribs);
	void addAttribute(string newAttribute);
	void setElement(Text textarg);
	void addElement(Element element);

	//	Operators
};

//	Template functions have to go here because of linker errors in the source file
template<class T> void Element::setElement(T element)
{
	elementList = element.getElements();
	content = element.getContent();
	type = element.getType();
}

template<class T> void Element::addElement(T element)
{
	Element tmp;
	tmp.setElement(element);

	elementList.push_back(tmp);
}

#endif	//	ELEMENT_HPP



//	TODO:
//
//	Also remember to include a "getType" to the other elements to avoid template specification here and to allow for more efficient tagging. I.E. p would become <p> or </p>
//	Subsequently, a map of types, HTML types, and their respective parameter lists might be in order
//
//
//	Having some issues with the copy constructor overriding the default constructor.
//
//	Element should have a specific constructor for Text, and maybe string(depending on how other features are implemented)
//
//	Seems to be a Makefile related issue when not cleaning the directory
//
//	Rewrite the setElement function so that the Text class does not require a getType function which, which returns ""
//
//
