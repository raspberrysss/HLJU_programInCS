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
        ~Student();//有疑问，delete究竟什么时候用
};

class Link
{
    private:
        Student * head;
        int num;
         //static int num;//因为要在Link的成员函数里操作才放到这里！
    public:
        Link();
        ~Link();//不会编写
        Link(int n);
        Link(Link &l);
        void creatlink(int n);
        void output();
        void insert_link(Student * S);//不知道了，怎么传都不行传指针貌似会产生错误，尝试传引用变量
        //void insert_link(Student &s);
        void delete_link(long id_l);
        Student * gethead();//用于连接函数
        void connect_link(Link &p);//将第二个链表的头指针存在第一个链表尾指针的next里//第一次自己写就写对了！代码天赋这一块！聪明这一块！
        void shownum();


};

#endif // STULINK_H_
