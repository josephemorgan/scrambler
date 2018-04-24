#ifndef _SCRAMBLER_H_
#define _SCRAMBLER_H_

#include <string>

class Word
{
private:
	char *word;

public:
	Word();
	~Word();

	char* get_word();
	void scramble (char*);
	void scramble (std::string);
};
#endif
