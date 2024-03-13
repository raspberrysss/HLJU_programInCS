#include<iostream>
#include "Binarytree.h"

using namespace std;

void Tree::show()
{
        cout<<"树是非常重要的一种数据结构"<<endl;
}

Tree::~Tree()
{
    cout<<"析构一个树对象"<<endl;
}

void Binary_Tree::show()
{
    cout<<"二叉树每个节点至多有两棵子树，且有左右之分"<<endl;
}

Binary_Tree::~Binary_Tree()
{
    cout<<"析构一个二叉树对象"<<endl;
}

void Binary_Sort_Tree::show()
{
    cout<<"二叉排序树首先是一个二叉树"<<endl;
    cout<<"如果左子树不空，左子树小于根节点"<<endl;
    cout<<"如果右子树不空，右子树大于根节点"<<endl;
}

Binary_Sort_Tree::~Binary_Sort_Tree()
{
    cout<<"析构一个二叉排列数对象"<<endl;
}

void useshow_reference(Tree &t)
{
    t.show();
}

void useshow_address(Tree *t)
{
    t->show();
}
