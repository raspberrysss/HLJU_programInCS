#include <iostream>
#include<cstdlib>
#include"stack00.h"

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
                Stack s1;
                cout<<"��������Ҫ������ַ������ַ�����"<<endl;
                int n;
                cin>>n;
                int i;
                char a;
                cout<<"�������ַ���"<<endl;
                for(i=0;i<n;i++)
                {
                    cin>>a;
                    s1.push(a);
                }
                s1.judge_symmetric();
                int flag2=1;
                while(flag2)
                {
                    cout<<"���Ƿ�Ҫ�����жϣ�����Y������N�˳�"<<endl;
                        char b;
                        cin>>b;
                        if(b=='Y')
                        {
                            s1.make_empty();
                            cout<<"��������Ҫ������ַ������ַ�����"<<endl;
                            int n;
                            cin>>n;
                            int i;
                            char a;
                            cout<<"�������ַ���"<<endl;
                            for(i=0;i<n;i++)
                            {
                                cin>>a;
                                s1.push(a);
                            }
                            s1.judge_symmetric();
                        }
                        else if(b=='N')
                        {
                            flag2=0;
                        }
                }

                system("pause");
                break;
            }
        case 2:
            {
                Stack s2;
                s2.match_brackets();
                int flag3=1;
                while(flag3)
                {
                    cout<<"�Ƿ�����жϣ�����������Y���˳�����N"<<endl;
                    char y;
                    cin>>y;
                    if(y=='Y')
                    {
                        Stack s3;
                        s3.match_brackets();
                    }
                    else if(y=='N')
                    {
                        flag3=0;
                    }
                }
                system("pause");
                break;
            }
        case 3:
            {
                Queue q1;
                int flag4=1;
                while(flag4)
                {

                    system("cls");
                    menu2();
                    int c2;
                    cin>>c2;
                    switch(c2)
                    {
                    case 1:
                        {
                            /*int n;
                            cout<<"������������ӵ�Ԫ�ظ���"<<endl;
                            cin>>n;
                            q1.enter1(n);
                            q1.show_queue();*/
                            int e;//!wen!
                            cout<<"��������ӵ�Ԫ��"<<endl;
                            cin>>e;
                            q1.enter(e);
                            q1.show_queue();
                            system("pause");
                            break;
                        }
                    case 2:
                        {
                            q1.leave();
                            q1.show_queue();
                            system("pause");
                            break;
                        }
                    case 3:
                        {
                            q1.make_empty();
                            system("pause");
                            break;
                        }
                    case 4:
                        {
                            flag4=0;
                            break;
                        }

                    }
                }

                system("pause");
                break;
            }
        case 4:
            {
                flag=0;
                //system("pause");
                break;
            }
        }
    }

    return 0;
}
