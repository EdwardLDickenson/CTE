#pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include "../deps.hpp"

#include "text.hpp"
#include "element.hpp"

class Span: public Element
{
private:

	Element content;	//	Get rid of this?

public:

	//	Constructors
	Span();
	Span(Text defaultContent);
	Span(Element defaultContent);
	Span(list<Element> defaultElements);

	//	Accessors
	string getContent();

	//	This is on the cutting block as well, but getElementList is not the same name as getElement which causes some inheritance issues 
	//list<Element> getElementList();

	//	Mutators
	void setElements(list<Element> newElements);	//	Requsite note about this being destructive
	/*void addElement(Element newElement);*/
	//template<class T> void addElement(T newElement);

	//	Operators
};
/*
template<class T> void Span::addElement(T newElement)
{
	Element tmp;
	tmp.setElement(newElement);

	Element::addElement(tmp);
}*/

#endif	//	SPAN_HPP



//	TODO:
//	Leave the add functionality commented out for now
//
// //	Span(ELement defaultContent) is untested
//
//


