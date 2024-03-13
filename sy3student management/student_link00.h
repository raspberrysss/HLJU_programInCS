#ifndef STULINK_H_
#define STULINK_H_
#include<string>

using namespace std;

class Student
{
    private :
        long id;
        string name;
        string sex;
        int age;
        string politics;
        Student * next;
    public:
        Student();
        //Student(Student&S);
        Student(long id_s,string name_s,string sex_s,int age_s,string politics_s,Student * next_s);
        void setinform();
        void setnext(Student *);
        Student * getnext();
        void showinform();
        long getid();
        ~Student();//�����ʣ�delete����ʲôʱ����
};

class Link
{
    private:
        Student * head;
        int num;
         //static int num;//��ΪҪ��Link�ĳ�Ա����������ŷŵ����
    public:
        Link();
        ~Link();//�����д
        Link(int n);
        Link(Link &l);
        void creatlink(int n);
        void output();
        void insert_link(Student * S);//��֪���ˣ���ô�������д�ָ��ò�ƻ�������󣬳��Դ����ñ���
        //void insert_link(Student &s);
        void delete_link(long id_l);
        Student * gethead();//�������Ӻ���
        void connect_link(Link &p);//���ڶ��������ͷָ����ڵ�һ������βָ���next��//��һ���Լ�д��д���ˣ������츳��һ�飡������һ�飡
        void shownum();


};

#endif // STULINK_H_
