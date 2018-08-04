cc = g++
flags = -c -Wall -std=c++14
ele = elements/
test = tests/

elementList = text.o paragraph.o element.o page.o span.o div.o
testList = testelement.o testspan.o testpage.o testtext.o testparagraph.o testdiv.o

all:	elements.o tests.o units.o testsuite.o
	$(cc) units.o elements.o tests.o testsuite.o -o units -std=c++14

testsuite.o:	testsuite/testsuite.cpp testsuite/testsuite.hpp
	$(cc) testsuite/testsuite.cpp $(flags)

units.o:	units.cpp $(test)units.hpp
	$(cc) units.cpp -c -Wall -std=c++14

elements.o:	$(elementList) $(ele)elements.hpp
	ld -r $(elementList) -o elements.o 

text.o:	$(ele)text.cpp $(ele)text.hpp
	$(cc) $(ele)text.cpp -c -Wall -std=c++14

paragraph.o:	$(ele)paragraph.cpp $(ele)paragraph.hpp
	$(cc) $(ele)paragraph.cpp -c -Wall -std=c++14

#	Does not seem to be effective. There is a bug when element.hpp is updated and the directory is not cleaned
element.o:	$(ele)element.*
	$(cc) $(ele)element.cpp -c -Wall -std=c++14

span.o:	$(ele)span.cpp $(ele)span.hpp
	$(cc) $(ele)span.cpp -c -Wall -std=c++14

div.o:	$(ele)div.cpp $(ele)div.hpp
	$(cc) $(ele)div.cpp -c -Wall -std=c++14

page.o:	$(ele)page.cpp $(ele)page.hpp
	$(cc) $(ele)page.cpp -c -Wall -std=c++14

tests.o:	$(testList) $(test)units.hpp
	$(cc) $(test)errornumbers.cpp -c -Wall -std=c++14
	ld -r $(testList) errornumbers.o -o tests.o

testelement.o:	$(test)testelement.cpp $(test)testelement.hpp
	$(cc) $(test)testelement.cpp -c -Wall -std=c++14

testtext.o:	$(test)testtext.cpp $(test)testtext.hpp
	$(cc) $(test)testtext.cpp -c -Wall -std=c++14

testspan.o:	$(test)testspan.cpp $(test)testspan.hpp
	$(cc) $(test)testspan.cpp -c -Wall -std=c++14

testparagraph.o:	$(test)testparagraph.cpp $(test)testparagraph.hpp
	$(cc) $(test)testparagraph.cpp -c -Wall -std=c++14

testdiv.o:	$(test)testdiv.cpp $(test)testdiv.hpp
	$(cc) $(test)testdiv.cpp -c -Wall -std=c++14

testpage.o:	$(test)testpage.cpp $(test)testpage.hpp
	$(cc) $(test)testpage.cpp -c -Wall -std=c++14

clean:
	rm -f *.o *.html units.csv units


#	TODO:
#
#	Header files have bug which does not update the object file after the headerfile has been edited.
#
#
