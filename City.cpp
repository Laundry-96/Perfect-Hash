#include "City.h"

City::City(string place, string coord)
{
	m_place = place;
	m_coord = coord;
	m_hashValue = 0;
}

string City::getPlace()
{
	return m_place;
}

string City::getCoord()
{
	return m_coord;
}