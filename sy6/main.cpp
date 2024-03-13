#include <iostream>
#include"Binarytree.h"

using namespace std;

const int TEST=3;

int main(void)
{
    Tree t1;
    Binary_Tree b1;
    Binary_Sort_Tree s1;
    /*Tree &t_ref1=t1;
    Tree &t_ref2=b1;
    Tree &t_ref3=s1;*/
    cout<<"ͨ�����ֲ�ͬ�������ʵ�ֶ�̬"<<endl;
    useshow_reference(t1);
    useshow_reference(b1);
    useshow_reference(s1);
    cout<<"*******************************************"<<endl;
    cout<<"ͨ�����ֲ�ͬ�����ַ����ʵ�ֶ�̬"<<endl;
    useshow_address(&t1);
    useshow_address(&b1);
    useshow_address(&s1);
    cout<<"*******************************************"<<endl;
    cout<<"ʹ�����麯����������"<<endl;
    Tree *tree_point[TEST];
    int i;
    int choice;
    for(i=0;i<TEST;i++)
    {
        cout<<"��ѡ�����֣�1.������ 2.���������� 3.���������ж���"<<endl;
        //cin>>choice;��Ϊ�����������������Σ�
        while(cin>>choice&&(choice!=1&&choice!=2&&choice!=3))//ȥ��cin�������ͺ��ˣ�Ϊɶ��
        {
            cout<<"������1 2 3�е�һ������"<<endl;
        }
        if(choice==1)
        {
            tree_point[i]=new Tree;
        }
        else if(choice==2)
        {
            tree_point[i]=new Binary_Tree;
        }
        else if(choice==3)
        {
            tree_point[i]=new Binary_Sort_Tree;
        }
        /*while(cin.get()!='\n')
        {
            continue;
        }*/
    }
    cout<<endl;
    for(i=0;i<TEST;i++)
    {
        tree_point[i]->show();
    }
    cout<<endl;
    for(i=0;i<TEST;i++)
    {
        delete tree_point[i];
    }
    return 0;
}
