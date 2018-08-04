#include "span.hpp"

//	Constructors
  Span::Span()
{
	Element::setType("span");
}

Span::Span(Text defaultContent)
{
	Element::setType("span");
	Element::addElement(defaultContent);
}

Span::Span(Element defaultContent)
{
	Element::setType("span");
	Element::addElement(defaultContent);
    Element::setContent(defaultContent.getContent());
}

Span::Span(list<Element> defaultElements)
{
	Element::setType("span");
	Element::setElements(defaultElements);
}

//	Accessors
string Span::getContent()
{
	return Element::getContent();
}

//	See header file
/*list<Element> Span::getElementList()
{
	return Element::getElements();
}*/

//	Mutators

void Span::setElements(list<Element> newElements)
{

}
/*
void Span::addElement(Element newElement)
{
	Element::addElement(newElement);
}*/



//	TODO:
//
//
//


