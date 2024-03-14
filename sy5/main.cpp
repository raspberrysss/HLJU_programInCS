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
                cout<<"此树的深度为"<<d<<endl;
                system("pause");
                break;

            }
        case 2:
            {
                char e[MAXSIZE];
                cout<<"请输入此完全二叉树的长度"<<endl;
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
                cout<<"请输入一串前序字符来代表二叉树"<<endl;
                tree=creat_bin_tree2();
                cout<<"前序遍历为"<<endl;
                pre_through_s(tree);
                cout<<endl;
                cout<<"中序遍历为"<<endl;
                mid_through_s(tree);
                cout<<endl;
                cout<<"后序遍历为"<<endl;
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
