# Toy Robot Simulator Coding Challenge
The detailed requirements and description of this coding challeneg is providied in the Toy Robot Code Challenge.pdf.

# Development Environment
The solution to this coding challenge has been developed on Visual Studio 2022 with toolset version v143 and supports C++ 20.
The projects ToyRobotSimulator and ToyRobotSimulatorUnitTest are console application whereas the project ToyRobotSimulatorLib is a static librray project.

# Run Application
* The Simulator can be run firectly from the IDE in debug/release mode. 
* The application can also be run from the command line terminal.
    * Run in debug mode: .\x64\Debug\ToyRobotSimulator.exe
* The application can also be run from the command line terminal.
    * Run in release mode: .\x64\Release\ToyRobotSimulator.exe
    
# Run Test
The unit test suite is developed using Boost.Test adaptor. Boost.Test required Boost libraries. Please refer the following tutoroal links to install Boost, write test and run them.
   * `https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-boost-test-for-cpp?view=vs-2022`
   * `https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2022`
   * `https://www.boost.org/doc/libs/1_46_0/libs/test/doc/html/utf.html`
   
The test suite is to be run on the Test Explorer. The Test Explorer can be opened by: Test -> Test Explorer.

A total of 33 test cases have been written in two suites: for Robot and Simulator classes' methods that covers sunnyday test scenarios, rainyday scenarios, edge and out of bound scenarios for the Robot's movement and also for verifying validity of the the commands (with/without parameters). 
