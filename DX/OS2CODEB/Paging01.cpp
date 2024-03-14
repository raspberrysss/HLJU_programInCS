#include"Paging.h"
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

/*Paging_table_item::Paging_table_item()
{
    id=0;
    num_piece=0;
    now=false;

}

Paging_table_item::~Paging_table_item()
{

}

Paging_table::Paging_table()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j++)
    }
    //for(vector<Paging_table_item>::iterator it=v.begin();it!=v.end();it++)
    //{
     //   it->Paging_table_item();
    //}
}

Paging_table::~Paging_table()
{

}
*/
location_gra::location_gra()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            lo[i][j]=0;
        }
    }
    count_spare=0;
}

location_gra::location_gra(const location_gra &lg)
{
    count_spare=lg.count_spare;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            lo[i][j]=lg.lo[i][j];
        }
    }
}

void location_gra::set_random(int cs)
{
    count_spare=cs;
    int count_t=0;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            lo[i][j]=(rand()%2);
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
             if(lo[i][j]==0)
            {
                count_t++;
            }
            if(count_t>count_spare)
            {
                lo[i][j]=1;
            }

        }
    }


}

void location_gra::show()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<lo[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool location_gra::is_have_spare()
{
    //!Ҳ����count_spare�ж�
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(lo[i][j]==0)
                return true;
        }
    }
    return false;
}

int location_gra::find_s()
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            if(lo[i][j]==0)
            {
                lo[i][j]=1;
                return i*8+j;
            }
        }
    }
    return -1;
}
location_gra::~location_gra()
{

}

FIFO::FIFO()
{
    len_pf=MAX;
    for(int i=0;i<MAX;i++)
    {
        pf[i].number=0;
        pf[i].num_piece=-1;
        pf[i].now=false;
    }
    c_m=0;
    c_q=0;
    c_z=0;
    c_v=0;
}

void FIFO::init_pf(int pf_len)
{
    len_pf=pf_len;
    for(int i=0;i<pf_len;i++)
    {
        pf[i].number=0;
        pf[i].num_piece=-1;
        pf[i].now=false;
    }
}

int FIFO::get_len_pf()
{
    return len_pf;
}

FIFO::~FIFO()
{


}

