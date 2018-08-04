#include "testpage.hpp"

bool testPage(ofstream &output)
{
	bool result = true;

	Page myPage;
	Page urlPage("Has url");
	Page full("Has url", "Has name");

	string html = myPage.html();

	if(html != "<html><head></head><body></body></html>")
	{
		string errmsg = "Improperly formatted html. Probably bad constructor";
		logError(errmsg, output);

		result = false;
	}

	if(myPage.getUrl() != "")
	{
		string errmsg = "Page url was unexpectedly non-empty. Probably bad constructor";
		logError(errmsg, output);

		result = false;
	}

	if(myPage.getPageName() != "")
	{
		string errmsg = "Page name was unexpectedly non-empty. Probably bad constructor";
		logError(errmsg, output);

		result = false;
	}

	myPage.setUrl("the URL");
	if(myPage.getUrl() != "the URL")
	{
		string errmsg = "Page url not set properly";
		logError(errmsg, output);

		result = false;
	}

	myPage.setPageName("Webpage");
	if(myPage.getPageName() != "Webpage")
	{
		string errmsg = "Page name not set properly. Probably setPageName";
		logError(errmsg, output);

		result = false;
	}

	/*myPage.setUrl("the URL.html");
	if(myPage.getUrl() != "the URL")
	{
		cout << myPage.getUrl() << endl;
		string errmsg = "Page url not set properly for string with .html ending";
		logError(errmsg, output);

		result = false;
	}

	myPage.setUrl("the.html url");
	if(myPage.getUrl() != "the")
	{
		string errmsg = "Page url not set properly for string with .html in the middle";
		logError(errmsg, output);

		result = false;
	}

	if(urlPage.getUrl() != "Has url")
	{
		string errmsg = "Page url not set properly. Page constructor probably failed to set it";
		logError(errmsg, output);

		result = false;
	}*/

	if(urlPage.html() != "<html><head></head><body></body></html>")
	{
		//	Here
		string errmsg = "Poorly formatted html ";
	}

	return result;
}



//	TODO:
//
//
//


