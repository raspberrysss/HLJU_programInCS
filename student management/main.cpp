#include <iostream>
#include<string>
#include<cstdlib>
#include"studentmanagement.h"


using namespace std;

void menu();

int main(void)
{
    int n1,n2;
    int flag=1;
    int choice;
    cout<<"请建立第一个链表"<<endl;//只写一个并输出就是错的，加上菜单之类的反而对了，怪
    cout<<"请输入学生个数并依次输入信息"<<endl;
    cin>>n1;
    Link l1(n1);
    cout<<"*****************************************"<<endl;
    cout<<"结果如下"<<endl;
    l1.output();
    l1.shownum();
    system("pause");
    while(flag)
    {
        system("cls");
        menu();
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                cout<<"请输入插入学生的信息"<<endl;
                 Student *new_n=new Student;
                 new_n->setinform();
                 new_n->setnext(NULL);
                 l1.insert_link(new_n);
                 cout<<"*****************************************"<<endl;
                 cout<<"结果如下"<<endl;
                 l1.output();
                 l1.shownum();
                 system("pause");
                 break;
                }
            case 2:
                {
                cout<<"请输入想要删除的学生的学号（eg 20210687）"<<endl;
                long id;
                cin>>id;
                l1.delete_link(id);
                cout<<"*****************************************"<<endl;
                cout<<"结果如下"<<endl;
                l1.output();
                l1.shownum();
                system("pause");
                break;
                }
            case 3:
                {
                    Link l2(l1);
                    cout<<"复制后的表格结果如下"<<endl;
                    l2.output();
                    l2.shownum();
                    system("pause");
                    break;
                }
            case 4:
                {
                    cout<<"请先建立需要连接的链表"<<endl;
                    cout<<"请输入学生个数并依次输入信息"<<endl;
                    cin>>n2;
                    Link l3(n2);
                    cout<<"结果如下"<<endl;
                    l3.output();
                    l3.shownum();
                    l1.connect_link(l3);
                    cout<<"连接后结果如下"<<endl;
                    l1.output();
                    l1.shownum();
                    system("pause");
                    break;
                }
            case 5:
                {
                    cout<<"感谢使用"<<endl;
                    flag=0;
                }

        }
    }

    return 0;
}
