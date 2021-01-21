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
    route line;
    direction dir = -1;               //定义方向
    line.evaluation(wherestart, dir); //初始位置与方向，-1代表还未走
    sqstack s;
    s.initstack();          //初始化栈
    s.push(line);           //初始位置入栈
    while (!s.stackempty()) //栈空判断
    {
        s.pop(line); //出栈
        coordinate where;
        line.place(where, line); //确定现在位置
        dir++;                   //改变方向
        while (dir < 4)
        {
            line.evaluation(where, dir); //改变方向赋值
            // cout << where.m_x << endl;
            // cout << where.m_y << endl;
            int i = line.m_x;
            int j = line.m_y;
            if (array[i][j] == 0)
            {
                s.push(line);                   //压栈
                line.place(where, line);        //确定位置
                array[line.m_x][line.m_y] = -1; //表示访问过
                if (where.evaluation(whereend))
                {
                    /*---------------输出栈-------------*/
                    sqstack end; //
                    end.initstack();
                    while (!s.stackempty())
                    {
                        s.pop(line);
                        end.push(line);
                    }
                    while (!end.stackempty())
                    {
                        end.pop(line);
                        line.show(line);
                    }
                    return 0;
                }
                else
                    dir = 0; //到达新位置，初始右转
            }
            else
                dir++; //没到达新位置，换方向
        }
    }
}

istream &operator>>(istream &cin, coordinate &where)
{
    cin >> where.m_x >> where.m_y;
    return cin;
}
