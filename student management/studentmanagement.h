#ifndef STUMANA_H_
#define STUMANA_H_

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
        Student(const Student&d);
        Student(long id_s,string name_s,string sex_s,int age_s,string politics_s,Student * next_s);
        void setinform();
        void setnext(Student *);
        Student * getnext();
        void showinform();
        long getid();
        Student & getstudent();
        ~Student();
};

class Link
{
    private:
        Student * head;
        int num;
    public:
        Link();
        ~Link();
        Link(int n);
        Link(const Link &l);
        void creatlink(int n);
        void output();
        void insert_link(Student * S);
        void delete_link(long id_l);
        Student * gethead();//用于连接函数
        void connect_link(Link &p);//将第二个链表的头指针存在第一个链表尾指针的next里//第一次自己写就写对了！代码天赋这一块！聪明这一块！
        void shownum();

};
#endif // STUMANA_H_
