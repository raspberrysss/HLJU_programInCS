#include <iostream>
#include<stdlib.h>
#include"Binary_Tree00.h"

using namespace std;

int main(void)
{
    int flag=1;
    while(flag)
    {
        system("cls");
        menu();
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                Bin_tree_node * tree;
                tree=creat_bin_tree();
                pre_order(tree);
                cout<<endl;
                int d;
                d=count_depth(tree);
                cout<<"���������Ϊ"<<d<<endl;
                system("pause");
                break;

            }
        case 2:
            {
                char e[MAXSIZE];
                cout<<"���������ȫ�������ĳ���"<<endl;
                int n;
                cin>>n;
                int i=1;
                for(i=1;i<=n;i++)
                {
                    cin>>e[i];
                }
                pre_full(e,n);
                system("pause");
                break;

            }
        case 3:
            {
                Bin_tree_node * tree;
                cout<<"������һ��ǰ���ַ������������"<<endl;
                tree=creat_bin_tree2();
                cout<<"ǰ�����Ϊ"<<endl;
                pre_through_s(tree);
                cout<<endl;
                cout<<"�������Ϊ"<<endl;
                mid_through_s(tree);
                cout<<endl;
                cout<<"�������Ϊ"<<endl;
                tail_through_s(tree);
                cout<<endl;
                system("pause");
                break;

            }
        case 4:
            {
                flag=0;
                break;
                //system("pause");
            }
        }
    }
    return 0;
}
