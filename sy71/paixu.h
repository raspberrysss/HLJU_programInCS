#ifndef PAIXU_H_
#define PAIXU_H_
#include<iostream>

using namespace std;

template <typename T>
void mySort(T a[],int n)
{
    int i,j;
    T t;
    int min_h;
    for(i=0;i<n-1;i++)
    {
        min_h=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_h])
            {
                min_h=j;
            }
        }
        t=a[i];
        a[i]=a[min_h];
        a[min_h]=t;
    }
}

template <typename T>
void input(T a[],int n)
{
    cout<<"please input the data "<<endl;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

template <typename T>
void show(T a[],int n)
{
    cout<<"the result is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

#endif // PAIXU_H_
