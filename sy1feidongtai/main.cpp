#include <iostream>
#include<stdlib.h>
#include"sequence.h"

using namespace std;
/*
8
1 4 5 6 6 7 8 9
1 2 3 4 5 6
*/
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
                Sequence s1;
                int c1,c2;
                char a;
                cout<<"���Ƚ���һ��˳���"<<endl;
                s1.set_sequence();
                cout<<"�������˳�������"<<endl;
                s1.show_sequence();
                cout<<"������в������,��������������Ԫ��ֵ,"<<endl;
                cin>>c1;
                s1.insert_value(c1);
                cout<<"������˳���Ϊ"<<endl;
                s1.show_sequence();
              int f=1;
              while(f)
              {
                cout<<"���Ƿ���������в��������������Y��N����ѡ��"<<endl;
                cin>>a;
                if(a=='Y')
                {
                cout<<"��������������Ԫ��ֵ,"<<endl;
                cin>>c2;
                s1.insert_value(c2);
                cout<<"������˳���Ϊ"<<endl;
                s1.show_sequence();
                }
                else if(a=='N')
                {
                    f=0;
                }
            }
                /*
                cout<<"�������в������,��������������Ԫ��ֵ"<<endl;
                cin>>c2;
                s1.insert_value(c2);
                cout<<"������˳���Ϊ"<<endl;
                s1.show_sequence();
                cout<<"�������в������,��������������Ԫ��ֵ"<<endl;
                cin>>c3;
                s1.insert_value(c3);
                cout<<"������˳���Ϊ"<<endl;
                s1.show_sequence();*/
                system("pause");
                break;
            }
            case 2:
                {
                    Sequence s3;
                    cout<<"���Ƚ���һ��˳���"<<endl;
                    s3.set_sequence();
                    cout<<"��������˳�������"<<endl;
                    s3.show_sequence();
                    cout<<"��������������ѭ���ƶ���λ��"<<endl;
                    int k;
                    cin>>k;
                    s3.move_s(k);
                    cout<<"���ƺ�Ϊ"<<endl;
                    s3.show_sequence();
                    system("pause");
                    break;
                }
            case 3:
                {
                    Sequence s2;
                    cout<<"���Ƚ���һ��˳���"<<endl;
                    s2.set_sequence();
                    cout<<"��������˳�������"<<endl;
                    s2.show_sequence();
                    s2.reverse_e();
                    cout<<"���������"<<endl;
                    s2.show_sequence();
                    system("pause");
                    break;
                }
            case 4:
                {
                    flag=0;
                    break;
                }


        }
    }

    return 0;
}
