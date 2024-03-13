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
    cout<<"已创建五位歌手，分别为"<<endl;
    cout<<s1<<s2<<s3<<s4<<s5;
    system("pause");
    while(flag)
    {
        system("cls");
        menu();
        cout<<"请输入数字进行选择"<<endl;
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
                cout<<"增加lily的粉丝数"<<endl;//case块执行完就消失？不消失，除非实在case里定义一个！
                cout<<"lily原本的粉丝数为"<<endl;
                s2.showfans();
                cout<<"请输入先要增加的数量"<<endl;
                cin>>add_count;
                Songer s_linshi;
                s_linshi=s2+add_count;
                s_linshi.showfans();
                system("pause");
                break;
            }
           case 3:
            {
                cout<<"为mike增加十个粉丝"<<endl;
                cout<<"前缀增加前"<<endl;
                s3.showfans();
                //s2.operator++();
                cout<<"前缀增加后"<<endl;
                (++s3).showfans();//s3.showfans();
                cout<<"*********************************************"<<endl;
                cout<<"后缀增加前"<<endl;
                s3.showfans();
                //operator++(s2,0);
                cout<<"后缀增加后"<<endl;
                 (s3++).showfans();//s3.showfans();
                system("pause");
                break;

            }
           case 4:
            {
                cout<<"比较lily与penny的粉丝数是否相等"<<endl;
                if(s2==s5)
                {
                    cout<<"两位歌手的粉丝数相等"<<endl;
                }
                else
                {
                    cout<<"两位歌手的粉丝数不相等"<<endl;
                }
                system("pause");
                break;

            }
           case 5:
            {
                cout<<"比较nancy的粉丝数是否大于penny"<<endl;
                if(s4>s5)
                {
                    cout<<"nancy的粉丝数更多"<<endl;
                }
                else
                {
                    cout<<"penny的粉丝数更多"<<endl;
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
                cout<<"感谢使用"<<endl;
                flag=0;
                system("pause");
                break;
            }
        }
    }
    cout<<"目前五位歌手的信息为"<<endl;
    cout<<s1<<s2<<s3<<s4<<s5;
    cout<<"复制第五位歌手信息"<<endl;
    Songer s6(s5);
    cout<<"倒序展示六位歌手并展示当前歌手人数"<<endl;
    cout<<s6<<s5<<s4<<s3<<s2<<s1;
    s1.shownum();
    return 0;
}
//!i++是先自增，然后返回自增之前的值 i=4，temp=i++，temp=4
//!++i也是先自增但是返回自增之后的值 i=4，temp=++i，temp=5
