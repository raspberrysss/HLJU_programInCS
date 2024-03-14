#include"Maxdd00.h"
#include<iostream>

using namespace std;

Maxsegment_d::Maxsegment_d()
{
    length_d=0;
    for(int i=0;i<100;i++)
    {
        array_d[i]=0;
    }
    for(int i=0;i<100;i++)
    {
        dynamic[i]=0;
    }
    sta=0;
    ter=0;
}

Maxsegment_d::~Maxsegment_d()
{

}

void Maxsegment_d::set_array_d()
{
    cout<<"�����볤��"<<endl;
    cin>>length_d;
    cout<<"���������Ԫ��"<<endl;
    for(int i=1;i<=length_d;i++)
    {
        cin>>array_d[i];
    }
    //cout<<endl;
    /*for(int i=1;i<=length_d;i++)
    {
        cout<<array_d[i]<<" ";
    }*/
}

int Maxsegment_d::find_Maxsegement()
{
    //b[j]ʼ�մ������������������Ҳ����
    int sum=0;
    int i=0;//��¼��ʼ�±�
    for(int j=1;j<=length_d;j++)
    {
        if(dynamic[j-1]>0)//ǰһ�����Ǹ����ͼ���
        {
            dynamic[j]=dynamic[j-1]+array_d[j];
        }
        else
        {
            dynamic[j]=array_d[j];
            i=j;
        }
        if(sum<dynamic[j])
        {
            sum=dynamic[j];
            sta=i;
            ter=j;
        }
    }
    return sum;
}

Max_order::Max_order()
{
    len1=0;
    len2=0;
    for(int i=1;i<=100;i++)//��1��ʼ�棬�����0Ҳ���ԣ�ֻ�ǳ�ʼ��ֵ
    {
        str1[i]='0';
        str2[i]='0';
    }
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            max_value[i][j]=0;
        }
    }
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            s_ter[i][j]='0';
        }
    }
    besti=0;
    bestj=0;
    flag=0;
    string w="";
}

Max_order::~Max_order()
{

}

void Max_order::set_str12()
{
    cout<<"�������һ�����еĳ���"<<endl;
    cin>>len1;
    cout<<"�������һ������"<<endl;
    for(int i=1;i<=len1;i++)
    {
        cin>>str1[i];
    }
    cout<<"������ڶ������еĳ���"<<endl;
    cin>>len2;
    cout<<"������ڶ�������"<<endl;
    for(int i=1;i<=len2;i++)
    {
        cin>>str2[i];
    }
}

void Max_order::set_value_ter()
{
    int i,j;
    for(i=0;i<=len1;i++)//����Ⱥ��Ƿ񲻱�Ҫ?��Ҫ����Ϊlen=5��Ҫ����
    {
        max_value[0][i]=0;//��0�и�ֵ0
    }
    for(j=0;j<=len2;j++)
    {
        max_value[j][0]=0;//��0�и�ֵ0
    }
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i]==str2[j])//����ȵ����������ǰ���Ѿ���Ӧ��
            {
                max_value[i][j]=max_value[i-1][j-1]+1;//б�Ͻǣ�1
                s_ter[i][j]='!';
                flag=1;
                besti=i;
                bestj=j;
            }
            else
            {
                //cout<<"��"<<max_value[i-1][j]<<"��"<<max_value[i][j-1]<<endl;
                if(max_value[i-1][j]>=max_value[i][j-1])//����������ı��
                {
                    max_value[i][j]=max_value[i-1][j];
                    s_ter[i][j]='*';
                }
                else
                {
                    max_value[i][j]=max_value[i][j-1];
                    s_ter[i][j]='<';
                }
            }
        }
    }
}

void Max_order::show_a()
{
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            cout<<max_value[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            cout<<s_ter[i][j]<<" ";
        }
        cout<<endl;
    }

}

void Max_order::LCS(int i,int j)
{
    if(i==0||j==0){return ;}
    if(s_ter[i][j]=='!')
    {
        LCS(i-1,j-1);//�ȵݹ��������������
        cout<<str1[i];
    }
    else if(s_ter[i][j]=='*')
    {
        LCS(i-1,j);
    }
    else
    {
        LCS(i,j-1);
    }
}
void Max_order:: LCS_many(int i_m,int j_m)
{

    while(i_m>0&&j_m>0)
    {
        if(str1[i_m-1]==str2[j_m-1])
        {
            w.push_back(str1[i_m-1]);
            //w=w+str1[i_m-1];
            --i_m;
            --j_m;
        }
        else
        {
            if(max_value[i_m-1][j_m]>max_value[i_m][j_m-1])
            {
                --i_m;
            }
            else if(max_value[i_m-1][j_m]<max_value[i_m][j_m-1])
            {
                --j_m;
            }
            else//������
            {
                LCS_many(i_m-1,j_m);//�ֿ��ݹ�Ѱ��
                LCS_many(i_m,j_m-1);
                return ;
            }
        }

    }
    //cout<<w;
}

void menu()
{
    cout<<"���������ֽ���ѡ��"<<endl;
    cout<<"1.��̬�滮��������Ӷκ�"<<endl;
    cout<<"2.��̬�滮���������������"<<endl;
    cout<<"3.�˳�"<<endl;
}
