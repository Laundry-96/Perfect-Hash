/*
 * Author: Austin DeLauney
 *
 * This class is used to hold City data, and manipulate it
 */

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
		string toString();

	private:
		string m_place;
		string m_coord;
};

#endif