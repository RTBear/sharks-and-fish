#include "Direction.hpp"
#include <cstdlib>

// ------------------------------------------------------------------
//
// Return a random direction
//
// ------------------------------------------------------------------
Direction randomDirection()
{
	switch (std::rand() % 4)
	{
		case 0: return Direction::up;
		case 1: return Direction::down;
		case 2: return Direction::left;
		case 3: return Direction::right;
	}
}

// ------------------------------------------------------------------
//
// Given a direction, return the next direction in a clockwise fashion
//
// ------------------------------------------------------------------
Direction nextDirection(Direction current)
{
	switch(current)
	{
		case Direction::up: return Direction::right;
		case Direction::down: return Direction::left;
		case Direction::left: return Direction::up;
		case Direction::right: return Direction::down;
	}
}
