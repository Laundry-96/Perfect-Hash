#ifndef SECONDARYHASH_H
#define SECONDARYHASH_H

#include "City.h"

class SecondaryHash
{
	public:
		//CONSTRUCTOR
		SecondaryHash();
		//DECONSTRUCTOR
	   ~SecondaryHash();

		/*
		 * insert(City city)
		 * 
		 * Inserts the City object into cities
		 *
		 * Preconditions : The object is a valid and unique City object
		 * Postconditions: The object is inserted into cities
		 */
		void insert(City city);

	private:

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
	     * Returns a hash based on the "place" string of the city
	     *
	     * Preconditions : Valid unique City object
	     * Postconditions: returns the index where the City should be stored
	     */
		unsigned int hash(City city);

		/*
		 * resize()
		 *
		 * Resizes the index when we run out of room
		 *
		 * Preconditions : No more room in cities (capacity == size) when trying to insert another object
		 * Postconditions: All items will be rehashed or let alone
		 */
		void resize();

		City cities[];
		unsigned int size;
		unsigned int capacity;
}