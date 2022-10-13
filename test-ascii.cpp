#include <iostream>


void test_ascii(std::string s) {
	/* 
		For each character in the string, it will print the 
		character and the ascii for that character
	*/

	char c;
	for(int i = 0; i < s.length(); i++) {
		// iterating through each character
		c = s[i];
		std::cout << c << " " << (int) c << "\n";
	}

}

int main() 
{

	test_ascii("Hello, world!");

	return 0;
}