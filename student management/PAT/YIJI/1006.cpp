#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    string a,b;
    char da,db;
    cin>>a>>da>>b>>db;
    vector<char> vc1;//vc[2] is still right
    vector<char> vc2;
    int s1,s2,s3;
    int i;
    for(i=0;i<a.length();i++)
    {
        if(a[i]==da)
        {
            vc1.push_back(a[i]);
        }
    }
    for(i=0;i<b.length();i++)
    {
        if(b[i]==db)
        {
            vc2.push_back(b[i]);
        }
    }
    if(vc1.empty())
    {
        s1=0;
    }
    else{
        for(i=0;i<vc1.size();i++)
    {
        if(i==0)
        {
            s1=vc1[i]-'0';
        }
        else
        {
            s1+=(vc1[i]-'0')*pow(10,i);
        }
    }
    }
    if(vc2.empty())
    {
        s2=0;
    }
    else
    {
        for(i=0;i<vc2.size();i++)
    {
        if(i==0)
        {
            s2=vc2[i]-'0';
        }
        else
        {
            s2+=(vc2[i]-'0')*pow(10,i);
        }
    }
    }
    s3=s1+s2;
    cout<<s3<<endl;

    return 0;
}
