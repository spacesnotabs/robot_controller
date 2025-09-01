#pragma once

#include "table.h"
#include "robot.h"
#include <vector>
#include <map>

/* 
Object that defines the controller
*/
class Controller {
public:
    Controller() {
        m_table = Table();
    }

    void addRobot(int x, int y, Orientation o) {
        // Creates and adds a robot to the table
        Robot newRobot = Robot(x, y, o);
        m_robots.push_back(newRobot);
    };

    void initializeTable(const int x, const int y) {
        // Set the upper right coordinates of the table
        m_table.setUpperRightCoordinates(x, y);
    }

    void executeRobotCommand(const int index, char command) {
        // Chooses which function to call based on the command
        if (command == 'M') moveRobot(index);
        else rotateRobot(index, command);
    }

    void moveRobot(const int index) {
        // Get new possible position and orientation
        Robot& robot = m_robots[index];

        int robotX = robot.getX();
        int robotY = robot.getY();
        Orientation robotO = robot.getOrientation();

        int width = m_table.getTableWidth();
        int height = m_table.getTableHeight();

        // Adjust orientation
        if (robotO == ORI_N) robotY += 1;
        else if (robotO == ORI_E) robotX += 1;
        else if (robotO == ORI_S) robotY -= 1;
        else if (robotO == ORI_W) robotX -= 1;

        // Set new coordinates if they are in bounds
        if ((robotX >= 0 && robotX < width) &&
            (robotY >= 0 && robotY < height)) {
            robot.setCoordinates(robotX, robotY);
        } else {
            std::cerr << "Attempted to move robot out of bounds!" << std::endl;
        }

    };

    void rotateRobot(const int index, const char direction) {
        // Rotates the orientation of the robot

        Robot& robot = m_robots[index];
        Orientation orientation = robot.getOrientation();
        int orientationInt = static_cast<int>(orientation);
        int adjustedOrientation = 0;

        // Set the robot's new orientation
        if (direction == 'L') {
            // Rotate counter-clockwise
            // To avoid negative indices, we add the array size to the new index.  We then need to take the modulo of the new index
            // to ensure we are within bounds.
            adjustedOrientation = (orientationInt + ORI_MAX - 1) % ORI_MAX;
        } else if (direction == 'R') {
            // Rotate clockwise
            adjustedOrientation = (orientationInt + 1) % ORI_MAX;
        }

        robot.setOrientation(static_cast<Orientation>(adjustedOrientation));
    };

    void printTable() {
        // Print an ASCII representation of the table
        Robot& robot1 = m_robots[0];
        Robot& robot2 = m_robots[1];

        int robot1X = robot1.getX();
        int robot1Y = robot1.getY();
        Orientation robot1O = robot1.getOrientation();

        int robot2X = robot2.getX();
        int robot2Y = robot2.getY();
        Orientation robot2O = robot2.getOrientation();

        int width = m_table.getTableWidth();
        int height = m_table.getTableHeight();

        int col = 0;
        int row = 0;

        // print header
        std::cout << "  ";
        for (col = 0; col < width; ++col) {
            std::cout << "___";
        }
        std::cout << std::endl;

        // print each row
        for (row = 0; row < height; ++row) {
            int actualRow = height - row - 1;
            std::cout << actualRow;
            for (col = 0; col < width; ++col) {
                if (robot1X == col && robot1Y == actualRow) std::cout << "|" << getRobotWidget(robot1O) << " ";
                else if (robot2X == col && robot2Y == actualRow) std::cout << "|" << getRobotWidget(robot2O) << " ";
                else std::cout << "|  ";
            }
            std::cout << "|" << std::endl;
            std::cout << "  ";
            for (col = 0; col < width; ++col) {
                std::cout << "___";
            }
            std::cout << std::endl;
        }
        
        // print footer
        std::cout << "  ";
        for (col = 0; col < width; ++col) {
            std::cout << " " << col << " ";
        }
        std::cout << std::endl;


    }

    void printTableStatus() {
        // Print the details of the current table status
        std::cout << std::endl << "- Table Status -" << std::endl;
        std::cout << "Upper Right Coordinate: (" << m_table.getUpperRightCoordinates().first << "," << m_table.getUpperRightCoordinates().second << ")" << std::endl;

        for (int ix = 0; ix < m_robots.size(); ++ix) {
            std::cout << "Robot " << ix << ": (" << m_robots[ix].getX() << "," << m_robots[ix].getY() << ") " << orientationMap[m_robots[ix].getOrientation()] << std::endl;
        }

        printTable();
        std::cout << std::endl;
    }

    char getRobotWidget(Orientation orientation) {
        // Get the character representation of the robot
        if (orientation == ORI_N) return '^';
        else if (orientation == ORI_E) return '>';
        else if (orientation == ORI_S) return 'v';
        else if (orientation == ORI_W) return '<';
        else return 'U'; // unknown
    }

private:
    Table m_table;  // the table object the robots live on
    std::vector<Robot> m_robots; // vector that holds the robots that live on the table
};
