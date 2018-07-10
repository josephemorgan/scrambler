#include "scrambler.h"
#include <iostream>

Word::Word (char* buffer)
{
	if (buffer[0] != '\0') {
		std::cout << "Making word...\n";
		// Copy buffer into word.
		word = new char[20];
		for (word_len = 0; buffer[word_len] != '\0'; ++word_len) {
			word[word_len] = buffer[word_len];
		}
		word[word_len] = '\0';
		srand(time(NULL));
	} else
		// TODO: Throw exception rather than quit.
		std::cerr << "Attemting to create empty word.\n", exit(0);
}

Word::Word (std::string buffer) : Word (buffer.c_str())
{
}

Word::~Word()
{
	delete[] word;
}

void Word::scramble()
{
	// TODO: Fix to handle punctuation.
	char *scrambled_word = new char[word_len];
	scrambled_word[0] = word[0];
	scrambled_word[word_len] = '\0';
	scrambled_word[word_len - 1] = word[word_len - 1];
	std::vector<char> origninal_word (word, word + word_len);
	unsigned int element_to_transfer;
	for (unsigned int i = 1; i < word_len - 1; ++i) {
		element_to_transfer = (rand() % (origninal_word.size() - 2)) + 1;
		scrambled_word[i] = origninal_word[element_to_transfer];
		origninal_word.erase(origninal_word.begin() + element_to_transfer);
	}
	delete[] word;
	word = scrambled_word;
	std::cout << std::string(word) << std::endl;
}
/* if ( // If the last char in the word is punctuation. Trust me.
 *     (
 *      word_buffer[word_buffer.length() - 1] >= 0x41 &&
 *      word_buffer[word_buffer.length() - 1] <= 0x5A) || (
 *      word_buffer[word_buffer.length() - 1] >= 0x61 &&
 *      word_buffer[word_buffer.length() - 1] <= 0x7A)
 *    ) */
