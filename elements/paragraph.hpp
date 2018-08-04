#pragma once

#ifndef PARAGRAPHELEMENT_HPP
#define PARAGRAPHELEMENT_HPP

#include "../deps.hpp"
#include "../cte.hpp"

class Paragraph: public Element
{
private:

	//list<Element> elements;

public:
	
	//	Constructors
	Paragraph();
	Paragraph(Element defaultContent);
	Paragraph(list<Element> defaultElements);

	//	Accessors

	//	Mutators
	void setElements(list<Element> newElements);// This does not append new elements, but rather is distructive
	//void addElement(Element newElement);
	//template<class T> void addElement(T newElement);

	//	Operators
};

#endif	//	PARAGRAPHELEMENT_HPP



//	TODO:
//
//
//


