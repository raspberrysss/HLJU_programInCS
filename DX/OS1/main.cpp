#include <iostream>
#include<cstdlib>
#include"List_P00.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

//!���⣺���յ�pre�����Ƿ��ޱ�Ҫ !!�ᣬ�б�Ҫ
//!delete ��ʱ��
//!��ϰһ����Ԫ�������ܶ�Ӧ�ÿ�������Ԫ����ֱ�ӽ��

int main(void)
{
    Link_PCB L_ready;
    Link_PCB L_execute;
    Link_PCB L_block;

    Link_Zone L_spa;//�����ڴ�����

    int flag=1;
    int flag2=1;

    while(flag2)
    {
        system("cls");
        int b,s;
        cout<<"�������ڴ����ʼ��ַ����С"<<endl;
        cin>>b>>s;
        if(b>=0&&s>0)
        {
            L_spa.create_link_zone(b,s);
            cout<<"�����ɹ�"<<endl;
            //L_spa.show_link_zone();
            flag2=0;
            system("pause");
        }
        else
        {
            cout<<"����������ݲ��Ϸ�������������"<<endl;
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
                cout<<"������Ҫ�����Ľ����������ڴ�����ռ�Ĵ�С"<<endl;
                cin>>s_add>>si_add;
                if(is_repeat(L_ready,L_execute,L_block,s_add))
                {
                    cout<<"�˽������ظ����޷����"<<endl;
                }
                else
                {
                    int ff;
                    if(is_spare(L_spa,si_add,ff))
                  {
                         //!д���ˣ��������ţ
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
                //cout<<"��������Ҫ��ֹ�Ľ�����"<<endl;
                //cin>>s_de;
                if(end_exe3(L_execute,L_spa))
                {
                    //!�ɹ���ֹ�ѿռ��ͷţ��Ȳ�����������ٰ��ܺϲ��ĺϲ�
                    merge_lz(L_spa);
                    L_spa.show_link_zone();
                    //!�ϲ�������д��������д������������
                    //merge_lz(L_spa);
                   // L_spa.show_link_zone();
                    ready_to_exe_auto(L_ready,L_execute);
                    show_three(L_ready,L_execute,L_block);
                }
                else
                {
                    cout<<"ִ������Ϊ��,�޷���ֹ"<<endl;
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
                cout<<"�������룬����������"<<endl;
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

//д�����
/*ִֻ�е�ʱ��ɽ���������˿���
end_three(L_ready,L_execute,L_block,s_de,fla);
//�������ò��볣������,�����õĴ�����
//end_three(L_ready,L_execute,L_block,0,s_de);
//!�������òŻ�� ��������������
if(fla!=1)
{
ready_to_exe_auto(L_ready,L_execute);
show_three(L_ready,L_execute,L_block);
}
else
{
}*/
