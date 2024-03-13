#ifndef STUVEC_H_
#define STUVEC_H_

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Student
{
    private:
        long id;
        string name;
        string sex;
        int score;
    public:
        Student();
        Student(long id_s,string name_s,string sex_s, int score_s);
        Student(const Student &S);
        //void setinform(int id_e,string name_e,string sex_e,int score_e);
        void setinform();
        void showinform();
        bool friend operator<(Student &s1,Student &s2);
        ~Student();
        long getid(){return id;};
        string getname(){return name;}//���治���ټӣ�
        string getsex(){return sex;}
        int getscore(){return score;}
};

class StudentControl
{
    private:
        vector<Student>vecStu;//������һֱ������Ϊ��.h�ļ��в��ܵ���vector����
        int num;
    public:
        StudentControl();
        StudentControl(int num_c);
        //void show(vecStu &v);
        void display();
        void input();
        void sort_s();
        void load_from_file(char *fielname);
        void write_to_file(char *filename);
        ~StudentControl();
        //bool friend operator<(vecStu v1,vecStu v2);

};

#endif // STUVEC
