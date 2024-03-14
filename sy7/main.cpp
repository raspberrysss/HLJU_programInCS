#include <iostream>
#include"Graph.h"
#include<cstdlib>

using namespace std;

int main(void)
{
    AMG_Graph g1,g2;
    ALG_Graph G1,G2;
    int flag1=1;
    int flag2=1;
    int flag3=1;
    while(flag1)
    {
        system("cls");
        menu();
        int choice1;
        cin>>choice1;
        switch(choice1)
        {
        case 1:
            {
                while(flag2)
                {
                    system("cls");
                    menu_AMG();
                    int choice2;
                    cin>>choice2;
                    switch(choice2)
                    {
                    case 1:
                        {
                            g1.Create_AMG_Graph_underieted();
                            g1.show_AMG_Graph();
                            g1.DFS_AMG_simple();
                            cout<<endl;
                            system("pause");
                            break;

                        }
                    case 2:
                        {
                            g2.Create_AMG_Graph_derieted();
                            g2.show_AMG_Graph();
                            g2.DFS_AMG_simple();

                            cout<<endl;
                            system("pause");
                            break;
                        }
                    case 3:
                        {
                            flag2=0;
                            break;
                        }
                    }
                }
                break;
                system("pause");

            }
        case 2:
            {
                while(flag3)
                {
                    system("cls");
                    menu_ALG();
                    int choice3;
                    cin>>choice3;
                    switch(choice3)
                    {
                    case 1:
                        {
                            G1.Create_ALG_Graph_undericted();
                            G1.Show_ALG_g();
                            G1.BFS_ALG_min();
                            cout<<endl;
                            system("pause");
                            break;
                        }
                    case 2:
                        {
                            G2.Create_ALG_Graph_dericted();
                            G2.Show_ALG_g();
                            G2.BFS_ALG_min();
                            cout<<endl;
                            system("pause");
                            break;
                        }
                    case 3:
                        {
                            flag3=0;
                            //system("pause");
                            break;
                        }
                    }
                }

                //system("pause");
                break;

            }
        case 3:
            {
                flag1=0;
                break;
                //system("pause");
            }
        }
    }
    return 0;
}
