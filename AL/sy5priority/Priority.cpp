#include"Priority00.h"
#include<iostream>
#include<string>
#include<algorithm>

//ab1 ac2 bc4 bd7 cd3
using namespace std;

const int MAX=23456;


Node::Node()
{
    name_node='0';
    length=0;
}

Node::~Node()
{

}

Priority_s::Priority_s():n_s()//��Ƕ�޲ε��ã�Ҳ���Բ�д
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            edge[i][j]=MAX;
        }
    }

    for(int i=0;i<100;i++)
    {
        distance[i]=MAX;//��ֵ����ΪMAX������������ֵС��·�����ȣ��滻
    }

    for(int i=0;i<100;i++)
    {
        v[100]='0';
        pre_v[100]='0';
    }
    v_n=0;
    se=0;
}

Priority_s::~Priority_s()
{

}

int Priority_s::index(char c)
{
    for(int i=0;i<v_n;i++)
    {
        if(c==v[i])
            return i;
    }
    return -1;
}

void Priority_s::set_graph()
{
    cout<<"�����붥�����"<<endl;
    cin>>v_n;
    cout<<"������ߵĸ���"<<endl;
    cin>>c_n;
    cout<<"�����붥������"<<endl;
    for(int i=0;i<v_n;i++)
    {
        cin>>v[i];
    }
    char v,u;
    int w;
    int x,y;
    cout<<"����������ͼ�ı߼�Ȩֵ����������ab5 ��������Ϊa���յ�Ϊb���߳�Ϊ5��"<<endl;
   for(int i=0;i<c_n;i++)
   {
        cin>>v>>u>>w;
        x=index(v);
        y=index(u);
        if(x!=-1&&y!=-1)
        {
            edge[x][y]=w;
        }
        else
        {
            cout<<"������ĵ㲢�������ڶ��㼯�У�����������"<<endl;
            i--;
        }
   }


}

void Priority_s::show_every()
{
    cout<<"�ڽӾ�������"<<endl;
    for(int i=0;i<v_n;i++)
    {
        for(int j=0;j<v_n;j++)
        {
            cout<<edge[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<v_n;i++)
    {
        if(distance[i]==MAX)
        {
            cout<<"��Դ�㵽"<<v[i]<<"��·��"<<endl;
        }
        else
        cout<<"��"<<v[i]<<"����̾���Ϊ"<<distance[i]<<endl;

    }
    output_pre();
}

void Priority_s::find_shortpath()
{
    char c;//������Ӧ�û���ã���ʱ���һ��
    cout<<"������Դ��"<<endl;
    cin>>c;
    n_s.set_name(c);
    n_s.set_length(0);//Ŀǰ������չ���ĳ���
    insert_pq(n_s);
    while(se!=0)
    {
        n_s=pop_pq();
        if(distance[index(n_s.get_name())]<n_s.get_len())//!����ӵ��Ѿ����ֱȵ�ǰ������չ���·�����̵ģ�ֱ�ӳ��ӣ����ñ����������ٽ��
        {
            continue;//����������ѭ��
        }
        for(int i=0;i<v_n;i++)//��ÿ����㣬Ѱ���䵥Դ���·��
        {
            int b=index(n_s.get_name());
            //ǰ���Ѿ�����char c���ڽӾ�����c�ᱨ��
            if(edge[b][i]<MAX&&n_s.get_len()+edge[b][i]<distance[i])
            {//�б߲���·����С�����
                distance[i]=n_s.get_len()+edge[b][i];
                pre_v[i]=n_s.get_name();
                Node n_next;//�¶��嶥���������
                n_next.set_name(v[i]);
                n_next.set_length(distance[i]);
                insert_pq(n_next);
            }
        }
    }

}

void Priority_s::insert_pq(Node n_n)
{
    int i=se++;
    //!seָ�������һ��λ�ã������ֵֻ�����˳�ʼ��
    //!i=se++ �Ƚ�se��ֵ����i��se�ټӼ�
    //i=++se �Ȱ�se++���ٸ���i
    while(i>0)//�ж��Ԫ�أ���Ҫ����С���ѵ���
    {
        //����iͣ�ڿ�λ��Ӧ�÷�n_n�ĵط�
        int p=(i-1)/2;//�鿴���ڵ�Ĵ�С
        if(n[p].get_len()<=n_n.get_len())//!ÿ����Ҫ����Ľ��Ƚϣ��
        {
            break;//����һ�����ڵ����㣬������Ҳ����Ҫ���ˣ�һ�����㣬ֱ���˳�
        }
        n[i].set_length(n[p].get_len());
        n[i].set_name(n[p].get_name());
        i=p;//���ݵ�ͷ������
    }
    //!��һ�ν��룬i=0��ֱ����ӣ����õ���
    n[i].set_length(n_n.get_len());//=������ֱ����
    n[i].set_name(n_n.get_name());
}

Node Priority_s::pop_pq()
{
    Node fro=n[0];//Ҫ���ӵĶ�ͷ
    Node x=n[--se];
    //�Ȱ�se--���ٸ�ֵ�����Ƕ�β��seָ���β����һ��
    int i=0;
    while((i*2+1)<se)
    {
        int l=2*i+1;
        int r=2*i+2;//���Һ���
        if(r<se&&n[r].get_len()<n[l].get_len())
        {
            l=r;//��������ԶС���Һ��ӣ�Ȼ��������ȥ�Ƚ�
            //ͬʱ����������·��С���ȳ���
        }
        if(n[l].get_len()>=x.get_len())
        {
            break;//�����ö�βȥ����ͷ����x�����ӱȽϣ�������ӱ��������ǶԵģ�����ֱ���˳�
        }
        n[i].set_length(n[l].get_len());//���ϵ��µĵ������ҵ�i����ʵ�λ��
        n[i].set_name(n[l].get_name());
        i=l;
    }
    n[i].set_length(x.get_len());
    n[i].set_name(x.get_name());
    return fro;
}

void Priority_s::output_pre()
{
    /*for(int i=0;i<v_n;i++)
    {
        cout<<pre_v[i]<<" ";
    }*/
    //�õݹ�Ӧ�ø���

    cout<<"���·��Ϊ"<<endl;
    for(int i=1;i<v_n;i++)
    {
        string s="";//!����
        int j=i;
        while(j!=0)
        {
            s=s+v[j];
          // cout<<v[j]<<" ";
            j=index(pre_v[j]);
        }
        s=s+v[j];
        //cout<<v[j]<<endl;
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        //string s="";
    }
    /*
    string s="";
    for(int i=0;i<v_n;i++)
    {
            s=s+v[i];
            cout<<v[i]<<"--------"<<endl;
            int j=i;
            while(pre_v[j]!='0')
            {
                s=s+pre_v[i];
               // cout<<pre_v[j];
                j=index(pre_v[j]);
                //cout<<"after"<<j<<" "<<pre_v[j]<<"****";
            }
            reverse(s.begin(),s.end());
            cout<<s<<endl;
            s="";
           // cout<<endl;
    }
    //cout<<s<<endl;
*/
}
