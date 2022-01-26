#include <string>
#include <sstream>
#include <algorithm>
#include "Simulator.h"

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::make_pair;
using std::stoi;
using std::string;
using std::stringstream;

namespace ToyRobotSimulator
{
#define ASCII_SPACE		0x20 // ' ' character
#define ASCII_COMA		0x2c // ',' character

#define COMMAND_WITH_NO_PARAM		1
#define COMMAND_WITH_PARAM			2

#define	COMMAND_PLACE			"PLACE"
#define	COMMAND_MOVE_FORWARD	"MOVE"
#define	COMMAND_TURN_LEFT		"LEFT"
#define	COMMAND_TURN_RIGHT		"RIGHT"
#define	COMMAND_REPORT			"REPORT"

	static string ToUpper(string &str)
	{
		for_each(str.begin(), str.end(), [](char &ch) { ch = toupper(ch); });
		return str;
	}

	static void RemoveExtraSpaces(string &command)
	{
		/* Remove extra spaces at the begging of the string */
		size_t offset = command.find_first_not_of(ASCII_SPACE);
		command = (offset == string::npos) ? "" : command.substr(offset);
		/* Remove extra spaces at the end of the string */
		offset = command.find_last_not_of(ASCII_SPACE);
		command = (offset == string::npos) ? "" : command.substr(0, offset + 1);

		stringstream ss(command);
		string commandName;
		getline(ss, commandName, static_cast<const char>(ASCII_SPACE));
		commandName += ASCII_SPACE;
		
		/* 
		If a command has parameter, remove extra spaces in betwwen 
		the command name and the parameter list 
		*/
		if (commandName.size() < command.size())
		{
			ss.str(ss.str().substr(commandName.size()));

			string parameter;
			while (getline(ss, parameter, static_cast<const char>(ASCII_SPACE)))
			{
				commandName += parameter;
			}
			command = commandName;
		}
	}

	static auto ParseTokens(string &command, const char delimiter) -> vector<string>
	{
		RemoveExtraSpaces(command);
		stringstream ss(command);
		string eachToken;
		vector<string> tokens;
		while (getline(ss, eachToken, delimiter))
		{
			tokens.push_back(eachToken);
		}

		return tokens;
	}
		
	void Simulator::Run()
	{
		string commandInput;
		TableTop tableTop;
		Robot robot(tableTop);

		while (getline(cin, commandInput))
		{
			if (commandInput.size() != 0)
			{
				try
				{
					auto [commandName, parameters] = ParseCommand(commandInput);
					ExecuteCommand(robot, commandName, parameters);
				}
				catch (const exception& ex)
				{
					cerr << "ERROR: " << ex.what() << endl;
				}
			}
		}
	}

	auto Simulator::ParseCommand(string& command) const -> pair<string, vector<string>>
	{
		pair<string, vector<string>> parsedCommand;
		vector<string> tokens = ParseTokens(command, ASCII_SPACE);

		if (COMMAND_WITH_PARAM == tokens.size())
		{
			auto parameters = ParseTokens(tokens[1], ASCII_COMA);
			parsedCommand = make_pair(move(tokens[0]), move(parameters));
		}
		else if (COMMAND_WITH_NO_PARAM == tokens.size())
		{
			parsedCommand = make_pair(move(tokens[0]), move(vector<string>{}));
		}
		else
		{
			throw std::invalid_argument("Unknown command: " + command);
		}

		return parsedCommand;
	}

	void Simulator::ExecuteCommand(Robot &robot, string commandName, vector<string> parameters)
	{
		ToUpper(commandName);

		if (!isRobotOnTable && (COMMAND_PLACE != commandName))
		{
			cerr << "Please use the PLACE command with valid coordinates and direction to place the toy robot on the table first!!!" << endl;
		}
		else if (COMMAND_PLACE == commandName)
		{
			try 
			{
				if (TOTAL_PARAMETEERS != parameters.size())
				{
					cout << "PLACE command called with incorrect number of arguments." << endl;
				}
				else
				{
					const int xCordinate = stoi(parameters.at(INDEX_PARAM_X_COORDINATE));
					const int yCordinate = stoi(parameters.at(INDEX_PARAM_Y_COORDINATE));
					const Direction direction = stringToEnum.at(ToUpper(parameters.at(INDEX_PARAM_DIRECTION)));

					if (robot.Place(xCordinate, yCordinate, direction))
					{
						isRobotOnTable = true;
					}
				}
			}
			catch (const exception& ex)
			{
				cerr << "ERROR: " << ex.what() << endl;
				cerr << "Invalid parameter(s) in PLACE command" << endl;
			}
		}
		else if (COMMAND_MOVE_FORWARD == commandName)
		{
			robot.MoveForward();
		}
		else if (COMMAND_TURN_LEFT == commandName)
		{
			robot.TurnLeft();
		}
		else if (COMMAND_TURN_RIGHT == commandName)
		{
			robot.TurnRight();
		}
		else if (COMMAND_REPORT == commandName)
		{
			robot.Report();
		}
		else
		{
			throw std::invalid_argument("Unknown command: " + commandName);
		}
	}
}


