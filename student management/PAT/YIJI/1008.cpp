#include<iostream>

using namespace std;

int main()
{
    int n;
    int count_a,count_b,count_p;
    int as_c,as_j,as_b;
    int bs_c,bs_j,bs_b;
    char a[110],b[110];
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        getchar();
        cin>>b[i];
    }
    count_a=count_b=count_p=0;
    as_c=as_b=as_j=bs_j=bs_c=bs_b=0;
    for(i=0;i<n;i++)
    {
        if(a[i]=='J')
        {
            if(b[i]=='J')
            {
               count_p++;
            }
            if(b[i]=='C')
            {
                count_b++;
                bs_c++;
            }
            if(b[i]=='B')
            {
                count_a++;
                as_j++;
            }
        }
        if(a[i]=='C')
        {
            if(b[i]=='C')
            {
               count_p++;
            }
            if(b[i]=='B')
            {
                count_b++;
                bs_b++;
            }
            if(b[i]=='J')
            {
                count_a++;
                as_c++;
            }
        }
        if(a[i]=='B')
        {
            if(b[i]=='B')
            {
               count_p++;
            }
            if(b[i]=='J')
            {
                count_b++;
                bs_j++;
            }
            if(b[i]=='C')
            {
                count_a++;
                as_b++;
            }
        }
    }
    cout<<count_a<<" "<<count_p<<" "<<(n-count_a-count_p)<<endl;
    cout<<count_b<<" "<<count_p<<" "<<(n-count_b-count_p)<<endl;
    //cout<<as_b<<" "<<as_c<<" "<<as_j<<endl;
    //cout<<bs_b<<" "<<bs_c<<" "<<bs_j<<endl;
    if(as_b>as_c&&as_b>as_j)
    {
        cout<<"B"<<" ";
    }
    else if(as_c>as_b&&as_c>as_j)
    {
        cout<<"C"<<" ";
    }
    else if(as_j>as_c&&as_j>as_b)
    {
        cout<<"J"<<" ";
    }
    if(as_b==as_c&&as_b>as_j)
    {
        cout<<"B"<<" ";
    }
    if(as_b==as_j&&as_b>as_c)
    {
        cout<<"B"<<" ";
    }
    if(as_c==as_j&&as_c>as_b)
    {
        cout<<"C"<<" ";
    }
    if(as_b==as_c&&as_b==as_j)
    {
        cout<<"B"<<" ";
    }
    if(bs_b>bs_c&&bs_b>bs_j)
    {
        cout<<"B"<<endl;
    }
    else if(bs_c>bs_b&&bs_c>bs_j)
    {
        cout<<"C"<<endl;
    }
    else if(bs_j>bs_c&&bs_j>bs_b)
    {
        cout<<"J"<<endl;
    }
    if(bs_b==bs_c&&bs_b>bs_j)
    {
        cout<<"B"<<" ";
    }
    if(bs_b==bs_j&&bs_b>bs_c)
    {
        cout<<"B"<<" ";
    }
    if(bs_c==bs_j&&bs_c>bs_b)
    {
        cout<<"C"<<" ";
    }
    if(bs_b==bs_c&&bs_b==bs_j)
    {
        cout<<"B"<<" ";
    }
    return 0;
}//自己一步一步解出来的，真棒！
