#include <iostream>
#include"Backtrack00.h"
#include<cstdlib>

using namespace std;

int main(void)
{
    int flag1=1;
    int choice;
    while(flag1)
    {
        system("cls");
        menu();
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                char c1;
                do
                {
                    system("cls");
                    N_queen nq1;
                    nq1.set_n();
                    nq1.backtrack(1);
                    cout<<"����Ϊ���õĿ����ԣ�һ����"<<nq1.get_sum()<<"��"<<endl;
                    cout<<"�Ƿ����(Y/N)"<<endl;
                    cin>>c1;
                }while(c1=='Y');

                break;
            }
            case 2:
            {
                char c2;
                do
                {
                    system("cls");
                    Subset s1;
                    s1.set_in();
                    if(s1.get_M()>=0)
                    {
                        s1.backtrack(0,s1.get_sn(),1);
                    //cout<<s1.get_flag()<<endl;
                        if(s1.get_flag()==0)
                        {
                            cout<<"�޽�"<<endl;
                        }
                        else
                        {
                             cout<<"����Ϊ���н⣬����"<<s1.get_num()<<"��"<<endl;
                        }
                    }
                    else
                    {
                        s1.backtrack_f(1);
                        if(s1.get_flag()==0)
                        {
                            cout<<"�޽�"<<endl;
                        }
                        else
                        {
                             cout<<"����Ϊ���н⣬����"<<s1.get_num()<<"��"<<endl;
                        }
                    }

                    cout<<"�Ƿ����(Y/N)"<<endl;
                    cin>>c2;
                }while(c2=='Y');
                break;
            }
            case 3:
            {
                flag1=0;
                break;
            }
            system("pause");
        }
    }

    return 0;
}

/*
1 2 7 5 10
-2 -3 5 6
-5 4 9

*/
