#include"File01.h"
#include<string>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include<ctime>
//#include<stringstream>

using namespace std;

FCB::FCB()
{
    name="no";
    size=0;
    flag=-1;
    first_b=-1;
    child=NULL;
    next=NULL;
    year=month=date=hour=minute=second=0;
//    date="nodate";
}

FCB::~FCB()
{

}

void FCB::set_FCB(string n,int s,int f,int fb,FCB* ne,FCB* c)//!��д��С����д���ͣ���д��һ��
{
    name=n;
    size=s;
    flag=f;
    first_b=fb;
    child=c;
    next=ne;

}

void FCB::set_time()
{
    struct tm *times;
    time_t t;
    t=time(0);
    times=localtime(&t);
    year=(times->tm_yday+1708);
    month=(times->tm_mon+1);
    date=times->tm_mday;
    hour=times->tm_hour;
    minute=times->tm_min;
    second=times->tm_sec;
       /* time_t now=time(NULL);
        tm* t=localtime(&now);
        stringstream ss;
        ss<<t->tm_year+1900<<"."<<t->tm_mon+1<<"."<<t->tm_mday<<".."<<t->tm_hour<<"."<<t->tm_min<<"."<<t->tm_sec;
        cout<<ss.str()<<endl;*/

}

void FCB::show_n()
{
    cout<<name<<":/";
}

void FCB::show()
{
    cout<<year<<"/"<<month<<"/"<<date<<"   "<<hour<<":"<<minute<<":"<<second<<"   ";
    if(flag==2)
    {
        cout<<"<DIR>   ";
    }
    else
    {
        cout<<"        ";
    }
    cout<<name<<endl;
    //<<name<<"       "<<endl;
}

FAT::FAT()
{
    for(int i=0;i<MAX;i++)
    {
        fat_table[i]=0;
    }
}

FAT::~FAT()
{

}

void FAT::makefat()
{
    //��һ��һ����0����root
    for(int i=1;i<MAX;i++)
    {
        fat_table[i]=(rand()%2);
    }

}

void FAT::show_fat()
{
    for(int i=0;i<MAX;i++)
    {
        cout<<fat_table[i]<<" ";
    }
}

int FAT::find_spare()
{
    int t=-1;
    for(int i=0;i<MAX;i++)
    {
        if(fat_table[i]==0)
        {
            t=i;
            break;
        }
    }
    return t;
}

void FAT::union_forfile(int s,int start)//s ��С��start ��ʼ�±�
{
        int c_flag=0;
        for(int i=0;i<MAX;i++)
        {
            if(fat_table[i]==0)
            {
                //cout<<"1"<<start<<endl;
                fat_table[start]=i;
                start=i;
                //cout<<"2"<<start<<endl;
                c_flag++;
                //cout<<"c"<<c_flag<<endl;
                if(c_flag==s)
                {
                    break;
                }
                //continue;
            }
    }
    fat_table[start]=-1;//!���start�����һ���ڴ��
    //int e_flag=1;
//    int index;
    /*while(c_flag!=s&&e_flag)
    {
        for(int i=start;i<MAX;i++)
        {
            if(fat_table[i]==0)//�����п���
                {
                    //cout<<start<<endl;
                    fat_table[start]=i;//����
                    start=i+start;//!��
                    //cout<<start<<endl;
                    c_flag++;
                }
        }
    }*/

}

int FAT::ca_0()
{
    int count_0=0;
    for(int i=0;i<MAX;i++)
    {
        if(fat_table[i]==0)
        {
            count_0++;
        }
    }
    return count_0;
}

void FAT::delete_d(int first)
{
     fat_table[first]=0;
}

void FAT:: delete_f(int f_f,int size_f)
{
    //!ȡ�������ٱ�0��Ҫ���Ǹ�����ס
    int tmp;
    //!д������������
    //!��ס�����Ǹ���������tmp
    for(int i=f_f;i!=-1;)
    {
        tmp=fat_table[i];
        fat_table[i]=0;
        i=tmp;
    }
    /*int count_s=size_f;
    int tmp=f_f;
    int tmp2=tmp;*/
    /*for(int i=0;i<count_s;i++)//��i����ѭ��������ѭ��ռ�Ĵ�С��
    {

    }*/
    /*
    while(count_s--)
    {
        tmp=fat_table[tmp2];
        tmp2=fat_table[fat_table[tmp]];
        //fat_table[tmp2]=0;
        fat_table[tmp]=0;

    }*/
    /*
    //cout<<"1111"<<endl;
    int tmp;
    int i;
    //cout<<f_f<<endl;
    //cout<<size_f<<endl;
    //cout<<"fat_table 10 "<<fat_table[10]<<endl;
    //!��������i��-1ʱ����fat_table[i]��ֵ
    for(i=f_f;fat_table[i]!=-1;)
    {
        //!��ѭ��
        //cout<<"i="<<i<<endl;
        //cout<<fat_table[i]<<endl;
        tmp=fat_table[i];
        if(tmp==-1)
        {
            break;
        }
        cout<<"00000"<<fat_table[tmp]<<endl;
        i=fat_table[tmp];
        cout<<"i="<<i<<endl;
        fat_table[tmp]=0;
        //cout<<"1"<<endl;
    }
    cout<<"hhh"<<endl;
    fat_table[i]=0;
    fat_table[f_f]=0;
     cout<<"i="<<i<<endl;
*/
    /*cout<<f_f<<" "<<size_f<<endl;
    int tmp=0;
    tmp=fat_table[f_f];
    for(int i=0;i<size_f-1;i++)
    {
        //cout<<fat_table[tmp]<<endl;
        //cout<<tmp<<endl;
        fat_table[tmp]=0;
        tmp=fat_table[tmp];
    }
    fat_table[f_f]=0;*/
}


