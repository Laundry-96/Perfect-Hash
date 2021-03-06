/*
 * Author: Austin DeLauney
 *
 * IS YOUR PROGRAM RUNNING??? WELL THEN YOU BETTER GO SIGKILL IT!!!
 */
#include "City.h"
#include <fstream>
#include <iostream>
#include "PrimaryHash.h"
#include <vector>

const string SEARCH_FOR_CITY = "Ringgold, GA";

using namespace std;

int main(int argc, char *argv[])
{

	string filename;
	vector<City*> cities;

	if(argc == 2)
	{
		filename = argv[1];
	}

	else
	{
		cout << "Incorrect command line arguments" << endl;
		return 1;
	}

	ifstream file(filename.c_str());

	if(file.is_open())
	{
		string line1;
		string line2;

		while(getline(file, line1) && getline(file, line2))
		{
			cities.push_back(new City(line1, line2));
		}
	}

	PrimaryHash primeHash(cities);

	primeHash.printStatistics();

	cout << primeHash.find(SEARCH_FOR_CITY) << endl;
}