/*#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{

	string inName;
	string outName;
	char *buffer = new char;

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

	FILE *readingFile = fopen(inName.c_str(), "r");

	FILE *writingFile = fopen(outName.c_str(), "wb");

	while (!feof(readingFile))
	{
		fread(buffer, 1, 1, readingFile);
		fwrite(buffer, 1, 1, writingFile);
	}

	fclose(readingFile);
	fclose(writingFile);
}*/

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

	//Trim off the last endl;
	//sum = sum.substr(0, sum.size() - 1);

	unsigned long len = sum.length();

	out.write((char*)&len, sizeof(unsigned long)); 
	out.write(sum.c_str(), sum.length());
}
