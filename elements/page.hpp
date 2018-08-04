#pragma once
#ifndef PAGE_HPP
#define PAGE_HPP

#include "../deps.hpp"

#include "element.hpp"

class Page
{
private:
	string name;
	string url;
	list<Element> elements;

public:
	//	Constructors/Destructors
	Page();
	Page(string url);
	Page(string url, string name);

	//	Accessors
	string getPageName();
	string getUrl(); 

	//	Mutators
	void setPageName(string name);
	void setUrl(string url);
	void setHtml();

	//	Operations
	string html();
	void appendElement(Element elementToBeAppened);
	void write();
};

#endif // PAGE_HPP



//	TODO:
//	Name should be remaned to title
//	
//	
