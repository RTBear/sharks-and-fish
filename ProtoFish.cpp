#include "ProtoFish.hpp"

// ------------------------------------------------------------------
//
// Default constructor that creates a fish in a random state.
//
// ------------------------------------------------------------------
ProtoFish::ProtoFish(unsigned int age) :
	m_age(age),
	m_direction(randomDirection()),
	m_dead(false)
{

}

// ------------------------------------------------------------------
//
// Another day passes.
//
// ------------------------------------------------------------------
void ProtoFish::timeUpdate()
{
	if (m_age < 100)
	{
		m_age++;
	}
	else
	{
		m_dead = true;
	}
}

// ------------------------------------------------------------------
//
// Return a character to represent me
//
// ------------------------------------------------------------------
char ProtoFish::toChar()
{
	if (m_dead) return 'x';

	char direction;
	switch (m_direction)
	{
		case Direction::up:
			direction = '^';
			break;
		case Direction::down:
			direction = 'v';
			break;
		case Direction::left:
			direction = '<';
			break;
		case Direction::right:
			direction = '>';
			break;
	}

	return direction;
}


// ------------------------------------------------------------------
//
// I will change direction in a random way
//
// ------------------------------------------------------------------
void ProtoFish::point()
{
	m_direction = randomDirection();
}
