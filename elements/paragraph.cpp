#include "paragraph.hpp"

Paragraph::Paragraph()
{
	Element::setType("p");
}

Paragraph::Paragraph(Element defaultContent)
{
	Element::setType("p");
	Element::addElement(defaultContent);
}

Paragraph::Paragraph(list<Element> defaultList)
{
	Element::setType("p");
	Element::setElements(defaultList);
}



//	TODO:
//
//
//


