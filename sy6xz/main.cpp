#include <iostream>
#include "sy6xz.h"

using namespace std;

const int TEST=2;

int main(void)
{
    Tree *point_tree[TEST];
    int i;
    int choice;
    for(i=0;i<TEST;i++)
    {
         cout<<"请选择数字： 1.二叉树对象 2.二叉树排列对象"<<endl;
         while(cin>>choice&&(choice!=1&&choice!=2))
         {
             cout<<"请输入数字1 2"<<endl;
         }
         if(choice==1)
         {
             point_tree[i]=new Binary_Tree;

         }
         else if(choice==2)
         {
             point_tree[i]=new Binary_Sort_Tree;
         }
    }
    cout<<endl;
    for(i=0;i<TEST;i++)
    {
        point_tree[i]->show();
    }
    cout<<endl;
    for(i=0;i<TEST;i++)
    {
        delete point_tree[i];
    }
    return 0;
}
