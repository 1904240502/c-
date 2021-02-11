/*停车场*/
#pragma once
#include <iostream>
#include "head.h"
using namespace std;

#define stack_init_size 10000 //栈的初始分配空间大小
#define stackincrement 10     //栈的分配增量
typedef PARKING selemtype;

class sqstack
{
public:
    void initstack();         //初始化栈
    void push(selemtype var); //入栈
    void pop(selemtype &var); //出栈
    bool stackempty();        //栈空
    bool stackfull(int n);
    void deleter(selemtype var);

private:
    selemtype data[stack_init_size];
    int top;
};

void sqstack::initstack()
{
    top = -1;
}
void sqstack::push(selemtype var)
{
    if (top == stack_init_size)
        return;
    top++;
    data[top] = var;
}
void sqstack::pop(selemtype &var)
{
    if (top == -1)
        return;
    var = data[top];
    top--;
}
bool sqstack::stackempty()
{
    if (top == -1)
        return true;
    else
        return false;
}
bool sqstack::stackfull(int n)
{
    if (top == n)
        return true;
    else
        return false;
}
void sqstack::deleter(selemtype var)
{
    for (int i = 0; i <= top; i++)
    {
        if (data[i].number == var.number)
        {
            for (int j = i + 1; j <= top; j++)
            {
                data[i] = data[j];
            }
            break;
        }
        else
        {
            cout << "没有该车辆" << endl;
        }
    }
    top--;
}