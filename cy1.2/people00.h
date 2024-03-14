#ifndef PEOPLE00_H_
#define PEOPLE00_H_

#include<string>

using namespace std;//用到string除了include，还要写这条

class Date
{
    private :
        int year,month,day;
    public:
        Date();//默认构造函数
        Date(int year_d,int month_d,int day_d);//构造函数
        Date(const Date &d);//复制构造函数声明格式,复制函数用于将一个对象复制到新创建的对象中
        ~Date();//析构函数
        void showdate();//显示日期的函数
        void getdate();//写入日期
};

class People
{
   private :
       int num;
       string name;
       long long id;
       Date birth;
   public :
        People();//默认构造
        //People(int num_p,string name_p,long long id_p,Date birth_p);//有参构造，分不同情况!参数给什么，调用什么，如果我参数给的是Date，则调用的是Date的复制构造
        //如果想调用Date的有参构造函数，则提供int x，int y，int z；然后调用Date的有参构造
        People(int num_P,string name_p,long long id_p,int year_p,int month_p,int day_p);
        People(const People &p);//复制构造，调用date的复制构造
        ~People();//析构函数
        void getpeople();
        void showpeople();
};
#endif // PEOPLE00_H_
