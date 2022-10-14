#include <iostream>
#include <cctype>

#include "vigenere.h"
#include "decrypt.h"
#include "caesar.h"

int get_place_in_alphabet(char c) {
	// tells what number the letter is of the alphabet. returns -1 if n/a

	if ( 65 <= c  && c <= 90) { // ascii range for capital letters
		return c - 64;
	} else if (97 <= c && c <= 122) { // ascii range for lowercase letters
			return c - 96;
	}
	return c; // this char is not alphabetical
}
char leftShiftChar(char c, int lshift) {
	// returns a shifted letter char by rlshift

	if ( std::isalpha(c) ) {
		if ( 65 <= c  && c <= 90) { // ascii range for capital letters

			return (char) (((c - lshift) % 26 ) + 65);
		} else if (97 <= c && c <= 122) { // ascii range for lowercase letters

			return (char) (((c - lshift) % 26 ) + 97);
		}
		/* 
		Adding the new shift, removing 65 (or 97) b/c that's the min ascii for a letter
		applying modulo of 25 b/c it must be in range [n, n+25] to be a letter.
		Therefore, this will wrap the shift if it's above n+25 back into n.
		*/
	}
	return c;
}

std::string decryptCaesar(std::string ciphertext, int rshift) {
	std::string return_string = "";
	char c;

	for(int i = 0; i<ciphertext.length(); i++ ) {
		c = ciphertext[i];

		if(std::isalpha(c)) {
			c = leftShiftChar(c, -1 * rshift);
		}
		return_string = return_string + c;
	}

	return return_string;
}

char shiftChar(char c, int rshift) {
	// returns a shifted letter char by rshift

	if ( std::isalpha(c) ) {
		if ( 65 <= c  && c <= 90) { // ascii range for capital letters
			return (char) (((c + rshift - 65) % 26 ) + 65);
		} else if (97 <= c && c <= 122) { // ascii range for lowercase letters
			return (char) (((c + rshift - 97) % 26 ) + 97);
		}
		/* 
		Adding the new shift, removing 65 (or 97) b/c that's the min ascii for a letter
		applying modulo of 25 b/c it must be in range [n, n+25] to be a letter.
		Therefore, this will wrap the shift if it's above n+25 back into n.
		*/
	}
	return c;
}


std::string decryptVigenere(std::string ciphertext, std::string keyword) {
	// applies a vigerne encryption on a text and returns it
	std::string return_string = "";
	int count = 0;
	char c;
	char keyword_c;
	for (int i=0; i<ciphertext.length();i++) {
		c = ciphertext[i];
		keyword_c = keyword[count % keyword.length()]; 
		// if keyword is shorter than ciphertext it wraps around

		if ( std::isalpha(c)) { // if c is not a letter
			c = shiftChar(c, -1 * (get_place_in_alphabet(keyword_c) - 1)); // shiftChar is from caesar.h
			count++; 
		}

		return_string = return_string + c;

	}

	return return_string;
}

int main() {

	std::cout << decryptCaesar("Rovvy, Gybvn!", 10);
	std::cout << decryptVigenere("Jevpq, Wyvnd!", "cake");

	return 0;
}