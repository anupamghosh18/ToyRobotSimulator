#pragma once
#include <string>
#include <map>
#include "Robot.h"

using std::map;

namespace ToyRobotSimulator
{
	enum PARAMETER_INDEX
	{
		INDEX_PARAM_X_COORDINATE,
		INDEX_PARAM_Y_COORDINATE,
		INDEX_PARAM_DIRECTION,
		TOTAL_PARAMETEERS
	};

	class Simulator
	{
	private:
		bool isRobotOnTable = false;
		map<string, Direction> stringToEnum = {{"NORTH", Direction::NORTH}, {"EAST", Direction::EAST}, {"SOUTH", Direction::SOUTH}, {"WEST", Direction::WEST}};

	public:
		void Run();
		[[nodiscard]] auto ParseCommand(string& line) const->pair<string, vector<string>>;
		void ExecuteCommand(Robot &robot, string name, vector<string> arguments);
	};
}