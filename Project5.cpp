#include "City.h"
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

int main(int argc, char *argv[])
{

	string filename;
	vector<City> cities;

	if(argc == 2)
	{
		filename == argv[1];
	}

	else
	{
		cout << "Incorrect command line arguments"
	}

	ifstream file(filename.c_str());

	if(file.is_open())
	{
		string line1;
		string line2;

		while(getline(file, line1) && getline(file, line2))
		{
			cities.push_back(City(line1, line2));
		}
	}

	for(unsigned int i = 0; i < cities.size(); i++)
	{
		
	}
}