#include "testparagraph.hpp"

bool testParagraph(testGroup &paraGroup)
{
    string luke = "Forasmuch as many have taken in hand to set forth in order a declaration of those things which are most surely believed among us, \
Even as they delivered them unto us, which from the beginning were eyewitnesses, and ministers of the word; \
It seemed good to me also, having had perfect understanding of all things from the very first, to write unto thee in order, most excellent Theophilus, \
That thou mightest know the certainty of those things, wherein thou hast been instructed. \
There was in the days of Herod, the king of Judaea, a certain priest named Zacharias, of the course of Abia: and his wife was of the daughters of Aaron, and her name was Elisabeth. \
And they were both righteous before God, walking in all the commandments and ordinances of the Lord blameless. \
And they had no child, because that Elisabeth was barren, and they both were now well stricken in years. \
And it came to pass, that while he executed the priest's office before God in the order of his course, \
According to the custom of the priest's office, his lot was to burn incense when he went into the temple of the Lord. \
And the whole multitude of the people were praying without at the time of incense. \
And there appeared unto him an angel of the Lord standing on the right side of the altar of incense. \
And when Zacharias saw him, he was troubled, and fear fell upon him. \
But the angel said unto him, Fear not, Zacharias: for thy prayer is heard; and thy wife Elisabeth shall bear thee a son, and thou shalt call his name John. \
And thou shalt have joy and gladness; and many shall rejoice at his birth. \
For he shall be great in the sight of the Lord, and shall drink neither wine nor strong drink; and he shall be filled with the Holy Ghost, even from his mother's womb. \
And many of the children of Israel shall he turn to the Lord their God. \
And he shall go before him in the spirit and power of Elias, to turn the hearts of the fathers to the children, and the disobedient to the wisdom of the just; to make ready a people prepared for the Lord. \
And Zacharias said unto the angel, Whereby shall I know this? for I am an old man, and my wife well stricken in years. \
And the angel answering said unto him, I am Gabriel, that stand in the presence of God; and am sent to speak unto thee, and to shew thee these glad tidings. \
And, behold, thou shalt be dumb, and not able to speak, until the day that these things shall be performed, because thou believest not my words, which shall be fulfilled in their season.";

    Paragraph empty;
	Text tmptxt;

    Assert<string> testEmptyContent("Content of paragraph is unexpectedly non-empty", "", empty.getContent());
    testEmptyContent.equal();
    paraGroup.addAssertion(testEmptyContent);

	Assert<string> testEmptyType("Type of paragraph is incorrect for an empty constructor", "p", empty.getType());
	testEmptyType.equal();
	paraGroup.addAssertion(testEmptyType);

	Assert<string> testEmptyClass("CSS Class of paragraph is unexpectedly non empty for an empty constructor", "", empty.getClass());
	testEmptyClass.equal();
	paraGroup.addAssertion(testEmptyClass);

	Assert<string> testEmptyId("Id of paragraph is unexpectedly non empty for an empty constructor", "", empty.getId());
	testEmptyId.equal();
	paraGroup.addAssertion(testEmptyId);

    empty.setContent(luke);


    //  Bug caused because one of these is formatted while the other ones are not.
    if(empty.getContent() == tmptxt.parsePlainText(luke))
    {
        cout << "Unit Test error" << endl;
    }

    cout << empty.getContent().length() << " " << tmptxt.parsePlainText(luke).length() << endl;


	Assert<string> testAddedContent("Content of paragraph is incorrect after adding content", empty.getContent(), tmptxt.parsePlainText(luke));
	testAddedContent.equal();
	paraGroup.addAssertion(testAddedContent);

    return true;
}

