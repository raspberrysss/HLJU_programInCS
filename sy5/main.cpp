#include <iostream>
#include"songer00.h"
#include<string>
#include<cstdlib>

using namespace std;

void menu();

int main(void)
{
    int flag=1;
    int choice;
    int add_count;
    Songer s1;
    Songer s2("lily",300);
    Songer s3("mike",250);
    Songer s4("nancy",340);
    Songer s5("penny",320);
    cout<<"�Ѵ�����λ���֣��ֱ�Ϊ"<<endl;
    cout<<s1<<s2<<s3<<s4<<s5;
    system("pause");
    while(flag)
    {
        system("cls");
        menu();
        cout<<"���������ֽ���ѡ��"<<endl;
        cin>>choice;
        switch(choice)
        {
           case 1:
            {
                s1.setinform();
                cout<<s1;
                system("pause");
                break;
            }
           case 2:
            {
                cout<<"����lily�ķ�˿��"<<endl;//case��ִ�������ʧ������ʧ������ʵ��case�ﶨ��һ����
                cout<<"lilyԭ���ķ�˿��Ϊ"<<endl;
                s2.showfans();
                cout<<"��������Ҫ���ӵ�����"<<endl;
                cin>>add_count;
                Songer s_linshi;
                s_linshi=s2+add_count;
                s_linshi.showfans();
                system("pause");
                break;
            }
           case 3:
            {
                cout<<"Ϊmike����ʮ����˿"<<endl;
                cout<<"ǰ׺����ǰ"<<endl;
                s3.showfans();
                //s2.operator++();
                cout<<"ǰ׺���Ӻ�"<<endl;
                (++s3).showfans();//s3.showfans();
                cout<<"*********************************************"<<endl;
                cout<<"��׺����ǰ"<<endl;
                s3.showfans();
                //operator++(s2,0);
                cout<<"��׺���Ӻ�"<<endl;
                 (s3++).showfans();//s3.showfans();
                system("pause");
                break;

            }
           case 4:
            {
                cout<<"�Ƚ�lily��penny�ķ�˿���Ƿ����"<<endl;
                if(s2==s5)
                {
                    cout<<"��λ���ֵķ�˿�����"<<endl;
                }
                else
                {
                    cout<<"��λ���ֵķ�˿�������"<<endl;
                }
                system("pause");
                break;

            }
           case 5:
            {
                cout<<"�Ƚ�nancy�ķ�˿���Ƿ����penny"<<endl;
                if(s4>s5)
                {
                    cout<<"nancy�ķ�˿������"<<endl;
                }
                else
                {
                    cout<<"penny�ķ�˿������"<<endl;
                }
                system("pause");
                break;
            }
           case 6:
            {
                s1.shownum();
                system("pause");
                break;
            }
           case 7:
            {
                cout<<"��лʹ��"<<endl;
                flag=0;
                system("pause");
                break;
            }
        }
    }
    cout<<"Ŀǰ��λ���ֵ���ϢΪ"<<endl;
    cout<<s1<<s2<<s3<<s4<<s5;
    cout<<"���Ƶ���λ������Ϣ"<<endl;
    Songer s6(s5);
    cout<<"����չʾ��λ���ֲ�չʾ��ǰ��������"<<endl;
    cout<<s6<<s5<<s4<<s3<<s2<<s1;
    s1.shownum();
    return 0;
}
//!i++����������Ȼ�󷵻�����֮ǰ��ֵ i=4��temp=i++��temp=4
//!++iҲ�����������Ƿ�������֮���ֵ i=4��temp=++i��temp=5
