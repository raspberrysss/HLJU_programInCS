#include<iostream>
#include<cstdlib>
#include<ctime>
#include"sort.h"

using namespace std;

Shell_Quick::Shell_Quick()
{
    int i;
    for(i=0;i<=MAX;i++)
    {
        //d[i]=0;
        s1[i]=0;
        s2[i]=0;
    }
    //��s[0]����һ�������㣬Ҳ���Ժ�������
}

Shell_Quick::~Shell_Quick()
{

}

void Shell_Quick::make_s1_s2()
{
    int i;
    int n1,n2;
    int a1,b1,a2,b2;
    srand(time(0));
    cout<<"�������һ�����ݵ����ݸ���"<<endl;
    cin>>n1;
    cout<<"�������һ�����ݵķ�Χ"<<endl;
    cin>>a1>>b1;
    for(i=1;i<=n1;i++)
    {
        s1[i]=((rand()%(b1-a1+1))+1);
    }
    cout<<"������ĵ�һ������Ϊ"<<endl;
    for(i=1;i<=n1;i++)
    {
        cout<<s1[i]<< " ";
    }
    cout<<endl;

    cout<<"������ڶ������ݵ����ݸ���"<<endl;
    cin>>n2;
    cout<<"������ڶ������ݵķ�Χ"<<endl;
    cin>>a2>>b2;
    for(i=1;i<=n2;i++)
    {
        s2[i]=((rand()%(b2-a2+1))+1);
    }
    cout<<"������ĵڶ�������Ϊ"<<endl;
    for(i=1;i<=n2;i++)
    {
        cout<<s2[i]<< " ";
    }
    cout<<endl;
    Shell(n1,n2);
    for(i=1;i<=n1;i++)
    {
        cout<<s1[i]<< " ";
    }
    cout<<endl;
    for(i=1;i<=n2;i++)
    {
        cout<<s2[i]<< " ";
    }
}

void Shell_Quick::Shell(int n_s1,int n_s2)
{
    int i1,j1,gap1;   // gapΪ������ÿ�μ�Ϊԭ����һ�롣
    int compare_c1,move_c1;
    compare_c1=0;
    move_c1=0;
    for (gap1 = n_s1 / 2; gap1 > 0; gap1 /= 2)
    {
        // ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
        for (i1 = 1;i1 <= gap1; i1++)
        {
            for (j1 = i1 + gap1; j1 <= n_s1; j1 += gap1)
            {
                // ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
                if (s1[j1] < s1[j1 - gap1])
                {
                    compare_c1++;
                    int tmp = s1[j1];
                    int k = j1 - gap1;
                    while (k >= 0 && s1[k] > tmp)
                    {
                        move_c1++;
                        s1[k + gap1] = s1[k];
                        k -= gap1;
                    }
                    s1[k + gap1] = tmp;
                }
            }
        }
    }
    int i2,j2,gap2;   // gapΪ������ÿ�μ�Ϊԭ����һ�롣
    int compare_c2,move_c2;
    compare_c2=0;
    move_c2=0;
    for (gap2 = n_s2 / 2; gap2 > 0; gap2 /= 2)
    {
        // ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
        for (i2 = 1;i2 <= gap2; i2++)
        {
            for (j2 = i2 + gap2; j2<= n_s2; j2 += gap2)
            {
                // ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
                if (s2[j2] < s2[j2 - gap2])
                {
                    compare_c2++;
                    int tmp = s2[j2];
                    int k = j2 - gap2;
                    while (k >= 0 && s2[k] > tmp)
                    {
                        move_c2++;
                        s2[k + gap2] = s2[k];
                        k -= gap2;
                    }
                    s2[k + gap2] = tmp;
                }
            }
        }
    }



    /*int i,j;
    //int dk;
    //dk=n_s;
    //cout<<(1/2);
    //while(dk>=1)//����ÿ�ζ���ȡһ�룬��whileѭ��ʵ��Ҳ����,��̫���ԣ��ȷ���
    //{

        //dk=n_s/2;//������Ϊn_s/2��ֱ�Ӳ�������
        cout<<dk;
        //!��ÿһ�����鶼����ֱ�Ӳ�������
       // cout<<"dk=="<<dk<<endl;
        for(i=dk+1;i<=n_s;i++)
        {
            //cout<<i;
            //cout<<"2p"<<endl;
            if(s1[i]<s1[i-dk])
            {
                s1[0]=s1[i];
                for(j=i-dk;j>0&&s1[0]<s1[j];j=j-dk)
                {
                    s1[j+dk]=s1[j];
                }
                s1[j+dk]=s1[0];
            }
        }

        for(i=dk+1;i<=n_s;i++)
        {
            //cout<<i;
            //cout<<"2p"<<endl;
            if(s1[i]<s1[i-dk])
            {
                s1[0]=s1[i];
                for(j=i-dk;j>0&&s1[0]<s1[j];j=j-dk)
                {
                    s1[j+dk]=s1[j];
                }
                s1[j+dk]=s1[0];
            }
        }

    //}*/



}






