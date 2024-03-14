#include<iostream>
#include"Graph.h"
#include<cstdio>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

AMG_Graph::AMG_Graph()
{
    int i,j;
    vex_num=0;
    edge_num=0;
    //需要去new什么吗？c++和c
    for(i=0;i<MAX;i++)
    {
        vex[i]='0';
    }
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            edge[i][j]=MAX_INIT;
        }
    }

}

AMG_Graph::~AMG_Graph()
{

}

int AMG_Graph::search_index(char c)
{
    int i;
    for(i=0;i<vex_num;i++)
    {
        if(c==vex[i])
        {
            return i;
        }
    }
    return -1;//没有找到，输入错误
}

void AMG_Graph::Create_AMG_Graph_underieted()
{
    int i,j,k;
    cout<<"请输入您想创建无向图的顶点个数"<<endl;
    cin>>vex_num;
    cout<<"请输入您想创建无向图的边的个数"<<endl;
    cin>>edge_num;
    cout<<"请输入顶点"<<endl;
    for(i=0;i<vex_num;i++)
    {
        cin>>vex[i];
    }
    cout<<"请输入邻接的顶点对(例：输入ab代表（a，b）)"<<endl;
    for(i=0;i<edge_num;i++)
    {
        char v,u;
        cin>>v>>u;
        j=search_index(v);
        k=search_index(u);
        if(j!=-1&&k!=-1)
        {
            edge[j][k]=1;
            edge[k][j]=1;
        }
        else
        {
            cout<<"您输入的点并不存在在顶点集中，请重新输入"<<endl;
            i--;
        }

    }
    //show_AMG_Graph();
}

void AMG_Graph::Create_AMG_Graph_derieted()
{

    int i,j,k;
    cout<<"请输入您想创建有向图的顶点个数"<<endl;
    cin>>vex_num;
    cout<<"请输入您想创建有向图的边的个数"<<endl;
    cin>>edge_num;
    cout<<"请输入顶点"<<endl;
    for(i=0;i<vex_num;i++)
    {
        cin>>vex[i];
    }
    cout<<"请输入邻接的顶点对(例：输入ab，代表<a,b>)"<<endl;
    for(i=0;i<edge_num;i++)
    {
        char v,u;
        cin>>v>>u;
        j=search_index(v);
        k=search_index(u);
        if(j!=-1&&k!=-1)
        {
            edge[j][k]=1;
        }
        else
        {
            cout<<"您输入的点并不存在在顶点集中，请重新输入"<<endl;
            i--;
        }

    }
}

void AMG_Graph::Create_AMG_Graph_underieted_wet()
{
    int i,j,k;
    cout<<"请输入您想创建无向网的顶点个数"<<endl;
    cin>>vex_num;
    cout<<"请输入您想创建无向网的边的个数"<<endl;
    cin>>edge_num;
    cout<<"请输入顶点"<<endl;
    for(i=0;i<vex_num;i++)
    {
        cin>>vex[i];
    }
    cout<<"请输入邻接的顶点对及其权值(例：输入ab6代表（a，b），其权值为6)"<<endl;
    for(i=0;i<edge_num;i++)
    {
        char v,u;
        int w;
        cin>>v>>u>>w;
        j=search_index(v);
        k=search_index(u);
        if(j!=-1&&k!=-1)
        {
            edge[j][k]=w;
            edge[k][j]=w;
        }
        else
        {
            cout<<"您输入的点并不存在在顶点集中，请重新输入"<<endl;
            i--;
        }

    }
}

void AMG_Graph::Create_AMG_Graph_derieted_wet()
{
    int i,j,k;
    cout<<"请输入您想创建有向网的顶点个数"<<endl;
    cin>>vex_num;
    cout<<"请输入您想创建有向网的边的个数"<<endl;
    cin>>edge_num;
    cout<<"请输入顶点"<<endl;
    for(i=0;i<vex_num;i++)
    {
        cin>>vex[i];
    }
    cout<<"请输入邻接的顶点对及其权值(例：输入ab6，代表<a,b>，其权值为6)"<<endl;
    for(i=0;i<edge_num;i++)
    {
        char v,u;
        int w;
        cin>>v>>u>>w;
        j=search_index(v);
        k=search_index(u);
        if(j!=-1&&k!=-1)
        {
            edge[j][k]=w;
        }
        else
        {
            cout<<"您输入的点并不存在在顶点集中，请重新输入"<<endl;
            i--;
        }

    }
}

