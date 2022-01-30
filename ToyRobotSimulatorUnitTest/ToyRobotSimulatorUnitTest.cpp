#define BOOST_TEST_MODULE MasterTestSuite

#include <string>
#include <boost/test/included/unit_test.hpp>
#include "Robot.h"
#include "Simulator.h"

using std::invalid_argument;
using std::pair;
using std::string;

using namespace boost::unit_test;
using namespace ToyRobotSimulator;

namespace ToyRobotSimulatorUnitTest
{
	BOOST_AUTO_TEST_SUITE(ToyRobotTest)

		BOOST_AUTO_TEST_CASE(TC1_Valid_Place_Command)
		{
			string report;
			Robot robot;
			bool isRobotOnTableTop = robot.Place(1, 1, Direction::NORTH);

			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(1, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,1,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC2_Multiple_Valid_Place_Command)
		{
			string report;
			Robot robot;
			bool isRobotOnTableTop = robot.Place(1, 1, Direction::NORTH);

			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(1, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,1,NORTH");

			isRobotOnTableTop = robot.Place(5, 2, Direction::WEST);
			BOOST_CHECK_EQUAL(5, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::WEST), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,2,WEST");

			isRobotOnTableTop = robot.Place(4, 0, Direction::SOUTH);
			BOOST_CHECK_EQUAL(4, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::SOUTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "4,0,SOUTH");

			isRobotOnTableTop = robot.Place(3, 1, Direction::EAST);
			BOOST_CHECK_EQUAL(3, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(1, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::EAST), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,1,EAST");
		}

		BOOST_AUTO_TEST_CASE(TC3_Valid_Move_Command)
		{
			string report;
			Robot robot;
			bool isRobotOnTableTop = robot.Place(1, 1, Direction::NORTH);

			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(1, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,1,NORTH");

			robot.MoveForward();
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC4_Valid_Left_Command)
		{
			string report;
			Robot robot;
			bool isRobotOnTableTop = robot.Place(1, 1, Direction::NORTH);

			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(1, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,1,NORTH");

			robot.MoveForward();
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");

			robot.TurnLeft();
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::WEST), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,WEST");
		}

		BOOST_AUTO_TEST_CASE(TC5_Valid_Right_Command)
		{
			string report;
			Robot robot;
			bool isRobotOnTableTop = robot.Place(1, 1, Direction::NORTH);

			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(1, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,1,NORTH");

			robot.MoveForward();
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");

			robot.TurnRight();
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::EAST), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,EAST");
		}

		BOOST_AUTO_TEST_CASE(TC6_Roam_Around_The_Table_Top)
		{
			string report;
			Robot robot;
			bool isRobotOnTableTop = robot.Place(2, 3, Direction::EAST);

			BOOST_CHECK_EQUAL(2, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::EAST), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "2,3,EAST");

			robot.MoveForward();
			BOOST_CHECK_EQUAL(3, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::EAST), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,3,EAST");

			robot.TurnLeft();
			BOOST_CHECK_EQUAL(3, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,3,NORTH");

			robot.MoveForward();
			BOOST_CHECK_EQUAL(3, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(4, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,4,NORTH");

			robot.TurnLeft();
			BOOST_CHECK_EQUAL(3, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(4, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::WEST), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);

			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,4,WEST");

			robot.MoveForward();
			BOOST_CHECK_EQUAL(2, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(4, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::WEST), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "2,4,WEST");

			robot.TurnRight();
			BOOST_CHECK_EQUAL(2, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(4, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, robot.IsValidDirection(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);

			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "2,4,NORTH");

			robot.MoveForward();
			BOOST_CHECK_EQUAL(2, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(5, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "2,5,NORTH");

			robot.MoveForward();
			BOOST_CHECK_EQUAL(2, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(5, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(true, robot.IsRobotOnTable(robot.GetXCoordinate(), robot.GetYCoordinate()));
			BOOST_CHECK_EQUAL(true, isRobotOnTableTop);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "2,5,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC7_Place_Command_Invalid_X_Coordinate)
		{
			Robot robot;
			bool isRobotOnTableTop = robot.Place(6, 3, Direction::EAST);

			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));			
			BOOST_CHECK_EQUAL(false, isRobotOnTableTop);
		}

		BOOST_AUTO_TEST_CASE(TC8_Place_Command_Invalid_Y_Coordinate)
		{
			Robot robot;
			bool isRobotOnTableTop = robot.Place(1, 6, Direction::EAST);

			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(false, isRobotOnTableTop);
		}

		BOOST_AUTO_TEST_CASE(TC9_Place_Command_Invalid_Direction)
		{
			Robot robot;
			bool isRobotOnTableTop = robot.Place(1, 1, Direction::MAX_DIRECTION);

			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			BOOST_CHECK_EQUAL(false, isRobotOnTableTop);
		}

	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(SimulatorTest)

		bool ExceptionMesageForEmptyCommand(const invalid_argument& ex)
		{
			BOOST_CHECK_EQUAL(ex.what(), std::string("Unknown command: "));
			return true;
		}

		BOOST_AUTO_TEST_CASE(TC10_Parse_Empty_Command)
		{
			string commandInput = "";
			Simulator simulator;
			
			BOOST_CHECK_EXCEPTION(simulator.ParseCommand(commandInput), invalid_argument, ExceptionMesageForEmptyCommand);
		}

		BOOST_AUTO_TEST_CASE(TC11_Parse_Command_With_Coma_Separated_Arguments)
		{
			string commandInput = "PLACE 1,2,NORTH";
			Simulator simulator;

			auto [commandName, parameters] = simulator.ParseCommand(commandInput);
			BOOST_CHECK_EQUAL(commandName, COMMAND_PLACE);
			BOOST_CHECK_EQUAL(3, parameters.size());
			BOOST_CHECK_EQUAL(1, stoi(parameters.at(INDEX_PARAM_X_COORDINATE)));
			BOOST_CHECK_EQUAL(2, stoi(parameters.at(INDEX_PARAM_Y_COORDINATE)));
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), (static_cast<int>(simulator.GetEnumValueOfDirection(parameters.at(INDEX_PARAM_DIRECTION)))));
		}

		/******** Test ExecuteCommand() *******/
		BOOST_AUTO_TEST_CASE(TC12_Execute_Command_In_Lower_Case)
		{
			string commandInput = "place 1,2,north";
			Simulator simulator;
			Robot robot;

			auto [commandName, parameters] = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, commandName, parameters);
			BOOST_CHECK_EQUAL(COMMAND_PLACE, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(3, parameters.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));

			string report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC13_Execute_Command_With_Mixed_Case)
		{
			string commandInput = "Place 1,2,North";
			Simulator simulator;
			Robot robot;

			auto [commandName, parameters] = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, commandName, parameters);
			BOOST_CHECK_EQUAL(COMMAND_PLACE, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(3, parameters.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));

			string report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC14_Execute_Command_With_Random_White_Spaces)
		{
			string commandInput = "    Place   1,2    ,   North   ";
			Simulator simulator;
			Robot robot;

			auto [commandName, parameters] = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, commandName, parameters);
			BOOST_CHECK_EQUAL(COMMAND_PLACE, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(3, parameters.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));

			string report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC15_Execute_No_Argument_Command)
		{
			string report;
			string commandInput = "place 1,2,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_MOVE_FORWARD, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,3,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC16_Execute_Multiple_Commands)
		{
			string report;
			string commandInput = "place 1,2,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_MOVE_FORWARD, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,3,NORTH");

			commandInput = "left";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_TURN_LEFT, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::WEST), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,3,WEST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_MOVE_FORWARD, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::WEST), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,3,WEST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_MOVE_FORWARD, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::WEST), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,3,WEST");

			commandInput = "right";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_TURN_RIGHT, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(3, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,3,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_MOVE_FORWARD, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(4, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,4,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_MOVE_FORWARD, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(5, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,5,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_MOVE_FORWARD, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(5, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,5,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC17_Parse_Command_With_Incorrect_Number_Of_Argument)
		{
			string commandInput = "PLACE 1,2";
			Simulator simulator;
			Robot robot;

			auto [commandName, parameters] = simulator.ParseCommand(commandInput);
			BOOST_CHECK_EQUAL(commandName, COMMAND_PLACE);
			BOOST_CHECK_EQUAL(2, parameters.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC18_Execute_Invalid_Move_Command)
		{
			string report;
			string commandInput = "place 1,2,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");

			commandInput = "move west";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_PLACE, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(1, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC19_Execute_Invalid_Left_Command)
		{
			string report;
			string commandInput = "place 1,2,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");

			commandInput = "left 1,2";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_PLACE, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(2, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC20_Execute_Invalid_Right_Command)
		{
			string report;
			string commandInput = "place 1,2,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");

			commandInput = "Right 2,5";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_PLACE, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(2, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC21_Execute_Invalid_Report_Command)
		{
			string report;
			string commandInput = "place 1,2,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "1,2,NORTH");

			commandInput = "report 1";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_PLACE, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(1, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(1, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(2, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC22_Execute_MOVE_Command_Before_PLACE)
		{
			string report;
			string commandInput = "move";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_UNKNOWN, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC23_Execute_LEFT_Command_Before_PLACE)
		{
			string report;
			string commandInput = "left";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_UNKNOWN, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC24_Execute_LEFT_Command_Before_PLACE)
		{
			string report;
			string commandInput = "right";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_UNKNOWN, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC25_Execute_REPORT_Command_Before_PLACE)
		{
			string report;
			string commandInput = "report";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			BOOST_CHECK_EQUAL(COMMAND_UNKNOWN, simulator.GetCommandName());
			BOOST_CHECK_EQUAL(0, parsedCommand.second.size());
			BOOST_CHECK_EQUAL(0, robot.GetXCoordinate());
			BOOST_CHECK_EQUAL(0, robot.GetYCoordinate());
			BOOST_CHECK_EQUAL(static_cast<int>(Direction::NORTH), static_cast<int>(robot.GetDirection()));
		}

		BOOST_AUTO_TEST_CASE(TC26_TableTop_NorthEast_Corner_Bound_Check)
		{
			string report;
			string commandInput = "place 5,5,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,5,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,5,NORTH");

			commandInput = "right";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,5,EAST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,5,EAST");
		}

		BOOST_AUTO_TEST_CASE(TC27_TableTop_NorthWest_Corner_Bound_Check)
		{
			string report;
			string commandInput = "place 0,5,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,5,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,5,NORTH");

			commandInput = "left";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,5,WEST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,5,WEST");
		}

		BOOST_AUTO_TEST_CASE(TC28_TableTop_SouthWest_Corner_Bound_Check)
		{
			string report;
			string commandInput = "place 0,0,south";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,0,SOUTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,0,SOUTH");

			commandInput = "right";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,0,WEST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,0,WEST");
		}

		BOOST_AUTO_TEST_CASE(TC29_TableTop_SouthEast_Corner_Bound_Check)
		{
			string report;
			string commandInput = "place 5,0,south";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,0,SOUTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,0,SOUTH");

			commandInput = "left";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,0,EAST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,0,EAST");
		}

		BOOST_AUTO_TEST_CASE(TC30_TableTop_North_Edge_Bound_Check)
		{
			string report;
			string commandInput = "place 3,5,north";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,5,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,5,NORTH");

			commandInput = "right";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,5,EAST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "4,5,EAST");
		}

		BOOST_AUTO_TEST_CASE(TC31_TableTop_West_Edge_Bound_Check)
		{
			string report;
			string commandInput = "place 0,3,west";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,3,WEST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,3,WEST");

			commandInput = "right";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,3,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "0,4,NORTH");
		}

		BOOST_AUTO_TEST_CASE(TC32_TableTop_South_Edge_Bound_Check)
		{
			string report;
			string commandInput = "place 3,0,south";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,0,SOUTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,0,SOUTH");

			commandInput = "left";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "3,0,EAST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "4,0,EAST");
		}

		BOOST_AUTO_TEST_CASE(TC33_TableTop_East_Edge_Bound_Check)
		{
			string report;
			string commandInput = "place 5,3,east";
			pair<string, vector<string>> parsedCommand;
			Simulator simulator;
			Robot robot;

			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,3,EAST");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,3,EAST");

			commandInput = "left";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,3,NORTH");

			commandInput = "move";
			parsedCommand = simulator.ParseCommand(commandInput);
			simulator.ExecuteCommand(robot, parsedCommand.first, parsedCommand.second);
			report = robot.Report();
			BOOST_CHECK_EQUAL(report, "5,4,NORTH");
		}

	BOOST_AUTO_TEST_SUITE_END()

}

