#include "SecondaryHash.h"

SecondaryHash::SecondaryHash()
{
	m_cities = NULL;

	//Set the primes
	prime1 = 16890581;
	prime2 = 17027399;

	seed = 0;
	srand(seed);

	c = rand();
	a = rand();
	b = rand();

	collisions = 0;
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
	srand(collisions);
	c = rand();
	a = rand();
	b = rand();
}

void SecondaryHash::initHash()
{

	size = toInsert.size();
	capacity = size*size;

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
		cout << toInsert[i]->getPlace() << endl;
		cout << toInsert[i]->getCoord() << endl;
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
		unsigned long key = hash(*toInsert.at(i));

		if(m_cities[key] != NULL)
		{
			collisions++;
			return false;
		}

		else
		{
			m_cities[key] = toInsert.at(i);
		}
	}

	return true;
}

unsigned long SecondaryHash::hash(City city)
{
	unsigned long x = numerizeString(city.getPlace());

	return (((a * x) + b) % prime2) % capacity;
}

unsigned long SecondaryHash::numerizeString(string place)
{
	unsigned long sum = 0;

	for(unsigned long i = 0; i < place.size(); i++)
	{
		sum = ((sum * c) + place.at(i)) % prime1;
	}

	return sum;
}