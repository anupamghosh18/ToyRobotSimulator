#pragma once

#include "Direction.h"

namespace ToyRobotSimulator
{
#define MAX_DIMENSION	5

	class TableTop
	{
	private:
		const int length;
		const int breadth;

	public:
		explicit TableTop(int length = 0, int breadth = 0);
		[[nodiscard]] int GetLength() const;
		[[nodiscard]] int GetBreadth() const;
		[[nodiscard]] bool TableTopBoundCheck(int length, int breadth) const;
		[[nodiscard]] bool IsValidDirection(Direction direction) const;

	};
}