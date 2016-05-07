#ifndef PRIMARYHASH_H
#define PRIMARYHASH_H

#include "City.h"
#include <cstdlib>
#include <cmath>
#include "SecondaryHash.h"
#include <vector>

using namespace std;

class PrimaryHash
{
	public:
		//CONSTRUCTOR
		PrimaryHash(vector<City> cities);
		//DECONSTRUCTOR
	   ~PrimaryHash();

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
		unsigned long hash(City city);

		/*
		 * numerizeString(string s)
		 * 
		 * Turns the string into a number by using a summing method
		 *
		 * Preconditions : String is unique
		 * Postconditions: Hash based on sum and constant and stuff
		 */
		unsigned long numerizeString(string s);

	private:
		unsigned int size, prime1, prime2, c, a, b;
		City *m_cities[];
		SecondaryHash *m_secondary[];
}