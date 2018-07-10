#include "scrambler.h"
#include <iostream>
#include <fstream>

int main() {
	std::ifstream infile;
	std::ofstream outfile;
	infile.open("input.txt");
	outfile.open("output.txt");
	Scrambler test_scrambler(&infile, &outfile);
}
