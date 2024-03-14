#include <iostream>
#include<cstdlib>
#include"List_P00.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

//!问题：回收的pre部分是否无必要 !!会，有必要
//!delete 的时机
//!复习一下友元函数，很多应该可以用友元函数直接解决

int main(void)
{
    Link_PCB L_ready;
    Link_PCB L_execute;
    Link_PCB L_block;

    Link_Zone L_spa;//空闲内存链表

    int flag=1;
    int flag2=1;

    while(flag2)
    {
        system("cls");
        int b,s;
        cout<<"请输入内存的起始地址及大小"<<endl;
        cin>>b>>s;
        if(b>=0&&s>0)
        {
            L_spa.create_link_zone(b,s);
            cout<<"创建成功"<<endl;
            //L_spa.show_link_zone();
            flag2=0;
            system("pause");
        }
        else
        {
            cout<<"您输入的数据不合法，请重新输入"<<endl;
            system("pause");
        }
    }


    while(flag)
    {
        int choice;
        system("cls");
        menu();
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                string s_add;
                int si_add;
                cout<<"请输入要创建的进程名及在内存中所占的大小"<<endl;
                cin>>s_add>>si_add;
                if(is_repeat(L_ready,L_execute,L_block,s_add))
                {
                    cout<<"此进程名重复，无法添加"<<endl;
                }
                else
                {
                    int ff;
                    if(is_spare(L_spa,si_add,ff))
                  {
                         //!写对了，我是真的牛
                        //cout<<ff<<endl;
                        L_spa.show_link_zone();
                        L_ready.create_link(s_add,si_add,ff);
                        ready_to_exe_auto(L_ready,L_execute);
                        show_three(L_ready,L_execute,L_block);
                  }

                }
                system("pause");
                break;
            }
        case 2:
            {
                //int fla=0;
                //cout<<"请输入想要中止的进程名"<<endl;
                //cin>>s_de;
                if(end_exe3(L_execute,L_spa))
                {
                    //!成功中止把空间释放，先插入空闲链表，再把能合并的合并
                    merge_lz(L_spa);
                    L_spa.show_link_zone();
                    //!合不起来，写不出来，写出来啦！！！
                    //merge_lz(L_spa);
                   // L_spa.show_link_zone();
                    ready_to_exe_auto(L_ready,L_execute);
                    show_three(L_ready,L_execute,L_block);
                }
                else
                {
                    cout<<"执行链表为空,无法中止"<<endl;
                }
                system("pause");
                break;
            }
        case 3:
            {
                if(block(L_execute,L_block))
                {
                    ready_to_exe_auto(L_ready,L_execute);
                    show_three(L_ready,L_execute,L_block);
                }
                system("pause");
                break;
            }
        case 4:
            {
                if(wake(L_block,L_ready))
                {
                    ready_to_exe_auto(L_ready,L_execute);
                    show_three(L_ready,L_execute,L_block);
                }
                system("pause");
                break;
            }
        case 5:
            {
                if(time(L_execute,L_ready))
                {
                    ready_to_exe_auto(L_ready,L_execute);
                    show_three(L_ready,L_execute,L_block);
                }
                system("pause");
                break;
            }
        case 6:
            {
                show_three(L_ready,L_execute,L_block);
                system("pause");
                break;
            }
        case 7:
            {
                L_spa.show_link_zone();
                system("pause");
                break;
            }
        case 8:
            {
                flag=0;
                system("pause");
                break;
            }
        default:
            {
                cout<<"错误输入，请重新输入"<<endl;
                system("pause");
                break;
            }

        }

    }
    //L_ready.create_link("j1");
    //L_ready.create_link("j2");
   //L_ready.create_link("j3");
    //L_ready.show_link();
    return 0;
}

//写错代码
/*只执行的时候可结束，想错了哭了
end_three(L_ready,L_execute,L_block,s_de,fla);
//用了引用不与常量绑定吗,是引用的错误吗
//end_three(L_ready,L_execute,L_block,0,s_de);
//!加了引用才会变 我真厉害！！！
if(fla!=1)
{
ready_to_exe_auto(L_ready,L_execute);
show_three(L_ready,L_execute,L_block);
}
else
{
}*/
