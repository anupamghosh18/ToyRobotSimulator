#pragma once
#include <string>
#include <map>
#include <functional>
#include "Robot.h"

using std::map;

namespace ToyRobotSimulator
{
#define	COMMAND_PLACE			"PLACE"
#define	COMMAND_MOVE_FORWARD	"MOVE"
#define	COMMAND_TURN_LEFT		"LEFT"
#define	COMMAND_TURN_RIGHT		"RIGHT"
#define	COMMAND_REPORT			"REPORT"
#define COMMAND_UNKNOWN			"UNKNOWN"

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
		string commandName = COMMAND_UNKNOWN;
		map<string, Direction> stringToEnum = {{"NORTH", Direction::NORTH}, {"EAST", Direction::EAST}, {"SOUTH", Direction::SOUTH}, {"WEST", Direction::WEST}};

	public:
		void Run();
		auto ParseCommand(string& line) const -> pair<string, vector<string>>;
		void ExecuteCommand(Robot &robot, string name, vector<string> arguments);

		/* For test */
		Direction GetEnumValueOfDirection(string direction);
		string GetCommandName();
	};
}