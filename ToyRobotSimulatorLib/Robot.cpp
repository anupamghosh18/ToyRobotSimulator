#include <sstream>
#include "Robot.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::make_pair;
using std::stringstream;

namespace ToyRobotSimulator
{
#define MAX_DIMENSION	5

	static pair<int, int> CoordinateOffset(Direction direction)
	{
		pair <int, int> offset;

		switch (direction)
		{
		case Direction::NORTH:
			offset = make_pair(0, 1);
			break;
		case Direction::EAST:
			offset = make_pair(1, 0);
			break;
		case Direction::SOUTH:
			offset = make_pair(0, -1);
			break;
		case Direction::WEST:
			offset = make_pair(-1, 0);
			break;
		}

		return offset;
	}

	Robot::Robot(int xCoordinate, int yCoordinate, Direction direction) : xCoordinate(xCoordinate), yCoordinate(yCoordinate), direction(direction)
	{}

	bool Robot::IsRobotOnTable(const int xCoordinate, const int yCoordinate)
	{
		return ((xCoordinate >= 0) && (xCoordinate <= MAX_DIMENSION) && (yCoordinate >= 0) && (yCoordinate <= MAX_DIMENSION));
	}

	bool Robot::IsValidDirection(const Direction direction)
	{
		return ((Direction::NORTH <= direction) && (direction < Direction::MAX_DIRECTION)) ? true : false;
	}

	bool Robot::Place(const int xCoordinate, const int yCoordinate, const Direction direction)
	{
		bool robotOnTableTop = false;

		if (IsRobotOnTable(xCoordinate, yCoordinate) && IsValidDirection(direction))
		{
			this->xCoordinate = xCoordinate;
			this->yCoordinate = yCoordinate;
			this->direction = direction;
			robotOnTableTop = true;
		}
		else
		{
			cerr << "Invalid parameter(s) in PLACE command" << endl;
		}

		return robotOnTableTop;
	}

	void Robot::MoveForward()
	{
		auto [xCoordinateOffset, yCoordinateOffset] = CoordinateOffset(direction);		
		const int finalXCoordinate = xCoordinate + xCoordinateOffset;
		const int finalYCoordinate = yCoordinate + yCoordinateOffset;

		if (IsRobotOnTable(finalXCoordinate, finalYCoordinate))
		{
			xCoordinate = finalXCoordinate;
			yCoordinate = finalYCoordinate;
		}
		else
		{
			cerr << "Out of bound. MOVE command ignored!!!" << endl;
		}
	}

	void Robot::TurnLeft()
	{
		direction = directionPostLeftTurn[static_cast<int>(direction)];
	}

	void Robot::TurnRight()
	{
		direction = directionPostRightTurn[static_cast<int>(direction)];
	}

	std::string Robot::Report() const
	{
		std::stringstream report;
		report << xCoordinate << "," << yCoordinate << "," << strDirection[static_cast<int>(direction)];
		return report.str();
	}

	int Robot::GetXCoordinate()
	{
		return xCoordinate;
	}

	int Robot::GetYCoordinate()
	{
		return yCoordinate;
	}

	Direction Robot::GetDirection()
	{
		return direction;
	}
}