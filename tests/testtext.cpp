#include "testtext.hpp"

bool testText(testGroup &textgroup)
{
	//string illegalCharacters[] = { "\n", "\r",  "\t", "<", ">", "'", "\"", "/", "&", "#", ";", "%"};
	//string legalCharacters[] = { "&#10;", "&#13;", "&#9;", "&#60;", "&#62;", "&#39;", "&#34;", "&#92;", "&#38;", "&#35;", "&#59;", "&#37;"};

	string illegalCharacters[] = {
		"\t",
		"\n",
		"\r",
		"\"",
		"#",
		"%",
		"&",
		"'",
		"/",
		";",
		"<",
		">",
		"\\"};

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

	Text empty;
	Text othello("Reputation is an idle and most false imposition; oft got without merit and lost without deserving");
	Text richardIII("Now is the winter of our discontent\nMade glorious by this sun of York");

	Assert<string> emptycontent("Content of Text with empty constructor is unexpectedly non-empty", empty.getContent(), "");
	emptycontent.equal();
	textgroup.addAssertion<string>(emptycontent);

	Assert<string> othellocontent("Text constructor failed with unformatted text", othello.getContent(), "Reputation is an idle and most false imposition&#59; oft got without merit and lost without deserving");
	othellocontent.equal();
	textgroup.addAssertion<string>(othellocontent);

	Assert<string> richardcontent("Text constructor failed on formmated input", richardIII.getContent(), "Now is the winter of our discontent&#10;Made glorious by this sun of York");
	richardcontent.equal();
	textgroup.addAssertion<string>(richardcontent);

	empty.setContent("Reputation is an idle and most false imposition; oft got without merit and lost without deserving");

	Assert<string> setemptycontent("Content of Text class is incorrectly formatted or empty after calling set content", empty.getContent(), "Reputation is an idle and most false imposition&#59; oft got without merit and lost without deserving");
	setemptycontent.equal();
	textgroup.addAssertion<string>(setemptycontent);

	empty.setContent("Now is the winter of our discontent\nMade glorious by this sun of York");

	Assert<string> emptyformatted("Formatted content of Text class is incorrect after calling setContent with a newline", empty.getContent(), "Now is the winter of our discontent&#10;Made glorious by this sun of York");
	emptyformatted.equal();
	textgroup.addAssertion<string>(emptyformatted);

	for(unsigned int i = 0; i < sizeof(illegalCharacters)/sizeof(*illegalCharacters); ++i)
	{
		Text endconstructor("This has an illegal character: " + illegalCharacters[i]);
		Assert<string> end("Text content is incorrect for constructor with an illegal character at the end", endconstructor.getContent(), "This has an illegal character: " + legalCharacters[i]);
		end.equal();
		textgroup.addAssertion<string>(end);

		Text beginconstructor(illegalCharacters[i] + " is in this Text");
		Assert<string> begin("Text content is incorrect for constructor with an illegal character at the beginning", beginconstructor.getContent(), legalCharacters[i] + " is in this Text");
		begin.equal();
		textgroup.addAssertion<string>(begin);

		Text middleconstructor("Illegal character " + illegalCharacters[i] + " in the middle");
		Assert<string> middle("Text content is incorrect for a constructor with an illegal character in the middle", middleconstructor.getContent(), "Illegal character " + legalCharacters[i] + " in the middle");
		middle.equal();
		textgroup.addAssertion(middle);

		Text justIllegal(illegalCharacters[i]);
		Assert<string> illegal("Text content is incorrect for constructor containing only an illegal character", justIllegal.getContent(), legalCharacters[i]);
		illegal.equal();
		textgroup.addAssertion<string>(illegal);

		Text setEndCons;
		setEndCons.setContent("This also has an illegal character at the end" + illegalCharacters[i]);
		Assert<string> setend("Text content is incorrect after setting it using an illegal character", setEndCons.getContent(), "This also has an illegal character at the end" + legalCharacters[i]);
		setend.equal();
		textgroup.addAssertion<string>(setend);

		Text setBeginCons;
		setBeginCons.setContent(illegalCharacters[i] + "Setting an illegal character at the beginning");
		Assert<string> setbegin("Text content is incorrect after setting an illegal character at the beginning", setBeginCons.getContent(), legalCharacters[i] + "Setting an illegal character at the beginning");
		setbegin.equal();
		textgroup.addAssertion<string>(setbegin);

		Text setmidcons;
		setmidcons.setContent("This string " + illegalCharacters[i] + " has an illegal character in the middle");
		Assert<string> setmid("Text content is incorrect after setting a string with an illegal character in the middle", setmidcons.getContent(), "This string " + legalCharacters[i] + " has an illegal character in the middle");
		setmid.equal();
		textgroup.addAssertion<string>(setmid);

		Text setillegalcons;
		setillegalcons.setContent(illegalCharacters[i]);
		Assert<string> setillegal("Text content is incorrect after setting a with only an illegal character", setillegalcons.getContent(), legalCharacters[i]);
		setillegal.equal();
		textgroup.addAssertion<string>(setillegal);
	}

	Text tag("<div>HTML</div>");
	Assert<string> testtag("Text content is incorrect for a constructor with two illegal characters", tag.getContent(), "&#60;div&#62;HTML&#60;&#47;div&#62;");
	testtag.equal();
	textgroup.addAssertion<string>(testtag);

	Text settag;
	settag.setContent("<div>HTML</div>");
	Assert<string> testsettag("Text content is incorrect after calling setContent with two illegal characters", settag.getContent(), "&#60;div&#62;HTML&#60;&#47;div&#62;");
	testsettag.equal();
	textgroup.addAssertion<string>(testsettag);

	string seedchars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789/*-+\\\";<>!@#$%^&*()_=|{}[]";

	srand(time(NULL));
	size_t times = 100;

	for(size_t j = 0; j < times; ++j)
	{
		size_t n = rand() % 1024;
		string randomstring = "";

		for(size_t i = 0; i < n; ++i)
		{
			randomstring += seedchars.at(rand() % seedchars.size());
		}

		string randomhtmlsafe = "";

		for(size_t i = 0; i < n; ++i)
		{
			bool legal = true;
			for(size_t k = 0; k < sizeof(illegalCharacters)/sizeof(*illegalCharacters); ++k)
			{
				if(randomstring.at(i) == illegalCharacters[k].at(0))
				{
					randomhtmlsafe += legalCharacters[k];
					legal = false;
				}
			}

			if(legal)
			{
				randomhtmlsafe += randomstring.at(i);
			}
		}

		Text randomtext(randomstring);
		Assert<string> testrandom("Text constructor failed on randomly generated string", randomtext.getContent(), randomhtmlsafe);
		testrandom.equal();
		textgroup.addAssertion<string>(testrandom);

		Text emptyrandom;
		emptyrandom.setContent(randomstring);
		Assert<string> testemptyrandom("Text content is incorrect after setting a randomly generated string", emptyrandom.getContent(), randomhtmlsafe);
		testemptyrandom.equal();
		textgroup.addAssertion<string>(testemptyrandom);
	}

	Text recursive("<div>This string is parsed in a manual recursive loop</div>");
	recursive.setContent(recursive.getContent());
	string expectedRecursiveResult = "&#38;&#35;60&#59;div&#38;&#35;62&#59;This string is parsed in a manual recursive loop&#38;&#35;60&#59;&#38;&#35;47&#59;div&#38;&#35;62&#59;";
	Assert<string> recursivetest("Text content is incorrect after recursively passing formatted text through the parsing algorithm", recursive.getContent(), expectedRecursiveResult);
	recursivetest.equal();
	textgroup.addAssertion<string>(recursivetest);

	Text unformatted("This string is unformatted and should not change no matter how many times it is passed through the parser");
	for(size_t i = 0; i < 100; ++i)
	{
		unformatted.setContent(unformatted.getContent());
	}

	Assert<string> unformattedtest("Text content is incorrect after passing unformatted text through the parser several times", unformatted.getContent(), "This string is unformatted and should not change no matter how many times it is passed through the parser");
	unformattedtest.equal();
	textgroup.addAssertion(unformattedtest);

	return true;
}



//	TODO:
//
//	Note that "cons" is show for constructor and has nothing to do with cons, car, and cdr
//
