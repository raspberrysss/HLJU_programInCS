#include<iostream>
#include"sequence.h"

using namespace std;

const int Maxsize=100;

void Elemt::set_e()
{
    cin>>e;
}

void Elemt::show_e()
{
    cout<<e<<" ";
}

int Elemt::get_e()
{
    return e;
}

void Elemt::assignment(int el)
{
    e=el;
}
Sequence::Sequence()
{
   e_p=new Elemt[Maxsize];//分配数组空间
   if(e_p==NULL){cout<<"分配内存失败"<<endl; }
   length=0;
}

Sequence::~Sequence()
{
    delete []e_p;//释放存储空间，因为e_p指向一个数组空间，所以delete[]e_p
    length=0;
}

void Sequence::set_sequence()
{
    //Elemt e1;
    cout<<"请输入顺序表中元素个数"<<endl;
    cin>>length;
    cout<<"请依次输入元素"<<endl;
    int i;
    for(i=0;i<length;i++)
    {
       e_p[i].set_e();//!输入元素，e_p指向开辟的数组，可代表数组名
    }
}

void Sequence::show_sequence()
{
    for(int i=0;i<length;i++)
    {
        e_p[i].show_e();
    }
    cout<<endl;
}

void Sequence::insert_value(int c)
{
    int i;
    i=0;
    while(c>e_p[i].get_e()&&i<length)//!
    {
        i++;
        //cout<<i<<endl;
    }//记录下来要插入的位置下标值
    cout<<"插入的位置数组下标为"<<i<<endl;
    int j;
    for(j=length-1;j>=i;j--)
    {
       // e_p[j+1].get_e()=e_p[j].get_e();//！左值错误！
        e_p[j+1].assignment(e_p[j].get_e());
    }
    e_p[i].assignment(c);
    length++;
    cout<<length<<endl;
}

/*void Sequence::swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}*/

void Sequence::reverse_e()
{
    int mid;
    mid=length/2;//length-1/2，要分奇偶讨论，奇数不影响，偶数则会无法交换一部分,1 2 3 4 ->4 2 3 1
    int i;
    for(i=0;i<mid;i++)//若只有1 2，等于号就是再换一遍，出现错误，其他情况可以再换一遍，但是也没有什么意义
    {
        int t;
        t=e_p[i].get_e();
        e_p[i].assignment(e_p[length-1-i].get_e());
        e_p[length-1-i].assignment(t);
        //swap(&(e_p[i].get_e()),&(e_p[length-1-i].get_e()));
        //使用引用变量&，会出现下面的错误
        //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'|swap(e_p[i].get_e(),e_p[length-1-i].get_e());
    }
    /*int left=0;//第一个元素的下标
    int right=length-1;//最后一个元素的下标
    mid=(left+right)/2;
    int i,j;
    i=mid-1;
    j=mid+1;*/
}
void Sequence::move_s(int k)
{
    k=k%length;
    //!利用循环不断往后移动，记录最后一位，向前补
    int i;
    for(i=0;i<k;i++)
    {
        int t;
        t=e_p[length-1].get_e();
        int j;
        for(j=length-2;j>=0;j--)
        {
            e_p[j+1].assignment(e_p[j].get_e());
        }
        e_p[0].assignment(t);
    }
    /*int i=0;
    for(i=0;i+k<=length-1;i++)
    {
        e_p[i+k].assignment(e_p[i].get_e());
    }*/

    /*while(i+k>length-1&&i<length)
    {
        e_p[i+k-length].assignment(e_p[i].get_e());
        i++;
    }*///!这个时候后面的数早就已经被替换，没办法再移动到前面

}

void menu()
{
    cout<<"1.测试插入算法"<<endl;
    cout<<"2.测试循环右移算法"<<endl;
    cout<<"3.测试逆置算法"<<endl;
    cout<<"4.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;
}


