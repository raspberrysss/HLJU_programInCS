#ifndef PERSONPS00_H_
#define PERSONPS00_H_

#include<string>

using namespace std;

class Person
{
    private:
        string name;
        string sex;
        int age;
    public:
        Person();
        Person(string name_p,string sex_p,int age_p);
        Person(Person &p);
        ~Person();
        void setinform_p();
        void showinform_p();

};

class Student:public Person
{
    private:
        long num;
        string school;
        string major;
    public:
        Student();
        Student(string name_s,string sex_s,int age_s,long num_s,string school_s,string major_s);
        Student(Student &s);
        ~Student();
        void setinform_s();
        void showinform_s();

};

class Graduate:public Student
{
    private:
        string research_direction;
    public:
        Graduate();
        Graduate(string name_g,string sex_g,int age_g,long num_g,string school_g,string major_g,string research_direction_g);
        Graduate(Graduate &g);
        ~Graduate();
        void setinform_g();
        void showinform_g();

};
#endif // PERSONPS00_H_
