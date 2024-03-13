#ifndef SONGER_H_
#define SONGER_H_
#include<string>//用string一定要用这个和std

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
        Songer  operator++();//前缀++
        friend Songer  operator++(Songer &s,int s_i=0);//后缀++,需要用int进行区分，默认参数定为0
        /*void operator++();//无返回值就不可以吗
        friend void operator++(Songer &s);*/
        friend ostream & operator<<(ostream &os,Songer &s);

};
#endif // SONGER_H_
