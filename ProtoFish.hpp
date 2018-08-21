#ifndef _PROTOFISH_HPP_
#define _PROTOFISH_HPP_

#include "Direction.hpp"

// ------------------------------------------------------------------
//
// A basic fish that changes direction and dies at age 100
//
// ------------------------------------------------------------------
class ProtoFish{
public:
	ProtoFish(unsigned int age);

	Direction getDirection()	{ return m_direction; }
	int getAge()				{ return m_age; }
	bool isDead()				{ return m_dead; }
 	void timeUpdate();
	char toChar();

	void point();

protected:
	Direction m_direction;		// Where I am heading
	unsigned int m_age;			// How long I have lived
	bool m_dead;				// Deadness
};

#endif
