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
         cout<<"��ѡ�����֣� 1.���������� 2.���������ж���"<<endl;
         while(cin>>choice&&(choice!=1&&choice!=2))
         {
             cout<<"����������1 2"<<endl;
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
