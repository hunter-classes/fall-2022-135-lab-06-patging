#include <iostream>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"

int get_place_in_alphabet(char c) {
	// tells what number the letter is of the alphabet. returns -1 if n/a

	if ( 65 <= c  && c <= 90) { // ascii range for capital letters
		return c - 64;
	} else if (97 <= c && c <= 122) { // ascii range for lowercase letters
			return c - 96;
	}
	return c; // this char is not alphabetical
}


std::string encryptVigenere(std::string plaintext, std::string keyword) {
	// applies a vigerne encryption on a text and returns it
	std::string return_string = "";
	int count = 0;
	char c;
	char keyword_c;
	for (int i=0; i<plaintext.length();i++) {
		c = plaintext[i];
		keyword_c = keyword[count % keyword.length()]; 
		// if keyword is shorter than plaintext it wraps around

		if ( std::isalpha(c)) { // if c is not a letter
			c = shiftChar(c, get_place_in_alphabet(keyword_c) - 1); // shiftChar is from caesar.h
			count++; 
		}

		return_string = return_string + c;

	}

	return return_string;
}
/*
int main() {
	std::cout << encryptVigenere()

	return 0;
} */