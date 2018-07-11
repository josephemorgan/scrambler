#ifndef _SCRAMBLER_H_
#define _SCRAMBLER_H_

#include "word.h"
#include <queue>
#include <fstream>

class Scrambler
{
private:
	std::ifstream *m_infile;
	std::ofstream *m_outfile;
	std::queue<Word> *m_buffer;

public:
	Scrambler(std::ifstream*);
	Scrambler(std::ifstream*, std::ofstream*);
	~Scrambler();

	void normalize_output();

};

#endif
