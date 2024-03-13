#include"sy8v.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

Student::Student()
{
    id=0;
    name="no mame";
    sex="no sex";
    score=0;
}

Student::Student(long id_s,string name_s,string sex_s, int score_s)
{
    id=id_s;
    name=name_s;
    sex=sex_s;
    score=score_s;
}

Student::Student(const Student &S)
{
    id=S.id;
    name=S.name;
    sex=S.sex;
    score=S.score;
}

/*void Student::setinform(int id_e,string name_e,string sex_e,int score_e)
{
    id=id_e;
    name=name_e;
    sex=sex_e;
    score=score_e;

}//用push——back（）*/

void Student::setinform()
{
    cin>>id;
    cin>>name;
    cin>>sex;
    cin>>score;

}//不用push——back（）

void Student::showinform()
{
    //cout<<"the information is"<<endl;
    cout<<id<<" "<<name<<" "<<sex<<" "<<score<<endl;
}

Student::~Student()
{

}

StudentControl::StudentControl()
{
    vecStu.resize(0);
    num=0;
}

bool operator<(Student &s1,Student &s2)
{
    if(s1.score<s2.score)
        return true;
    else
        return false;
}

StudentControl::StudentControl(int num_c)
{
    num=num_c;
    vecStu.resize(num_c);
}

/*void StudentControl::show(vecStu &v)
{
    v.showinform();
}*/
void StudentControl::display()
{
    int i;
    for(i=0;i<num;i++)
    {
         vecStu[i].showinform();
    }
}

void StudentControl::input()
{
    cout<<"please input the information of the student(eg 20213456 nancy f 88)"<<endl;
    int i;
    for(i=0;i<num;i++)
    {
        vecStu[i].setinform();
    }
}//no push_back();
void StudentControl::sort_s()
{
    sort(vecStu.begin(),vecStu.end());
}

void StudentControl:: write_to_file(char *filename)
{
    ofstream fout;//文件作为输出目标
    fout.open(filename);
    int i;
    for(i=0;i<num;i++)
    {
       // cout<<vecStu[i].getid()<<endl;
        fout<<vecStu[i].getid()<<" "<<vecStu[i].getname()<<" "<<vecStu[i].getsex()<<" "<<vecStu[i].getscore()<<endl;
         //vecStu[i].showinform();
        // fout.write(reinterpret_cast<char*>(&vecStu[i]),sizeof(vecStu[i]));
    }
    fout.close();

}
void StudentControl::load_from_file(char *filename)
{
    ifstream fin;//有问题，要大改，写完电路再说
    fin.open(filename);
    int i;
    for(i=0;i<num;i++)
    {
         //input(vecStu[i]);
//         filename.read(reinterpret_cast<char*>(&vecStu[i]),sizeof(vecStu[i]));
    }
}

StudentControl::~StudentControl()
{

}
