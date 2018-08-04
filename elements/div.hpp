#ifndef DIV_HPP
#define DIV_HPP

#pragma once

#include "../deps.hpp"
#include "../cte.hpp"

class Div: public Element
{
private:

	string alignment;

public:

	//	Constructors
	Div();
	Div(Text defaultContent);
	Div(Element defaultContent);
	Div(list<Element> contentList);

	//	Accessors
	string getAlignment();
	bool hasAttributes();
	string getAttributes();

	//	Mutators
	void setAlignment(string newAlignment);

	//	Operators
};

#endif	//	DIV_HPP



//	TODO:
//
//
//


