/*
 * Author: Austin DeLauney
 *
 * This class is to store all of the hashes that collided from PrimaryHash
 */
#include "SecondaryHash.h"

SecondaryHash::SecondaryHash()
{
	m_cities = NULL;

	//Set the primes
	prime1 = 16890581;
	prime2 = 17027399;

	tries = 0;

	rehash();
}

SecondaryHash::~SecondaryHash()
{
	//Delete all items from the vector, not array, because we don't know where they are in the array
	for(unsigned int i = 0; i < size; i++)
	{
		delete toInsert[i];
	}

	delete[] m_cities;
	m_cities = NULL;

}

void SecondaryHash::insert(City *city)
{
	toInsert.push_back(city);
}

void SecondaryHash::rehash()
{
	srand(tries);
	c = rand() % prime1 + 1;
	a = rand() % prime2 + 1;
	b = rand() % (prime2);
}

void SecondaryHash::initHash()
{
	//Set size and capacity
	size = toInsert.size();
	capacity = size*size;

	//Do we rehash or not?
	bool firstRun = true;

	do
	{
		initHashTable();
		if(!firstRun)
			rehash();
		else
			firstRun = false;
	} while(!generateHash());
}

void SecondaryHash::printCities()
{
	for(unsigned int i = 0; i < toInsert.size(); i++)
	{
		cout << toInsert[i]->toString() << endl;
	}
}

string SecondaryHash::find(string cityToFind)
{
	unsigned long long key = hash(cityToFind);

	if(m_cities[key] == NULL || m_cities[key]->getPlace() != cityToFind)
	{
		return "n/a";
	}

	else
	{
		return m_cities[key]->toString();
	}
}

void SecondaryHash::initHashTable()
{
	//If m_cities isn't instantiated, instantiate it
	if(m_cities != NULL)
	{
		delete[] m_cities;
	}

	m_cities = new City*[capacity]();

	for(int i = 0; i < capacity; i++)
	{
		m_cities[i] = NULL;
	}
}

bool SecondaryHash::generateHash()
{
	for(unsigned int i = 0; i < size; i++)
	{
		unsigned long long key = hash(toInsert.at(i)->getPlace());

		if(m_cities[key] != NULL)
		{
			tries++;
			return false;
		}

		else
		{
			m_cities[key] = toInsert.at(i);
		}
	}

	return true;
}

unsigned long long SecondaryHash::hash(string place)
{
	unsigned long long x = numerizeString(place);

	return (((a * x) + b) % prime2) % capacity;
}

unsigned long long SecondaryHash::numerizeString(string place)
{
	unsigned long long sum = 0;

	for(unsigned long long i = 0; i < place.size(); i++)
	{
		sum = ((sum * c) + place.at(i)) % prime1;
	}

	return sum;
}