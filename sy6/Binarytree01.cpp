#include<iostream>
#include "Binarytree.h"

using namespace std;

void Tree::show()
{
        cout<<"���Ƿǳ���Ҫ��һ�����ݽṹ"<<endl;
}

Tree::~Tree()
{
    cout<<"����һ��������"<<endl;
}

void Binary_Tree::show()
{
    cout<<"������ÿ���ڵ�������������������������֮��"<<endl;
}

Binary_Tree::~Binary_Tree()
{
    cout<<"����һ������������"<<endl;
}

void Binary_Sort_Tree::show()
{
    cout<<"����������������һ��������"<<endl;
    cout<<"������������գ�������С�ڸ��ڵ�"<<endl;
    cout<<"������������գ����������ڸ��ڵ�"<<endl;
}

Binary_Sort_Tree::~Binary_Sort_Tree()
{
    cout<<"����һ����������������"<<endl;
}

void useshow_reference(Tree &t)
{
    t.show();
}

void useshow_address(Tree *t)
{
    t->show();
}
