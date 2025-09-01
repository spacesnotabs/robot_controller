/*
A simple program which controls two virtual robots moving on a table surface.
The user passes in initial table setup and commands for robots via text file.
The initial table setup is displayed, the robots are moved, and the final table
setup is displayed.
*/
#include "headers/controller.h"
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

/*
Parse a line of text and return a vector of the individual characters
*/
vector<char> parseLine(string line) {
    vector<char> tokens;
    istringstream iss(line);

    // grab individual characters
    string word;
    while (iss >> word) {
        // assume each token is a single character
        tokens.push_back(word[0]);
    }

    return tokens;
}

/*
Convert a character ('0' - '9') to an int
*/
int charToInt(char c) {
    return c - '0';
}

/*
Convert orientation character to enum
*/
Orientation charToEnum(char c) {
    if (c == 'N') return ORI_N;
    else if (c == 'E') return ORI_E;
    else if (c == 'S') return ORI_S;
    else if (c == 'W') return ORI_W;
    return ORI_MAX;
}

int main(int argc, char* argv []) {
    // Read in test file
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>";
        return 1;
    }

    // get filename
    string filename;
    if (argc > 1) {
       filename = argv[1]; 
    }

    // open the file
    string line;
    int line_no = 0;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file!";
        return 1;
    }

    // Create the Controller class
    Controller controller = Controller();

    // Parse each line and execute commands
    while (getline(file, line)) {
        if (line_no == 0) {
            vector<char> coords = parseLine(line);  // upper right coordinates of table e.g. 3 7
            controller.initializeTable(charToInt(coords[0]), charToInt(coords[1]));
        } else if (line_no == 1) {
            vector<char> robot1 = parseLine(line);  // robot 1 starting position e.g. 1 2 N 
            controller.addRobot(charToInt(robot1[0]), charToInt(robot1[1]), charToEnum(robot1[2]));
        } else if (line_no == 2) {
            vector<char> robot2 = parseLine(line);  // robot 2 starting position e.g. 3 5 E 
            controller.addRobot(charToInt(robot2[0]), charToInt(robot2[1]), charToEnum(robot2[2]));
            controller.printTableStatus();
        } else if (line_no == 3) {
            vector<char> commands1 = parseLine(line);  // robot 1 commands e.g. L M L M R M L M
            vector<char>::iterator it = commands1.begin();
            while (it != commands1.end()) {
                controller.executeRobotCommand(0, *it);
                it++;
            }
        } else if (line_no == 4) {
            vector<char> commands2 = parseLine(line);  // robot 2 commands e.g. L M L M R M L M
            vector<char>::iterator it = commands2.begin();
            while (it != commands2.end()) {
                controller.executeRobotCommand(1, *it);
                it++;
            }

            controller.printTableStatus();
        }
        line_no++;
    }

    return 0;
}
