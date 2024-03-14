#include <iostream>
#include<stdlib.h>
#include"os400.h"
#include<vector>

using namespace std;

int main(void)
{
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

                FCFS();
                system("pause");
                break;


            }
        case 2:
            {
                SJF();
                system("pause");
                break;

            }
        case 3:
            {
                Time_change();
                system("pause");
                break;

            }
       case 4:
            {

                flag1=0;
                break;

            }
      /* case 5:
            {
                flag1=0;
                break;
                //system("pause");
            }*/
           default:
            {
                cout<<"指令错误，请输入正确指令"<<endl;
                system("pause");
                break;

            }
        }
    }
    return 0;
}
