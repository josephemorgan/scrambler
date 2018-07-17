#include "scrambler.h"
#include <iostream>
#include <ctime>

const unsigned MAX_WORD_LENGTH = 32;

Word::Word (char* buffer)
{
	if (buffer[0] != '\0') {
		// Copy buffer into word.
		p_word = new char[MAX_WORD_LENGTH];
		for (m_word_len = 0; buffer[m_word_len] != '\0'; ++m_word_len) {
			p_word[m_word_len] = buffer[m_word_len];
		}
		p_word[m_word_len] = '\0';
		srand(time(NULL));
	} else
		// TODO: Throw exception rather than quit.
		std::cerr << "Attemting to create empty word.\n", exit(0);
}

Word::Word (std::string buffer)
{
	srand(time(NULL));
	p_word = new char[MAX_WORD_LENGTH];
	for (m_word_len = 0; buffer.c_str()[m_word_len] != '\0'; ++m_word_len) {
		p_word[m_word_len] = buffer[m_word_len];
	}
}

Word::~Word()
{
	delete[] p_word;
}

Word::Word (const Word& copy_from)
{
	srand(time(NULL));
	operator=(copy_from);
}

Word& Word::operator=(const Word &copy_from)
{
	m_word_len = copy_from.m_word_len;
	m_state = copy_from.m_state;
	p_word = new char[MAX_WORD_LENGTH];
	for (unsigned i = 0; i < MAX_WORD_LENGTH; ++i)
		p_word[i] = copy_from.p_word[i];
	return *this;
}

bool Word::is_punctuation(char c)
{
	return (
			(c >= 0x22 && c <= 0x2f) || 
			(c >= 0x3a && c <= 0x40) || 
			(c >= 0x5b && c <= 0x60) || 
			(c >= 0x7b && c <= 0x7e)) ? true : false;
}

void Word::scramble()
{
	char *scrambled_word = new char[m_word_len];
	char punctuation = '\0';
	if (is_punctuation(p_word[m_word_len - 1])) {
		punctuation = p_word[m_word_len - 1];
		p_word[--m_word_len] = '\0';
	}
	scrambled_word[0] = p_word[0];
	scrambled_word[m_word_len] = '\0';
	scrambled_word[m_word_len - 1] = p_word[m_word_len - 1];
	std::vector<char> origninal_word (p_word, p_word + m_word_len);
	unsigned int element_to_transfer;
	for (unsigned int i = 1; i < m_word_len - 1; ++i) {
		element_to_transfer = (rand() % (origninal_word.size() - 2)) + 1;
		scrambled_word[i] = origninal_word[element_to_transfer];
		origninal_word.erase(origninal_word.begin() + element_to_transfer);
	}
	if (punctuation != '\0') {
		scrambled_word[m_word_len++] = punctuation;
		scrambled_word[m_word_len] = '\0';
	}
	delete[] p_word;
	p_word = scrambled_word;
}

std::string Word::get_word(bool debug)
{
	if (debug == true)
		std::cerr <<  std::string(p_word) << "(" << m_word_len << ") ";
	return std::string(p_word);
}

unsigned Word::get_len()
{
	return m_word_len;
}