FCB_tree::FCB_tree()
{
    root=NULL;
    now=root;
}

FCB_tree::~FCB_tree()
{

}



void FCB_tree::show_root()
{
    root->show_n();
}

void FCB_tree::show_now()
{
    if(now!=root)
        now->show_n();
}

/*void FCB_tree::create_md(string mn)
{
    now=new FCB;//nowָ���´�����Ŀ¼
//    now->set_FCB(mn,,2,1,NULL,NULL);
}*/


void menu()
{
    cout<<"md���Ŀ¼�� ����Ŀ¼"<<endl;
    cout<<"rd���Ŀ¼�� ɾ����Ŀ¼"<<endl;
    cout<<"cd���Ŀ¼�� �л�Ŀ¼"<<endl;
    cout<<"dir ��ʾĿ¼���ļ�"<<endl;
    cout<<"del����ļ��� ɾ���ļ�"<<endl;
    cout<<"dir ��ʾĿ¼���ļ�"<<endl;
    cout<<"sf ��ʾfat��"<<endl;
    cout<<"e �˳�"<<endl;

}

void init(FCB_tree &ft,FAT &fa)
{
    ft.root=new FCB;
    ft.root->set_FCB("root",1,2,0,NULL,NULL);
    fa.zhanyong(0);
    ft.root->set_time();
    ft.now=ft.root;
    //ft.tail=ft.root;
}

void create_md(FCB_tree &ft,FAT &fa,string mn)
{
    //ft.now=new FCB;
    int spare_i=fa.find_spare();
    if(spare_i==-1)
    {
        cout<<"���ڴ�ռ�"<<endl;
    }
    else
    {
       //now��Զָ��ǰĿ¼,Ҫ�ڵ�ǰĿ¼�½�����Ŀ¼,�л�Ŀ¼ʱnowҲ�����ƶ���ȥ
       //!Ŀ¼������һ�����ӣ�ֻ��ָ���һ�����ӣ������Ļ�Ҫ��nextָ��ȥ�ң��ҵ�null����һ��Ž���
       FCB* tmp=new FCB;
       tmp->set_FCB(mn,1,2,spare_i,NULL,NULL);
       tmp->set_time();
       fa.zhanyong(spare_i);

       FCB *bb;//����ָ��
       bb=ft.now;//!Ҫ�����￪ʼ��������������Ҫ��ǰĿ¼��ʼ��������nowָ�붨λ��Ҫ�ӽ�ȥ��Ŀ¼
       if(bb->get_c()==NULL)
       {
           //cout<<"1"<<endl;
            bb->set_c(tmp);//Ҫ��û�к��ӣ�ֱ����Ϊ���ӹ�ס
       }
       else
       {
           //cout<<"2"<<endl;
           bb=bb->get_c();
           while(bb->get_n()!=NULL)
           {
               //cout<<"3"<<endl;
               bb=bb->get_n();
           }
           //!�ҵ����һ����㣬����������
            bb->set_n(tmp);
            /*while(bb->get_c()!=NULL)//�����nextһ����null�������Ҿ���
           {
               bb=bb->get_c();//ֱ���������
           }*/
       }
       //!��ס������ǰĿ¼������
       //ft.now=tmp;//!nowָ��tmp����˼
       //ft.now->show_n();

       /*!����е�̫������
       //�жϵ�ǰĿ¼��childָ���ǲ��ǿգ��ǵĻ����Ŀ¼���ǵ�һ������
       if(ft.now->get_c()==NULL)
       {
           ft.now->set_c(tmp);
           ft.now=tmp;//?ָ��ָ��˭��������
           //����now��ʹ��ָ��Ŀ¼
       }
       else//�����ң�ֱ���ҵ�next�ǿյ�
       {
          FCB* b;//����ָ��
          b=ft.root;//��ͷ��ʼ����


       }*/
    }
}

