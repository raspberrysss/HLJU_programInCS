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
            //创建目录后当前目录还是不更改
            string mdn;
            cin>>mdn;
            if(!is_samename(ft,mdn))
            {
                create_md(ft,fat,mdn);
            }

            //fat.show_fat();
            //system("pause");
            //cout<<mdn;
            //创建目录，在当前父目录建新目录

        }
        else if(input=="dir"||input=="DIR")
        {
            show_dqml(ft);
            //显示当前目录的全部
            //有一个记录当前目录的指针
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
            //删除空目录
            string dm;
            cin>>dm;
            remove_d(ft,fat,dm);
            //fat.show_fat();

        }
        else if(input=="cd"||input=="CD")
        {
            string cdn;
            cin>>cdn;//输入目录名，进入这个目录
            //!遍历找目录指针,只在本层遍历就行
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
            cout<<"指令错误，请重新输入"<<endl;
        }
        system("pause");
    }

    return 0;
}
