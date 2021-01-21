#include <iostream>
using namespace std;

#define stack_init_size 100 //栈的初始分配空间大小
#define stackincrement 10   //栈的分配增量
typedef route selemtype;

class sqstack
{
public:
    void initstack();         //初始化栈
    void push(selemtype var); //入栈
    void pop(selemtype &var); //出栈
    bool stackempty();        //栈空
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