void FIFO::show()
{
    cout<<"ҳ��\t���\t״̬"<<endl;
    for(int i=0;i<len_pf;i++)
    {
        cout<<pf[i].number<<"\t"<<pf[i].num_piece<<"\t"<<pf[i].now<<endl;
    }

    cout<<"����ͷ--->����β"<<endl;
    for(vector<int>::iterator it=q1.begin();it!=q1.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

void FIFO::show1()
{
    cout<<"ҳ��\t���\t\t״̬"<<endl;
    for(int i=0;i<len_pf;i++)
    {
        cout<<pf[i].number<<"\t"<<pf[i].num_piece<<"\t\t"<<pf[i].now<<endl;
    }

    cout<<"����ͷ--->����β"<<endl;
    for(vector<int>::iterator it=q1.begin();it!=q1.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

void FIFO::show_rate_qy()
{
    double rate;
    rate=(double)c_q/c_v*100;
    cout<<"ȱҳ��Ϊ"<<rate<<"%"<<endl;
}

/*
int ca_f(int add)
{
    int p_n=add/len_pf;//ҳ��
    int p_p=add%len_pf;//ҳ��ƫ����
    //��ҳ������û�д���
    if(pf[p_n].num_piece!=-1)//�п��
    {
        //����
    }
    else//==-1
    {
        if(is_have_spare())
        {

        }
       //���ڴ����п�ʱ
    }
}*/

LRU::LRU()
{
    len_pl=MAX;
    for(int i=0;i<MAX;i++)
    {
        pl[i].number=0;
        pl[i].num_piece=-1;
        pl[i].now=false;
    }
     c_m=c_q=c_z=c_v=0;
}

void LRU::init_pl(int pl_len)
{
    len_pl=pl_len;
    for(int i=0;i<pl_len;i++)
    {
        pl[i].number=0;
        pl[i].num_piece=-1;
        pl[i].now=false;
    }
}

void LRU::show_rate_qy()
{
    double rate;
    //cout<<c_q<<" "<<c_v<<endl;
    //cout<<(double)c_q/c_v;
    rate=(double)c_q/c_v*100;
    cout<<"ȱҳ��Ϊ"<<rate<<"%"<<endl;
}


void LRU::show()
{
    cout<<"ҳ��\t���\t״̬"<<endl;
    for(int i=0;i<len_pl;i++)
    {
        cout<<pl[i].number<<"\t"<<pl[i].num_piece<<"\t"<<pl[i].now<<endl;
    }
    cout<<"����ͷ--->����β"<<endl;
    for(vector<int>::iterator it=q2.begin();it!=q2.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

void LRU::show1()
{
    cout<<"ҳ��\t���\t\t״̬"<<endl;
    for(int i=0;i<len_pl;i++)
    {
        cout<<pl[i].number<<"\t"<<pl[i].num_piece<<"\t"<<pl[i].now<<endl;
    }
    cout<<"����ͷ--->����β"<<endl;
    for(vector<int>::iterator it=q2.begin();it!=q2.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

LRU::~LRU()
{

}

int ca_f(FIFO &f1,location_gra &lg,int add,int piec)
{
    f1.cv_add();
    int add_real=0;
    int p_n=add/(piec*1024);//ҳ��=�߼���ַ/���С��ҳ���С��
     //cout<<p_n<<endl;
    int p_p=add%(piec*1024);//ҳ��ƫ����=�߼���ַ%���С
    //cout<<p_p<<endl;
    //��ҳ������û�д���
   // cout<<f1.pf[p_n].num_piece<<endl;
    if(f1.pf[p_n].num_piece!=-1)//�п��
    {
         f1.cm_add();//����
         add_real=f1.pf[p_n].num_piece*piec*1024+p_p;
    }
    else//==-1
    {
        //���ڴ����п�ʱ
        //cout<<"l"<<endl;
        if(lg.is_have_spare())//�п��У�ֻȱҳ
        {
            f1.cq_add();
            f1.pf[p_n].number=p_n;
            f1.pf[p_n].num_piece=lg.find_s();//���
            f1.pf[p_n].now=true;
            f1.q1.push_back(f1.pf[p_n].number);//ҳ�������
            //cout<<f1.pf[p_n].num_piece<<endl;
            add_real=f1.pf[p_n].num_piece*piec*1024+p_p;
            lg.de_c();

        }
        else//���û�! !�û�������˸���ҳ��
        {
            f1.cq_add();
            f1.cz_add();
            vector<int>::iterator k=f1.q1.begin();
            f1.pf[p_n].number=p_n;
            f1.pf[p_n].num_piece=f1.pf[*k].num_piece;//!�ǰѶ�Ӧ�Ŀ�Ÿ��£�����ҳ��
            f1.pf[p_n].now=true;
            //����֮ǰҳ��
            f1.pf[*k].num_piece=-1;
            f1.pf[*k].now=false;
            f1.q1.erase(k);
            f1.q1.push_back(f1.pf[p_n].number);
            add_real=f1.pf[p_n].num_piece*piec*1024+p_p;

        }

    }
    return add_real;
}

int ca_l(LRU &l1,location_gra &lg,int add,int piec)
{
    l1.cv_add();
    int add_real=0;
    int p_n=add/(piec*1024);//ҳ��=�߼���ַ/���С��ҳ���С��
    int p_p=add%(piec*1024);//ҳ��ƫ����=�߼���ַ%���С
    if(l1.pl[p_n].num_piece!=-1)//�п��
    {
        //!����ʱ�����еķ���β
         int t=l1.pl[p_n].number;
         l1.q2.push_back(t);//������ڶ�β
         for(vector<int>::iterator it=l1.q2.begin();it!=l1.q2.end();it++)
         {
             if(*it==t)//��������ڶ�β����ɾ����
             {
                l1.q2.erase(it);
                break;
             }
         }
         l1.cm_add();//����
         add_real=l1.pl[p_n].num_piece*piec*1024+p_p;
    }
    else//==-1
    {
        //���ڴ����п�ʱ
        //cout<<"l"<<endl;
        if(lg.is_have_spare())//�п��У�ֻȱҳ
        {
            l1.cq_add();
            //cout<<l1.get_cq()<<endl;
            l1.pl[p_n].number=p_n;
            l1.pl[p_n].num_piece=lg.find_s();//���
            l1.pl[p_n].now=true;
            l1.q2.push_back(l1.pl[p_n].number);//ҳ�������
            add_real=l1.pl[p_n].num_piece*piec*1024+p_p;
            lg.de_c();

        }
        else//���û�
        {
            l1.cq_add();
            l1.cz_add();
            vector<int>::iterator k=l1.q2.begin();
            l1.pl[p_n].number=p_n;
            l1.pl[p_n].num_piece=l1.pl[*k].num_piece;
            l1.pl[p_n].now=true;
            //����֮ǰҳ��
            l1.pl[*k].num_piece=-1;
            l1.pl[*k].now=false;
            l1.q2.erase(k);
            l1.q2.push_back(l1.pl[p_n].number);
            add_real=l1.pl[p_n].num_piece*piec*1024+p_p;

        }

    }
    return add_real;
}

int ca_fh(FIFO &f1,location_gra &lg,int add,int piec)
{
    f1.cv_add();
    int add_real=0;

    int p_n=add>>(piec/2+10);//��ʮ���������ƿ��С���ݵĴ���������ҳ��
    //!ҳ��ƫ�������ǰ�ҳ�Ų���ȫ����Ϊ0 ��piec=2��������0000 0111 1111 1111 ������һ���䣬����0��Ϊ0
    //!!!piec=2,��2��11����
    //!���в�����add��Ȼû�б仯������
    //!!��1�ͻ�������⣬Ϊʲô�� 1002 1002 2
    int change=(0xffffffff)<<(piec/2+10);
    change=~change;
    int p_p=add&change;
    //cout<<"p_p:"<<p_p<<endl;
    //cout<<hex<<p_p<<endl;
    //cout<<p_n<<endl;
    //cout<<hex<<add<<endl;
    if(f1.pf[p_n].num_piece!=-1)//�п��
    {
         f1.cm_add();//����
        add_real=(f1.pf[p_n].num_piece<<(piec/2+10))|p_p;
    }
    else//==-1
    {
        //���ڴ����п�ʱ
        //cout<<"l"<<endl;
        if(lg.is_have_spare())//�п��У�ֻȱҳ
        {
            f1.cq_add();
            f1.pf[p_n].number=p_n;
            f1.pf[p_n].num_piece=lg.find_s();//���
            f1.pf[p_n].now=true;
            f1.q1.push_back(f1.pf[p_n].number);//ҳ�������
            add_real=(f1.pf[p_n].num_piece<<(piec/2+10))|p_p;
            //add_real=f1.pf[p_n].num_piece*piec*1024+p_p;
            lg.de_c();

        }
        else//���û�! !�û�������˸���ҳ��
        {
            f1.cq_add();
            f1.cz_add();
            vector<int>::iterator k=f1.q1.begin();

            f1.pf[p_n].number=p_n;
            //cout<<f1.pf[p_n].number<<endl;
            f1.pf[p_n].num_piece=f1.pf[*k].num_piece;//!�ǰѶ�Ӧ�Ŀ�Ÿ��£�����ҳ��
            //cout<<f1.pf[p_n].num_piece<<endl;
            f1.pf[p_n].now=true;
            //����֮ǰҳ��
            f1.pf[*k].num_piece=-1;
            f1.pf[*k].now=false;
            f1.q1.erase(k);
            f1.q1.push_back(f1.pf[p_n].number);
            add_real=(f1.pf[p_n].num_piece<<(piec/2+10))|p_p;
            //cout<<(f1.pf[p_n].num_piece<<(piec/2+10))<<endl;

        }

    }
    return add_real;
}

int ca_lh(LRU &l1,location_gra &lg,int add,int piec)
{
    l1.cv_add();
    int add_real=0;

    int p_n=add>>(piec/2+10);//��ʮ���������ƿ��С���ݵĴ���������ҳ��
    //!ҳ��ƫ�������ǰ�ҳ�Ų���ȫ����Ϊ0 ��piec=2��������0000 0111 1111 1111 ������һ���䣬����0��Ϊ0
    //!!!piec=2,��2��11����
    //!���в�����add��Ȼû�б仯������
    int change=(0xffffffff)<<(piec/2+10);
    change=~change;
    int p_p=add&change;
    //cout<<hex<<p_p<<endl;
    //cout<<p_n<<endl;
    //cout<<hex<<add<<endl;
    if(l1.pl[p_n].num_piece!=-1)//�п��
    {
        //!����ʱ�����еķ���β
         int t=l1.pl[p_n].number;
         l1.q2.push_back(t);//������ڶ�β
         for(vector<int>::iterator it=l1.q2.begin();it!=l1.q2.end();it++)
         {
             if(*it==t)//��������ڶ�β����ɾ����
             {
                l1.q2.erase(it);
                break;
             }
         }
         l1.cm_add();//����
         add_real=(l1.pl[p_n].num_piece<<(piec/2+10))|p_p;
    }
    else//==-1
    {
        //���ڴ����п�ʱ
        //cout<<"l"<<endl;
        if(lg.is_have_spare())//�п��У�ֻȱҳ
        {
            l1.cq_add();
            //cout<<l1.get_cq()<<endl;
            l1.pl[p_n].number=p_n;
            l1.pl[p_n].num_piece=lg.find_s();//���
            l1.pl[p_n].now=true;
            l1.q2.push_back(l1.pl[p_n].number);//ҳ�������
            add_real=(l1.pl[p_n].num_piece<<(piec/2+10))|p_p;
            lg.de_c();

        }
        else//���û�
        {
            l1.cq_add();
            l1.cz_add();
            vector<int>::iterator k=l1.q2.begin();
            l1.pl[p_n].number=p_n;
            l1.pl[p_n].num_piece=l1.pl[*k].num_piece;
            l1.pl[p_n].now=true;
            //����֮ǰҳ��
            l1.pl[*k].num_piece=-1;
            l1.pl[*k].now=false;
            l1.q2.erase(k);
            l1.q2.push_back(l1.pl[p_n].number);
            add_real=(l1.pl[p_n].num_piece<<(piec/2+10))|p_p;

        }

    }
    return add_real;
}

void menu()
{
    cout<<"��ӭ����ҳ���û�ģ�����"<<endl;
    cout<<"������ҳ����������С(kb)�������ڴ����"<<endl;
   // cout<<"����000�˳�ϵͳ"<<endl;
}

void menu2()
{
    cout<<"��ѡ��ʮ�������뻹��ʮ����������"<<endl;
    cout<<"1.ʮ����"<<endl;
    cout<<"2.ʮ������"<<endl;
    cout<<"0.�˳�"<<endl;
}

