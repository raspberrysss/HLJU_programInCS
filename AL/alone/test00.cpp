#include<iostream>

using namespace std;

//����������ݹ���ֵ����⣬�ŵ������ǶԵġ�

int get_Max(int *array_m,int left,int right)
{


    //cout<<"���ú�������"<<count_m<<"   ";
    int sum;//����Ӷκ�
    if(left==right)//����ʼ���յ�һ��ʱ��ֻ��һ���Ӷ����ݣ��ݹ����
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
        int center=(left+right)/2;//�ֶ�
        int leftsum=get_Max(array_m,left,center);//�ݹ�Ѱ�������С�Ӷκ�
        int rightsum=get_Max(array_m,center+1,right);
        //�������߿����꣬���������м����
        int s1=0;
        int lefts=0;//����ߵ�����
        for(int i=center;i>=left;i--)
        {
            lefts+=array_m[i];
            if(lefts>s1)
            {
                s1=lefts;
            }
        }
        int s2=0;
        int rights=0;//���ұߵ�����
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
    cout<<"��ǰ"<<sum<<endl;
    return sum;
}

int main()
{
    int l;
    int a[20];
    cin>>l;
    cout<<"Ԫ��"<<endl;
    for(int i=0;i<l;i++)
    {
        cin>>a[i];
    }
    int sum=get_Max(a,0,l-1);
    cout<<sum;
    return 0;
}
