/* 
Patrick Ging
Professor Zamanksy
Lab 6A
*/
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
	/* 
		Uses input stream to grab a string input and
		apply it to the test_ascii(std::string) method
	*/
	std::string input;

	std::cout << "Input: ";
	std::cin >> input;

	std::cout << "\n";
	test_ascii(input);

	return 0;
}