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

	Robot::Robot(TableTop tableTop) : tableTop(tableTop)
	{}

	bool Robot::Place(const int xCoordinate, const int yCoordinate, const Direction direction)
	{
		bool robotOnTableTop = false;

		if (tableTop.TableTopBoundCheck(xCoordinate, yCoordinate) && tableTop.IsValidDirection(direction))
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

		if (tableTop.TableTopBoundCheck(finalXCoordinate, finalYCoordinate))
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

	void Robot::Report() const
	{
		cout << xCoordinate << "," << yCoordinate << "," << strDirection[static_cast<int>(direction)] << endl;
	}
}