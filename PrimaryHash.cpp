#include "PrimaryHash.h"

PrimaryHash::PrimaryHash(vector<City> cities)
{
	//Set the prime
	prime1 = 16890581;
	prime2 = 17027399;

	//Seed random and generate c
	srand(0);
	c = rand() % prime1 + 1;
	a = rand() % prime1 + 1;
	b = rand() % prime1;

	size = cities.size();

	//Instantiate m_cities
	m_cities = new City[cities.size()];

	//Instantiate m_secondary
	m_container = new SeconadryHash[cities.size()];

	for(unsigned int = 0; i < cities.size(); i++)
	{
		m_cities[i] = NULL;
		m_secondary[i] = NULL;
	}

	//Add all of the objects in cities to the container
	for(unsigned int i = 0; i < cities.size(); i++)
	{
		addToHash(cities.at(i));
	}
}

PrimaryHash::~PrimaryHash()
{
	for(int i = 0; i < size; i++)
	{
		delete m_cities[i];
		delete m_secondary[i];
	}

	delete m_cities;
	delete m_secondary;
	m_ = NULL;

}

void addToHash(City city)
{
	string place = city.getPlace();

	container[hash(city)]->insert(city);
}

unsigned long hash(City city)
{
	unsigned long x = numerizeString(city->getPlace());

	return (((a * x) + b) % prime2) % size;
}

unsigned long numerizeString(string place)
{
	unsigned long sum = 0;
	for(unsigned long i = 0; i < place.size(); i++)
	{
		sum = ((sum * c) + place.at(i)) % prime1;
	}

	return sum;
}