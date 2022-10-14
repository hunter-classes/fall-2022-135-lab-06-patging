main: main.o caesar.o vigenere.o decrypt.o doctest.h
	g++ -o main -std=c++11 main.o caesar.o vigenere.o decrypt.o

tests: tests.o caesar.o vigenere.o decrypt.o doctest.h
	g++ -o tests -std=c++11 tests.o caesar.o vigenere.o decrypt.o

test-ascii: test-ascii.o 
	g++ -o test-ascii -std=c++11 test-ascii.o

vigenere.o: vigenere.cpp vigenere.h caesar.cpp caesar.h
	g++ -c -std=c++11 vigenere.cpp caesar.cpp

test-ascii.o: test-ascii.cpp
	g++ -c -std=c++11 test-ascii.cpp

decrypt.o: decrypt.cpp caesar.cpp vigenere.cpp decrypt.h vigenere.h caesar.h
	g++ -c -std=c++11 decrypt.cpp caesar.cpp vigenere.cpp

caesar.o: caesar.cpp caesar.h
	g++ -c -std=c++11 caesar.cpp
main.o: main.cpp caesar.h
	g++ -c -std=c++11 main.cpp
tests.o: tests.cpp doctest.h caesar.h
	g++ -c -std=c++11 tests.cpp
clean:
	rm -f main.o caesar.o tests.o main tests test-ascii