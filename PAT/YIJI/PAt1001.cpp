#include<iostream>

using namespace std;

int main(void)
{
    int n;
    int i;
    while(cin>>n)//c++做题格式

    {
        for(i=0;i<n;i++)
    {
        double a,b,c;//这里的数据类型变成double就对了，证明double的范围大于unsinged int，而且double 不能用unsigned 修饰
        cin>>a;
        cin>>b;
        cin>>c;
        if(a+b>c)
        {
            cout<<"Case #"<<(i+1)<<": true"<<endl;
        }
        else
        {
            cout<<"Case #"<<(i+1)<<": false"<<endl;
        }
    }
    }
    return 0;
}
