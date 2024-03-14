#ifndef DISPATCH_H_
#define DISPATCH_H_

#include<string>

using namespace std;

class PCB
{
    private:
        string name;
        int time_sub;//提交时间
        int time_fin;//完成时间
        int time_sta;//开始时间
    public:
        PCB();
        ~PCB();
        void set_s(int s){time_sub=s;}
        void set_f(int f){time_fin=f;}
        void set_st(int st){time_sta=st;}
};

void menu();

#endif // DISPATH_H_
