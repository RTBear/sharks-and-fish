#ifndef _DIRECTION_HPP_
#define _DIRECTION_HPP_

// ------------------------------------------------------------------
//
// There are four directions: up, down, left right
//
// ------------------------------------------------------------------
enum class Direction
{
	up,
	down,
	left,
	right
};

Direction randomDirection();
Direction nextDirection(Direction current);

#endif
