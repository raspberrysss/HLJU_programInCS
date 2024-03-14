#include <iostream>
#include"greedy00.h"
#include<cstdlib>
/*
   总容量30
   6
   11 22
   3 1.8
   4.2 12.6
   9 6
   14 20
   2.4 8.6

   3
   9 27
   15 30
   21 36
*/

/*
    11
    1 4
    0 6
    5 7
    5 9
    3 5
    3 8
    6 10
    8 12
    8 11
    12 14
    2 13

    5
    0 3
    2 3
    4 5
    2 4
    1 6
*/

using namespace std;

int main(void)
{
    int flag=1;
    int ch;
    while(flag)
    {
        system("cls");
        menu();
        cin>>ch;
        system("cls");
        switch(ch)
        {
        case 1:
            {

                char s1;
                do
                {
                    system("cls");
                    Knapsack_g k1;
                    k1.set_information();
                    k1.greedy();
                    cout<<"是否继续解决背包问题（Y/N）"<<endl;
                    cin>>s1;
                }while(s1=='Y');
                break;
                system("pause");
            }
        case 2:
            {
                char s2;
                do
                {
                    system("cls");
                    Activity_g a1;
                    a1.set_in();
                    a1.greedy();
                    cout<<"是否继续解决活动安排问题（Y/N）"<<endl;
                    cin>>s2;
                }while(s2=='Y');
                break;
                system("pause");
            }
        case 3:
            {
                flag=0;
                break;
                system("pause");
            }
        }
    }

    return 0;
}
