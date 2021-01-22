#pragma once
#include <iostream>
using namespace std;

#define right 0
#define down 1
#define left 2
#define up 3

typedef int direction;

class coordinate
{
public:
    bool evaluation(coordinate where);

public:
    int m_x;
    int m_y;
};

bool coordinate::evaluation(coordinate where)
{
    if (this->m_x == where.m_x && this->m_y == where.m_y)
        return true;
    else
        return false;
}

class route : public coordinate
{
    friend ostream &operator<<(ostream &cout, route &line);

private:
    direction m_dir;

public:
    void place(coordinate &where, route line);
    void judge(coordinate where, direction dir);
    void evaluation(coordinate where, direction dir);
    void dir(direction &dir, route line);
    void show(route line);
};
ostream &operator<<(ostream &cout, route &line);
//确定现在位置
void route::place(coordinate &where, route line)
{
    where.m_x = line.m_x;
    where.m_y = line.m_y;
}
//改变方向后，方向与位置赋值
void route::judge(coordinate where, direction dir)
{
    this->m_dir = dir;
    switch (dir)
    {
    case right:
        this->m_x = where.m_x;
        this->m_y = where.m_y + 1;
        break;
    case down:
        this->m_x = where.m_x + 1;
        this->m_y = where.m_y;
        break;
    case left:
        this->m_x = where.m_x;
        this->m_y = where.m_y - 1;
        break;
    case up:
        this->m_x = where.m_x - 1;
        this->m_y = where.m_y;
        break;
    default:
        break;
    }
}
//坐标及将要进行的方向
void route::evaluation(coordinate where, direction dir)
{
    this->m_dir = dir;
    this->m_x = where.m_x;
    this->m_y = where.m_y;
}
//出栈后确定方向
void route::dir(direction &dir, route line)
{
    dir = line.m_dir;
}
//输出位置与方向
void route::show(route line)
{
    cout << line << endl;
}
//左移重载
ostream &operator<<(ostream &cout, route &line)
{
    cout << "(" << line.m_x << "," << line.m_y << "," << line.m_dir << ")";
    return cout;
}
