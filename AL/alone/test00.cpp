#include<iostream>

using namespace std;

//就是在类里递归出现的问题，放到外面是对的。

int get_Max(int *array_m,int left,int right)
{


    //cout<<"调用函数次数"<<count_m<<"   ";
    int sum;//最大子段和
    if(left==right)//当起始和终点一样时，只有一个子段数据，递归出口
    {
        if(array_m[left]>=0)
        {
            sum=array_m[left];
        }
        else
        {
            sum=0;
        }
    }
    else
    {
        int center=(left+right)/2;//分段
        int leftsum=get_Max(array_m,left,center);//递归寻找左边最小子段和
        int rightsum=get_Max(array_m,center+1,right);
        //左右两边考虑完，接下来找中间情况
        int s1=0;
        int lefts=0;//找左边的最优
        for(int i=center;i>=left;i--)
        {
            lefts+=array_m[i];
            if(lefts>s1)
            {
                s1=lefts;
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
            }
        }
        sum=s1+s2;
        if(sum<leftsum){sum=leftsum;}
        if(sum<rightsum){sum=rightsum;}

    }
    cout<<"当前"<<sum<<endl;
    return sum;
}

int main()
{
    int l;
    int a[20];
    cin>>l;
    cout<<"元素"<<endl;
    for(int i=0;i<l;i++)
    {
        cin>>a[i];
    }
    int sum=get_Max(a,0,l-1);
    cout<<sum;
    return 0;
}