void AMG_Graph::show_AMG_Graph()
{
    int i,j;
    cout<<"此图的顶点数为"<<vex_num<<endl;
    cout<<"此图的边数为"<<edge_num<<endl;
    cout<<"此图的邻接矩阵为"<<endl;
    for(i=0;i<vex_num;i++)
    {
        for(j=0;j<vex_num;j++)
        {
            printf("%d\t",edge[i][j]);//cout<<edge[i][j]<<" ";
        }
        cout<<endl;
    }
}

void AMG_Graph::DFS_AMG_simple()
{
    //!从结点i到j，进行深搜，因为是一条道走到黑，所以也不会将已访问过的结点再次访问
    //!有问题！如果是某些图，则无法做到，只能做到遍历，应该找到方法进行处理
    //!找到头，重新找
    //!最后直接倒着输出递归栈
    //从而实现简单路径
   char a,b;
   stack<int> s;
   //stack<char> s2;//再定义一个栈来装要输出的数
   cout<<"请输入您想输出简单路径的起点和终点（例：输入ab，代表求起点是a，终点是b的简单路径）"<<endl;
   cin>>a>>b;
   int i,j;
   i=search_index(a);
   j=search_index(b);
   int visited[MAX]={0};
   int u,k;
   //int flag=0;
   //从i做起点开始遍历
   //j做终点的条件是什么？j已经被访问到了，visite【j】=1;
   visited[i]=1;//从i开始访问，变成1
   s.push(i);
   //cout<<vex[i];
  //1 s2.push(vex[i]);
  // int flag1=0;
  //!只可以输出一条，该怎么输出多条呢？
  if(i!=-1&&j!=-1)//在这里就可以判断是否存在，不用用flag
  {
      while(visited[j]!=1)//j未被访问过
   {
       u=s.top();
       for(k=0;k<vex_num;k++)
       {
           if(edge[u][k]==1&&visited[k]==0)
           {
               visited[k]=1;
               //cout<<vex[k];
               s.push(k);
              // s2.push(vex[k]);
               break;//break中止所有k的循环，直接执行下面的语句
           }
       }
       if(k==vex_num)
       {
           s.pop();
       }
       if(k==vex_num&&visited[j]!=1)//!当一条道走到黑还没有访问到j，则这条道废掉，从头找
       {
           //flag=1;
           continue;//跳出本次循环，接着判定while，然后往下走
           //cout<<"此路不通"<<endl;
           //怎么从头开始找？
       }
      /* if(visited[j]==1)
       {
           flag1=1;
       }*/
   }
  }
  else{
    cout<<"您输入的顶点并不存在，程序结束"<<endl;
    exit(0);
  }
  //cout<<endl;
  stack<char> s2;
  while(!s.empty())
  {
      int w;
      w=s.top();
      s2.push(vex[w]);
      w++;
      s.pop();
  }
  cout<<"此两点之间的一条简单路径为"<<endl;
  while(!s2.empty())
  {
      cout<<s2.top();
      s2.pop();
  }

 /* while(!s.empty())
  {
      int w;
      w=s.top();
      cout<<vex[w];
      s.pop();
  }*/

  //自己改对啦！但是和我想的不一样，莫名奇妙就对了，奇怪,没改对，白高兴了，哭了
  //!continue还是不太懂,它到底跳出了哪个循环了？为什么都正常输出，先输出的是13呢
  //!判断flag，决定是否要输出它，flag变过就证明s2不输出
  /*int w;
  if(flag==0)//代表没经历过退回重找的过程，正常输出
  {
      vector<char> v;
      while(!s2.empty())
      {
          v[w]=s2.top();
          s2.pop();
          w++;
      }
      vector<char>::iterator v_p;
      for(v_p=v.end();v_p!=v.begin();v_p--)
      {
                cout<<*v_p;
      }
  }*/
  /*while(!s2.empty())
  {
      cout<<endl;
      cout<<s2.top()<<endl;
      s2.pop();
  }*/

}

Adj_node::Adj_node()
{
    index=0;
    w=0;
    next=NULL;
}

