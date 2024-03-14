#include"Dispatch.h"
#include <iostream>
#include<stdlib.h>


using namespace std;

int main(void)
{
    //cout<<"111111111111111"<<endl;
    int flag1=1;
    while(flag1)
    {
        system("cls");
        menu();
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                break;
                system("pause");

            }
        case 2:
            {
                break;
                system("pause");

            }
        case 3:
            {
                break;
                system("pause");

            }
       case 4:
            {
                break;
                system("pause");

            }
       case 5:
            {
                flag1=0;
                break;
                system("pause");
            }
           default:
            {
                cout<<"指令错误，请输入正确指令"<<endl;
                break;
                    system("pause");

            }
        }
    }
    return 0;
}
