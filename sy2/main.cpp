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
                cout<<"���������뽨������Ľ�����"<<endl;
                cin>>n;
                l1.creat_list_tail(n);
                cout<<"��������������"<<endl;
                l1.show_list();
                cout<<"���������в����������������������ֵ"<<endl;
                int e;
                cin>>e;
                l1.insert_list(e);
                cout<<"���������"<<endl;
                l1.show_list();
                int flag2=1;
                while(flag2)
                {
                    char c;
                    cout<<"���Ƿ�Ҫ�������룬����Y����������N�˳�"<<endl;
                    cin>>c;
                    if(c=='Y')
                    {
                        int e2;
                        cout<<"����������Ҫ�����ֵ"<<endl;
                        cin>>e2;
                        l1.insert_list(e2);
                        cout<<"����������Ϊ"<<endl;
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
              cout<<"���������뽨������Ľ�����"<<endl;
              cin>>n2;
              l2.creat_list_tail(n2);
              cout<<"����������"<<endl;
              l2.show_list();
              cout<<"���ú������Ϊ"<<endl;
              l2.reverse_l();
              //l2.reverse_me();
              l2.show_list();
              system("pause");
              break;
      }
      case 3:
            {
                List l3,l4;
                cout<<"�뽨�������������кϲ�"<<endl;
                int n3,n4;
                cout<<"�������һ������Ľ�����"<<endl;
                cin>>n3;
                l3.creat_list_tail(n3);
                cout<<"������ڶ�������Ľ�����"<<endl;
                cin>>n4;
                l4.creat_list_tail(n4);
                cout<<"������ɺ�ֱ�Ϊ"<<endl;
                l3.show_list();
                l4.show_list();
                cout<<"�ݼ��ϲ�������"<<endl;
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