Adj_node::~Adj_node()
{

}

void Adj_node::set_index(int in)
{
    index=in;
}

void Adj_node::set_next(Adj_node* n)
{
    next=n;
}

void Adj_node::set_w(int w_w)
{
    w=w_w;
}

int Adj_node::get_index()
{
    return index;
}

Adj_node* Adj_node::get_next()
{
    return next;
}

int Adj_node::get_w()
{
    return w;
}

/*Adj_node_w::Adj_node_w()
{
        index_w=0;
        next_w=NULL;
        w=0;
}

Adj_node_w::~Adj_node_w()
{

}

int Adj_node_w::get_index_w()
{
   return index_w;
}

int Adj_node_w::get_w()
{
    return w;
}

Adj_node* Adj_node_w::get_next_w()
{
    return next_w;
}

void Adj_node_w::set_index_w(int in_w)
{
    index_w=in_w;
}

void Adj_node_w::set_next_w(Adj_node* n_w)
{
    next_w=n_w;
}
void Adj_node_w::set_w(int w_w)
{
        w=w_w;
}
*/

VexNode::VexNode()
{
    node='0';
    first=NULL;
}

VexNode::~VexNode()
{

}

void VexNode::set_first(Adj_node *f)
{
    first=f;
}

void VexNode::set_node(char c)
{
        node=c;
}

char VexNode::get_node()
{
    return node;
}

Adj_node* VexNode::get_first()
{
    return first;
}

ALG_Graph::ALG_Graph()
{
    vex_num_l=0;
    edge_num_l=0;
    //如何初始化呢？
    //Vex.VexNode();
    //定义的时候已经初始化了呢？
    for(int i=0;i<MAX;i++)
    {

        Vex[i].set_node('0');
        Vex[i].set_first(NULL);

    }
}

ALG_Graph::~ALG_Graph()
{

}

int ALG_Graph::search_index_l(char c)
{
    int i;
    for(i=0;i<vex_num_l;i++)
    {
        if(c==Vex[i].get_node())
        {
            return i;
        }
    }
    return -1;
}

void ALG_Graph::Create_adj_node_list(int j,int k)
{
    Adj_node *p=new Adj_node;//要为其分配空间
    p->set_index(k);
    p->set_next(Vex[j].get_first());//!由其实现头插，类似实验三的头插！
    Vex[j].set_first(p);
}

void ALG_Graph::Create_adj_node_list_w(int j,int k,int w)
{
    Adj_node *p=new Adj_node;//要为其分配空间
    p->set_index(k);
    p->set_w(w);
    p->set_next(Vex[j].get_first());//!由其实现头插，类似实验三的头插！
    Vex[j].set_first(p);
}

void ALG_Graph::Create_ALG_Graph_dericted()
{
    int i;
    char c;
    cout<<"请输入此有向图的顶点个数"<<endl;
    cin>>vex_num_l;
    cout<<"请输入此有向图的边个数"<<endl;
    cin>>edge_num_l;
    cout<<"请输入此图的顶点"<<endl;
    for(i=0;i<vex_num_l;i++)
    {
         cin>>c;
         Vex[i].set_node(c);
         Vex[i].set_first(NULL);
    }
    char u,v;
    int j,k;
    cout<<"请输入邻接顶点对（例：ab代表<a,b>)"<<endl;
    for(i=0;i<edge_num_l;i++)
    {
        cin>>v>>u;
        j=search_index_l(v);
        k=search_index_l(u);
        if(j!=-1&&k!=-1)
        {
            Create_adj_node_list(j,k);
        }
        else
        {
            cout<<"此顶点对不存在"<<endl;
            i--;
        }


    }

}

void ALG_Graph::Create_ALG_Graph_undericted()
{
    int i;
    char c;
    cout<<"请输入此无向图的顶点个数"<<endl;
    cin>>vex_num_l;
    cout<<"请输入此无向图的边个数"<<endl;
    cin>>edge_num_l;
    cout<<"请输入此图的顶点"<<endl;
    for(i=0;i<vex_num_l;i++)
    {
         cin>>c;
         Vex[i].set_node(c);
         Vex[i].set_first(NULL);
    }
    char u,v;
    int j,k;
    cout<<"请输入邻接顶点对（例：ab代表(a,b))"<<endl;
    for(i=0;i<edge_num_l;i++)
    {
        cin>>v>>u;
        j=search_index_l(v);
        k=search_index_l(u);
        if(j!=-1&&k!=-1)
        {
            Create_adj_node_list(j,k);
            Create_adj_node_list(k,j);
        }
        else
        {
            cout<<"此顶点对不存在"<<endl;
            i--;
        }


    }

}

