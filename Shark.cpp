#include "Shark.hpp"

Shark::Shark(int starvation, int starvationPeriod, int gestation, int gestationPeriod, unsigned int startingAge) :
	Fish(gestation, gestationPeriod, startingAge),
	m_starvation(starvation),
	m_starvationPeriod(starvationPeriod)
{
	//empty 
}

void Shark::eat()
{
	m_starvation = m_starvationPeriod;
}

char Shark::toChar()
{
	if (m_dead) return 'x';

	char direction;
	switch (m_direction)
	{
	case Direction::up:
		direction = 'u';
		break;
	case Direction::down:
		direction = 'd';
		break;
	case Direction::left:
		direction = 'l';
		break;
	case Direction::right:
		direction = 'r';
		break;
	}

	return direction;
}

void Shark::timeUpdate()
{
	if (m_starvation == 0)
	{
		m_dead = true;
	}
	m_starvation--;
	Fish::timeUpdate();
}

void Shark::point(std::vector<std::string>& map)
{
	static int closeI = 0;
	static int closeJ = 0;

	bool closer = false;

	// checks inside square for fish
	// if it finds one on one of the turn directions, it blocks that direction
	for (int k = 1; k <= 3; k++)
	{
		for (int l = 1; l <= 3; l++)
		{
			if ((map[k][l] != '.') && ((k != 2) || (l != 2)))
			{
				if ((k == 1) && (l == 2))
				{
					m_direction = Direction::up;
					return;
				}
				else if ((k == 3) && (l == 2))
				{
					m_direction = Direction::down;
					return;
				}
				else if ((k == 2) && (l == 1))
				{
					m_direction = Direction::left;
					return;
				}
				else if ((k == 2) && (l == 3))
				{
					m_direction = Direction::right;
					return;
				}
				closer = true;
				closeI = k;
				closeJ = l;
			}
		}
	}

	// checks outer square if there were no fish closer (in the inner square)
	if (!closer)
	{
		for (int k = 0; k <= 4; k++)
		{
			for (int l = 0; l <= 4; l++)
			{
				if ((map[k][l] != '.') && ((k != 2) || (l != 2)))
				{
					closeI = k;
					closeJ = l;
				}
			}
		}
	}

	std::vector<std::string> closeMap =
	{
		"20003",
		"22033",
		"22.33",
		"22133",
		"21113",
	};
	int temp = (closeMap[closeI][closeJ]) - '0';

	switch (temp)
	{
	case 0: m_direction = Direction::up; break;
	case 1: m_direction = Direction::down; break;
	case 2: m_direction = Direction::left; break;
	case 3: m_direction = Direction::right; break;
	}
}

