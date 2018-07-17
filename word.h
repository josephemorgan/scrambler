#ifndef _WORD_H_
#define _WORD_H_

#include <string>

class Word
{
private:
	char *p_word;
	unsigned m_word_len;
	bool m_state; // 0 is original input, 1 is scrambled

	bool is_punctuation(char);

public:
	Word (char *buffer);
	Word (std::string buffer);
	Word(const Word&);
	~Word();

	Word& operator=(const Word&);

	void scramble();
	std::string get_word(bool debug = false);
	unsigned get_len();
};

#endif
