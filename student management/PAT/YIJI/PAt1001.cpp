#include<iostream>

using namespace std;

int main(void)
{
    int n;
    int i;
    while(cin>>n)//c++�����ʽ

    {
        for(i=0;i<n;i++)
    {
        double a,b,c;//������������ͱ��double�Ͷ��ˣ�֤��double�ķ�Χ����unsinged int������double ������unsigned ����
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
