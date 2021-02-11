#include "queue.h"
#include "stack.h"
using namespace std;

#define fee 5 //停车每小时费用

void inparking(PARKING &car);
int parking_fee(PARKING car);

int main()
{
    int n;
    /*--------------------------初始停车场位置-------------------------*/
    cout << "请输入停车场的总车位" << endl;
    cin >> n;

    /*--------------------------初始停车场-------------------------*/
    queue q;
    q.initqueue();
    sqstack s;
    s.initstack();
    PARKING car;
    cout << "请输入车辆状态" << endl;
    cout << "1.驶入\t\t2.驶出" << endl;
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        /*-------------------车辆信息初始------------------------------*/
        car.status = "驶入";
        cout << "请输入车辆的车牌号" << endl;
        int numbers;
        cin >> numbers;
        car.numbers(numbers);
        //判断停车场是否已满
        if (s.stackfull(n))
        {
            //停车厂已满车辆入便道
            cout << "停车场已满" << endl;
            q.pushqueue(car);
        }
        else
        {
            //停车场未满车辆入库
            inparking(car);
            s.push(car);
        }
        break;
    case 2:
        car.status = "驶出";
        cout << "请输入车牌号码" << endl;
        cin >> car.number;
        s.deleter(car);
        cout << "您本次的停车费是" << parking_fee(car) << "元" << endl;
        car.status = "驶入";
        q.popqueue(car);
        inparking(car);
        s.push(car);
    default:
        break;
    }
}
//入库时间
void inparking(PARKING &car)
{
    cout << "请输入车辆入库时间" << endl;
    cin >> car.day;
    cout << "天";
    cin >> car.hour;
    cout << "时";
    cin >> car.min;
    cout << "分";
    cin >> car.sec;
    cout << "秒" << endl;
}
//计算车费
int parking_fee(PARKING car)
{
    cout << "请输入车辆出库时间" << endl;
    TIME outtime;
    cin >> outtime.day;
    cout << "天";
    cin >> outtime.hour;
    cout << "时";
    cin >> outtime.min;
    cout << "分";
    cin >> outtime.sec;
    cout << "秒" << endl;
    int x;
    x = (outtime.day * 24 + outtime.hour) - (car.day * 24 + car.hour);
    if (outtime.min != 0 || outtime.sec != 0)
    {
        return (x + 1) * fee;
    }
    else
    {
        return (x)*fee;
    }
    return x;
}