#include "scrambler.h"
#include <iostream>

Scrambler::Scrambler(std::ifstream *infile)
{
	m_infile = infile;
	m_buffer = new std::queue<Word>;
}

Scrambler::Scrambler(std::ifstream *infile, std::ofstream *outfile)
{
	if (!infile->is_open() || !outfile->is_open())
		exit(1);
	m_infile = infile;
	m_outfile = outfile;
	m_buffer = new std::queue<Word>;
	std::string word_buffer;
	while (*infile >> word_buffer) {
		Word temp_word(word_buffer);
		m_buffer->push(temp_word);
	}
	while (!m_buffer->empty()) {
		m_buffer->front().scramble();
		*outfile << m_buffer->front().get_word() << " ";
		m_buffer->pop();
	}

}

Scrambler::~Scrambler()
{
	delete m_buffer;
}
