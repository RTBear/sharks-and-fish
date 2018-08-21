#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Direction.hpp"
#include "ProtoFish.hpp"
#include "Fish.hpp"			// TODO: uncomment to test fish
#include "Shark.hpp"		// TODO: uncomment to test fish and sharks

void testProtoFish();
void testFish();
void testShark();
void updateShark(Shark& mako, std::vector<std::string>& map, std::string expected);

//int main(void)
//{
//	Fish myFish(0, 10, 1);
//
//	std::vector<std::string> sonarMap2 =
//			{
//				".....",
//				".....",
//				"d..d.",
//				".....",
//				"....d",
//			};
//	myFish.point(sonarMap2);
//
//	return 0;
//}

// ------------------------------------------------------------------
//
// Entry point for the test drive for the assignment.
//
// ------------------------------------------------------------------
int main() {

	std::srand(static_cast<unsigned int>(std::time(0)));

	testProtoFish();
	testFish();
	testShark();

	return 0;
}


// ------------------------------------------------------------------
//
// Utility function used to print the sonar map and the ProtoFish in the middle.
//
// ------------------------------------------------------------------
void printMap(ProtoFish& fish, std::vector<std::string> map)
{
	map[2][2] = fish.toChar();
	for (auto&& row : map)
	{
		for (auto&& value : row)
		{
			std::cout << value;
		}
		std::cout << std::endl;
	}
}

// ------------------------------------------------------------------
//
// Utility function used to print the sonar map and the Shark in the middle.
//
// ------------------------------------------------------------------
void printMap(Shark& fish, std::vector<std::string> map)
{
	map[2][2] = fish.toChar();
	for (auto&& row : map)
	{
		for (auto&& value : row)
		{
			std::cout << value;
		}
		std::cout << std::endl;
	}
}

// ------------------------------------------------------------------
//
// Provided tests for the ProtoFish class.
//
// ------------------------------------------------------------------
void testProtoFish()
{
	std::cout << "--- ProtoFish Tests ---" << std::endl;
	std::vector<std::string> sonarMap =
	{
		".....",
		".....",
		".....",
		".....",
		"....."
	};

	ProtoFish nemo(96);
	for (int timeStep = 0; timeStep < 5; timeStep++)
	{
		nemo.point();
		nemo.timeUpdate();
		printMap(nemo, sonarMap);
		if (timeStep == 4)
		{
			std::cout << "expected output: X" << std::endl;
		}
		std::cout << std::endl;
	}
}

// ------------------------------------------------------------------
//
// Provided tests for the Fish class.
//
// ------------------------------------------------------------------
void testFish()
{
	std::cout << std::endl << "--- Fish Tests ---" << std::endl;
	std::vector<std::string> sonarMap2 =
	{
		".....",
		".....",
		"^....",
		".....",
		".....",
	};

	Fish guppy(2, 5, 90);
	guppy.point(sonarMap2);
	guppy.timeUpdate();
	printMap(guppy, sonarMap2);
	if (guppy.haveBaby())
	{
		std::cout << "baby time." << std::endl;
	}
	std::cout << "expected output: <" << std::endl;
	std::cout << "=====" << std::endl;

	std::vector<std::string> sonarMap3 =
	{
		".<...",
		".....",
		".....",
		".....",
		".....",
	};

	guppy.point(sonarMap3);
	guppy.timeUpdate();
	printMap(guppy, sonarMap3);
	if (guppy.haveBaby())
	{
		std::cout << "baby time." << std::endl;
	}
	std::cout << "expected output: ^ and baby time" << std::endl;
	std::cout << "=====" << std::endl;

	std::vector<std::string> sonarMap4 =
	{
		".<...",
		".....",
		".....",
		"....v",
		".....",
	};
	guppy.point(sonarMap4);
	guppy.timeUpdate();
	printMap(guppy, sonarMap4);
	if (guppy.haveBaby())
	{
		std::cout << "baby time." << std::endl;
	}
	std::cout << "expected output: ^ or >" << std::endl;
	std::cout << "=====" << std::endl;
}

// ------------------------------------------------------------------
//
// Helper function that performs common operations on a Shark.
//
// ------------------------------------------------------------------
void updateShark(Shark& mako, std::vector<std::string>& map, std::string expected)
{
	mako.point(map);
	mako.timeUpdate();
	printMap(mako, map);
	if (mako.haveBaby())
	{
		std::cout << "baby time." << std::endl;
	}
	if (mako.isDead())
	{
		std::cout << "dead." << std::endl;
	}
	std::cout << expected << std::endl;
	std::cout << "=====" << std::endl << std::endl;
}

// ------------------------------------------------------------------
//
// Provided tests for the Shark class.
//
// ------------------------------------------------------------------
void testShark()
{
	std::cout << std::endl << "--- Shark Tests ---" << std::endl;
	Shark mako(3, 6, 2, 5, 90);
	std::vector<std::string> sonarMap5 =
	{
		".....",
		".....",
		"^....",
		".....",
		".....",
	};
	updateShark(mako, sonarMap5, "expected output: l");

	std::vector<std::string> sonarMap6 =
	{
		"..>..",
		".....",
		".....",
		".....",
		".....",
	};
	updateShark(mako, sonarMap6, "expected output: u and baby time");

	std::vector<std::string> sonarMap7 =
	{
		".....",
		".....",
		"....^",
		".....",
		".....",
	};
	mako.eat();
	updateShark(mako, sonarMap7, "expected output: r");

	std::vector<std::string> sonarMap8 =
	{
		".....",
		".....",
		".....",
		".....",
		"..^..",
	};
	updateShark(mako, sonarMap8, "expected output: d");

	std::vector<std::string> sonarMap9 =
	{
		">....",
		"..>..",
		".....",
		".>...",
		"..^>.",
	};
	updateShark(mako, sonarMap9, "expected output: u");
	updateShark(mako, sonarMap9, "expected output: u");
	updateShark(mako, sonarMap9, "expected output: u and baby time");
	updateShark(mako, sonarMap9, "expected output: u");
	updateShark(mako, sonarMap9, "expected output: x and dead");
}
