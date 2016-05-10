/*
 * Author: Austin DeLauney
 *
 * Runs the Project5.cpp, but used a .bin file as input
 */
#include "City.h"
#include <fstream>
#include <iostream>
#include "PrimaryHash.h"
#include <sstream>
#include <vector>

const string SEARCH_FOR_CITY = "Ringgold, GA";

using namespace std;

int main(int argc, char *argv[])
{

	string filename;

	if(argc == 2)
	{
		filename = argv[1];
	}

	else
	{
		cout << "Incorrect command line arguments" << endl;
		return 1;
	}

	ifstream file;
	file.open(filename.c_str(), ios::in | ios::binary);

	unsigned long len = 0;

	file.read((char*)&len, sizeof(unsigned long));

	if(len == 0)
	{
		cout << "No Cities to populate... Exiting..." << endl;
		return 1;
	}

	char citiesText[len];
	file.read((char*)&citiesText, len);
	string citiesString(citiesText);
	istringstream iss(citiesString);
	string line1, line2;
	vector<City*> cities;

	while(getline(iss, line1) && getline(iss, line2))
	{
		cities.push_back(new City(line1, line2));
	}

	PrimaryHash primeHash(cities);

	primeHash.printStatistics();

	cout << primeHash.find(SEARCH_FOR_CITY) << endl;
}