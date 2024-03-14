#include <iostream>
#include"list00.h"
#include<cstdlib>

using namespace std;

int main(void)
{
    List l1,l2;
    int n;
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
                cout<<"请输入您想建立链表的结点个数"<<endl;
                cin>>n;
                l1.creat_list_tail(n);
                cout<<"您的链表建立如下"<<endl;
                l1.show_list();
                cout<<"接下来进行插入操作，请输入您想插入的值"<<endl;
                int e;
                cin>>e;
                l1.insert_list(e);
                cout<<"插入后如下"<<endl;
                l1.show_list();
                int flag2=1;
                while(flag2)
                {
                    char c;
                    cout<<"您是否要继续插入，输入Y继续，输入N退出"<<endl;
                    cin>>c;
                    if(c=='Y')
                    {
                        int e2;
                        cout<<"请输入您想要插入的值"<<endl;
                        cin>>e2;
                        l1.insert_list(e2);
                        cout<<"插入后的链表为"<<endl;
                        l1.show_list();
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
              int n2;
              cout<<"请输入您想建立链表的结点个数"<<endl;
              cin>>n2;
              l2.creat_list_tail(n2);
              cout<<"此链表如下"<<endl;
              l2.show_list();
              cout<<"逆置后的链表为"<<endl;
              l2.reverse_l();
              //l2.reverse_me();
              l2.show_list();
              system("pause");
              break;
      }
      case 3:
            {
                List l3,l4;
                cout<<"请建立两个链表，进行合并"<<endl;
                int n3,n4;
                cout<<"请输入第一个链表的结点个数"<<endl;
                cin>>n3;
                l3.creat_list_tail(n3);
                cout<<"请输入第二个链表的结点个数"<<endl;
                cin>>n4;
                l4.creat_list_tail(n4);
                cout<<"建立完成后分别为"<<endl;
                l3.show_list();
                l4.show_list();
                cout<<"递减合并后如下"<<endl;
                l3.add_list_decline(l4);
                //l3.add_me(l4);
                l3.show_list();
                system("pause");
                break;
      }
      case 4:
        {
            flag1=0;
        }
        }
    }

    return 0;
}