void ALG_Graph::Create_ALG_Graph_dericted_wet()
{
    int i;
    char c;
    cout<<"请输入此有向图的顶点个数"<<endl;
    cin>>vex_num_l;
    cout<<"请输入此有向图的边个数"<<endl;
    cin>>edge_num_l;
    cout<<"请输入此图的顶点"<<endl;
    for(i=0;i<vex_num_l;i++)
    {
         cin>>c;
         Vex[i].set_node(c);
         Vex[i].set_first(NULL);
    }
    char u,v;
    int w;
    int j,k;
    cout<<"请输入邻接顶点对及其权值（例：ab6代表<a,b>，权值为6)"<<endl;
    for(i=0;i<edge_num_l;i++)
    {
        cin>>v>>u>>w;
        j=search_index_l(v);
        k=search_index_l(u);
        if(j!=-1&&k!=-1)
        {
            Create_adj_node_list_w(j,k,w);
        }
        else
        {
            cout<<"此顶点对不存在"<<endl;
            i--;
        }


    }
}

void ALG_Graph::Create_ALG_Graph_undericted_wet()
{
    int i;
    char c;
    cout<<"请输入此有向图的顶点个数"<<endl;
    cin>>vex_num_l;
    cout<<"请输入此有向图的边个数"<<endl;
    cin>>edge_num_l;
    cout<<"请输入此图的顶点"<<endl;
    for(i=0;i<vex_num_l;i++)
    {
         cin>>c;
         Vex[i].set_node(c);
         Vex[i].set_first(NULL);
    }
    char u,v;
    int w;
    int j,k;
    cout<<"请输入邻接顶点对及其权值（例：ab6代表（a,b），权值为6)"<<endl;
    for(i=0;i<edge_num_l;i++)
    {
        cin>>v>>u>>w;
        j=search_index_l(v);
        k=search_index_l(u);
        if(j!=-1&&k!=-1)
        {
            Create_adj_node_list_w(j,k,w);
            Create_adj_node_list_w(k,j,w);
        }
        else
        {
            cout<<"此顶点对不存在"<<endl;
            i--;
        }


    }
}

void ALG_Graph::Show_ALG_g()
{
    int i;
    cout<<"此图的顶点个数为"<<vex_num_l<<endl;
    cout<<"此图的边数为"<<edge_num_l<<endl;
    cout<<"此图的邻接表为"<<endl;
    Adj_node * b;
    for(i=0;i<vex_num_l;i++)
    {
        cout<<Vex[i].get_node()<<": ";
        b=Vex[i].get_first();
        while(b!=NULL)
        {
            cout<<b->get_index()<<" ";
            b=b->get_next();
        }
        cout<<endl;

    }

}

void ALG_Graph::Show_ALG_w()
{
    int i;
    cout<<"此图的顶点个数为"<<vex_num_l<<endl;
    cout<<"此图的边数为"<<edge_num_l<<endl;
    cout<<"此图的邻接表为"<<endl;
    Adj_node * b;
    for(i=0;i<vex_num_l;i++)
    {
        cout<<Vex[i].get_node()<<": ";
        b=Vex[i].get_first();
        while(b!=NULL)
        {
            cout<<b->get_index()<<"/"<<b->get_w()<<" ";
            b=b->get_next();
        }
        cout<<endl;

    }
}

