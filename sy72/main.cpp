#include <iostream>
#include"jihem.h"

using namespace std;

void menu1();
void menu2();

int main(void)
{
    int choice,choice2;
    int n,i;
    int add_one;
    double add_one2;
    char add_one3;
    int flag1,flag2,flag3,flag4;
    flag1=flag2=flag3=flag4=1;//Ҫ���岻ͬ���ĸ�����Ȼ��һ������ͽ����ˣ������Ľ���ȥѭ��
    int element1;
    double element2;
    char element3;
    cout<<"��ӭ�����������ݹ���ϵͳ"<<endl;
    system("pause");
    while(flag2)
    {
    system("cls");
     menu2();
    while(cin>>choice&&(choice!=1&&choice!=2&&choice!=3&&choice!=4))
    {
        cout<<"����������1 2 3 4����ѡ��"<<endl;
    }
    if(choice==1)
    {
        cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
        cin>>n;
        Set<int>s1(n);
        for( i=0;i<n;i++)
    {
        cin>>add_one;
        s1.add(add_one);
    }
        s1.display();
        system("pause");
        while(flag1)
        {
            system("cls");
            menu1();
            cin>>choice2;
            switch(choice2)
            {
                case 1:
                {
                    cout<<"���������㼯�϶����������ӵ�Ԫ��"<<endl;
                    cin>>element1;
                    s1.add(element1);
                    s1.display();
                    system("pause");
                    break;
                }
                case 3:
                    {
                        cout<<"������һ������"<<endl;
                        cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
                        cin>>n;
                        Set<int>s2(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one;
                            s2.add(add_one);
                        }
                        s2.display();
                        cout<<"����s1�󲢼�"<<endl;
                        (s1+s2).display();//s4=s1+s2�ᱨ��
                        system("pause");
                        break;
                    }
                case 2:
                    {
                        cout<<"������һ������"<<endl;
                        cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
                        cin>>n;
                        Set<int>s3(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one;
                            s3.add(add_one);
                        }
                        s3.display();
                        cout<<"��s1��ֵ����"<<endl;
                        s3=s1;
                        s3.display();
                        system("pause");
                        break;
                    }
                case 4:
                    {
                        Set<int>s4(s1);
                        cout<<"�����µļ���ʹ����ȸ���s1����"<<endl;
                        s4.display();
                        system("pause");
                        break;
                    }
                case 5:
                    {
                        flag1=0;
                        cout<<"���˳������������ͼ��ϵĹ���"<<endl;
                        system("pause");
                        break;
                    }

            }

        }
    }
    else if(choice==2)
    {
         cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
        cin>>n;
        Set<double>s5(n);
        for( i=0;i<n;i++)
    {
        cin>>add_one2;
        s5.add(add_one2);
    }
        s5.display();
        system("pause");
        while(flag3)
        {
            system("cls");
            menu1();
            cin>>choice2;
            switch(choice2)
            {
                case 1:
                {
                    cout<<"���������㼯�϶����������ӵ�Ԫ��"<<endl;
                    cin>>element2;
                    s5.add(element2);
                    s5.display();
                    system("pause");
                    break;
                }
                case 3:
                    {
                        cout<<"������һ������"<<endl;
                        cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
                        cin>>n;
                        Set<double>s6(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one2;
                            s6.add(add_one2);
                        }
                        s6.display();
                        cout<<"����s1�󲢼�"<<endl;
                        (s5+s6).display();//s4=s1+s2�ᱨ��
                        system("pause");
                        break;
                    }
                case 2:
                    {
                        cout<<"������һ������"<<endl;
                        cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
                        cin>>n;
                        Set<double>s7(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one2;
                            s7.add(add_one2);
                        }
                        s7.display();
                        cout<<"��s1��ֵ����"<<endl;
                        s7=s5;
                        s7.display();
                        system("pause");
                        break;
                    }
                case 4:
                    {
                        Set<double>s8(s5);
                        cout<<"�����µļ���ʹ����ȸ���s1����"<<endl;
                        s8.display();
                        system("pause");
                        break;
                    }
                case 5:
                    {
                        flag3=0;
                        cout<<"���˳������������ͼ��ϵĹ���"<<endl;
                        system("pause");
                        break;
                    }

            }

        }
    }
    else if(choice==3)
    {
        cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
        cin>>n;
        Set<char>s1(n);
        for( i=0;i<n;i++)
    {
        cin>>add_one3;
        s1.add(add_one3);
    }
        s1.display();
        system("pause");
        while(flag4)
        {
            system("cls");
            menu1();
            cin>>choice2;
            switch(choice2)
            {
                case 1:
                {
                    cout<<"���������㼯�϶����������ӵ�Ԫ��"<<endl;
                    cin>>element3;
                    s1.add(element3);
                    s1.display();
                    system("pause");
                    break;
                }
                case 3:
                    {
                        cout<<"������һ������"<<endl;
                        cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
                        cin>>n;
                        Set<char>s2(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one3;
                            s2.add(add_one3);
                        }
                        s2.display();
                        cout<<"����s1�󲢼�"<<endl;
                        (s1+s2).display();//s4=s1+s2�ᱨ��
                        system("pause");
                        break;
                    }
                case 2:
                    {
                        cout<<"������һ������"<<endl;
                        cout<<"���������뽨���ļ�����Ԫ�صĸ�����Ԫ��"<<endl;
                        cin>>n;
                        Set<char>s3(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one3;
                            s3.add(add_one3);
                        }
                        s3.display();
                        cout<<"��s1��ֵ����"<<endl;
                        s3=s1;
                        s3.display();
                        system("pause");
                        break;
                    }
                case 4:
                    {
                        Set<char>s4(s1);
                        cout<<"�����µļ���ʹ����ȸ���s1����"<<endl;
                        s4.display();
                        system("pause");
                        break;
                    }
                case 5:
                    {
                        flag4=0;
                        cout<<"���˳������������ͼ��ϵĹ���"<<endl;
                        system("pause");
                        break;
                    }

            }

        }
    }
    else if(choice==4)
    {
        flag2=0;
    }
    }
    cout<<"��л����ʹ��"<<endl;
    return 0;
}

void menu1()
{
    cout<<"�����ѡ��"<<endl;
    cout<<"1.�򼯺������Ԫ��"<<endl;
    cout<<"2.�Լ���ֱ�Ӹ�ֵ"<<endl;
    cout<<"3.���������ϵĲ���"<<endl;
    cout<<"4.�Լ��Ͻ��и���"<<endl;
    cout<<"5.�˳�"<<endl;
}

void menu2()
{
     cout<<"���Ƚ���һ������"<<endl;
    cout<<"��ѡ�����������ͣ�1 ���� 2 ˫���ȸ����� 3 �ַ��ͣ�4�˳�"<<endl;
}
