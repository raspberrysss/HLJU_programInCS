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
        cout<<"��ѡ�����ֽ��в���"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1://����{}�Ͳ�����jump to case�����ʼ���ı����ˣ�Ϊʲô��
               {
                 cout<<"Ŀǰ���ж��ٸ�ѧ������Ϣ��Ҫ¼��"<<endl;
                 cin>>n1;
                 cout<<"������¼��ѧ����Ϣ"<<endl;
                 Link l1(n1);
                 //l1.creatlink(n);
                 cout<<"*****************************************"<<endl;
                 cout<<"�������"<<endl;
                 l1.output();
                 l1.shownum();
                 system("pause");
                 break;
               }

            case 2:
                {
                cout<<"�����µı��"<<endl;
                cout<<"������ѧ������"<<endl;
                cin>>n2;
                cout<<"������¼��ѧ����Ϣ"<<endl;
                 Link l2(n2);
                 cout<<"*****************************************"<<endl;
                 cout<<"�������"<<endl;
                 l2.output();
                 /*
                 cout<<"���������ѧ������Ϣ"<<endl;
                 Student *new_n=new Student;
                 new_n->setinform();
                 new_n->setnext(NULL);
                 l2.insert_link(new_n);
                 cout<<"*****************************************"<<endl;
                 cout<<"�������"<<endl;
                 l2.output();
                 l2.shownum();
                 system("pause");
                 break;*/
                }
            case 3:
                {
                cout<<"�����µı��"<<endl;
                cout<<"������ѧ������"<<endl;
                cin>>n3;
                cout<<"������¼��ѧ����Ϣ"<<endl;
                Link l3(n3);
                cout<<"*****************************************"<<endl;
                cout<<"�������"<<endl;
                l3.output();
                cout<<"��������Ҫɾ����ѧ����ѧ�ţ�eg 20210687��"<<endl;
                long id;
                cin>>id;
                l3.delete_link(id);
                cout<<"*****************************************"<<endl;
                cout<<"�������"<<endl;
                l3.output();
                system("pause");
                break;
                }
           /* case 4:
            {
                cout<<"���Ƚ�����һ����"<<endl;
                int n2;
                cout<<"����������������Ҫ������"<<endl;
                cin>>n2;
                l2.creatlink(n2);
                cout<<"*****************************************"<<endl;
                cout<<"�������"<<endl;
                l2.output();
                cout<<"���������һ�������������"<<endl;
                l1.connect_link(l2);
                cout<<"*****************************************"<<endl;
                cout<<"�������"<<endl;
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
