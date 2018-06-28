#ifndef _SCRAMBLER_H_
#define _SCRAMBLER_H_

#include <string>
#include <vector>

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

class Scrambler
{
private:
	std::vector<Word> *text_file;

public:
	Scrambler();
	~Scrambler();

};

