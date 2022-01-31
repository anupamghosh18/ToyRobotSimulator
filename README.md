# Toy Robot Simulator Coding Challenge
## Description

* The application is a simulation of a toy robot moving on a square tabletop, of dimensions 5 units x 5 units. There are no other obstructions on the table surface.
* The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.
* Create an application that can read in commands of the following form:

PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT

* PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.
* The origin (0,0) can be considered to be the SOUTH WEST most corner.
* The first valid command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The application should discard all commands in the sequence until a valid PLACE command has been executed
* MOVE will move the toy robot one unit forward in the direction it is currently facing.
* LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the robot.
* REPORT will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.
* A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands.
* Input can be from a file, or from standard input, as the developer chooses.
* Provide test data to exercise the application.

## Constraints

* The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.
* Any move that would cause the robot to fall must be ignored.

## Example Input and Output:

### Example a

PLACE 0,0,NORTH                                                                                                                                                                   
MOVE                                                                                                                                                                             
REPORT

#### Expected output:

Output: 0,1,NORTH

### Example b

PLACE 0,0,NORTH                                                                                                                                                                   
LEFT                                                                                                                                                                             
REPORT

#### Expected output:

Output: 0,0,WEST

### Example c

PLACE 1,2,EAST                                                                                                                                                                   
MOVE                                                                                                                                                                             
MOVE                                                                                                                                                                             
LEFT                                                                                                                                                                             
MOVE                                                                                                                                                                             
REPORT

#### Expected output

Output: 3,3,NORTH


# Development Environment
The solution to this coding challenge has been developed on Visual Studio 2022 with toolset version v143 and supports C++ 20.
The projects ToyRobotSimulator and ToyRobotSimulatorUnitTest are console application whereas the project ToyRobotSimulatorLib is a static librray project.

# Run Application
* The Simulator can be run firectly from the IDE in debug/release mode. 
* The application can also be run from the command line terminal.
    * Run in debug mode: .\x64\Debug\ToyRobotSimulator.exe
* The application can also be run from the command line terminal.
    * Run in release mode: .\x64\Release\ToyRobotSimulator.exe
* The commands are case insensitive.
* Any additional whitespace before, after or in-between the command and the parameter list are taken care of. The command still executes correctly.
    
# Run Test
The unit test suite is developed using Boost.Test adaptor. Boost.Test required Boost libraries. Please refer the following tutoroal links to install Boost, write test and run them.
   * `https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-boost-test-for-cpp?view=vs-2022`
   * `https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2022`
   * `https://www.boost.org/doc/libs/1_46_0/libs/test/doc/html/utf.html`
   
The test suite is to be run on the Test Explorer. The Test Explorer can be opened by: Test -> Test Explorer.

A total of 33 test cases have been written in two suites: for Robot and Simulator classes' methods that covers sunnyday test scenarios, rainyday scenarios, edge and out of bound scenarios for the Robot's movement and also for verifying validity of the the commands (with/without parameters). 
