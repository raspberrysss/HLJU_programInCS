#include <iostream>
#include"link_cycle00.h"
#include<cstdlib>

using namespace std;

/*
��������ѧУ԰��Ϣ�Ż� 4399��Ϸ��վ ����ѧԺ c++ѧϰ c����ѧϰ
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
                cout<<"����������Ҫ���������Ԫ�ظ���"<<endl;
                cin>>n;
                lc1.creat_link_c(n);
                cout<<"����������������"<<endl;
                lc1.show_link();
                cout<<"����������ɾ���Ľ��ĺ�̽�������"<<endl;
                int d;
                cin>>d;
                lc1.delete_pre(d);
                cout<<"�Ѿ�ɾ�����������ǰ�ý�㣬ɾ�������������"<<endl;
                lc1.show_link();
                int flag2=1;
                while(flag2)
                {
                    cout<<"�Ƿ����ɾ����������������Y���˳�������N"<<endl;
                    char c;
                    cin>>c;
                    if(c=='Y')
                    {
                        cout<<"����������ɾ���Ľ��ĺ�̽�������"<<endl;
                        int d;
                        cin>>d;
                        lc1.delete_pre(d);
                        cout<<"�Ѿ�ɾ�����������ǰ�ý�㣬ɾ�������������"<<endl;
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
                cout<<"����������������"<<endl;
                lh1.show_tail();
                cout<<"���潫�����е�Ԫ�ط��࣬�õ�����ѭ����������"<<endl;
                lh1.classify2(lh2,lh3,lh4);
                cout<<"�������� ";
                lh2.show_classify_cycle();
                cout<<"��ĸ���� ";
                lh3.show_classify_cycle();
                cout<<"�����ַ����� ";
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
                cout<<"������������ʵ���վ������"<<endl;
                cin>>s;
                ld1.locate(s);
                cout<<"��ǰ˳������"<<endl;
                ld1.show_list_d();
                int flag3=1;
                while(flag3)
                {
                    cout<<"�Ƿ�������ʣ�������������Y,��������N"<<endl;
                    char c2;
                    cin>>c2;
                    if(c2=='Y')
                    {
                        string s2;
                        cout<<"������������ʵ���վ������"<<endl;
                        cin>>s2;
                        ld1.locate(s2);
                        //cout<<"��ǰ˳������"<<endl;
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
