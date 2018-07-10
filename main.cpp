#include "scrambler.h"
#include <iostream>

int main() {
	std::cout << "Enter a word: ";
	char* test_string = new char[20];
	std::cin >> test_string;
	std::cout << std::endl << "The entered word was: " << test_string << std::endl;
	Word test_word (test_string);
	test_word.scramble();
}
