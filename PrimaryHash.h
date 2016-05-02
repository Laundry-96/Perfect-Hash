#ifndef PERFECTHASH_H
#define PERFECTHASH_H

#include "City.h"
#include <vector>

using namespace std;

class PrimaryHash
{
	public:
		PrimaryHash(vector<City> cities);

		/*
		 * addToHash(City city)
		 *
		 * Adds the current City object to m_cities
		 *
		 * Preconditions : m_cities has enough room, and the city object is able to map
		 * Postconditions: the City object is now in m_cities and added to the correct mapped secondary hash
		 */
		void addToHash(City city);

		/*
		 * hash(City city)
		 *
		 * Hashes the city based on place (EX: "Montgomery, AL")
		 *
		 * Precondition : The place is unique
		 * Postcondition: Returns a hash based on the algorithm used
		 */ 
		unsigned int hash(City city);

	private:
		SecondaryHash container[];
}