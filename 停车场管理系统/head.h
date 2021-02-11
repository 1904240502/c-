#include <iostream>
#include <string>

using namespace std;

class TIME
{
    public:
        TIME();

    public:
        int day;
        int hour;
        int min;
        int sec;
};
class PARKING : public TIME
{
public:
    void nowstatus(char status);
    void numbers(int number);
    void times(TIME time);
    PARKING operator=(const PARKING P);
    // void s(PARKING P, PARKING s);

public:
    string status;
    int number;
};
TIME::TIME()
{
    day = 0;
    hour = 0;
    min = 0;
    sec = 0;
}
void PARKING::nowstatus(char status) //状态
{
    this->status = status;
}
void PARKING ::numbers(int number) //车牌号
{
    this->number = number;
}
void PARKING ::times(TIME time) //时间
{
    this->day = time.day;
    this->hour = time.hour;
    this->min = time.min;
    this->sec = time.sec;
}

PARKING PARKING::operator=(const PARKING P)
{
    status = P.status;
    number = P.number;
    day = P.day;
    hour = P.hour;
    min = P.min;
    sec = P.sec;
    return *this;
}
// void PARKING::s(PARKING P, PARKING s)
// {
//     *this = P = s;
// }
