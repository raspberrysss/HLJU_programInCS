#include <iostream>
#include"tree00.h"

using namespace std;

int main()
{
    Tree tree1;
    Tree tree2;
    cout<<"test the Ä¬ÈÏº¯Êý"<<endl;
    tree2.show();
    int year;
    tree1.getage();
    cout<<"please enter the year"<<endl;
    cin>>year;
    tree1.grow(year);
    tree1.show();
    return 0;
}
