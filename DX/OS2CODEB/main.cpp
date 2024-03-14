#include <iostream>
#include"Paging.h"

using namespace std;

//!太牛了,我好厉害！

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

    cout<<"随机生成的位示图为"<<endl;
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
                    cout<<"请输入逻辑地址,输入-1结束"<<endl;
                    cin>>add;
                    if(add>(pc*piec*1024))
                    {
                        cout<<"逻辑地址越界，退出程序"<<endl;
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

                        cout<<"采用FIFO方法"<<endl;
                        cout<<"物理地址为"<<endl;
                        cout<<ca_f(f,lg2,add,piec)<<endl;
                        f.show();
                        cout<<"用fifo方法";
                        f.show_rate_qy();
                        cout<<"***********************************************"<<endl;
                        cout<<"采用LRU方法"<<endl;
                        cout<<"物理地址为"<<endl;
                        cout<<ca_l(l,lg1,add,piec)<<endl;
                        l.show();
                        cout<<"采用LRU方法";
                        l.show_rate_qy();
                        cout<<"当前位示图为"<<endl;
                        lg2.show();
                        /*cout<<"当前位示图为"<<endl;
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
                    cout<<"请输入十六进制逻辑地址,输入-1结束"<<endl;
                    cin>>hex>>add2;

                    if(add2>(pc*piec*1024))
                    {
                        cout<<"逻辑地址越界，退出程序"<<endl;
                        add2=-1;
                    }

                    if(add2==-1)
                    {
                        flag3=0;
                    }


                    else
                    {

                        //f1.show();
                        cout<<"采用FIFO方法"<<endl;
                        cout<<"物理地址为"<<endl;
                        cout<<hex<<ca_fh(f1,lg3,add2,piec)<<endl;
                        f1.show1();
                        cout<<"用fifo方法";
                        f1.show_rate_qy();
                        cout<<"***********************************************"<<endl;
                        cout<<"采用LRU方法"<<endl;
                        cout<<"物理地址为"<<endl;
                        cout<<hex<<ca_lh(l1,lg4,add2,piec)<<endl;
                        l1.show1();
                        cout<<"采用LRU方法";
                        l1.show_rate_qy();
                        cout<<"当前位示图为"<<endl;
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

