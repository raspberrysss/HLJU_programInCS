#ifndef DISPATCH_H_
#define DISPATCH_H_

#include<string>

using namespace std;

class PCB
{
    private:
        string name;
        int time_sub;//�ύʱ��
        int time_fin;//���ʱ��
        int time_sta;//��ʼʱ��
    public:
        PCB();
        ~PCB();
        void set_s(int s){time_sub=s;}
        void set_f(int f){time_fin=f;}
        void set_st(int st){time_sta=st;}
};

void menu();

#endif // DISPATH_H_
