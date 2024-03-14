/**

*/
#include <iostream>
#include"Maxdd00.h"
#include<stdlib.h>

using namespace std;

int main(void)
{
   int choice;
   int flag1=1;
   char c1,c2;
   while(flag1)
   {
       system("cls");
       menu();
       cin>>choice;
       switch(choice)
       {
       case 1:
        {

            do{
                system("cls");
                Maxsegment_d m1;
                m1.set_array_d();
                int s=m1.find_Maxsegement();
                cout<<"最大子段和"<<s<<" 起始下标"<<m1.get_sta()<<" 终止下标"<<m1.get_ter()<<endl;
                cout<<"是否继续（Y/N）"<<endl;
                cin>>c1;
            }while(c1=='Y');
            system("pause");
            break;

        }
        case 2:
        {
            do{
                system("cls");
                Max_order mo1;
                mo1.set_str12();
                mo1.set_value_ter();
                //cout<<mo1.get_besti()<<" "<<mo1.get_bestj()<<endl;
                mo1.show_a();
                //mo1.LCS(mo1.get_len1(),mo1.get_len2());
                if(mo1.get_flag()==1)
                {
                     cout<<"最长公共子序列为";
                    // mo1.LCS(mo1.get_len1(),mo1.get_len2());
                    mo1.LCS(mo1.get_besti(),mo1.get_bestj());//从最后一个打标记的开始,或者最后也可以
                    cout<<endl;
                }
                else
                {
                    cout<<"这两个序列无公共子序列"<<endl;
                }
                //mo1.LCS_many(mo1.get_len1(),mo1.get_len2());
                //mo1.s_w();
                cout<<"是否继续（Y/N）"<<endl;
                cin>>c2;
            }while(c2=='Y');
            system("pause");
            break;

        }
        case 3:
        {
            flag1=0;
            //system("pause");
            break;

        }
       }
   }


    return 0;
}
