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
   e_p=new Elemt[Maxsize];//��������ռ�
   if(e_p==NULL){cout<<"�����ڴ�ʧ��"<<endl; }
   length=0;
}

Sequence::~Sequence()
{
    delete []e_p;//�ͷŴ洢�ռ䣬��Ϊe_pָ��һ������ռ䣬����delete[]e_p
    length=0;
}

void Sequence::set_sequence()
{
    //Elemt e1;
    cout<<"������˳�����Ԫ�ظ���"<<endl;
    cin>>length;
    cout<<"����������Ԫ��"<<endl;
    int i;
    for(i=0;i<length;i++)
    {
       e_p[i].set_e();//!����Ԫ�أ�e_pָ�򿪱ٵ����飬�ɴ���������
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
    }//��¼����Ҫ�����λ���±�ֵ
    cout<<"�����λ�������±�Ϊ"<<i<<endl;
    int j;
    for(j=length-1;j>=i;j--)
    {
       // e_p[j+1].get_e()=e_p[j].get_e();//����ֵ����
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
    mid=length/2;//length-1/2��Ҫ����ż���ۣ�������Ӱ�죬ż������޷�����һ����,1 2 3 4 ->4 2 3 1
    int i;
    for(i=0;i<mid;i++)//��ֻ��1 2�����ںž����ٻ�һ�飬���ִ���������������ٻ�һ�飬����Ҳû��ʲô����
    {
        int t;
        t=e_p[i].get_e();
        e_p[i].assignment(e_p[length-1-i].get_e());
        e_p[length-1-i].assignment(t);
        //swap(&(e_p[i].get_e()),&(e_p[length-1-i].get_e()));
        //ʹ�����ñ���&�����������Ĵ���
        //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'|swap(e_p[i].get_e(),e_p[length-1-i].get_e());
    }
    /*int left=0;//��һ��Ԫ�ص��±�
    int right=length-1;//���һ��Ԫ�ص��±�
    mid=(left+right)/2;
    int i,j;
    i=mid-1;
    j=mid+1;*/
}
void Sequence::move_s(int k)
{
    k=k%length;
    //!����ѭ�����������ƶ�����¼���һλ����ǰ��
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
    }*///!���ʱ������������Ѿ����滻��û�취���ƶ���ǰ��

}

void menu()
{
    cout<<"1.���Բ����㷨"<<endl;
    cout<<"2.����ѭ�������㷨"<<endl;
    cout<<"3.���������㷨"<<endl;
    cout<<"4.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;
}


