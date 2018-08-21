#ifndef _FISH_HPP_
#define _FISH_HPP_

#include <string>
#include <vector>
#include <iostream>

#include "ProtoFish.hpp"

// ------------------------------------------------------------------
//
// A basic fish that changes direction and dies at age 100
//
// ------------------------------------------------------------------
class Fish : public ProtoFish
{
public:
	// overloaded constructor
	Fish(int gestation, int gestationPeriod, unsigned int startingAge);

	// checks to see if its time to have a baby
	bool haveBaby();

	// updates gestation and fish age
	void timeUpdate();

	// turns fish in appropriate direction
	void point(std::vector<std::string>& map);

protected:
	int m_gestation;
	int m_gestationPeriod;
};

#endif