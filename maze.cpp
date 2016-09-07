#include <iostream>
#include <vector>

#include "maze.h"

using namespace std;

vector< vector< vector<int> > > mazeMap = {
  {{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
   {WALL, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL},
   {WALL, WALL, WALL, ROAD, WALL, ROAD, WALL, WALL},
   {WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
   {WALL, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, WALL, WALL},
   {WALL, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
   {ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL},
   {WALL, WALL, WALL, WALL, WALL, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD},
   {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}},

  {{WALL, ROAD, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, WALL, WALL},
   {WALL, ROAD, WALL, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
   {ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL},
   {WALL, WALL, WALL, WALL, WALL, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, WALL},
   {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL},
   {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
   {WALL, WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL},
   {WALL, WALL, WALL, ROAD, WALL, ROAD, WALL, WALL},
   {WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL}}
};

Maze::Maze(int _maze, string _wall, string _road, int _anchor_x, int _anchor_y):m_intMaze(_maze) {
  m_strWall = _wall;
  m_strRoad = _road;
  m_iAnchor_x = _anchor_x;
  m_iAnchor_y = _anchor_y;
}

void Maze::setWall(string _wall) {
  m_strWall = _wall;
}

void Maze::setRoad(string _road) {
  m_strRoad = _road;
}

void Maze::setAnchor_x(int _anchor_x) {
  m_iAnchor_x = _anchor_x;
}

void Maze::setAnchor_y(int _anchor_y) {
  m_iAnchor_y = _anchor_y;
}

/* 打印迷宫 */
void Maze::print() const {
  cout << "\e[2J";
  int wall_len = this->m_strWall.size();
  for (int row = 0; row < mazeMap[this->m_intMaze].size(); row++) {
    for (int col = 0; col < mazeMap[this->m_intMaze][row].size(); col++) {
      cout << "\e[" << (row + this-> m_iAnchor_y) << ";" << (col * wall_len + this->m_iAnchor_x) << "H";
      if (mazeMap[this->m_intMaze][row][col] == WALL) {
	cout << this->m_strWall;
      } else if (mazeMap[this->m_intMaze][row][col] == ROAD) {
	cout << this->m_strRoad;
      }
    }
    cout << endl;
  }
}
