#ifndef OS00_H_
#define OS00_H_
#include<vector>
/*
B 1 3
A 0 4
C 2 5
D 3 2
E 4 4
*/

/*
A 0 4
B 0 3
C 2 5
D 3 2
E 3 4
*/

/*SFJ �����������֪����ô��
A 0 4
B 0 3
C 2 5
D 4 2
E 3 4
*/

using std::string;

class PCB
{
    private:
        string name;//��ҵ��
        int time_sub;//�ύʱ��
        int time_ke;//����ʱ�䣬����ʱ��
        //�û������������ͺ�
        int time_sta;//��ʼʱ��,���㷨�ó���ʼʱ��
        int time_fin;//���ʱ�䣬�ɿ�ʼ�����е���
        int time_tt;//��תʱ�䣬���-�ύ
        double w;//��Ȩw=T/����
        //PCB* next;
    public:
        PCB();
        ~PCB();
        int get_sub(){return time_sub;}
        int get_fin(){return time_fin;}
        int get_ke(){return time_ke;}
        string get_name(){return name;}
        int get_sta(){return time_sta;}
        int get_tt(){return time_tt;}
        double get_w(){return w;}
        //void set_all(int s,int k);
        void set_sub(int s){time_sub=s;}
        void set_k(int k){time_ke=k;}
        void set_name(string n_s){name=n_s;}
        void set_sta(int sta_s){time_sta=sta_s;}
        void ca_fin(){time_fin=time_sta+time_ke;}
        void ca_tt(){time_tt=time_fin-time_sub;}
        void ca_w(){w=(double)time_tt/(double)time_ke;}
        void show();
        void dec_ke(int q_d){time_ke=time_ke-q_d;}

//        void set_next(PCB* p){next=p;};
  //      PCB* get_next(){return next;};

};

/*class PCB_link
{
    private:
        PCB* head;//ͷָ��
        int length;
    public:
        PCB_link();
        ~PCB_link();
};*/

void menu();
void FCFS();
void SJF();
void Time_change();//ʱ��Ƭ��ת
#endif // OS00_H_
