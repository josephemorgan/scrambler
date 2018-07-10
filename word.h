#ifndef _WORD_H_
#define _WORD_H_

class Word
{
private:
	char *word;
	unsigned char word_len;
	bool state; // 0 is original input, 1 is scrambled

public:
	Word (char *buffer);
	~Word();

	void scramble();
	char *get_word();
};

#endif
