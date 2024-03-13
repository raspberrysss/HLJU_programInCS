#ifndef SONGER00_H_
#define SONGER00_H_

#include<iostream>
#include<string>

using namespace std;
//static int num_songer;可以不在成员里声明吗？

class Songer
{
   private:
       string name;
       int fans_count;
       static int num_songer;
   public:
       Songer();
       Songer(string name_s, int fans_count_s );
       ~Songer();
       Songer(const Songer &s);
       void setcount();
       void showcount();
       void showsonger();
       void shownum();//¾²Ì¬³ÉÔ±º¯Êý静态成员函数
       //friend bool PK(const Songer &s1,const Songer &s2);
       friend int PK(const Songer &s1,const Songer &s2);//友元函数可以使非成员函数直接访问类的私有成员
};
#endif // SONGER00_H_
