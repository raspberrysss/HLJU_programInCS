#ifndef SONGER_H_
#define SONGER_H_
#include<string>//��stringһ��Ҫ�������std

using namespace std;

class Songer
{
    private:
        string name;
        int fans_count;
        static int songer_num;
    public:
        Songer();
        Songer(string name_s,int fans_count_s);
        ~Songer();
        Songer(const Songer &s);
        void setinform();
        void shownum();
        void showfans();
        Songer operator+(int add);
        bool operator>(Songer &s);
        friend bool operator==(Songer &s1,Songer &s2);
        Songer  operator++();//ǰ׺++
        friend Songer  operator++(Songer &s,int s_i=0);//��׺++,��Ҫ��int�������֣�Ĭ�ϲ�����Ϊ0
        /*void operator++();//�޷���ֵ�Ͳ�������
        friend void operator++(Songer &s);*/
        friend ostream & operator<<(ostream &os,Songer &s);

};
#endif // SONGER_H_
