#include "head.h"
#include "stack.h"
typedef int graph;

//坐标右移运算符重定义
istream &operator>>(istream &cin, coordinate &where);
int main()
{
    /*----------------------------------创建迷宫-----------------------------------------*/
    int m, n;
    cout << "请输入你要建立迷宫的大小" << endl;
    cin >> n >> m;
    graph array[m + 2][n + 2];
    cout << "建立迷宫0是通路1不能走" << endl;
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i == 0 || j == 0 || i == m + 1 || j == n + 1)
            {
                array[i][j] = 1;
                continue;
            }
            else
            {
                cin >> array[i][j];
            }
        }
    }

    /*----------------------------------走迷宫-----------------------------------------*/
    //定位置
    coordinate wherestart, whereend;
    cout << "请输入迷宫的初始位置" << endl;
    cin >> wherestart;
    cout << "请输入迷宫的终点位置" << endl;
    cin >> whereend;
    //出发
    route line1;
    direction dir = -1;                //定义方向
    line1.evaluation(wherestart, dir); //坐标及将要进行的方向
    array[line1.m_x][line1.m_y] = -1;  //表示访问过
    sqstack s;
    s.initstack();          //初始化栈
    s.push(line1);          //初始位置入栈
    while (!s.stackempty()) //栈空判断
    {
        s.pop(line1); //出栈
        coordinate where;
        line1.place(where, line1); //确定现在位置
        line1.dir(dir, line1);
        while (dir < 4)
        {
            dir++; //改变方向
            line1.evaluation(where, dir);
            route line2; //line1的下一步
            line2.judge(where, dir);
            if (array[line2.m_x][line2.m_y] == 0) //可以走
            {
                array[line2.m_x][line2.m_y] = -1; //表示访问过
                s.push(line1);                    //压栈
                line2.place(where, line2);        //确定新位，判断新位置，是否到终点，没有的话进行下一次位置方向判断
                if (where.evaluation(whereend))
                {
                    /*---------------输出栈-------------*/
                    sqstack end; //
                    end.initstack();
                    while (!s.stackempty())
                    {
                        s.pop(line1);
                        end.push(line1);
                    }
                    while (!end.stackempty())
                    {
                        end.pop(line1);
                        line1.show(line1);
                    }
                    return 0;
                }
                else
                    dir = -1; //到达新位置
            }
        }
    }
}

istream &operator>>(istream &cin, coordinate &where)
{
    cin >> where.m_x >> where.m_y;
    return cin;
}
