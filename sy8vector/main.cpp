#include"sy8v.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

int main(void)
{
    int n;
    char filename1[20];
    cout<<"how many student do you want to input"<<endl;
    cin>>n;
    StudentControl s1(n);
    StudentControl s2(n);
    s1.input();
    s1.sort_s();
    s1.display();
    cout<<"************************************************"<<endl;
    cout<<"enter name for new file"<<endl;
    cin>>filename1;
    s1.write_to_file(filename1);
    /*string filename_s;
    cin>>filename_s;
    ofstream fout(filename_s.c_str());
    fout<<"hello world"<<endl;这样可以*/
    //s2.load_from_file(filename1);
   // s2.display();


    return 0;
}
