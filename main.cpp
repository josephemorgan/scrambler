#include "scrambler.h"
#include <iostream>
#include <vector>

int main() {
	std::vector<std::string> test_strings;
	std::vector<Word> test_words(6);

	test_strings.push_back("Tremble");
	test_strings.push_back("Dissasociate");
	test_strings.push_back("Exciting");
	test_strings.push_back("I");
	test_strings.push_back("Wallow");
	test_strings.push_back("Exhaustion");
	for (size_t i = 0; i < test_strings.size(); ++i) {
		test_words[i].scramble(test_strings[i]);
		std::cout << test_words[i].get_word() << std::endl;
	}
}
