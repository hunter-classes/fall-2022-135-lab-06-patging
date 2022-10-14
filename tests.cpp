/* 
Patrick Ging
Professor Zamanksy
Lab 6
tests.cpp
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

// test for char shiftChar(char c, int rshift)
TEST_CASE("Tests for shiftChar(char, int) in caesar.h") {

	// making sure it returns normal characters at shift 0
	CHECK (shiftChar('c',0) == 'c');
	CHECK (shiftChar('H',0) == 'H');
	CHECK (shiftChar('Y',0) == 'Y');
	CHECK (shiftChar('B',0) == 'B');
	CHECK (shiftChar('g',0) == 'g');

	// should return char is input char is not alpha
	CHECK (shiftChar('2', 12) == '2');
	CHECK (shiftChar('}', 1) == '}');
	CHECK (shiftChar(' ', 120 == ' '));

	// simple cases with no wrapping
	CHECK (shiftChar('A',2) == 'C');
	CHECK (shiftChar('b', 3) == 'e');
	CHECK (shiftChar('L', 1) == 'M');
	CHECK (shiftChar('Y', 1) == 'Z');
	CHECK (shiftChar('w', 2) == 'y');

	// wrapping cases
	CHECK (shiftChar('z', 1) == 'a');
	CHECK (shiftChar('Z', 3) == 'C');
	CHECK (shiftChar('A', 26) == 'A');
	CHECK (shiftChar('b', 27) == 'c');
	CHECK (shiftChar('p', 2600) == 'p');

}

// test for std::string encryptCaesar(std::string plaintext, int rshift)

TEST_CASE("Tests for encryptCaesar(string, int);") {

	// testing cases where no shift
	CHECK(encryptCaesar("hello",0) == "hello");
	CHECK(encryptCaesar("computer science", 0) == "computer science");
	CHECK(encryptCaesar("",0) == "");
	CHECK(encryptCaesar("test_case",0) == "test_case");

	// normal cases no punctuation, same case
	CHECK(encryptCaesar("patrick", 3) == "sdwulfn");
	CHECK(encryptCaesar("PATRICK", 3) == "SDWULFN");
	CHECK(encryptCaesar("computersciences",10) == "mywzedobcmsoxmoc");
	CHECK(encryptCaesar("COMPUTERSCIENCES",10) == "MYWZEDOBCMSOXMOC");
	CHECK(encryptCaesar("xboxlive", 28) == "zdqznkxg");
	CHECK(encryptCaesar("XBOXLIVE", 28) == "ZDQZNKXG");
	CHECK(encryptCaesar("coconut", 260) == "coconut");
	CHECK(encryptCaesar("COCONUT", 260) == "COCONUT");

	//no punctuation, differing cases

	CHECK(encryptCaesar("BLAHblah", 10) == "LVKRlvkr");
	CHECK(encryptCaesar("blahBLAH", 10) == "lvkrLVKR");
	CHECK(encryptCaesar("AbCdEfGh", 27) == "BcDeFgHi");
	CHECK(encryptCaesar("aBcDeFgH", 27) == "bCdEfGhI");

	// cases regarding spaces

	CHECK(encryptCaesar("Eli Manning", 30) == "Ipm Qerrmrk");
	CHECK(encryptCaesar("Ammonium Carbon Dioxide", 13) == "Nzzbavhz Pneoba Qvbkvqr");
	CHECK(encryptCaesar(" ", 199) == " ");
	CHECK(encryptCaesar(" ", 2033) == " ");

	// punctiation included cases or anything outside of range

	CHECK(encryptCaesar("Patrick!", 34) == "Xibzqks!");
	CHECK(encryptCaesar("ceaser_Neron!", 22) == "yawoan_Jankj!");
	CHECK(encryptCaesar("Ball&Fall", 11) == "Mlww&Qlww");
	CHECK(encryptCaesar("!!!111", 10000) == "!!!111");
	CHECK(encryptCaesar("119", 119) == "119");
 
}

// test for char encryptVigenere(char c, int rshift)
TEST_CASE("Tests for encryptVigenere(string, string) in vigenere.h") { 
	CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
}

// test for char decryptVigenere(char c, int rshift)
TEST_CASE("Tests for decryptVigenere(string, int) in decrypt.h") { 
	CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");

}

// test for char decryptCaesar(char c, int rshift)
TEST_CASE("Tests for decryptCaesar(string, int) in decrypt.h") { 
	CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
}
