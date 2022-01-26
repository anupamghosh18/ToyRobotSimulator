#pragma once

#include <iostream>
#include <vector>
#include "TableTop.h"

using std::pair;
using std::string;
using std::vector;

namespace ToyRobotSimulator
{
	class Robot
	{
	private:
		const vector <string> strDirection = {"NORTH", "EAST", "SOUTH", "WEST"};
		const vector <Direction> directionPostLeftTurn = { Direction::WEST, Direction::NORTH, Direction::EAST, Direction::SOUTH };
		const vector <Direction> directionPostRightTurn = { Direction::EAST , Direction::SOUTH, Direction::WEST, Direction::NORTH};

		TableTop tableTop;
		int xCoordinate = 0;
		int yCoordinate = 0;
		Direction direction = Direction::NORTH;

	public:
		Robot(TableTop tabletop);
		bool Place(const int xCoordinate, const int yCoordinate, const Direction direction);
		void MoveForward();
		void TurnLeft();
		void TurnRight();
		void Report() const;
	};
}