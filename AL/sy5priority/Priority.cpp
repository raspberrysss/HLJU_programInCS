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

Priority_s::Priority_s():n_s()//内嵌无参调用，也可以不写
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
        distance[i]=MAX;//初值均设为MAX，当遇到比其值小的路径长度，替换
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
    cout<<"请输入顶点个数"<<endl;
    cin>>v_n;
    cout<<"请输入边的个数"<<endl;
    cin>>c_n;
    cout<<"请输入顶点名称"<<endl;
    for(int i=0;i<v_n;i++)
    {
        cin>>v[i];
    }
    char v,u;
    int w;
    int x,y;
    cout<<"请输入有向图的边及权值（例：输入ab5 则代表起点为a，终点为b，边长为5）"<<endl;
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
            cout<<"您输入的点并不存在在顶点集中，请重新输入"<<endl;
            i--;
        }
   }


}

void Priority_s::show_every()
{
    cout<<"邻接矩阵如下"<<endl;
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
            cout<<"从源点到"<<v[i]<<"无路径"<<endl;
        }
        else
        cout<<"到"<<v[i]<<"的最短距离为"<<distance[i]<<endl;

    }
    output_pre();
}

void Priority_s::find_shortpath()
{
    char c;//用重载应该会更好，有时间改一下
    cout<<"请输入源点"<<endl;
    cin>>c;
    n_s.set_name(c);
    n_s.set_length(0);//目前根到扩展结点的长度
    insert_pq(n_s);
    while(se!=0)
    {
        n_s=pop_pq();
        if(distance[index(n_s.get_name())]<n_s.get_len())//!当入队的已经出现比当前根到扩展结点路径更短的，直接出队，不用遍历所有相临结点
        {
            continue;//仅结束本次循环
        }
        for(int i=0;i<v_n;i++)//对每个结点，寻找其单源最短路径
        {
            int b=index(n_s.get_name());
            //前面已经定义char c，邻接矩阵用c会报错
            if(edge[b][i]<MAX&&n_s.get_len()+edge[b][i]<distance[i])
            {//有边并且路径最小才入队
                distance[i]=n_s.get_len()+edge[b][i];
                pre_v[i]=n_s.get_name();
                Node n_next;//新定义顶点让其入队
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
    //!se指向的是下一个位置，里面的值只进行了初始化
    //!i=se++ 先将se的值赋给i，se再加加
    //i=++se 先把se++，再赋给i
    while(i>0)//有多个元素，需要进行小根堆调整
    {
        //最后的i停在空位，应该放n_n的地方
        int p=(i-1)/2;//查看父节点的大小
        if(n[p].get_len()<=n_n.get_len())//!每次与要插入的结点比较，妙！
        {
            break;//若第一个父节点满足，其他的也不需要看了，一定满足，直接退出
        }
        n[i].set_length(n[p].get_len());
        n[i].set_name(n[p].get_name());
        i=p;//回溯到头结点结束
    }
    //!第一次进入，i=0，直接入队，不用调整
    n[i].set_length(n_n.get_len());//=不可以直接用
    n[i].set_name(n_n.get_name());
}

Node Priority_s::pop_pq()
{
    Node fro=n[0];//要出队的队头
    Node x=n[--se];
    //先把se--，再赋值，才是队尾，se指向队尾的下一个
    int i=0;
    while((i*2+1)<se)
    {
        int l=2*i+1;
        int r=2*i+2;//左右孩子
        if(r<se&&n[r].get_len()<n[l].get_len())
        {
            l=r;//让左孩子永远小于右孩子，然后让左孩子去比较
            //同时这样可以让路径小的先出队
        }
        if(n[l].get_len()>=x.get_len())
        {
            break;//假设拿队尾去补队头，拿x与左孩子比较，如果左孩子比他大，则是对的，可以直接退出
        }
        n[i].set_length(n[l].get_len());//从上到下的调整，找到i最合适的位置
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
    //用递归应该更好

    cout<<"最短路径为"<<endl;
    for(int i=1;i<v_n;i++)
    {
        string s="";//!清零
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
