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
    //delete [] array_m;//��û���������ڿ�������
}

void MaxSe::set_array()
{
    cout<<"�������������鳤��"<<endl;
    cin>>length;
    cout<<"���������Ԫ��"<<endl;
    for(int i=0;i<length;i++)
    {
        cin>>array_m[i];
    }
}

void MaxSe::show_array()
{
    cout<<"��������"<<endl;
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
    //cout<<"���ú�������"<<count_m<<"   ";
    int sum;//����Ӷκ�
    if(left==right)//����ʼ���յ�һ��ʱ��ֻ��һ���Ӷ����ݣ��ݹ����
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
        int center=(left+right)/2;//�ֶ�
        int leftsum=get_Max(left,center);//�ݹ�Ѱ�������С�Ӷκ�
        int rightsum=get_Max(center+1,right);
        //�������߿����꣬���������м����
        int s1=0;
        int lefts=0;//����ߵ�����
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
        int rights=0;//���ұߵ�����
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
    //cout<<"��ǰ"<<sum<<endl;
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
    cout<<"�������������鳤��"<<endl;
    cin>>length;
    cout<<"���������Ԫ��"<<endl;
    for(int i=0;i<length;i++)
    {
        cin>>array_mo[i];
    }
}

void Mode::show_array_mo()
{
    cout<<"��������"<<endl;
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

void Mode::get_mo_mu(int left,int right)//������ʼ�±꣬������ֹ�±�
{
    //1 1 1 1 2 2 2 3 3 3�ǶԵģ���ʱֻ����һ����ݹ鼴���ҵ���������
    //1 1 1 2 2 2 3 3 3 3 ���������
   // cout<<"1";
    sort(array_mo,array_mo+length);//��������
    //cout<<"2";��������ѭ��
    int center=(left+right)/2;//��λ������
    int mid=array_mo[center];
    //cout<<"m"<<mid<<endl;
    int first=0;
    int last=0;//��¼����λ����һ����ͬ���������һ����ͬ�ĺ�һ�������󳤶�
    for(int i=left;i<right;i++)
    {
        //cout<<"iii"<<array_mo[i]<<endl;
        if(array_mo[i]==mid)
        {
            first=i;
            //cout<<"f"<<first<<endl;
            break;//�ҵ���һ������ѭ��
            //first-1������ߵ���ֹ
        }
    }
    for(int i=first;i<right;i++)
    {
        //!�����ݹ�ʱ��û�в����ڵ�ʱ���˲���ѭ����
        if(array_mo[i]!=mid)
        {
            last=i;
            //cout<<"l"<<last<<endl;
            break;
            //last�����ұߵĿ�ʼ
        }
        //!!!
        if(i==right-1)
        {
            last=right;
            //cout<<"r"<<right<<endl;
        }
    }
    int len_mid=last-first;//��λ�����鳤
    //cout<<len_mid<<endl;
    if(multiplicity<=len_mid)//�ݹ���ڣ������ǰ����С����
    {
        multiplicity=len_mid;
        mode=mid;
        m[h].mid=mode;
        m[h].mul=multiplicity;
        h++;
        /*
        s[h]=mode;//������λ�����飬�������������������ȵ�
        h++;*/
       //cout<<mode<<"  "<<multiplicity<<endl;
    }
    if(first-left>=len_mid)//�����ߵĴ�����λ�����ȣ��������(first-left)�����������ж϶������
    {
        cout<<"��ݹ�"<<endl;
        get_mo_mu(left,first);//������first-1��Ҫ��ѭ���󷽱�ͳһ���㳤��
    }
    if(right-last+1>=len_mid)//right-last+1����Ϊ�ǵ�һ������ͬ������������Ҫ��һ
    {
        cout<<"�ҵݹ�"<<endl;
        get_mo_mu(last,right+1);
    }
    //!������ô���ݹ鶼�ḳֵ����ô��,����ϸ����!
    //?����û���£�����
    /*if(multiplicity==len_mid)//����ж��������ܲ��ԣ���Ϊǰ�汻��ֵ���������Ƕ�������
    {
        s[h]=mid;
        h++;
        if(flag_s==0)
        {
            flag_s=1;
        }
        else{
            s[h]=mid;//��ʱ����λ���Ž�ȥ

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
    cout<<"������";
    for(int i=0;i<h;i++)
    {
        if(m[i].mul==max_mu)
        {
            cout<<m[i].mid<<" ";
        }
    }
    cout<<endl;
    cout<<"������"<<max_mu<<endl;
}

void menu()
{
    cout<<"���������ֽ���ѡ��"<<endl;
    cout<<"1.�÷��η�������Ӷκ�"<<endl;
    cout<<"2.�÷��η�������������"<<endl;
    cout<<"3.�˳�"<<endl;
}
