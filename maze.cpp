#include <iostream>
#include <vector>

#include "maze.h"
#include "terminal.h"

using namespace std;


/* 地图的定义 */
vector< vector< vector<int> > > Maze::mazeMap = {
    {{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
     {ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, WALL, WALL, WALL, WALL},
     {WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL},
     {WALL, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD},
     {WALL, ROAD, WALL, WALL, WALL, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL, WALL, WALL, WALL, WALL},
     {WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL, WALL, WALL, WALL},
     {WALL, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL},
     {WALL, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL},
     {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}}
};

Maze::Maze() {
    m_iWallColor = 43;
    m_iRoadColor = 42;
    m_iMap = 0;
    m_iWidth = 32;
    m_iHeight = 15;
}

void Maze::setWallColor(const int _wall_color) {
    m_iWallColor = _wall_color;
}

void Maze::setRoadColor(const int _road_color) {
    m_iRoadColor = _road_color;
}

void Maze::setMap(const int _map) {
    m_iMap = _map;
}

int Maze::getWallColor() const {
    return m_iWallColor;
}

int Maze::getRoadColor() const {
    return m_iRoadColor;
}

int Maze::getMap() const {
    return m_iMap;
}

/* 打印地图 */
void Maze::printSelf() const {
    int anchX = getAnch_x();
    int anchY = getAnch_y();
    for (int row = 0; row < mazeMap[this->m_iMap].size(); row++) {
        for (int col = 0; col < mazeMap[this->m_iMap][row].size(); col++) {
            Terminal::gotoPoint(col + anchX, row + anchY);
            if (mazeMap[this->m_iMap][row][col] == WALL) {
                Terminal::colorPrint(" ", m_iWallColor);
            } else if (mazeMap[this->m_iMap][row][col] == ROAD) {
                Terminal::colorPrint(" ", m_iRoadColor);
            }
        }
    }
}

/* 检查指定坐标在地图上的位置状态 */
int Maze::checkPoint(int _x, int _y) const {
    if (_y < 0 || _y >= mazeMap[this->m_iMap].size()
        || _x < 0 || _x >= mazeMap[this->m_iMap][_y].size()) {
        return MAP_OUT;
    } else if (WALL == mazeMap[this->m_iMap][_y][_x]) {
        return MAP_NO;
    } else {
        return MAP_YES;
    }
}
