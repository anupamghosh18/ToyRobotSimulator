#include <iostream>
#include "TableTop.h"

namespace ToyRobotSimulator
{
	TableTop::TableTop(int length, int breadth) : length(length), breadth(breadth)
	{}

	int TableTop::GetLength() const
	{
		return length;
	}

	int TableTop::GetBreadth() const
	{
		return breadth;
	}

	bool TableTop::TableTopBoundCheck(int length, int breadth) const
	{
		return ((length >= 0) && (length <= MAX_DIMENSION) && (breadth >= 0) && (breadth <= MAX_DIMENSION));
	}

	bool TableTop::IsValidDirection(Direction direction) const
	{
		return ((Direction::NORTH <= direction) && (direction < Direction::MAX_DIRECTION)) ? true : false;
	}
}
