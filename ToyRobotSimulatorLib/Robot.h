#pragma once

#include <iostream>
#include <vector>
#include "Direction.h"

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

		int xCoordinate;
		int yCoordinate;
		Direction direction;

	public:
		Robot(int xCoordinate = 0, int yCoordinate = 0, Direction direction = Direction::NORTH);
		bool IsRobotOnTable(const int xCoordinate, const int yCoordinate);
		bool IsValidDirection(Direction direction);
		bool Place(const int xCoordinate, const int yCoordinate, const Direction direction);
		void MoveForward();
		void TurnLeft();
		void TurnRight();
		[[nodiscard]] std::string Report() const;
		
		/* For Test */
		int GetXCoordinate();
		int GetYCoordinate();
		Direction GetDirection();
		

	};
}