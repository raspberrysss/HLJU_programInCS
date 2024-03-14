#include <iostream>
#include<stdlib.h>
#include"sequence.h"

using namespace std;
/*
8
1 4 5 6 6 7 8 9
1 2 3 4 5 6
*/
int main(void)
{
    int flag=1;
    while(flag)
    {
        system("cls");
        menu();
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                Sequence s1;
                int c1,c2;
                char a;
                cout<<"请先建立一个顺序表"<<endl;
                s1.set_sequence();
                cout<<"您输入的顺序表如下"<<endl;
                s1.show_sequence();
                cout<<"下面进行插入操作,请输入您想插入的元素值,"<<endl;
                cin>>c1;
                s1.insert_value(c1);
                cout<<"插入后的顺序表为"<<endl;
                s1.show_sequence();
              int f=1;
              while(f)
              {
                cout<<"您是否想继续进行插入操作，请输入Y或N进行选择"<<endl;
                cin>>a;
                if(a=='Y')
                {
                cout<<"请输入您想插入的元素值,"<<endl;
                cin>>c2;
                s1.insert_value(c2);
                cout<<"插入后的顺序表为"<<endl;
                s1.show_sequence();
                }
                else if(a=='N')
                {
                    f=0;
                }
            }
                /*
                cout<<"继续进行插入操作,请输入您想插入的元素值"<<endl;
                cin>>c2;
                s1.insert_value(c2);
                cout<<"插入后的顺序表为"<<endl;
                s1.show_sequence();
                cout<<"继续进行插入操作,请输入您想插入的元素值"<<endl;
                cin>>c3;
                s1.insert_value(c3);
                cout<<"插入后的顺序表为"<<endl;
                s1.show_sequence();*/
                system("pause");
                break;
            }
            case 2:
                {
                    Sequence s3;
                    cout<<"请先建立一个顺序表"<<endl;
                    s3.set_sequence();
                    cout<<"您建立的顺序表如下"<<endl;
                    s3.show_sequence();
                    cout<<"请输入您想向右循环移动的位次"<<endl;
                    int k;
                    cin>>k;
                    s3.move_s(k);
                    cout<<"右移后为"<<endl;
                    s3.show_sequence();
                    system("pause");
                    break;
                }
            case 3:
                {
                    Sequence s2;
                    cout<<"请先建立一个顺序表"<<endl;
                    s2.set_sequence();
                    cout<<"您建立的顺序表如下"<<endl;
                    s2.show_sequence();
                    s2.reverse_e();
                    cout<<"逆序后如下"<<endl;
                    s2.show_sequence();
                    system("pause");
                    break;
                }
            case 4:
                {
                    flag=0;
                    break;
                }


        }
    }

    return 0;
}
