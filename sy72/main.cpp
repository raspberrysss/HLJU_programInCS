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
    flag1=flag2=flag3=flag4=1;//要定义不同的四个，不然第一个用完就结束了，其他的进不去循环
    int element1;
    double element2;
    char element3;
    cout<<"欢迎来到集合数据管理系统"<<endl;
    system("pause");
    while(flag2)
    {
    system("cls");
     menu2();
    while(cin>>choice&&(choice!=1&&choice!=2&&choice!=3&&choice!=4))
    {
        cout<<"请输入数字1 2 3 4进行选择"<<endl;
    }
    if(choice==1)
    {
        cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
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
                    cout<<"请输入满足集合定义的您想添加的元素"<<endl;
                    cin>>element1;
                    s1.add(element1);
                    s1.display();
                    system("pause");
                    break;
                }
                case 3:
                    {
                        cout<<"定义另一个集合"<<endl;
                        cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
                        cin>>n;
                        Set<int>s2(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one;
                            s2.add(add_one);
                        }
                        s2.display();
                        cout<<"将与s1求并集"<<endl;
                        (s1+s2).display();//s4=s1+s2会报错
                        system("pause");
                        break;
                    }
                case 2:
                    {
                        cout<<"定义另一个集合"<<endl;
                        cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
                        cin>>n;
                        Set<int>s3(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one;
                            s3.add(add_one);
                        }
                        s3.display();
                        cout<<"将s1赋值给它"<<endl;
                        s3=s1;
                        s3.display();
                        system("pause");
                        break;
                    }
                case 4:
                    {
                        Set<int>s4(s1);
                        cout<<"创建新的集合使其深度复制s1内容"<<endl;
                        s4.display();
                        system("pause");
                        break;
                    }
                case 5:
                    {
                        flag1=0;
                        cout<<"已退出此种数据类型集合的管理"<<endl;
                        system("pause");
                        break;
                    }

            }

        }
    }
    else if(choice==2)
    {
         cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
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
                    cout<<"请输入满足集合定义的您想添加的元素"<<endl;
                    cin>>element2;
                    s5.add(element2);
                    s5.display();
                    system("pause");
                    break;
                }
                case 3:
                    {
                        cout<<"定义另一个集合"<<endl;
                        cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
                        cin>>n;
                        Set<double>s6(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one2;
                            s6.add(add_one2);
                        }
                        s6.display();
                        cout<<"将与s1求并集"<<endl;
                        (s5+s6).display();//s4=s1+s2会报错
                        system("pause");
                        break;
                    }
                case 2:
                    {
                        cout<<"定义另一个集合"<<endl;
                        cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
                        cin>>n;
                        Set<double>s7(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one2;
                            s7.add(add_one2);
                        }
                        s7.display();
                        cout<<"将s1赋值给它"<<endl;
                        s7=s5;
                        s7.display();
                        system("pause");
                        break;
                    }
                case 4:
                    {
                        Set<double>s8(s5);
                        cout<<"创建新的集合使其深度复制s1内容"<<endl;
                        s8.display();
                        system("pause");
                        break;
                    }
                case 5:
                    {
                        flag3=0;
                        cout<<"已退出此种数据类型集合的管理"<<endl;
                        system("pause");
                        break;
                    }

            }

        }
    }
    else if(choice==3)
    {
        cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
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
                    cout<<"请输入满足集合定义的您想添加的元素"<<endl;
                    cin>>element3;
                    s1.add(element3);
                    s1.display();
                    system("pause");
                    break;
                }
                case 3:
                    {
                        cout<<"定义另一个集合"<<endl;
                        cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
                        cin>>n;
                        Set<char>s2(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one3;
                            s2.add(add_one3);
                        }
                        s2.display();
                        cout<<"将与s1求并集"<<endl;
                        (s1+s2).display();//s4=s1+s2会报错
                        system("pause");
                        break;
                    }
                case 2:
                    {
                        cout<<"定义另一个集合"<<endl;
                        cout<<"请输入您想建立的集合中元素的个数及元素"<<endl;
                        cin>>n;
                        Set<char>s3(n);
                        for(i=0;i<n;i++)
                        {
                            cin>>add_one3;
                            s3.add(add_one3);
                        }
                        s3.display();
                        cout<<"将s1赋值给它"<<endl;
                        s3=s1;
                        s3.display();
                        system("pause");
                        break;
                    }
                case 4:
                    {
                        Set<char>s4(s1);
                        cout<<"创建新的集合使其深度复制s1内容"<<endl;
                        s4.display();
                        system("pause");
                        break;
                    }
                case 5:
                    {
                        flag4=0;
                        cout<<"已退出此种数据类型集合的管理"<<endl;
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
    cout<<"感谢您的使用"<<endl;
    return 0;
}

void menu1()
{
    cout<<"请进行选择"<<endl;
    cout<<"1.向集合中添加元素"<<endl;
    cout<<"2.对集合直接赋值"<<endl;
    cout<<"3.求两个集合的并集"<<endl;
    cout<<"4.对集合进行复制"<<endl;
    cout<<"5.退出"<<endl;
}

void menu2()
{
     cout<<"请先建立一个集合"<<endl;
    cout<<"请选择其数据类型（1 整型 2 双精度浮点型 3 字符型）4退出"<<endl;
}
