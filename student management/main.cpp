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
    cout<<"�뽨����һ������"<<endl;//ֻдһ����������Ǵ�ģ����ϲ˵�֮��ķ������ˣ���
    cout<<"������ѧ������������������Ϣ"<<endl;
    cin>>n1;
    Link l1(n1);
    cout<<"*****************************************"<<endl;
    cout<<"�������"<<endl;
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
                cout<<"���������ѧ������Ϣ"<<endl;
                 Student *new_n=new Student;
                 new_n->setinform();
                 new_n->setnext(NULL);
                 l1.insert_link(new_n);
                 cout<<"*****************************************"<<endl;
                 cout<<"�������"<<endl;
                 l1.output();
                 l1.shownum();
                 system("pause");
                 break;
                }
            case 2:
                {
                cout<<"��������Ҫɾ����ѧ����ѧ�ţ�eg 20210687��"<<endl;
                long id;
                cin>>id;
                l1.delete_link(id);
                cout<<"*****************************************"<<endl;
                cout<<"�������"<<endl;
                l1.output();
                l1.shownum();
                system("pause");
                break;
                }
            case 3:
                {
                    Link l2(l1);
                    cout<<"���ƺ�ı��������"<<endl;
                    l2.output();
                    l2.shownum();
                    system("pause");
                    break;
                }
            case 4:
                {
                    cout<<"���Ƚ�����Ҫ���ӵ�����"<<endl;
                    cout<<"������ѧ������������������Ϣ"<<endl;
                    cin>>n2;
                    Link l3(n2);
                    cout<<"�������"<<endl;
                    l3.output();
                    l3.shownum();
                    l1.connect_link(l3);
                    cout<<"���Ӻ�������"<<endl;
                    l1.output();
                    l1.shownum();
                    system("pause");
                    break;
                }
            case 5:
                {
                    cout<<"��лʹ��"<<endl;
                    flag=0;
                }

        }
    }

    return 0;
}
