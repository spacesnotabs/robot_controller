#pragma once

#include <iostream>
#include <utility>
#include <map>

enum Orientation {
    ORI_N = 0,
    ORI_E = 1,
    ORI_S = 2,
    ORI_W = 3,
    ORI_MAX = 4,
};

std::map<Orientation, char> orientationMap {
    {ORI_N, 'N'},
    {ORI_E, 'E'},
    {ORI_S, 'S'},
    {ORI_W, 'W'},
};

/*
Object that defines a robot's position and orientation
*/
class Robot {
public:
    Robot(int x = 0, int y = 0, Orientation o = ORI_N) {
        setCoordinates(x, y); // start robot at passed in arguments
        setOrientation(o);    // start robot passed in orientation
    };

    ~Robot(){};

    void setCoordinates (const int x, const int y) {
        m_coords.first = x;
        m_coords.second = y;
    }

    void setOrientation(const Orientation o) {
        m_orientation = o;
    }

    int getX() { return m_coords.first; }
    int getY() { return m_coords.second; }
    Orientation getOrientation() { return m_orientation; }

private:
    std::pair<int, int> m_coords; // x,y coordinates of robot's current position
    Orientation m_orientation;
};

