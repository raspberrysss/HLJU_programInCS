#ifndef PEOPLE00_H_
#define PEOPLE00_H_

#include<string>

using namespace std;//�õ�string����include����Ҫд����

class Date
{
    private :
        int year,month,day;
    public:
        Date();//Ĭ�Ϲ��캯��
        Date(int year_d,int month_d,int day_d);//���캯��
        Date(const Date &d);//���ƹ��캯��������ʽ,���ƺ������ڽ�һ�������Ƶ��´����Ķ�����
        ~Date();//��������
        void showdate();//��ʾ���ڵĺ���
        void getdate();//д������
};

class People
{
   private :
       int num;
       string name;
       long long id;
       Date birth;
   public :
        People();//Ĭ�Ϲ���
        //People(int num_p,string name_p,long long id_p,Date birth_p);//�вι��죬�ֲ�ͬ���!������ʲô������ʲô������Ҳ���������Date������õ���Date�ĸ��ƹ���
        //��������Date���вι��캯�������ṩint x��int y��int z��Ȼ�����Date���вι���
        People(int num_P,string name_p,long long id_p,int year_p,int month_p,int day_p);
        People(const People &p);//���ƹ��죬����date�ĸ��ƹ���
        ~People();//��������
        void getpeople();
        void showpeople();
};
#endif // PEOPLE00_H_