void find_m(FCB_tree &ft,string mnf)//���ı���
{
    if(mnf=="~")
    {
        ft.now=ft.root;
        cout<<"�ص���Ŀ¼"<<endl;
    }
    else
    {
        FCB * bb;
        bb=ft.now;//�ӵ�ǰĿ¼��ʼ����
        if(bb->get_c()==NULL)
        {
            cout<<"��ǰĿ¼Ϊ�գ������л���Ŀ¼"<<endl;
        }
        else
        {
            bb=bb->get_c();
            while(bb!=NULL&&bb->get_name()!=mnf&&bb->get_flag()==2)
            {
                bb=bb->get_n();
            }
            if(bb==NULL)
            {
                cout<<"�޷��ҵ���Ҫ�л���Ŀ¼"<<endl;
            }
            else
            {
                if(bb->get_flag()==2)
                {
                    cout<<"�ɹ��л�"<<endl;
                    ft.now=bb;
                }
                else
                {
                    cout<<"����ָ���Ŀ¼"<<endl;
                }

            }
        }
    }
}

void show_dqml(FCB_tree &ft)
{
    FCB* b1;//����
    b1=ft.now;
    if(b1->get_c()==NULL)
    {
        cout<<"��Ϊ��Ŀ¼"<<endl;
    }
    else
    {
        b1=b1->get_c();
       // b1->show();
        while(b1!=NULL)
        {
            b1->show();
            b1=b1->get_n();
        }


    }

}

void create_mk(FCB_tree &ft,FAT &fa,string fn,int s)
{
    int spare_first_i=fa.find_spare();//��ʼ�±�
    if(fa.ca_0()<s)
    {
        cout<<"���㹻�ڴ�ռ䣬�޷�����"<<endl;
    }
    else
    {

        FCB* tmp=new FCB;//���ļ����
        //������Ŀ¼�����һ����
        //!�ص��Ǹ���һ��fat��
        //cout<<"jj4"<<endl;
        tmp->set_FCB(fn,s,1,spare_first_i,NULL,NULL);
        tmp->set_time();
        fa.union_forfile(s,spare_first_i);
        //cout<<"jj6"<<endl;

       FCB *bb;//����ָ��
       bb=ft.now;
       if(bb->get_c()==NULL)
       {
          // cout<<"jj2"<<endl;
            bb->set_c(tmp);//Ҫ��û�к��ӣ�ֱ����Ϊ���ӹ�ס
       }
       else
       {
           bb=bb->get_c();
           while(bb->get_n()!=NULL)
           {
            //   cout<<"jjj"<<endl;
               bb=bb->get_n();
           }
           //!�ҵ����һ����㣬����������
            bb->set_n(tmp);
       }
       //ft.now->show_n();
    }


}

void remove_d(FCB_tree &ft,FAT &fa,string rdn)//ɾ���ļ���ɾ��Ŀ¼Ӧ�ÿ�����һ������������һ��
{
    //cout<<ft.now->get_name()<<endl;
    FCB* b;
    FCB* pre;//ǰ��ָ��
    b=ft.now;
    pre=b;
    if(b->get_c()==NULL)
    {
        cout<<"��ǰĿ¼�����κ��ļ����޷�����ɾ��"<<endl;
    }
    else
    {
        b=b->get_c();
        if(b->get_name()==rdn)//��һ�����ӽ�����Ҫɾ����
        {
            cout<<b->get_flag()<<endl;
            if(b->get_flag()==1)//ɾ�ļ�
            {
          //      cout<<"123456"<<endl;
                //b->get_first();
                //b->get_size();
                fa.delete_f(b->get_first(),b->get_size());
                pre->set_c(b->get_n());
            }
            else if(b->get_flag()==2)
            {
                if(b->get_c()!=NULL)
                {
                    cout<<"��Ŀ¼��Ϊ�գ��޷�ɾ��"<<endl;
                }
                else
                {
                    fa.delete_d(b->get_first());
                    pre->set_c(b->get_n());
                }
            }

        }
        else
        {
           while(b!=NULL&&b->get_name()!=rdn)
            {
                pre=b;
                b=b->get_n();
            }
            if(b==NULL)
            {
                cout<<"δ���ҵ���ɾ����Ŀ¼���ļ�"<<endl;
            }
            else
            {
                if(b->get_flag()==1)//ɾ�ļ�
                {
            //        cout<<"11111"<<endl;
                    //cout<<b->get_first();
                    //cout<<b->get_size();
                    fa.delete_f(b->get_first(),b->get_size());
              //      cout<<"1"<<endl;
                }
                else if(b->get_flag()==2)
                {
                //    cout<<"2"<<endl;
                    fa.delete_d(b->get_first());
                }
                pre->set_n(b->get_n());
            }

    }
        }

}


bool is_samename(FCB_tree &ft,string n)
{
    FCB* find_p;//����ָ��
    find_p=ft.now;
    if(find_p->get_c()==NULL)
    {
        return false;
    }
    else
    {
        find_p=find_p->get_c();
        while(find_p!=NULL&&find_p->get_name()!=n)
        {
            find_p=find_p->get_n();
        }
        if(find_p==NULL)
        {
            return false;
        }
        else
        {
            cout<<"��Ŀ¼������ͬ���ļ����޷�����"<<endl;
            return true;
        }
    }
}
/*MU::MU()
{
    name="no";
}

MU::~MU()
{

}

void MU::set_MU(string s)
{
    name=s;
}*/
