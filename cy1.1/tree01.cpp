#include<iostream>
#include"tree00.h"

using namespace std;

Tree::Tree()
{
    age=0;
}

void Tree::getage()
{
    cout<<"please enter the age of the tree"<<endl;
    cin>>age;
}
void Tree::grow(int year)
{
    age=age+year;
}
void Tree::show()
{
    cout<<"the age of this tree is "<<age<<endl;
}

Tree::~Tree()
{

}

