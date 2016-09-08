#ifndef PERSON_H
#define PERSON_H

#include "maze.h"

#define MOVE_NO		0 //撞墙
#define MOVE_YES	1 //正常
#define MOVE_OUT	2 //走出迷宫

/* 人类 */
class Person {
 public:
    Person(int _x = 0, int _y = 1, string _body = " ", int _maze = 0, string _wall = " ", string _road = " ", int _anchor_x = 30, int _anchor_y = 5);
    ~Person();
    int moveUp();
    int moveDown();
    int moveLeft();
    int moveRight();
    void print();
    void init();
    int getPosX();
    int getPosY();
    void setPosX();
    void setPosY();
    void setBody(string);
    int checkMove(int _x, int _y);

 private:
    void move(int _x, int _y) ;
    
 private:
    Maze *m_mazeMap;
    int m_iX; //位置横坐标
    int m_iY; //位置纵坐标
    int m_iPreX; //上一个位置横坐标
    int m_iPreY; //上一个位置纵坐标
    //int m_iDirection; //面朝方向
    string m_strBody; //身体形状,可以修改X为其他的东西
};

#endif
