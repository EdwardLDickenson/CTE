#include "errornumbers.hpp"

string messageLUT[] = 
{
	//	For debug purposes the initial element of this list is kept empty.
	//	None of these can have a comma "," contained inside of them
	//	Error codes should have a standard naming procedure so that we can differentiate the errors
	//	Error should be loaded from "errormessages.csv" not stored in the C++ file
	//	Ideally, these messages would be loaded from an iterator in their respective functions, in units.cpp, but manually writing them in has the added benefit of forcing someone to check that it is the correct message
	"",
	"Improperly formatted html. Probably bad constructor",
	"Page url was unexpectedly non-empty. Probably bad constructor",
	"Page name was unexpectedly non-empty. Probably bad constructor",
	"Page name not set properly. Probably setPageName",
	"Page url not set properly",
	"Page url not set properly for string with .html ending",
	"Page url not set properly for string with .html in the middle",
	"Page url not set properly. Page constructor probably failed to set it",
	"htmlizeIllegalChars reports illegal chars in a string with only legal chars",
	"htmlizeIllegalChars does not replace greater and less than signs with their respective codes",
	"htmlizeIllegalChars does not replace the slash characters with their respective codes",
	"htmlizeIllegalChars does not replace the ampersand with the appropriate code",
	"htmlizeIllegalChars does not replace the pound sign with the appropriate code"
};

unsigned int getErrorNumber(string errorMsg)
{
	unsigned int length = sizeof(messageLUT) / sizeof(*messageLUT);

	for(unsigned int i = 0; i < length; ++i)
	{
		if(errorMsg == messageLUT[i])
		{
			return i;
		}
	}

	//	Tecnically, this return value is also shared with an empty string. Somewhat sloppy, but not unacceptable.
	return 0;
}

void logError(string errmsg, ofstream &output)
{
	clock_t executionTime = clock();
	output << errmsg << "," << getErrorNumber(errmsg) << "," << (double(executionTime) / CLOCKS_PER_SEC) << endl;
}



//	TODO:
//
//
//


