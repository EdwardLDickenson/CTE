#include "text.hpp"

string Text::getType()
{
	//	Currently, the solution in element.hpp requires this function return an empty string, ""
	//	In the future there will probably be a better solution
	return "";
}

//	Constructors
Text::Text()
{
	content = "";
}

Text::Text(string text)
{
	content = parsePlainText(text);
}

//	Accessorssetend
string Text::getContent()
{
	return content;
}

/*list<Element> Text::getElements()
{
	list<Element> result;

	Element tmp;

	tmp.setContent(content);
	result.push_back(tmp);

	return result;
}*/

//	Mutators
void Text::setContent(string text)
{
	content = parsePlainText(text);
}

//	Operators
string Text::parsePlainText(string text)
{
	char illegalCharacters[] = {
		'\t',
		'\n',
		'\r',
		'"',
		'#',
		'%',
		'&',
		'\'',
		'/',
		';',
		'<',
		'>',
		'\\'};

	string legalCharacters[] = {
		"&#9;",
		"&#10;",
		"&#13;",
		"&#34;",
		"&#35;",
		"&#37;",
		"&#38;",
		"&#39;",
		"&#47;",
		"&#59;",
		"&#60;",
		"&#62;",
		"&#92;"};

	size_t length = sizeof(illegalCharacters) / sizeof(*illegalCharacters);

	string result = "";

	for(size_t i = 0; i < text.size(); ++i)
	{
		bool legal = true;
		for(size_t j = 0; j < length; ++j)
		{
			if(text.at(i) == illegalCharacters[j])
			{
				string start = text.substr(0, i);
				result += legalCharacters[j];

				legal = false;
			}
		}

		if(legal)
		{
			result += text.at(i);
		}
	}

	return result;
}



//	TODO:
//
//	Edit element.hpp so that this class does not require a getType function (which should always reutrn "")
//
//	Text::parsePlainText should be static. And renamed
//
//
