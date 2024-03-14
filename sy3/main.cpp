#include <iostream>
#include"link_cycle00.h"
#include<cstdlib>

using namespace std;

/*
黑龙江大学校园信息门户 4399游戏网站 计软学院 c++学习 c语言学习
1 c ! H $ 2 4 i n ) a
*/

int main(void)
{
    int flag1;
    flag1=1;
    while(flag1)
    {
        system("cls");
        menu();
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                Link_cycle lc1;
                int n;
                cout<<"请输入您想要建立链表的元素个数"<<endl;
                cin>>n;
                lc1.creat_link_c(n);
                cout<<"您建立的链表如下"<<endl;
                lc1.show_link();
                cout<<"请输入您想删除的结点的后继结点的数据"<<endl;
                int d;
                cin>>d;
                lc1.delete_pre(d);
                cout<<"已经删除您输入结点的前置结点，删除后的链表如下"<<endl;
                lc1.show_link();
                int flag2=1;
                while(flag2)
                {
                    cout<<"是否继续删除，若继续请输入Y，退出请输入N"<<endl;
                    char c;
                    cin>>c;
                    if(c=='Y')
                    {
                        cout<<"请输入您想删除的结点的后继结点的数据"<<endl;
                        int d;
                        cin>>d;
                        lc1.delete_pre(d);
                        cout<<"已经删除您输入结点的前置结点，删除后的链表如下"<<endl;
                        lc1.show_link();
                    }
                    else if(c=='N')
                    {
                        flag2=0;
                    }
                }
                system("pause");
                break;
            }
        case 2:
            {
                List_ch lh1,lh2,lh3,lh4;
                lh1.creat_tail();
                cout<<"您建立的链表如下"<<endl;
                lh1.show_tail();
                cout<<"下面将链表中的元素分类，得到三条循环链表，如下"<<endl;
                lh1.classify2(lh2,lh3,lh4);
                cout<<"数字链表 ";
                lh2.show_classify_cycle();
                cout<<"字母链表 ";
                lh3.show_classify_cycle();
                cout<<"其他字符链表 ";
                lh4.show_classify_cycle();
                system("pause");
                break;
            }
        case 3:
            {
                List_d ld1;
                ld1.creat_tail();
                ld1.show_list_d();
                string s;
                cout<<"请输入您想访问的网站的名字"<<endl;
                cin>>s;
                ld1.locate(s);
                cout<<"当前顺序如下"<<endl;
                ld1.show_list_d();
                int flag3=1;
                while(flag3)
                {
                    cout<<"是否继续访问，若继续请输入Y,否则输入N"<<endl;
                    char c2;
                    cin>>c2;
                    if(c2=='Y')
                    {
                        string s2;
                        cout<<"请输入您想访问的网站的名字"<<endl;
                        cin>>s2;
                        ld1.locate(s2);
                        //cout<<"当前顺序如下"<<endl;
                        ld1.show_list_d();

                    }
                    else if(c2=='N')
                    {
                        flag3=0;
                    }
                }
                system("pause");
                break;
            }
        case 4:
            {
                flag1=0;
                break;
            }
        }
    }

    return 0;
}
