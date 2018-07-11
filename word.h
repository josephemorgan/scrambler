#ifndef _WORD_H_
#define _WORD_H_

#include <string>

class Word
{
private:
	char *word;
	unsigned word_len;
	bool state; // 0 is original input, 1 is scrambled

public:
	Word (char *buffer);
	Word (std::string buffer);
	Word(const Word&);
	~Word();

	Word& operator=(const Word&);

	void scramble();
	std::string get_word();
	unsigned get_len();
};

#endif
