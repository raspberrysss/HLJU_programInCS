#include <iostream>
#include"paixu.h"

using namespace std;

int main(void)
{
    int n_m;
    int a[20];
    double b[20];
    char c[20];
    cout<<"please enter the number you want to input"<<endl;
    cin>>n_m;
    cout<<"input the integer"<<endl;
    input(a,n_m);
    mySort(a,n_m);
    show(a,n_m);
    cout<<"input the double"<<endl;
    input(b,n_m);
    mySort(b,n_m);
    show(b,n_m);
    cout<<"input the char"<<endl;
    input(c,n_m);
    mySort(c,n_m);
    show(c,n_m);
    return 0;
}
