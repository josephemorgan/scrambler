#ifndef _SCRAMBLER_H_
#define _SCRAMBLER_H_

#include "word.h"
#include <queue>
#include <fstream>

class Scrambler
{
private:
	std::ifstream infile;
	std::ofstream outfile;
	std::queue<Word> *buffer;

public:
	Scrambler(std::istream);
	Scrambler(std::istream, std::ostream);
	~Scrambler();

};

#endif
