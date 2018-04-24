#include "scrambler.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>

Word::Word()
{
	word = new char[20];
	word[0] = '\0';
	srand(time(NULL));
}

Word::~Word()
{
	delete[] word;
}

char *Word::get_word()
{
	return word;
}

void Word::scramble(char* input_word)
{
	if (input_word[0] != '\0') {
		int word_size = 1;
		word[0] = input_word[0];

		// Copies input word into word.
		for (int i = 1; input_word[i] != '\0'; ++i) {
			word[i] = input_word[i];
			++word_size;
		}
		word[word_size] = '\0';

		// Fill available_i with list of available indices.
		std:: vector<int> available_i;
		for (int i = 1; i < (word_size - 1); ++i)
			available_i.push_back(i);

		// Take from the 2nd char. to the 2nd to last of input_word,
		// assign to random index from available_i of word.
		int index = -1;
		for (int i = 1; i < (word_size - 1); ++i) {
			index = rand() % (available_i.size() + 1);
			word[available_i[index]] = input_word[i];
			available_i.erase(std::remove(available_i.begin(), available_i.end(), index), available_i.end());
		}
	}
}

void Word::scramble(std::string input_word) {
	char *c_input_word = new char[25];
	strcpy(c_input_word, input_word.c_str());

	scramble(c_input_word);
	delete[] c_input_word;
}
