#ifndef TEXT_HPP
#define TEXT_HPP

#pragma once

#include "../deps.hpp"
//#include "element.hpp"

//	Note that Text does not inherit anything from the Element 
class Text
{
private:
	string content;
	//	No element list becuase text is supposed to be atomic
public:

	//	Constructors
	Text();
	Text(string text);

	//	Accessors
	string getContent();
	//	Without this, we will probably need template specialization
	//list<Element> getElements();
	string getType();
	
	//	Mutators
	void setContent(string text);

	//	Operators
	string parsePlainText(string text);
};

#endif //	TEXT_HPP



//	TODO:
//
//	Type should probably be an empty string for non-language types
//
//	Text::parsePlainText should be static. And renamed
//


