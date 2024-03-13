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
    cout<<"通过三种不同对象调用实现多态"<<endl;
    useshow_reference(t1);
    useshow_reference(b1);
    useshow_reference(s1);
    cout<<"*******************************************"<<endl;
    cout<<"通过三种不同对象地址调用实现多态"<<endl;
    useshow_address(&t1);
    useshow_address(&b1);
    useshow_address(&s1);
    cout<<"*******************************************"<<endl;
    cout<<"使用用虚函数，虚析构"<<endl;
    Tree *tree_point[TEST];
    int i;
    int choice;
    for(i=0;i<TEST;i++)
    {
        cout<<"请选择数字：1.树对象 2.二叉树对象 3.二叉树排列对象"<<endl;
        //cin>>choice;因为我这样就是输入两次！
        while(cin>>choice&&(choice!=1&&choice!=2&&choice!=3))//去掉cin那条语句就好了，为啥呢
        {
            cout<<"请输入1 2 3中的一个数字"<<endl;
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
