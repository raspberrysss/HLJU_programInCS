#include <iostream>
#include"student2.h"
#include<string>
#include<cstdlib>

using namespace std;

void menu();

int main(void)
{
    int choice;
    int n1,n2,n3;
    int flag=1;
    while(flag)
    {
        system("cls");
        menu();
        cout<<"请选择数字进行操作"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1://加上{}就不会有jump to case。与初始化的报错了，为什么？
               {
                 cout<<"目前您有多少个学生的信息想要录入"<<endl;
                 cin>>n1;
                 cout<<"请依次录入学生信息"<<endl;
                 Link l1(n1);
                 //l1.creatlink(n);
                 cout<<"*****************************************"<<endl;
                 cout<<"结果如下"<<endl;
                 l1.output();
                 l1.shownum();
                 system("pause");
                 break;
               }

            case 2:
                {
                cout<<"创建新的表格"<<endl;
                cout<<"请输入学生个数"<<endl;
                cin>>n2;
                cout<<"请依次录入学生信息"<<endl;
                 Link l2(n2);
                 cout<<"*****************************************"<<endl;
                 cout<<"结果如下"<<endl;
                 l2.output();
                 /*
                 cout<<"请输入插入学生的信息"<<endl;
                 Student *new_n=new Student;
                 new_n->setinform();
                 new_n->setnext(NULL);
                 l2.insert_link(new_n);
                 cout<<"*****************************************"<<endl;
                 cout<<"结果如下"<<endl;
                 l2.output();
                 l2.shownum();
                 system("pause");
                 break;*/
                }
            case 3:
                {
                cout<<"创建新的表格"<<endl;
                cout<<"请输入学生个数"<<endl;
                cin>>n3;
                cout<<"请依次录入学生信息"<<endl;
                Link l3(n3);
                cout<<"*****************************************"<<endl;
                cout<<"结果如下"<<endl;
                l3.output();
                cout<<"请输入想要删除的学生的学号（eg 20210687）"<<endl;
                long id;
                cin>>id;
                l3.delete_link(id);
                cout<<"*****************************************"<<endl;
                cout<<"结果如下"<<endl;
                l3.output();
                system("pause");
                break;
                }
           /* case 4:
            {
                cout<<"请先建立另一链表"<<endl;
                int n2;
                cout<<"请输入新链表所需要的人数"<<endl;
                cin>>n2;
                l2.creatlink(n2);
                cout<<"*****************************************"<<endl;
                cout<<"结果如下"<<endl;
                l2.output();
                cout<<"接下来与第一个链表进行连接"<<endl;
                l1.connect_link(l2);
                cout<<"*****************************************"<<endl;
                cout<<"结果如下"<<endl;
                l1.output();
                system("pause");
                break;
            }
            case 5:
                {

                }
           system("pause");*/

        }
    }
    return 0;
}
