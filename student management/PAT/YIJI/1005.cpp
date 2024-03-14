#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct stu
{
    long long num;
    int d;
    int c;
};

bool comp(const stu &s1,const stu &s2)
{
    int sum1,sum2;
    sum1=s1.c+s1.d;
    sum2=s2.c+s2.d;
    if(sum1>sum2)
    {
        return true;
    }
    else if(sum1==sum2)
    {
        if(s1.d>s2.d)
        {
            return true;
        }
        else if(s1.d==s2.d)
        {
            if(s1.num>s2.num)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    stu s[100001];
    vector<stu> vs1;
    vector<stu> vs2;
    vector<stu> vs3;
    vector<stu> vs4;
    int N,L,H;
    cin>>N>>L>>H;
    int M=0;
    int i;
    for( i=0;i<N;i++)
    {
        cin>>s[i].num>>s[i].d>>s[i].c;
    }
    for(i=0;i<N;i++)
    {
        if(s[i].d>=L&&s[i].c>=L)
        {
           M++;
        }
        if(s[i].d>=H&&s[i].c>=H)
        {
            vs1.push_back(s[i]);
        }
        else if(s[i].d>=H&&s[i].c<H&&s[i].c>=L)
        {
            vs2.push_back(s[i]);
        }
        else if(s[i].d>=L&&s[i].c>=L&&s[i].d<H&&s[i].c<H&&(s[i].c<=s[i].d))
        {
            vs3.push_back(s[i]);
        }
        else if(s[i].d>=L&&s[i].c>=L)
        {
            vs4.push_back(s[i]);
        }
    }
    cout<<M<<endl;
    sort(vs1.begin(),vs1.end(),comp);
    for(i=0;i<vs1.size();i++)
    {
        cout<<vs1[i].num<<" "<<vs1[i].d<<" "<<vs1[i].c<<endl;
    }
    sort(vs2.begin(),vs2.end(),comp);
    for(i=0;i<vs2.size();i++)
    {
        cout<<vs2[i].num<<" "<<vs2[i].d<<" "<<vs2[i].c<<endl;
    }
    sort(vs3.begin(),vs3.end(),comp);
    for(i=0;i<vs3.size();i++)
    {
        cout<<vs3[i].num<<" "<<vs3[i].d<<" "<<vs3[i].c<<endl;
    }
    sort(vs4.begin(),vs4.end(),comp);
    for(i=0;i<vs4.size();i++)
    {
        cout<<vs4[i].num<<" "<<vs4[i].d<<" "<<vs4[i].c<<endl;
    }
    return 0;
}
