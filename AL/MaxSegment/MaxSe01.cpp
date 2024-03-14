#include"MaxSe00.h"
#include<iostream>
#include<algorithm>

using namespace std;

//int MaxSe::count_m=0;
//int s[100]={0};

MaxSe::MaxSe()
{
    length=0;
    sta=0;
    ter=0;
   // array_m=new int[length];
   for(int i=0;i<100;i++)
   {
       array_m[i]=0;
   }

}

MaxSe::~MaxSe()
{
    length=0;
    sta=0;
    ter=0;
    //delete [] array_m;//有没有区别？现在看不出来
}

void MaxSe::set_array()
{
    cout<<"请输入整数数组长度"<<endl;
    cin>>length;
    cout<<"请输入各个元素"<<endl;
    for(int i=0;i<length;i++)
    {
        cin>>array_m[i];
    }
}

void MaxSe::show_array()
{
    cout<<"主段如下"<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<array_m[i]<<" ";
    }
}

int MaxSe::get_length()
{
    return length;
}

int MaxSe::get_Max(int left,int right)
{

    //count_m++;
    //cout<<"调用函数次数"<<count_m<<"   ";
    int sum;//最大子段和
    if(left==right)//当起始和终点一样时，只有一个子段数据，递归出口
    {
        if(array_m[left]>=0)
        {
            sum=array_m[left];
            sta=left;
            ter=right;
        }
        else
        {
            sum=0;
        }
    }
    else
    {
        int center=(left+right)/2;//分段
        int leftsum=get_Max(left,center);//递归寻找左边最小子段和
        int rightsum=get_Max(center+1,right);
        //左右两边考虑完，接下来找中间情况
        int s1=0;
        int lefts=0;//找左边的最优
        for(int i=center;i>=left;i--)
        {
            lefts+=array_m[i];
            if(lefts>s1)
            {
                s1=lefts;
                sta=i;
            }
        }
        int s2=0;
        int rights=0;//找右边的最优
        for(int i=center+1;i<=right;i++)
        {
            rights+=array_m[i];
            if(rights>s2)
            {
                s2=rights;
                ter=i;
            }
        }
        sum=s1+s2;
        if(sum<leftsum){sum=leftsum;}
        if(sum<rightsum){sum=rightsum;}

    }
    //cout<<"当前"<<sum<<endl;
    return sum;
}

Mode::Mode()
{
    length=0;
    for(int i=0;i<100;i++)
    {
        array_mo[i]=0;
    }
    for(int i=0;i<100;i++)
    {
        m[i].mid=0;
        m[i].mul=0;
    }
   /* for(int i=0;i<100;i++)
   {
       s[i]=0;
   }*/
    mode=0;
    multiplicity=0;
    h=0;
    flag_s=0;
}

Mode::~Mode()
{
    length=0;

}

void Mode::set_array_mo()
{
    cout<<"请输入整数数组长度"<<endl;
    cin>>length;
    cout<<"请输入各个元素"<<endl;
    for(int i=0;i<length;i++)
    {
        cin>>array_mo[i];
    }
}

void Mode::show_array_mo()
{
    cout<<"主段如下"<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<array_mo[i]<<" ";
    }
}

void Mode::show_s()
{
    for(int i=0;i<h;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void Mode::show_m()
{
    for(int i=0;i<h;i++)
    {
        cout<<m[i].mid<<" "<<m[i].mul<<" ";
    }
}

void Mode::get_mo_mu(int left,int right)//数组起始下标，数组终止下标
{
    //1 1 1 1 2 2 2 3 3 3是对的，此时只进行一次左递归即可找到众数重数
    //1 1 1 2 2 2 3 3 3 3 会出现问题
   // cout<<"1";
    sort(array_mo,array_mo+length);//进行排序
    //cout<<"2";出现了死循环
    int center=(left+right)/2;//中位数坐标
    int mid=array_mo[center];
    //cout<<"m"<<mid<<endl;
    int first=0;
    int last=0;//记录与中位数第一个相同的数和最后一个相同的后一个数，求长度
    for(int i=left;i<right;i++)
    {
        //cout<<"iii"<<array_mo[i]<<endl;
        if(array_mo[i]==mid)
        {
            first=i;
            //cout<<"f"<<first<<endl;
            break;//找到第一个就退循环
            //first-1就是左边的终止
        }
    }
    for(int i=first;i<right;i++)
    {
        //!这样递归时，没有不等于的时候，退不出循环！
        if(array_mo[i]!=mid)
        {
            last=i;
            //cout<<"l"<<last<<endl;
            break;
            //last就是右边的开始
        }
        //!!!
        if(i==right-1)
        {
            last=right;
            //cout<<"r"<<right<<endl;
        }
    }
    int len_mid=last-first;//中位数数组长
    //cout<<len_mid<<endl;
    if(multiplicity<=len_mid)//递归出口，如果当前重数小，换
    {
        multiplicity=len_mid;
        mode=mid;
        m[h].mid=mode;
        m[h].mul=multiplicity;
        h++;
        /*
        s[h]=mode;//所有中位数数组，从里面找重数最大且相等的
        h++;*/
       //cout<<mode<<"  "<<multiplicity<<endl;
    }
    if(first-left>=len_mid)//如果左边的大于中位数长度，从左边找(first-left)，等于用于判断多个众数
    {
        cout<<"左递归"<<endl;
        get_mo_mu(left,first);//不能是first-1，要出循环后方便统一计算长度
    }
    if(right-last+1>=len_mid)//right-last+1是因为是第一个不相同的数，长度需要加一
    {
        cout<<"右递归"<<endl;
        get_mo_mu(last,right+1);
    }
    //!无论怎么样递归都会赋值，怎么办,再仔细看看!
    //?数组没更新？？？
    /*if(multiplicity==len_mid)//这个判断条件可能不对，因为前面被赋值，无论怎们都会进这个
    {
        s[h]=mid;
        h++;
        if(flag_s==0)
        {
            flag_s=1;
        }
        else{
            s[h]=mid;//此时的中位数放进去

        }

        cout<<"s"<<s[h]<<endl;
        //cout<<"h"<<h<<endl;
        h++;

    }*/
}

void Mode::find_max_mu()
{
    int max_mu=0;
    for(int i=0;i<h;i++)
    {
        if(m[i].mul>max_mu)
        {
            max_mu=m[i].mul;
        }
    }
    cout<<"众数是";
    for(int i=0;i<h;i++)
    {
        if(m[i].mul==max_mu)
        {
            cout<<m[i].mid<<" ";
        }
    }
    cout<<endl;
    cout<<"重数是"<<max_mu<<endl;
}

void menu()
{
    cout<<"请输入数字进行选择"<<endl;
    cout<<"1.用分治法求最大子段和"<<endl;
    cout<<"2.用分治法求众数，重数"<<endl;
    cout<<"3.退出"<<endl;
}
