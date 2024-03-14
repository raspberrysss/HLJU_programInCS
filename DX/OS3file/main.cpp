#include <iostream>
#include<string>
#include"File01.h"
#include<cstdlib>

using namespace std;

int main(void)
{
    FCB_tree ft;
    FAT fat;
    fat.makefat();
    //fat.show_fat();
    //system("pause");
    init(ft,fat);
    //cout<<"++++++++++++++++++++++++++++++++++"<<endl;
    //fat.show_fat();
    //system("pause");
    //ft.init();

    int flag=1;
    while(flag)
    {
        system("cls");
        ft.show_root();
        ft.show_now();
        string input;
        cin>>input;
        if(input=="md"||input=="MD")
        {
            //����Ŀ¼��ǰĿ¼���ǲ�����
            string mdn;
            cin>>mdn;
            if(!is_samename(ft,mdn))
            {
                create_md(ft,fat,mdn);
            }

            //fat.show_fat();
            //system("pause");
            //cout<<mdn;
            //����Ŀ¼���ڵ�ǰ��Ŀ¼����Ŀ¼

        }
        else if(input=="dir"||input=="DIR")
        {
            show_dqml(ft);
            //��ʾ��ǰĿ¼��ȫ��
            //��һ����¼��ǰĿ¼��ָ��
        }
        else if(input=="mk"||input=="MK")
        {
            string fn;
            int fs;
            cin>>fn>>fs;
            if(!is_samename(ft,fn))
            {
                create_mk(ft,fat,fn,fs);
            }

            //fat.show_fat();

        }
        else if(input=="del"||input=="DEL")
        {
            string fn;
            cin>>fn;
            remove_d(ft,fat,fn);
            //fat.show_fat();
        }
        else if(input=="rd"||input=="RD")
        {
            //ɾ����Ŀ¼
            string dm;
            cin>>dm;
            remove_d(ft,fat,dm);
            //fat.show_fat();

        }
        else if(input=="cd"||input=="CD")
        {
            string cdn;
            cin>>cdn;//����Ŀ¼�����������Ŀ¼
            //!������Ŀ¼ָ��,ֻ�ڱ����������
            find_m(ft,cdn);

        }
        else if(input=="e"||input=="E")
        {
            flag=0;
        }
        else if(input=="h"||input=="H")
        {
           menu();
        }
        else if(input=="sf"||input=="SF")
        {
            fat.show_fat();
        }
        else
        {
            cout<<"ָ���������������"<<endl;
        }
        system("pause");
    }

    return 0;
}
