/*车场外的便道*/
#pragma once
#include <iostream>
using namespace std;

#define queue_init_size 100
#define queueincrement 10
typedef PARKING selemtype;

class queue
{
public:
    void initqueue();         //初始化队列
    void pushqueue(selemtype var); //入队
    void popqueue(selemtype &var); //出队
    bool queueempty();        //队空

private:
    selemtype data[queue_init_size];
    int front;
    int rear;
};

void queue::initqueue()
{
    front = 0;
    rear = 0;
}
void queue::pushqueue(selemtype var)
{
    if (front == (rear + 1) % queue_init_size)
        return;
    data[rear] = var;
    rear++;
}
void queue::popqueue(selemtype &var)
{
    if (rear == (front + 1) % queue_init_size)
        return;
    var = data[front];
    front++;
}
bool queue::queueempty()
{
    if (rear == (front + 1) % queue_init_size)
        return true;
    else
        return false;
}