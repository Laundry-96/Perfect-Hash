#ifndef SECONDARYHASH_H
#define SECONDARYHASH_H

#include "City.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class SecondaryHash
{
	public:
		//CONSTRUCTOR
		SecondaryHash();
		//DECONSTRUCTOR
	   ~SecondaryHash();

		/*
		 * insert(City *city)
		 * 
		 * Inserts the City object into cities
		 *
		 * Preconditions : The object is a valid and unique City object
		 * Postconditions: The object is inserted into cities
		 */
		void insert(City *city);

		void initHash();

		void printCities();

		string find(string cityToFind);

		unsigned int getSize() { return size; }
		unsigned int getTries() { return tries + 1; }

	private:

		/*
		 * generateHash()
		 *
		 * Generates the array, and puts all of the items from toInsert into the hash
		 *
		 * Preconditions : None
		 * Postconditions: cities is filled with the objects from toInsert
		 */
		bool generateHash();

		void initHashTable();

		/*
	     * rehash()
	     *
	     * Called when we have a collision.
	     *
	     * Preconditions : Capacity is greater than 0, size is greater than 0, and a new hash method has been set
	     * Postconditions: All objects in cities have been re inserted based on thier new hash 
	     */
	    void rehash();

		/*
		 * hash(City city)
		 *
		 * Hashes the city based on place (EX: "Montgomery, AL")
		 *
		 * Precondition : The place is unique
		 * Postcondition: Returns a hash based on the algorithm used
		 */ 
		unsigned long hash(string place);

		/*
		 * numerizeString(string s)
		 * 
		 * Turns the string into a number by using a summing method
		 *
		 * Preconditions : String is unique
		 * Postconditions: Hash based on sum and constant and stuff
		 */
		unsigned long numerizeString(string s);

		vector<City*> toInsert;
		City **m_cities;
		unsigned int size, capacity, seed, c, a, b, tries, prime1, prime2;
};

#endif