void ALG_Graph::BFS_ALG_min()
{
      char a,b;
      cout<<"请输入起点与终点"<<endl;
      cin>>a>>b;
      int i,j;
      i=search_index_l(a);
      j=search_index_l(b);
      int visited[MAX]={0};//判断是否被访问过
      int path[vex_num_l]={-1};//!最重要的数组是path，由它回溯前一个结点，由广度搜索找到
      queue<int> q;//存下标的队列
      Adj_node *p;//遍历指针
      if(i!=-1&&j!=-1)
      {
          visited[i]=1;//先访问起点
          q.push(i);
          //访问后直接出队，访问其邻接点，访问后访问其邻接点后再出队是一样的
          while(!q.empty())
          {
              int u=q.front();
              q.pop();//队头出队
              p=Vex[u].get_first();
              while(p!=NULL)
              {
                  int n=p->get_index();
                  if(visited[n]!=1)//没被访问过的，入队列
                  {
                      visited[n]=1;
                      path[n]=u;//!这句是重点！！！
                      q.push(n);
                  }
                  p=p->get_next();
              }

          }
          if(path[j]==-1&&i!=j)
          {
              cout<<"此两点间无路径"<<endl;
          }
          else
          {
              stack<char> input;
              int k;
              k=j;
              while(k!=-1)
              {
                  input.push(Vex[k].get_node());
                  k=path[k];
              }
              cout<<"两点间的最短路径为"<<endl;
              while(!input.empty())
              {
                  cout<<input.top();
                  input.pop();
              }

          }
      }
      else{
        cout<<"您输入的顶点并不存在于图中"<<endl;
      }
}

void menu()
{
    cout<<"1.寻找用邻接矩阵建成的图的一条简单路径"<<endl;
    cout<<"2.寻找用邻接表建成的图的最短路径"<<endl;
    cout<<"3.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;
}

void menu_AMG()
{
    cout<<"1.建立无向图求一条简单路径"<<endl;
    cout<<"2.建立有向图求一条简单路径"<<endl;
    cout<<"3.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;
}

void menu_ALG()
{
    cout<<"1.建立无向图求最短路径"<<endl;
    cout<<"2.建立有向图求最短路径"<<endl;
    cout<<"3.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;

}

//    int visited[MAX]={0};
//    int i,j,u;
//    stack<int> s;
//    for(i=0;i<vex_num;i++)//防止非联通图，将以每个起点开始遍历，防止无法顺着遍历到
// {
//        while(!s.empty())
//    {
//       /* visited[i]=1;//开始遍历的被访问
//        cout<<vex[i];
//        s.push(i);//将其下标，即将其入栈，等它的所有结点被访问完才出栈
//        for(j=0;j<vex_num;j++)//扫描这一行，找其邻接点
//        {
//           // u=s.top();//记录下标，开始找，不能用i
//            if(edge[i][j]==1)//找到其邻接点，访问，但不能全访问，还要记录之前访问的是谁，方便回退
//            {
//                    visited[j]=1;
//                    cout<<vex[j];
//                    s.push(j);
//                    break;
//            }
//            if(j==vex_num)
//            {
//                s.pop();
//            }
//        }
//        }
//    }
//    /*
//   char a,b;
//   stack<int> s;
//   cout<<"请输入您想输出简单路径的起点和终点（例：输入ab，代表求起点是a，终点是b的简单路径）"<<endl;
//   cin>>a>>b;
//   int i,j;
//   i=search_index(a);
//   j=search_index(b);
//   int visited[MAX]={0};//visited数组置零，均未被访问过
//   //int k;
//   for(k=i;k<vex_num;k++)//从k开始遍历，防止非连通？
//   {
//
//   }
//   cout<<vex[i]<<" ";
//   visited[i]=1;//从起点开始遍历
//   s.push(i);//将下标入栈
//   int k;
//
//   因为深度优先搜索就是一条路走到黑，只要遍历起点到终点就可以了，已经访问过的一定不会出现。
//   但是简单路径也会有多条，所以要多次从起点深度搜索
//
//
//   while(!s.empty())//当栈顶不为终点时，进行遍历，若栈顶为终点，证明终点已被访问过了，已经到达
//   {
//       int u;
//       u=s.top();
//       for(k=0;k<vex_num;k++)//扫描每行，找邻接点
//       {
//           if(edge[u][k]!=MAX_INIT&&visited[k]!=1)//找到第一个邻接点
//            {
//                visited[k]=1;//标记被访问过
//                s.push(k);
//                cout<<vex[k]<<" ";
//                break;
//            }
//       }
//       if(k==vex_num)
//       {
//           s.pop();
//       }
//   }
//   //cout<<"good"<<endl;*/

