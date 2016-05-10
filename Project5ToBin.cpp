/*
 * Author: Austin DeLauney
 *
 * This class turns a text file into a .bin file!
 */
#include <iostream>
#include <fstream>

using namespace std;

void toBin(ofstream &out, int dec);

int main(int argc, char *argv[])
{
	string inName;
	string outName;

	if(argc == 3)
	{
		inName = argv[1];
		outName = argv[2];
	}

	else
	{
		cout << "Incorrect command line arguments" << endl;
		return 1;
	}

	std::ifstream in(inName.c_str());
	std::ofstream out(outName.c_str(), ios::out | ios::binary);

	string line;
	string sum = "";

	while(getline(in, line)) {
		sum += line;
		sum += "\n";
	}

	unsigned long len = sum.length();

	out.write((char*)&len, sizeof(unsigned long)); 
	out.write(sum.c_str(), sum.length());
}
