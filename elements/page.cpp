#include "page.hpp"

Page::Page()
{

}

Page::Page(string constructorUrl)
{
	url = constructorUrl;
}

Page::Page(string constructorUrl, string pageName)
{
	url = constructorUrl;
	name = pageName;
}

string Page::getPageName()
{
	return name;
}

string Page::getUrl()
{
	return url;
}

void Page::setPageName(string newName)
{
	name = newName;
}

void Page::setUrl(string newUrl)
{
	//	Actually, not sold on this
	if(newUrl.find(".html") != ULLONG_MAX)
	{
		newUrl = newUrl.substr(0, newUrl.find(".html"));
	}

	url = newUrl;
}

void Page::appendElement(Element elementToBeAppended)
{

}

string Page::html()
{
	string result = "";

	result += "<html>";
	result += "<head>";

	if(name != "")
	{
		result += "<title>";
		result += name;
		result += "</title>";
	}

	result += "</head>";
	result += "<body>";

	for(size_t i = 0; i < elements.size(); ++i)
	{

	}

	result += "</body>";
	result += "</html>";

	return result;
}

void Page::write()
{
	if(url == "")
	{
		//	Probably should throw an error
		return;
	}

	string fileName = url + ".html";

	ofstream htmlFile(fileName.c_str());

	htmlFile << html() << endl;
}

//	TODO:
//	
//	
//	
