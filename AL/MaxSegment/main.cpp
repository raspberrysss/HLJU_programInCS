/**
    最大子段和是指一个整型主段中按顺序拿出子段，其和最大的为最大子段和,如果是负数，则最大子段和为0
    用分治法解决求最大子段和问题，可以把一个段分为左右两份，最大子段和要不出现在左边，要不出现在右边，要不在左右之间，若在左边或右边可以通过不断细分递归求解，若在中间则可以计算左边最优的一段，再加上右边最优的一段

    找一个整数组中出现次数最多的数，就是众数，其出现的次数就是它的重数
    用分治法求众数重数，把一个数组快排，找到中位数，遍历得到与中位数相等的第一个数和最后一个数的位置，得到长度，比较
    多个众数建立一个结构体数组比较



*/

/**
    在类中私有成员定义数组时，可以直接定义数组，也可以用指针定义，后续new数组，好处只有动态吗？
    头文件只是定义声明并没有创建对吗？见c++ primer plus P303 ,只有类创建对象时才会有内存空间，类的声明只是告诉编译器类是什么样子的，编译器却没有分配内存空间去存放这个类
    ！递归理解的不好，下午仔细过一遍
    在类里递归动态数组会出现问题？
    ！！左右递归时last的大小要注意！！！

*/

#include <iostream>
#include<cstdlib>
#include"MaxSe00.h"

using namespace std;

int main(void)
{
    int choice;
    int flag=1;
    while(flag)
    {
        system("cls");
        menu();
        cin>>choice;
        switch(choice)
        {
        case 1:
            {

                char f;
                do{
                system("cls");
                MaxSe m1;
                m1.set_array();
                //m1.show_array();
                //cout<<endl;
                int s=m1.get_Max(0,m1.get_length()-1);
                cout<<"最大子段和为"<<s<<endl;//有时会出现溢出问题？类中动态数组出现问题
                cout<<"起始下标"<<m1.get_sta()<<"  "<<"终止下标"<<m1.get_ter()<<endl;
                cout<<"是否继续用分治法求最大子段和（Y/N）"<<endl;
                cin>>f;
                }while(f=='Y');
                system("pause");
                break;
            }
        case 2:
            {
                char f2;
                do{
                system("cls");
                Mode mo1;
                mo1.set_array_mo();
                //mo1.show_array_mo();
                //cout<<endl;
                mo1.get_mo_mu(0,mo1.get_length()-1);
               /* cout<<"众数是";
                mo1.show_s();
                cout<<"重数是"<<mo1.get_mu()<<endl;*/
               // mo1.show_m();
               mo1.find_max_mu();
                //mo1.show_s();
                /*if(mo1.get_h()>1)//如果众数有多个，就用数组输出，如何判断众数有多个？
                {
                    cout<<"众数是";
                    mo1.show_s();
                    cout<<"重数是"<<mo1.get_mu()<<endl;
                }
                else
                {
                    cout<<"众数是"<<mo1.get_mo()<<"重数是"<<mo1.get_mu()<<endl;
                }*/

                //cout<<"众数是"<<mo1.get_mo()<<"重数是"<<mo1.get_mu()<<endl;
                /*if(mo1.get_flags()!=0)
                {
                    cout<<"众数是";
                    mo1.show_s();
                    cout<<"重数是"<<mo1.get_mu()<<endl;
                }
                else{
                    cout<<"众数是"<<mo1.get_mo()<<"重数是"<<mo1.get_mu()<<endl;
                }*/
                cout<<"是否继续用分治法求众数和重数（Y/N）"<<endl;
                cin>>f2;
                }while(f2=='Y');
                system("pause");
                break;
            }
        case 3:
            {
                flag=0;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
