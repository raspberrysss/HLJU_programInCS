#include"Backtrack00.h"
#include<iostream>
#include<cmath>

using namespace std;

N_queen::N_queen()
{
    n=0;
    sum=0;
    for(int i=1;i<=100;i++)//��1�п�ʼ��
    {
        result[i]=0;
    }
}

N_queen::~N_queen()
{

}

void N_queen::set_n()
{
    cout<<"���������̸�������������"<<endl;
    cin>>n;
}

bool N_queen::is_place(int d)//�����ж��Ѿ��źõĺ�Ҫ�ŵ��Ƿ���Թ���
{
    for(int i=1;i<d;i++)//�ӵ�һ�п�ʼ�Ƚϣ���Ҫȷ�������ɵĺ�ÿһ���Ѿ��źõĶ�����ͻ
    {
        if(result[i]==result[d]||(abs(result[i]-result[d])==abs(i-d)))
        {
            return false;
        }
    }
    return true;//���еı��������ȷ������ͻ
}

void N_queen::backtrack(int t)
{
    //cout<<"t="<<t<<"n="<<n<<endl;
    if(t>n)
    {
        sum++;
        for(int i=1;i<=n;i++)
        {
            cout<<"��"<<i<<"�����ӷ��ڵ�"<<i<<"��"<<"��"<<result[i]<<"��"<<endl;
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
                backtrack(t+1);//!�ݹ�����󣬻ص������ʱt����t(�������ı�t��ֵ��������ѭ��
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
    cout<<"�����뼯�ϳ���"<<endl;
    cin>>n;
    cout<<"�����뼯��"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>S[i];
       // sum_n+=S[i];
    }
   // cout<<sum_n;
    cout<<"�������"<<endl;
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
    if(t>n)//t=n+1 ������Ҷ�ӽ��
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
        //!sum_m��sum_n������ȫ�֣���Ҫ�仯��ÿһ�λ��ݣ�����ǰֵ,tҲ����ǰֵ���ݹ������t��ֵ���䣬����ֻ���丱��
        //1������չ����ѡ��0������չ����ѡ��
        //!�ݹ������һ��Ҫ����ԭ����״̬���䣬��sm���ں����嶨�壬��ݹ��������Ҫ����sm��sm=sm-s[t]
        //����֦������Ը���������
        //!���֦=�ŵ����⣡������������M������ֱ�Ӽ���Ӱ�쵽һ���������ɣ����ֱ�Ӽ������Ϻ����M�Ľ�㣬���Ǵ����
        if(sm+S[t]<=M)//�����û��M��ѡ��
        {
            result[t]=1;
            backtrack(sm+S[t],sn-S[t],t+1);

        }
        if(sm+sn>M)//���Ѿ����ϵ����ͺ�δ��ѡ������ĺ�С����Ҫ�õ��ĺͣ��ұߵĿ���ֱ�Ӽ�֦����
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
        sum-=S[f];//!�ݹ������Ҫ����ԭ�е�״̬
        backtrack_f(f+1);
    }
}

void menu()
{
    cout<<"1.n������"<<endl;
    cout<<"2.�Ӽ�������"<<endl;
    cout<<"3.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;
}


/*for(int i=0;i<=1;i++)
        {
            result[t]=i;
            //!�������Ϊʲô��sum_m=sum_m+result[i]*S[t];
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


