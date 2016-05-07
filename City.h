#ifndef CITY_H
#define CITY_H

#include <string>

using namespace std;

class City
{
	public:
		//CONSTRUCTOR
		City(string place, string coord);

		/*
		 * Getters:
		 *
		 * Return the information that this class holds
		 */ 
		string getPlace();
		string getCoord();
		unsigned long getHashValue();

		void setHashValue(unsigned long hashVal);

	private:
		unsigned long m_hashValue;
		string m_place;
		string m_coord;
};

#endif