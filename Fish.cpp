#include "Fish.hpp"

Fish::Fish(int gestation, int gestationPeriod, unsigned int startingAge) :
	m_gestation(gestation),
	m_gestationPeriod(gestationPeriod),
	ProtoFish(startingAge)
{
	//empty
}

bool Fish::haveBaby()
{
	if (m_gestation == 0)
	{
		m_gestation = m_gestationPeriod;
		return true;
	}
	else
	{
		return false;
	}
}

void Fish::timeUpdate()
{
	m_gestation--;
	ProtoFish::timeUpdate();
}

void Fish::point(std::vector<std::string>& map)
{
	static int closeI = 0;
	static int closeJ = 0;

	bool closer = false;

	bool upBlocked = false;
	bool leftBlocked = false;
	bool rightBlocked = false;
	bool downBlocked = false;

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
					upBlocked = true;
				}
				else if ((k == 3) && (l == 2))
				{
					downBlocked = true;
				}
				else if ((k == 2) && (l == 1))
				{
					leftBlocked = true;
				}
				else if ((k == 2) && (l == 3))
				{
					rightBlocked = true;
				}
				else
				{
					closer = true;
					closeI = k;
					closeJ = l;

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
					case 0: if (!upBlocked) this->m_direction = Direction::up; break;
					case 1: if (!downBlocked) this->m_direction = Direction::down; break;
					case 2: if (!leftBlocked) this->m_direction = Direction::left; break;
					case 3: if (!rightBlocked) this->m_direction = Direction::right; break;
					}
				}
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
					case 0: if (!upBlocked) this->m_direction = Direction::up; break;
					case 1: if (!downBlocked) this->m_direction = Direction::down; break;
					case 2: if (!leftBlocked) this->m_direction = Direction::left; break;
					case 3: if (!rightBlocked) this->m_direction = Direction::right; break;
					}
				}
			}
		}
	}
}