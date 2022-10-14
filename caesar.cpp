/* 
Patrick Ging
Professor Zamanksy
Lab 6
funcs.cpp
*/

#include <iostream>
#include "caesar.h"
#include <cctype>

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

std::string encryptCaesar(std::string plaintext, int rshift) {
	// applies a ceaser shift of rshift onto a string and returns it
	std::string return_string = "";

	for (int i =0; i< plaintext.length(); i++) {
		return_string = return_string + shiftChar(plaintext[i],rshift);
	}

	return return_string;
}
