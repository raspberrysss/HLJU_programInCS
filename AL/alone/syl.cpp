#include <iostream>
#include<algorithm>
using namespace std;
int a[100];//重数
int b[100];//众数

int zhongshu(int array[],int k,int m,int l)
{
    int i,j;
    int mid;
    mid=(k+m)/2;
    i=mid+1;
    j=mid;
    while(array[i]==array[mid])//右边
    {
        i++;
        a[l]++;
        b[l]=array[mid];
    }
    while(array[j]==array[mid])//左边
    {
        j--;
        a[l]++;
        b[l]=array[mid];
    }
    if(j+1<a[l]&&m-i<a[l])
    {
        return l;
    }//如果中位数的左右两边剩余数字都比中位数的重数少则无需再次计较
    if(j+1<a[l]&&m-i>a[l])
    {
        l++;
        zhongshu(array,i,m,l);
    }//右边剩的数字多再次比较
    if(j+1>a[l]&&m-i>a[l])
    {
        l++;
        zhongshu(array,0,j,l);
    }//左面剩的数字多再次比较
}

int main()
{
    int n,x,i,l,k=0;
    int array[1000];
    cout<<"输入判断数组的长度"<<endl;
    cin>>n;
    for(i=0; i<200; i++)
    {
        a[i]=0;
        b[i]=0;
    }
    cout<<"输入判断的数组"<<endl;
    for(i=0; i<n; i++)
        cin>>array[i];
    sort(array,array+n);//排序
    l=zhongshu(array,0,n,0);
    for(int i=0;i<=l;i++)
    {
        cout<<b[i]<<endl;
    }
    if(l==0)
    {
        cout<<"众数为："<<b[l]<<endl;
        cout<<"重数为："<<a[l]<<endl;
    }
    else
    {
        for(int x=0; x<=l; x++)
        {
                cout<<"众数为："<<b[x]<<endl;
                cout<<"重数为："<<a[x]<<endl;
        }
    }
    return 0;
}

