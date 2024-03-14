#include"Backtrack00.h"
#include<iostream>
#include<cmath>

using namespace std;

N_queen::N_queen()
{
    n=0;
    sum=0;
    for(int i=1;i<=100;i++)//从1行开始存
    {
        result[i]=0;
    }
}

N_queen::~N_queen()
{

}

void N_queen::set_n()
{
    cout<<"请输入棋盘格行数（列数）"<<endl;
    cin>>n;
}

bool N_queen::is_place(int d)//用来判断已经放好的和要放的是否可以共存
{
    for(int i=1;i<d;i++)//从第一行开始比较，需要确保新生成的和每一个已经放好的都不冲突
    {
        if(result[i]==result[d]||(abs(result[i]-result[d])==abs(i-d)))
        {
            return false;
        }
    }
    return true;//所有的遍历完才能确定不冲突
}

void N_queen::backtrack(int t)
{
    //cout<<"t="<<t<<"n="<<n<<endl;
    if(t>n)
    {
        sum++;
        for(int i=1;i<=n;i++)
        {
            cout<<"第"<<i<<"个棋子放在第"<<i<<"行"<<"第"<<result[i]<<"列"<<endl;
        }
        cout<<"***********************"<<endl;;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            result[t]=i;
            if(is_place(t))
            {
                backtrack(t+1);//!递归出来后，回到这里，此时t还是t(函数不改变t的值），继续循环
            }
        }
    }

}

Subset::Subset()
{
    for(int i=1;i<=100;i++)
    {
        S[i]=0;
    }
    for(int i=1;i<=100;i++)
    {
        result[i]=0;
    }
    M=0;
    n=0;
    flag=0;
    sum=0;
//    sum_m=0;
    number=0;
  //  sum_n=0;
}

Subset::~Subset()
{

}

void Subset::set_in()
{
    cout<<"请输入集合长度"<<endl;
    cin>>n;
    cout<<"请输入集合"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>S[i];
       // sum_n+=S[i];
    }
   // cout<<sum_n;
    cout<<"请输入和"<<endl;
    cin>>M;

}

int Subset::get_sn()
{
    int sn;
    for(int i=1;i<=n;i++)
    {
        sn+=S[i];
    }
    return sn;
}

void Subset::backtrack(int sm,int sn,int t)
{
   // cout<<"t="<<t<<"n="<<n<<endl;
    if(t>n)//t=n+1 遍历到叶子结点
    {
//        cout<<sum_m<<"=sum"<<endl;
        if(sm==M)
        {
            //cout<<"hh"<<endl;

            number++;
            for(int i=1;i<=n;i++)
            {

                if(result[i]==1)
                {
                    flag=1;
                    cout<<S[i]<<" ";
                }
                //cout<<result[i]<<" ";
            }
            if(flag==1)
                cout<<endl;
        }

    }
    else
    {
        //!sum_m和sum_n不能作全局，需要变化，每一次回溯，代表当前值,t也代表当前值，递归出来后，t的值不变，函数只是其副本
        //1往左扩展代表选择，0往右扩展代表不选择
        //!递归回来后，一定要保持原来的状态不变，若sm不在函数体定义，则递归出来后，需要处理sm，sm=sm-s[t]
        //！剪枝条件面对负数不成立
        //!左剪枝=号的问题！！！，当等于M不可以直接剪，影响到一个结点的生成，如果直接剪掉加上后等于M的结点，则是错误的
        if(sm+S[t]<=M)//如果还没到M，选择
        {
            result[t]=1;
            backtrack(sm+S[t],sn-S[t],t+1);

        }
        if(sm+sn>M)//当已经加上的数和和未被选择的数的和小于需要得到的和，右边的可以直接剪枝放弃
        {
            result[t]=0;
            backtrack(sm,sn-S[t],t+1);

        }
    }


}

void Subset::backtrack_f(int f)
{
    if(f>n)
    {
        if(sum==M)
        {
           number++;
            for(int i=1;i<=n;i++)
            {

                if(result[i]==1)
                {
                    flag=1;
                    cout<<S[i]<<" ";
                }
                //cout<<result[i]<<" ";
            }
            if(flag==1)
                cout<<endl;
        }
    }
    else
    {
        result[f]=1;
        sum+=S[f];
        backtrack_f(f+1);

        result[f]=0;
        sum-=S[f];//!递归回来后要保持原有的状态
        backtrack_f(f+1);
    }
}

void menu()
{
    cout<<"1.n后问题"<<endl;
    cout<<"2.子集和问题"<<endl;
    cout<<"3.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;
}


/*for(int i=0;i<=1;i++)
        {
            result[t]=i;
            //!会溢出，为什么？sum_m=sum_m+result[i]*S[t];
            if(result[i]==1)
            {
                sum_m+=S[t];
            }
            if(result[i]==0)
            {
                sum_m-=S[t];
            }
         //   cout<<sum_m<<endl;
           // cout<<result[t]<<" "<<S[t]<<endl;
            if(sum_m<M)
            {
             //   cout<<"hh"<<endl;
                backtrack(t+1);
            }*/


