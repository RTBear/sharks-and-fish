#ifndef _SHARK_HPP_
#define _SHARK_HPP_

#include <iostream>

#include "Fish.hpp"

class Shark : public Fish
{
public:
	// overloaded constructor for a standard shark
	Shark(int starvation, int starvationPeriod, int gestation, int gestationPeriod, unsigned int startingAge);

	// shark is fed, resets starvation timer
	void eat();

	// overridden toChar method for outputing letter representations of direction
	char toChar();

	// overridden timeUpdate method, accounting for shark starvation
	void timeUpdate();

	// overriden point method, disregards pointing toward blank spaces.
	void point(std::vector<std::string>& map);

protected:
	int m_starvation;
	int m_starvationPeriod;
};

#endif 
