#include <iostream>
#include<algorithm>
using namespace std;
int a[100];//����
int b[100];//����

int zhongshu(int array[],int k,int m,int l)
{
    int i,j;
    int mid;
    mid=(k+m)/2;
    i=mid+1;
    j=mid;
    while(array[i]==array[mid])//�ұ�
    {
        i++;
        a[l]++;
        b[l]=array[mid];
    }
    while(array[j]==array[mid])//���
    {
        j--;
        a[l]++;
        b[l]=array[mid];
    }
    if(j+1<a[l]&&m-i<a[l])
    {
        return l;
    }//�����λ������������ʣ�����ֶ�����λ�����������������ٴμƽ�
    if(j+1<a[l]&&m-i>a[l])
    {
        l++;
        zhongshu(array,i,m,l);
    }//�ұ�ʣ�����ֶ��ٴαȽ�
    if(j+1>a[l]&&m-i>a[l])
    {
        l++;
        zhongshu(array,0,j,l);
    }//����ʣ�����ֶ��ٴαȽ�
}

int main()
{
    int n,x,i,l,k=0;
    int array[1000];
    cout<<"�����ж�����ĳ���"<<endl;
    cin>>n;
    for(i=0; i<200; i++)
    {
        a[i]=0;
        b[i]=0;
    }
    cout<<"�����жϵ�����"<<endl;
    for(i=0; i<n; i++)
        cin>>array[i];
    sort(array,array+n);//����
    l=zhongshu(array,0,n,0);
    for(int i=0;i<=l;i++)
    {
        cout<<b[i]<<endl;
    }
    if(l==0)
    {
        cout<<"����Ϊ��"<<b[l]<<endl;
        cout<<"����Ϊ��"<<a[l]<<endl;
    }
    else
    {
        for(int x=0; x<=l; x++)
        {
                cout<<"����Ϊ��"<<b[x]<<endl;
                cout<<"����Ϊ��"<<a[x]<<endl;
        }
    }
    return 0;
}

