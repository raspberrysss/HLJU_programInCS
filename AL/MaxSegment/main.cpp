/**
    ����Ӷκ���ָһ�����������а�˳���ó��ӶΣ��������Ϊ����Ӷκ�,����Ǹ�����������Ӷκ�Ϊ0
    �÷��η����������Ӷκ����⣬���԰�һ���η�Ϊ�������ݣ�����Ӷκ�Ҫ����������ߣ�Ҫ���������ұߣ�Ҫ��������֮�䣬������߻��ұ߿���ͨ������ϸ�ֵݹ���⣬�����м�����Լ���������ŵ�һ�Σ��ټ����ұ����ŵ�һ��

    ��һ���������г��ִ�������������������������ֵĴ���������������
    �÷��η���������������һ��������ţ��ҵ���λ���������õ�����λ����ȵĵ�һ���������һ������λ�ã��õ����ȣ��Ƚ�
    �����������һ���ṹ������Ƚ�



*/

/**
    ������˽�г�Ա��������ʱ������ֱ�Ӷ������飬Ҳ������ָ�붨�壬����new���飬�ô�ֻ�ж�̬��
    ͷ�ļ�ֻ�Ƕ���������û�д������𣿼�c++ primer plus P303 ,ֻ���ഴ������ʱ�Ż����ڴ�ռ䣬�������ֻ�Ǹ��߱���������ʲô���ӵģ�������ȴû�з����ڴ�ռ�ȥ��������
    ���ݹ����Ĳ��ã�������ϸ��һ��
    ������ݹ鶯̬�����������⣿
    �������ҵݹ�ʱlast�Ĵ�СҪע�⣡����

*/

#include <iostream>
#include<cstdlib>
#include"MaxSe00.h"

using namespace std;

int main(void)
{
    int choice;
    int flag=1;
    while(flag)
    {
        system("cls");
        menu();
        cin>>choice;
        switch(choice)
        {
        case 1:
            {

                char f;
                do{
                system("cls");
                MaxSe m1;
                m1.set_array();
                //m1.show_array();
                //cout<<endl;
                int s=m1.get_Max(0,m1.get_length()-1);
                cout<<"����Ӷκ�Ϊ"<<s<<endl;//��ʱ�����������⣿���ж�̬�����������
                cout<<"��ʼ�±�"<<m1.get_sta()<<"  "<<"��ֹ�±�"<<m1.get_ter()<<endl;
                cout<<"�Ƿ�����÷��η�������Ӷκͣ�Y/N��"<<endl;
                cin>>f;
                }while(f=='Y');
                system("pause");
                break;
            }
        case 2:
            {
                char f2;
                do{
                system("cls");
                Mode mo1;
                mo1.set_array_mo();
                //mo1.show_array_mo();
                //cout<<endl;
                mo1.get_mo_mu(0,mo1.get_length()-1);
               /* cout<<"������";
                mo1.show_s();
                cout<<"������"<<mo1.get_mu()<<endl;*/
               // mo1.show_m();
               mo1.find_max_mu();
                //mo1.show_s();
                /*if(mo1.get_h()>1)//��������ж���������������������ж������ж����
                {
                    cout<<"������";
                    mo1.show_s();
                    cout<<"������"<<mo1.get_mu()<<endl;
                }
                else
                {
                    cout<<"������"<<mo1.get_mo()<<"������"<<mo1.get_mu()<<endl;
                }*/

                //cout<<"������"<<mo1.get_mo()<<"������"<<mo1.get_mu()<<endl;
                /*if(mo1.get_flags()!=0)
                {
                    cout<<"������";
                    mo1.show_s();
                    cout<<"������"<<mo1.get_mu()<<endl;
                }
                else{
                    cout<<"������"<<mo1.get_mo()<<"������"<<mo1.get_mu()<<endl;
                }*/
                cout<<"�Ƿ�����÷��η���������������Y/N��"<<endl;
                cin>>f2;
                }while(f2=='Y');
                system("pause");
                break;
            }
        case 3:
            {
                flag=0;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
