#include <iostream>
#include"Paging.h"

using namespace std;

//!̫ţ��,�Һ�������

int main(void)
{
    FIFO f,f1;
    LRU l,l1;
    location_gra lg1;
    int pc,piec,csp;
    menu();
    cin>>pc>>piec>>csp;
    f.init_pf(pc);
    l.init_pl(pc);
    f1.init_pf(pc);
    l1.init_pl(pc);
    lg1.set_random(csp);
    location_gra lg2(lg1);
    location_gra lg3(lg1);
    location_gra lg4(lg1);

    cout<<"������ɵ�λʾͼΪ"<<endl;
    lg1.show();
   // cout<<endl;
    //lg2.show();
    system("pause");
    system("cls");
    int flag2=1;
    while(flag2)
    {
            system("cls");
            menu2();
            int choice;
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    int flag=1;
                while(flag)
                {
                    int add=0;
                    cout<<"�������߼���ַ,����-1����"<<endl;
                    cin>>add;
                    if(add>(pc*piec*1024))
                    {
                        cout<<"�߼���ַԽ�磬�˳�����"<<endl;
                        add=-1;
                    }
                    if(add==-1)
                    {
                        flag=0;
                    }
                    else
                    {
                       // cout<<ca_f(f,lg1,add,piec)<<endl;
                       // f.show();

                        cout<<"����FIFO����"<<endl;
                        cout<<"�����ַΪ"<<endl;
                        cout<<ca_f(f,lg2,add,piec)<<endl;
                        f.show();
                        cout<<"��fifo����";
                        f.show_rate_qy();
                        cout<<"***********************************************"<<endl;
                        cout<<"����LRU����"<<endl;
                        cout<<"�����ַΪ"<<endl;
                        cout<<ca_l(l,lg1,add,piec)<<endl;
                        l.show();
                        cout<<"����LRU����";
                        l.show_rate_qy();
                        cout<<"��ǰλʾͼΪ"<<endl;
                        lg2.show();
                        /*cout<<"��ǰλʾͼΪ"<<endl;
                        lg1.show();
                        */
                        //lg2.show();

                    }
                }
                system("pause");
                break;
                }
                case 2:
                {
                int flag3=1;
                while(flag3)
                {
                    int add2=0;
                    cout<<"������ʮ�������߼���ַ,����-1����"<<endl;
                    cin>>hex>>add2;

                    if(add2>(pc*piec*1024))
                    {
                        cout<<"�߼���ַԽ�磬�˳�����"<<endl;
                        add2=-1;
                    }

                    if(add2==-1)
                    {
                        flag3=0;
                    }


                    else
                    {

                        //f1.show();
                        cout<<"����FIFO����"<<endl;
                        cout<<"�����ַΪ"<<endl;
                        cout<<hex<<ca_fh(f1,lg3,add2,piec)<<endl;
                        f1.show1();
                        cout<<"��fifo����";
                        f1.show_rate_qy();
                        cout<<"***********************************************"<<endl;
                        cout<<"����LRU����"<<endl;
                        cout<<"�����ַΪ"<<endl;
                        cout<<hex<<ca_lh(l1,lg4,add2,piec)<<endl;
                        l1.show1();
                        cout<<"����LRU����";
                        l1.show_rate_qy();
                        cout<<"��ǰλʾͼΪ"<<endl;
                        lg3.show();

                    }

                }
                system("pause");
                break;
                }
                case 0:
                {
                     flag2=0;
                     system("pause");
                     break;
                }



    //f.show();



    }
}



    //f.show();


   /* do
    {
        menu();
        cin>>pc>>piec>>csp;


    }while(pc!=0&&piec!=0&&csp!=0);*/

    return 0;
}

