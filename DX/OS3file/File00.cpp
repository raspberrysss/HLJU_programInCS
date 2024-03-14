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

void FCB::set_FCB(string n,int s,int f,int fb,FCB* ne,FCB* c)//!先写大小，再写类型，再写第一块
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
    //第一个一定是0，给root
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

void FAT::union_forfile(int s,int start)//s 大小，start 开始下标
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
    fat_table[start]=-1;//!最后start是最后一个内存块
    //int e_flag=1;
//    int index;
    /*while(c_flag!=s&&e_flag)
    {
        for(int i=start;i<MAX;i++)
        {
            if(fat_table[i]==0)//发现有空闲
                {
                    //cout<<start<<endl;
                    fat_table[start]=i;//回填
                    start=i+start;//!妙
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
    //!取出数，再变0，要把那个数记住
    int tmp;
    //!写出来啦！！！
    //!记住的是那个数，就是tmp
    for(int i=f_f;i!=-1;)
    {
        tmp=fat_table[i];
        fat_table[i]=0;
        i=tmp;
    }
    /*int count_s=size_f;
    int tmp=f_f;
    int tmp2=tmp;*/
    /*for(int i=0;i<count_s;i++)//用i控制循环次数，循环占的大小次
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
    //!出错在于i在-1时仍让fat_table[i]赋值
    for(i=f_f;fat_table[i]!=-1;)
    {
        //!死循环
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
    now=new FCB;//now指向新创建的目录
//    now->set_FCB(mn,,2,1,NULL,NULL);
}*/


void menu()
{
    cout<<"md后加目录名 创建目录"<<endl;
    cout<<"rd后加目录名 删除空目录"<<endl;
    cout<<"cd后加目录名 切换目录"<<endl;
    cout<<"dir 显示目录中文件"<<endl;
    cout<<"del后加文件名 删除文件"<<endl;
    cout<<"dir 显示目录中文件"<<endl;
    cout<<"sf 显示fat表"<<endl;
    cout<<"e 退出"<<endl;

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
        cout<<"无内存空间"<<endl;
    }
    else
    {
       //now永远指向当前目录,要在当前目录下建立新目录,切换目录时now也跟着移动过去
       //!目录不仅有一个孩子，只是指向第一个孩子，其他的还要靠next指针去找，找到null后这一层才结束
       FCB* tmp=new FCB;
       tmp->set_FCB(mn,1,2,spare_i,NULL,NULL);
       tmp->set_time();
       fa.zhanyong(spare_i);

       FCB *bb;//遍历指针
       bb=ft.now;//!要从哪里开始遍历？？？还是要当前目录开始遍历，把now指针定位到要加进去的目录
       if(bb->get_c()==NULL)
       {
           //cout<<"1"<<endl;
            bb->set_c(tmp);//要是没有孩子，直接作为孩子挂住
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
           //!找到最后一个结点，挂在它后面
            bb->set_n(tmp);
            /*while(bb->get_c()!=NULL)//根结点next一定是null，往下找就行
           {
               bb=bb->get_c();//直接往后挂吗？
           }*/
       }
       //!挂住，但当前目录不更改
       //ft.now=tmp;//!now指向tmp的意思
       //ft.now->show_n();

       /*!想的有点太复杂了
       //判断当前目录的child指针是不是空，是的话这个目录就是第一个孩子
       if(ft.now->get_c()==NULL)
       {
           ft.now->set_c(tmp);
           ft.now=tmp;//?指针指向谁是左还是右
           //更新now，使其指向目录
       }
       else//不断找，直到找到next是空的
       {
          FCB* b;//遍历指针
          b=ft.root;//从头开始遍历


       }*/
    }
}

void find_m(FCB_tree &ft,string mnf)//树的遍历
{
    if(mnf=="~")
    {
        ft.now=ft.root;
        cout<<"回到根目录"<<endl;
    }
    else
    {
        FCB * bb;
        bb=ft.now;//从当前目录开始遍历
        if(bb->get_c()==NULL)
        {
            cout<<"当前目录为空，无想切换的目录"<<endl;
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
                cout<<"无法找到想要切换的目录"<<endl;
            }
            else
            {
                if(bb->get_flag()==2)
                {
                    cout<<"成功切换"<<endl;
                    ft.now=bb;
                }
                else
                {
                    cout<<"错误指令，非目录"<<endl;
                }

            }
        }
    }
}

void show_dqml(FCB_tree &ft)
{
    FCB* b1;//遍历
    b1=ft.now;
    if(b1->get_c()==NULL)
    {
        cout<<"此为空目录"<<endl;
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
    int spare_first_i=fa.find_spare();//起始下标
    if(fa.ca_0()<s)
    {
        cout<<"无足够内存空间，无法建立"<<endl;
    }
    else
    {

        FCB* tmp=new FCB;//新文件结点
        //挂树和目录结点是一样的
        //!重点是更改一下fat表
        //cout<<"jj4"<<endl;
        tmp->set_FCB(fn,s,1,spare_first_i,NULL,NULL);
        tmp->set_time();
        fa.union_forfile(s,spare_first_i);
        //cout<<"jj6"<<endl;

       FCB *bb;//遍历指针
       bb=ft.now;
       if(bb->get_c()==NULL)
       {
          // cout<<"jj2"<<endl;
            bb->set_c(tmp);//要是没有孩子，直接作为孩子挂住
       }
       else
       {
           bb=bb->get_c();
           while(bb->get_n()!=NULL)
           {
            //   cout<<"jjj"<<endl;
               bb=bb->get_n();
           }
           //!找到最后一个结点，挂在它后面
            bb->set_n(tmp);
       }
       //ft.now->show_n();
    }


}

void remove_d(FCB_tree &ft,FAT &fa,string rdn)//删除文件和删除目录应该可以用一个函数，方法一样
{
    //cout<<ft.now->get_name()<<endl;
    FCB* b;
    FCB* pre;//前置指针
    b=ft.now;
    pre=b;
    if(b->get_c()==NULL)
    {
        cout<<"当前目录下无任何文件，无法查找删除"<<endl;
    }
    else
    {
        b=b->get_c();
        if(b->get_name()==rdn)//第一个孩子结点就是要删除的
        {
            cout<<b->get_flag()<<endl;
            if(b->get_flag()==1)//删文件
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
                    cout<<"此目录不为空，无法删除"<<endl;
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
                cout<<"未查找到想删除的目录或文件"<<endl;
            }
            else
            {
                if(b->get_flag()==1)//删文件
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
    FCB* find_p;//查找指针
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
            cout<<"此目录下已有同名文件，无法创建"<<endl;
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
