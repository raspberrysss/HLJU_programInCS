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
    //将s[0]在这一步就置零，也可以后面置零
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
    cout<<"请输入第一组数据的数据个数"<<endl;
    cin>>n1;
    cout<<"请输入第一组数据的范围"<<endl;
    cin>>a1>>b1;
    for(i=1;i<=n1;i++)
    {
        s1[i]=((rand()%(b1-a1+1))+1);
    }
    cout<<"随机出的第一组数据为"<<endl;
    for(i=1;i<=n1;i++)
    {
        cout<<s1[i]<< " ";
    }
    cout<<endl;

    cout<<"请输入第二组数据的数据个数"<<endl;
    cin>>n2;
    cout<<"请输入第二组数据的范围"<<endl;
    cin>>a2>>b2;
    for(i=1;i<=n2;i++)
    {
        s2[i]=((rand()%(b2-a2+1))+1);
    }
    cout<<"随机出的第二组数据为"<<endl;
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
    int i1,j1,gap1;   // gap为步长，每次减为原来的一半。
    int compare_c1,move_c1;
    compare_c1=0;
    move_c1=0;
    for (gap1 = n_s1 / 2; gap1 > 0; gap1 /= 2)
    {
        // 共gap个组，对每一组都执行直接插入排序
        for (i1 = 1;i1 <= gap1; i1++)
        {
            for (j1 = i1 + gap1; j1 <= n_s1; j1 += gap1)
            {
                // 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
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
    int i2,j2,gap2;   // gap为步长，每次减为原来的一半。
    int compare_c2,move_c2;
    compare_c2=0;
    move_c2=0;
    for (gap2 = n_s2 / 2; gap2 > 0; gap2 /= 2)
    {
        // 共gap个组，对每一组都执行直接插入排序
        for (i2 = 1;i2 <= gap2; i2++)
        {
            for (j2 = i2 + gap2; j2<= n_s2; j2 += gap2)
            {
                // 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
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
    //while(dk>=1)//增量每次都是取一半，用while循环实现也可以,不太可以，先放下
    //{

        //dk=n_s/2;//递增量为n_s/2的直接插入排序
        cout<<dk;
        //!对每一个分组都进行直接插入排序
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






