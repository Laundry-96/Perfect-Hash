#include "PrimaryHash.h"

PrimaryHash::PrimaryHash(vector<City*> cities)
{
	//Set the primes
	prime1 = 16890581;
	prime2 = 17027399;

	//Seed random and generate c
	srand(0);
	c = rand() % prime1 + 1;
	a = rand() % prime1 + 1;
	b = rand() % prime1;

	capacity = cities.size();
	size = 0;

	//Instantiate m_cities
	m_cities = new City*[capacity];

	//Instantiate m_secondary
	m_secondary = new SecondaryHash*[capacity];

	for(unsigned int i = 0; i < capacity; i++)
	{
		m_cities[i] = NULL;
		m_secondary[i] = NULL;
	}

	//Add all of the objects in cities to the container
	for(unsigned int i = 0; i < capacity; i++)
	{
		addToHash(cities.at(i));
	}

	//Now Generate Secondary Hashes if possible
	for(unsigned int i = 0; i < capacity; i++)
	{
		if(m_secondary[i] != NULL)
		{
			m_secondary[i]->initHash();
		}
	}
}

PrimaryHash::~PrimaryHash()
{
	for(unsigned int i = 0; i < capacity; i++)
	{
		//Check if there is a secondary hash first
		if(m_secondary[i] != NULL)
		{
			delete m_secondary[i];
			m_secondary[i] = NULL;
		}

		else
		{
			if(m_cities[i] != NULL)
			{
				delete m_cities[i];
				m_cities[i] = NULL;
			}
		}
	}

	delete m_cities;
	delete m_secondary;
	m_cities = NULL;
	m_secondary = NULL;

}

void PrimaryHash::addToHash(City *city)
{
	unsigned int whereToInsert = hash(city);

	//If there isn't a collision
	if(m_cities[whereToInsert] == NULL)
	{
		m_cities[whereToInsert] = city;
		size++;
	}

	//If there is a collision
	else
	{
		//Check if there is anything in the secondary slot
		if(m_secondary[whereToInsert] == NULL)
		{
			//Create a new secondary hash
			m_secondary[whereToInsert] = new SecondaryHash();

			//Insert the original object, and the collided one
			m_secondary[whereToInsert]->insert(m_cities[whereToInsert]);
			m_secondary[whereToInsert]->insert(city);
		}

		//If there is already a secondary slot
		else
		{
			//Just insert the collided one
			m_secondary[whereToInsert]->insert(city);
		}
	}
}

unsigned long PrimaryHash::hash(City *city)
{
	unsigned long x = numerizeString(city->getPlace());

	return (((a * x) + b) % prime2) % capacity;
}

unsigned long PrimaryHash::numerizeString(string place)
{
	unsigned long sum = 0;
	for(unsigned long i = 0; i < place.size(); i++)
	{
		sum = ((sum * c) + place.at(i)) % prime1;
	}

	return sum;
}