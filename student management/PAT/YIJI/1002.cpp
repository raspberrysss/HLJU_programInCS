#include<iostream>
#include<iomanip>
#include<cstdio>

using namespace std;

int main()
{
    int n,a;
    int s1,s2,s3;
    double s4;
    while(cin>>n)
    {
        int i;
        int j=0;
        int k=0;
        int z=0;
        s1=s2=s3=0;
        s4=0.0;
        int b=0;//b也要清零！
        double s44=0.0;
        for(i=0;i<n;i++)
        {
            cin>>a;
            if(a%10==0)
            {
                s1=s1+a;
            }
            if(a%5==1)
            {
                j++;
                if(j%2==1)
                {
                    s2=s2+a;
                }
                else if(j%2==0)
                {
                    s2=s2-a;
                }
            }
            if(a%5==2)
            {
                s3=s3+1;
            }
            if(a%5==3)
            {
                k++;
                s4=s4+a;
            }
            s44=s4/k;
            if(a%5==4)
            {
                z++;
                if(a>b)
                {
                    b=a;
                }
            }

        }
        if(s1==0)
        {
            cout<<"N ";
        }
        else
        {
            cout<<s1<<" ";
        }
        if(s2==0)
        {
            cout<<"N ";
        }
        else
        {
            cout<<s2<<" ";
        }
         if(s3==0)
        {
            cout<<"N ";
        }
        else
        {
            cout<<s3<<" ";
        }
        if(k==0)
        {
            cout<<"N ";
        }
        else
        {
            //printf("%.1lf ",s44);
            cout<<setprecision(1)<<fixed<<s44<<" ";//用（s4/k）就输出inf，为什么呢？,不用fixed也不行

        }
        if(z==0)
        {
            cout<<"N"<<endl;
        }
        else
        {
            cout<<b<<endl;
        }

    }

    return 0;
}
