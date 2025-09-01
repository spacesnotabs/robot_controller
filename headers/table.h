#pragma once

/* 
Object that defines the table coordinates and its dimensions
*/
#include <utility>
#include <iostream>

class Table {
public:
    Table() {}
    std::pair<int, int> getUpperRightCoordinates() { return m_upperRight; }
    void setUpperRightCoordinates(int x, int y) {
        m_upperRight.first = x;
        m_upperRight.second = y;
    }

    int getTableWidth() {return m_upperRight.first + 1;}
    int getTableHeight() {return m_upperRight.second + 1;}

private:
    std::pair<int, int> m_upperRight;   // coordinates of upper right point on table
};