/*bool testParagraph(ofstream &output)
{
	bool result = true;
	Paragraph  empty;
	Text tmp;

	if (empty.getContent() != "")
	{
		string errmsg = "Content of Paragraph is unexpectedly non-empty for empty constructor";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getType() != "paragraph")
	{
		string errmsg = "Type of Paragraph is incorrect";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getClass() != "")
	{
		string errmsg = "Class of Paragraph is unexpectedly non-empty for empty constructor";
		logError(errmsg, output);

		result = false;
	}

	if(empty.getId() != "")
	{
		string errmsg = "Id of Paragraph is unexpectedly non-empty for empty constructor";
		logError(errmsg, output);

		result = false;
	}

	string luke = "Forasmuch as many have taken in hand to set forth in order a declaration of those things which are most surely believed among us, \
Even as they delivered them unto us, which from the beginning were eyewitnesses, and ministers of the word; \
It seemed good to me also, having had perfect understanding of all things from the very first, to write unto thee in order, most excellent Theophilus, \
That thou mightest know the certainty of those things, wherein thou hast been instructed. \
There was in the days of Herod, the king of Judaea, a certain priest named Zacharias, of the course of Abia: and his wife was of the daughters of Aaron, and her name was Elisabeth. \
And they were both righteous before God, walking in all the commandments and ordinances of the Lord blameless. \
And they had no child, because that Elisabeth was barren, and they both were now well stricken in years. \
And it came to pass, that while he executed the priest's office before God in the order of his course, \
According to the custom of the priest's office, his lot was to burn incense when he went into the temple of the Lord. \
And the whole multitude of the people were praying without at the time of incense. \
And there appeared unto him an angel of the Lord standing on the right side of the altar of incense. \
And when Zacharias saw him, he was troubled, and fear fell upon him. \
But the angel said unto him, Fear not, Zacharias: for thy prayer is heard; and thy wife Elisabeth shall bear thee a son, and thou shalt call his name John. \
And thou shalt have joy and gladness; and many shall rejoice at his birth. \
For he shall be great in the sight of the Lord, and shall drink neither wine nor strong drink; and he shall be filled with the Holy Ghost, even from his mother's womb. \
And many of the children of Israel shall he turn to the Lord their God. \
And he shall go before him in the spirit and power of Elias, to turn the hearts of the fathers to the children, and the disobedient to the wisdom of the just; to make ready a people prepared for the Lord. \
And Zacharias said unto the angel, Whereby shall I know this? for I am an old man, and my wife well stricken in years. \
And the angel answering said unto him, I am Gabriel, that stand in the presence of God; and am sent to speak unto thee, and to shew thee these glad tidings. \
And, behold, thou shalt be dumb, and not able to speak, until the day that these things shall be performed, because thou believest not my words, which shall be fulfilled in their season.";

	Text lukeText(luke);
	Element lukePara;
	lukePara.setElement(lukeText);

	//	Text::parsePlainText should be static. And renamed
	empty.addElement(lukePara);
	if(empty.getContent() != "<" + empty.getType() + ">" + tmp.parsePlainText(luke) + "</" + empty.getType() + ">")
	{
		string errmsg = "Paragraph content unexpectedly empty after adding text";
		logError(errmsg, output);

		result = false;
	}

	Paragraph param(lukePara);
	if(param.getType() != "paragraph")
	{
		string errmsg = "Paragraph type is incorrect for a non-empty constructor";
		logError(errmsg, output);

		result = false;
	}

	if(param.getContent() != "<" + param.getType() + ">" + tmp.parsePlainText(luke) + "</" + param.getType() + ">")
	{
		string errmsg = "Paragraph content is incorrect for parameterized constructor";
		logError(errmsg, output);

		result = false;
	}

	if(param.getClass() != "")
	{
		string errmsg = "Paragraph CSS Class is unexpectedly non-empty for a parameterized constructor";
		logError(errmsg, output);

		result = false;
	}

	if(param.getId() != "")
	{
		string errmsg = "Paragraph Id is unexpectedly non-empty for a parameterized conssstructor";
		logError(errmsg, output);

		result = false;
	}

	Text secondText("This is a second text element");
	Element tmpLuke;
	tmpLuke.setElement(secondText);

	list<Element> textList;
	textList.push_back(lukePara);
	textList.push_back(tmpLuke);

	Paragraph paramList(textList);
	if(paramList.getType() != "paragraph")
	{
		string errmsg = "Paragraph type is incorrect for constructor with element list";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getClass() != "")
	{
		string errmsg = "Paragraph class is unexpectedly non-empty for constructor with element list";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getId() != "")
	{
		string errmsg = "Paragraph Id is unexpectedly non-empty for constructor with element list";
		logError(errmsg, output);

		result = false;
	}

	if(paramList.getContent() != "<" + paramList.getType() + ">" + lukePara.getContent() + tmpLuke.getContent() + "</" + paramList.getType() + ">")
	{
		string errmsg = "Paragraph content is wrongly formatted for constructor with element list";
		logError(errmsg, output);

		result = false;
	}

	Paragraph inside;
	Paragraph outside;

	inside.addElement(lukeText);

	outside.addElement(inside);
	outside.addElement(secondText);

	if(outside.getContent() != "<" + outside.getType() + ">" + "<" + inside.getType() + ">" + lukeText.getContent() + "</" + inside.getType() + ">" + secondText.getContent() + "</" + outside.getType() + ">")
	{
		string errmsg = "Nested Paragraph content is wrongly formatted";
		logError(errmsg, output);

		result = false;
	}

	//	Just checking that manually adding Elements still works. Not that it is a terribly common operation, but there is still utility in testing it
	Element textWrapper;
	textWrapper.setElement(lukeText);

	Paragraph elementWrapper;
	elementWrapper.addElement(textWrapper);

	if(elementWrapper.getContent() != "<" + elementWrapper.getType() + ">" + lukeText.getContent() + "</" + elementWrapper.getType() + ">")
	{
		string errmsg = "Manual Element insertion has failed to format correctly";
		logError(errmsg, output);

		result = false;
	}

	return result;
}
*/


//	TODO:
//
//	Text::parsePlainText should be static. And renamed
//
//	This does not test Element insertions into the Paragraph element in the same way that the Span tests do. This functionality should also be tested, but because it is time
//	consuming, it will be a special series of tests instead of the reverse (like for the Span tests).
//
//
//
