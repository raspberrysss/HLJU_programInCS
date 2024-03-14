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
    //!也可用count_spare判断
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
    cout<<"页号\t块号\t状态"<<endl;
    for(int i=0;i<len_pf;i++)
    {
        cout<<pf[i].number<<"\t"<<pf[i].num_piece<<"\t"<<pf[i].now<<endl;
    }

    cout<<"队列头--->队列尾"<<endl;
    for(vector<int>::iterator it=q1.begin();it!=q1.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

void FIFO::show1()
{
    cout<<"页号\t块号\t\t状态"<<endl;
    for(int i=0;i<len_pf;i++)
    {
        cout<<pf[i].number<<"\t"<<pf[i].num_piece<<"\t\t"<<pf[i].now<<endl;
    }

    cout<<"队列头--->队列尾"<<endl;
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
    cout<<"缺页率为"<<rate<<"%"<<endl;
}

/*
int ca_f(int add)
{
    int p_n=add/len_pf;//页号
    int p_p=add%len_pf;//页内偏移量
    //找页表里有没有存在
    if(pf[p_n].num_piece!=-1)//有块号
    {
        //命中
    }
    else//==-1
    {
        if(is_have_spare())
        {

        }
       //当内存中有空时
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
    cout<<"缺页率为"<<rate<<"%"<<endl;
}


void LRU::show()
{
    cout<<"页号\t块号\t状态"<<endl;
    for(int i=0;i<len_pl;i++)
    {
        cout<<pl[i].number<<"\t"<<pl[i].num_piece<<"\t"<<pl[i].now<<endl;
    }
    cout<<"队列头--->队列尾"<<endl;
    for(vector<int>::iterator it=q2.begin();it!=q2.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

void LRU::show1()
{
    cout<<"页号\t块号\t\t状态"<<endl;
    for(int i=0;i<len_pl;i++)
    {
        cout<<pl[i].number<<"\t"<<pl[i].num_piece<<"\t"<<pl[i].now<<endl;
    }
    cout<<"队列头--->队列尾"<<endl;
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
    int p_n=add/(piec*1024);//页号=逻辑地址/块大小（页面大小）
     //cout<<p_n<<endl;
    int p_p=add%(piec*1024);//页内偏移量=逻辑地址%块大小
    //cout<<p_p<<endl;
    //找页表里有没有存在
   // cout<<f1.pf[p_n].num_piece<<endl;
    if(f1.pf[p_n].num_piece!=-1)//有块号
    {
         f1.cm_add();//命中
         add_real=f1.pf[p_n].num_piece*piec*1024+p_p;
    }
    else//==-1
    {
        //当内存中有空时
        //cout<<"l"<<endl;
        if(lg.is_have_spare())//有空闲，只缺页
        {
            f1.cq_add();
            f1.pf[p_n].number=p_n;
            f1.pf[p_n].num_piece=lg.find_s();//块号
            f1.pf[p_n].now=true;
            f1.q1.push_back(f1.pf[p_n].number);//页号入队列
            //cout<<f1.pf[p_n].num_piece<<endl;
            add_real=f1.pf[p_n].num_piece*piec*1024+p_p;
            lg.de_c();

        }
        else//需置换! !置换后别忘了更改页表
        {
            f1.cq_add();
            f1.cz_add();
            vector<int>::iterator k=f1.q1.begin();
            f1.pf[p_n].number=p_n;
            f1.pf[p_n].num_piece=f1.pf[*k].num_piece;//!是把对应的块号更新，不是页号
            f1.pf[p_n].now=true;
            //更改之前页表
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
    int p_n=add/(piec*1024);//页号=逻辑地址/块大小（页面大小）
    int p_p=add%(piec*1024);//页内偏移量=逻辑地址%块大小
    if(l1.pl[p_n].num_piece!=-1)//有块号
    {
        //!命中时把命中的放在尾
         int t=l1.pl[p_n].number;
         l1.q2.push_back(t);//把其放在队尾
         for(vector<int>::iterator it=l1.q2.begin();it!=l1.q2.end();it++)
         {
             if(*it==t)//！把其放在队尾，后删除它
             {
                l1.q2.erase(it);
                break;
             }
         }
         l1.cm_add();//命中
         add_real=l1.pl[p_n].num_piece*piec*1024+p_p;
    }
    else//==-1
    {
        //当内存中有空时
        //cout<<"l"<<endl;
        if(lg.is_have_spare())//有空闲，只缺页
        {
            l1.cq_add();
            //cout<<l1.get_cq()<<endl;
            l1.pl[p_n].number=p_n;
            l1.pl[p_n].num_piece=lg.find_s();//块号
            l1.pl[p_n].now=true;
            l1.q2.push_back(l1.pl[p_n].number);//页号入队列
            add_real=l1.pl[p_n].num_piece*piec*1024+p_p;
            lg.de_c();

        }
        else//需置换
        {
            l1.cq_add();
            l1.cz_add();
            vector<int>::iterator k=l1.q2.begin();
            l1.pl[p_n].number=p_n;
            l1.pl[p_n].num_piece=l1.pl[*k].num_piece;
            l1.pl[p_n].now=true;
            //更改之前页表
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

    int p_n=add>>(piec/2+10);//把十六进制右移块大小的幂的次数，就是页号
    //!页内偏移量就是把页号部分全部变为0 若piec=2，则与上0000 0111 1111 1111 ，碰上一不变，碰上0变为0
    //!!!piec=2,是2的11次幂
    //!进行操作后add居然没有变化？？？
    //!!用1就会出现问题，为什么？ 1002 1002 2
    int change=(0xffffffff)<<(piec/2+10);
    change=~change;
    int p_p=add&change;
    //cout<<"p_p:"<<p_p<<endl;
    //cout<<hex<<p_p<<endl;
    //cout<<p_n<<endl;
    //cout<<hex<<add<<endl;
    if(f1.pf[p_n].num_piece!=-1)//有块号
    {
         f1.cm_add();//命中
        add_real=(f1.pf[p_n].num_piece<<(piec/2+10))|p_p;
    }
    else//==-1
    {
        //当内存中有空时
        //cout<<"l"<<endl;
        if(lg.is_have_spare())//有空闲，只缺页
        {
            f1.cq_add();
            f1.pf[p_n].number=p_n;
            f1.pf[p_n].num_piece=lg.find_s();//块号
            f1.pf[p_n].now=true;
            f1.q1.push_back(f1.pf[p_n].number);//页号入队列
            add_real=(f1.pf[p_n].num_piece<<(piec/2+10))|p_p;
            //add_real=f1.pf[p_n].num_piece*piec*1024+p_p;
            lg.de_c();

        }
        else//需置换! !置换后别忘了更改页表
        {
            f1.cq_add();
            f1.cz_add();
            vector<int>::iterator k=f1.q1.begin();

            f1.pf[p_n].number=p_n;
            //cout<<f1.pf[p_n].number<<endl;
            f1.pf[p_n].num_piece=f1.pf[*k].num_piece;//!是把对应的块号更新，不是页号
            //cout<<f1.pf[p_n].num_piece<<endl;
            f1.pf[p_n].now=true;
            //更改之前页表
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

    int p_n=add>>(piec/2+10);//把十六进制右移块大小的幂的次数，就是页号
    //!页内偏移量就是把页号部分全部变为0 若piec=2，则与上0000 0111 1111 1111 ，碰上一不变，碰上0变为0
    //!!!piec=2,是2的11次幂
    //!进行操作后add居然没有变化？？？
    int change=(0xffffffff)<<(piec/2+10);
    change=~change;
    int p_p=add&change;
    //cout<<hex<<p_p<<endl;
    //cout<<p_n<<endl;
    //cout<<hex<<add<<endl;
    if(l1.pl[p_n].num_piece!=-1)//有块号
    {
        //!命中时把命中的放在尾
         int t=l1.pl[p_n].number;
         l1.q2.push_back(t);//把其放在队尾
         for(vector<int>::iterator it=l1.q2.begin();it!=l1.q2.end();it++)
         {
             if(*it==t)//！把其放在队尾，后删除它
             {
                l1.q2.erase(it);
                break;
             }
         }
         l1.cm_add();//命中
         add_real=(l1.pl[p_n].num_piece<<(piec/2+10))|p_p;
    }
    else//==-1
    {
        //当内存中有空时
        //cout<<"l"<<endl;
        if(lg.is_have_spare())//有空闲，只缺页
        {
            l1.cq_add();
            //cout<<l1.get_cq()<<endl;
            l1.pl[p_n].number=p_n;
            l1.pl[p_n].num_piece=lg.find_s();//块号
            l1.pl[p_n].now=true;
            l1.q2.push_back(l1.pl[p_n].number);//页号入队列
            add_real=(l1.pl[p_n].num_piece<<(piec/2+10))|p_p;
            lg.de_c();

        }
        else//需置换
        {
            l1.cq_add();
            l1.cz_add();
            vector<int>::iterator k=l1.q2.begin();
            l1.pl[p_n].number=p_n;
            l1.pl[p_n].num_piece=l1.pl[*k].num_piece;
            l1.pl[p_n].now=true;
            //更改之前页表
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
    cout<<"欢迎来到页面置换模拟程序"<<endl;
    cout<<"请输入页面个数，块大小(kb)，空闲内存个数"<<endl;
   // cout<<"输入000退出系统"<<endl;
}

void menu2()
{
    cout<<"请选择十进制输入还是十六进制输入"<<endl;
    cout<<"1.十进制"<<endl;
    cout<<"2.十六进制"<<endl;
    cout<<"0.退出"<<endl;
}

