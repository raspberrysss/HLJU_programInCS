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
    //��Ҫȥnewʲô��c++��c
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
    return -1;//û���ҵ����������
}

void AMG_Graph::Create_AMG_Graph_underieted()
{
    int i,j,k;
    cout<<"���������봴������ͼ�Ķ������"<<endl;
    cin>>vex_num;
    cout<<"���������봴������ͼ�ıߵĸ���"<<endl;
    cin>>edge_num;
    cout<<"�����붥��"<<endl;
    for(i=0;i<vex_num;i++)
    {
        cin>>vex[i];
    }
    cout<<"�������ڽӵĶ����(��������ab����a��b��)"<<endl;
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
            cout<<"������ĵ㲢�������ڶ��㼯�У�����������"<<endl;
            i--;
        }

    }
    //show_AMG_Graph();
}

void AMG_Graph::Create_AMG_Graph_derieted()
{

    int i,j,k;
    cout<<"���������봴������ͼ�Ķ������"<<endl;
    cin>>vex_num;
    cout<<"���������봴������ͼ�ıߵĸ���"<<endl;
    cin>>edge_num;
    cout<<"�����붥��"<<endl;
    for(i=0;i<vex_num;i++)
    {
        cin>>vex[i];
    }
    cout<<"�������ڽӵĶ����(��������ab������<a,b>)"<<endl;
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
            cout<<"������ĵ㲢�������ڶ��㼯�У�����������"<<endl;
            i--;
        }

    }
}

void AMG_Graph::Create_AMG_Graph_underieted_wet()
{
    int i,j,k;
    cout<<"���������봴���������Ķ������"<<endl;
    cin>>vex_num;
    cout<<"���������봴���������ıߵĸ���"<<endl;
    cin>>edge_num;
    cout<<"�����붥��"<<endl;
    for(i=0;i<vex_num;i++)
    {
        cin>>vex[i];
    }
    cout<<"�������ڽӵĶ���Լ���Ȩֵ(��������ab6����a��b������ȨֵΪ6)"<<endl;
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
            cout<<"������ĵ㲢�������ڶ��㼯�У�����������"<<endl;
            i--;
        }

    }
}

void AMG_Graph::Create_AMG_Graph_derieted_wet()
{
    int i,j,k;
    cout<<"���������봴���������Ķ������"<<endl;
    cin>>vex_num;
    cout<<"���������봴���������ıߵĸ���"<<endl;
    cin>>edge_num;
    cout<<"�����붥��"<<endl;
    for(i=0;i<vex_num;i++)
    {
        cin>>vex[i];
    }
    cout<<"�������ڽӵĶ���Լ���Ȩֵ(��������ab6������<a,b>����ȨֵΪ6)"<<endl;
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
            cout<<"������ĵ㲢�������ڶ��㼯�У�����������"<<endl;
            i--;
        }

    }
}

void AMG_Graph::show_AMG_Graph()
{
    int i,j;
    cout<<"��ͼ�Ķ�����Ϊ"<<vex_num<<endl;
    cout<<"��ͼ�ı���Ϊ"<<edge_num<<endl;
    cout<<"��ͼ���ڽӾ���Ϊ"<<endl;
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
    //!�ӽ��i��j���������ѣ���Ϊ��һ�����ߵ��ڣ�����Ҳ���Ὣ�ѷ��ʹ��Ľ���ٴη���
    //!�����⣡�����ĳЩͼ�����޷�������ֻ������������Ӧ���ҵ��������д���
    //!�ҵ�ͷ��������
    //!���ֱ�ӵ�������ݹ�ջ
    //�Ӷ�ʵ�ּ�·��
   char a,b;
   stack<int> s;
   //stack<char> s2;//�ٶ���һ��ջ��װҪ�������
   cout<<"���������������·���������յ㣨��������ab�������������a���յ���b�ļ�·����"<<endl;
   cin>>a>>b;
   int i,j;
   i=search_index(a);
   j=search_index(b);
   int visited[MAX]={0};
   int u,k;
   //int flag=0;
   //��i����㿪ʼ����
   //j���յ��������ʲô��j�Ѿ������ʵ��ˣ�visite��j��=1;
   visited[i]=1;//��i��ʼ���ʣ����1
   s.push(i);
   //cout<<vex[i];
  //1 s2.push(vex[i]);
  // int flag1=0;
  //!ֻ�������һ��������ô��������أ�
  if(i!=-1&&j!=-1)//������Ϳ����ж��Ƿ���ڣ�������flag
  {
      while(visited[j]!=1)//jδ�����ʹ�
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
               break;//break��ֹ����k��ѭ����ֱ��ִ����������
           }
       }
       if(k==vex_num)
       {
           s.pop();
       }
       if(k==vex_num&&visited[j]!=1)//!��һ�����ߵ��ڻ�û�з��ʵ�j�����������ϵ�����ͷ��
       {
           //flag=1;
           continue;//��������ѭ���������ж�while��Ȼ��������
           //cout<<"��·��ͨ"<<endl;
           //��ô��ͷ��ʼ�ң�
       }
      /* if(visited[j]==1)
       {
           flag1=1;
       }*/
   }
  }
  else{
    cout<<"������Ķ��㲢�����ڣ��������"<<endl;
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
  cout<<"������֮���һ����·��Ϊ"<<endl;
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

  //�Լ��Ķ��������Ǻ�����Ĳ�һ����Ī������Ͷ��ˣ����,û�Ķԣ��׸����ˣ�����
  //!continue���ǲ�̫��,�������������ĸ�ѭ���ˣ�Ϊʲô��������������������13��
  //!�ж�flag�������Ƿ�Ҫ�������flag�����֤��s2�����
  /*int w;
  if(flag==0)//����û�������˻����ҵĹ��̣��������
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
    //��γ�ʼ���أ�
    //Vex.VexNode();
    //�����ʱ���Ѿ���ʼ�����أ�
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
    Adj_node *p=new Adj_node;//ҪΪ�����ռ�
    p->set_index(k);
    p->set_next(Vex[j].get_first());//!����ʵ��ͷ�壬����ʵ������ͷ�壡
    Vex[j].set_first(p);
}

void ALG_Graph::Create_adj_node_list_w(int j,int k,int w)
{
    Adj_node *p=new Adj_node;//ҪΪ�����ռ�
    p->set_index(k);
    p->set_w(w);
    p->set_next(Vex[j].get_first());//!����ʵ��ͷ�壬����ʵ������ͷ�壡
    Vex[j].set_first(p);
}

void ALG_Graph::Create_ALG_Graph_dericted()
{
    int i;
    char c;
    cout<<"�����������ͼ�Ķ������"<<endl;
    cin>>vex_num_l;
    cout<<"�����������ͼ�ı߸���"<<endl;
    cin>>edge_num_l;
    cout<<"�������ͼ�Ķ���"<<endl;
    for(i=0;i<vex_num_l;i++)
    {
         cin>>c;
         Vex[i].set_node(c);
         Vex[i].set_first(NULL);
    }
    char u,v;
    int j,k;
    cout<<"�������ڽӶ���ԣ�����ab����<a,b>)"<<endl;
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
            cout<<"�˶���Բ�����"<<endl;
            i--;
        }


    }

}

void ALG_Graph::Create_ALG_Graph_undericted()
{
    int i;
    char c;
    cout<<"�����������ͼ�Ķ������"<<endl;
    cin>>vex_num_l;
    cout<<"�����������ͼ�ı߸���"<<endl;
    cin>>edge_num_l;
    cout<<"�������ͼ�Ķ���"<<endl;
    for(i=0;i<vex_num_l;i++)
    {
         cin>>c;
         Vex[i].set_node(c);
         Vex[i].set_first(NULL);
    }
    char u,v;
    int j,k;
    cout<<"�������ڽӶ���ԣ�����ab����(a,b))"<<endl;
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
            cout<<"�˶���Բ�����"<<endl;
            i--;
        }


    }

}

void ALG_Graph::Create_ALG_Graph_dericted_wet()
{
    int i;
    char c;
    cout<<"�����������ͼ�Ķ������"<<endl;
    cin>>vex_num_l;
    cout<<"�����������ͼ�ı߸���"<<endl;
    cin>>edge_num_l;
    cout<<"�������ͼ�Ķ���"<<endl;
    for(i=0;i<vex_num_l;i++)
    {
         cin>>c;
         Vex[i].set_node(c);
         Vex[i].set_first(NULL);
    }
    char u,v;
    int w;
    int j,k;
    cout<<"�������ڽӶ���Լ���Ȩֵ������ab6����<a,b>��ȨֵΪ6)"<<endl;
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
            cout<<"�˶���Բ�����"<<endl;
            i--;
        }


    }
}

void ALG_Graph::Create_ALG_Graph_undericted_wet()
{
    int i;
    char c;
    cout<<"�����������ͼ�Ķ������"<<endl;
    cin>>vex_num_l;
    cout<<"�����������ͼ�ı߸���"<<endl;
    cin>>edge_num_l;
    cout<<"�������ͼ�Ķ���"<<endl;
    for(i=0;i<vex_num_l;i++)
    {
         cin>>c;
         Vex[i].set_node(c);
         Vex[i].set_first(NULL);
    }
    char u,v;
    int w;
    int j,k;
    cout<<"�������ڽӶ���Լ���Ȩֵ������ab6����a,b����ȨֵΪ6)"<<endl;
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
            cout<<"�˶���Բ�����"<<endl;
            i--;
        }


    }
}

void ALG_Graph::Show_ALG_g()
{
    int i;
    cout<<"��ͼ�Ķ������Ϊ"<<vex_num_l<<endl;
    cout<<"��ͼ�ı���Ϊ"<<edge_num_l<<endl;
    cout<<"��ͼ���ڽӱ�Ϊ"<<endl;
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
    cout<<"��ͼ�Ķ������Ϊ"<<vex_num_l<<endl;
    cout<<"��ͼ�ı���Ϊ"<<edge_num_l<<endl;
    cout<<"��ͼ���ڽӱ�Ϊ"<<endl;
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
      cout<<"������������յ�"<<endl;
      cin>>a>>b;
      int i,j;
      i=search_index_l(a);
      j=search_index_l(b);
      int visited[MAX]={0};//�ж��Ƿ񱻷��ʹ�
      int path[vex_num_l]={-1};//!����Ҫ��������path����������ǰһ����㣬�ɹ�������ҵ�
      queue<int> q;//���±�Ķ���
      Adj_node *p;//����ָ��
      if(i!=-1&&j!=-1)
      {
          visited[i]=1;//�ȷ������
          q.push(i);
          //���ʺ�ֱ�ӳ��ӣ��������ڽӵ㣬���ʺ�������ڽӵ���ٳ�����һ����
          while(!q.empty())
          {
              int u=q.front();
              q.pop();//��ͷ����
              p=Vex[u].get_first();
              while(p!=NULL)
              {
                  int n=p->get_index();
                  if(visited[n]!=1)//û�����ʹ��ģ������
                  {
                      visited[n]=1;
                      path[n]=u;//!������ص㣡����
                      q.push(n);
                  }
                  p=p->get_next();
              }

          }
          if(path[j]==-1&&i!=j)
          {
              cout<<"���������·��"<<endl;
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
              cout<<"���������·��Ϊ"<<endl;
              while(!input.empty())
              {
                  cout<<input.top();
                  input.pop();
              }

          }
      }
      else{
        cout<<"������Ķ��㲢��������ͼ��"<<endl;
      }
}

void menu()
{
    cout<<"1.Ѱ�����ڽӾ��󽨳ɵ�ͼ��һ����·��"<<endl;
    cout<<"2.Ѱ�����ڽӱ��ɵ�ͼ�����·��"<<endl;
    cout<<"3.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;
}

void menu_AMG()
{
    cout<<"1.��������ͼ��һ����·��"<<endl;
    cout<<"2.��������ͼ��һ����·��"<<endl;
    cout<<"3.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;
}

void menu_ALG()
{
    cout<<"1.��������ͼ�����·��"<<endl;
    cout<<"2.��������ͼ�����·��"<<endl;
    cout<<"3.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;

}

//    int visited[MAX]={0};
//    int i,j,u;
//    stack<int> s;
//    for(i=0;i<vex_num;i++)//��ֹ����ͨͼ������ÿ����㿪ʼ��������ֹ�޷�˳�ű�����
// {
//        while(!s.empty())
//    {
//       /* visited[i]=1;//��ʼ�����ı�����
//        cout<<vex[i];
//        s.push(i);//�����±꣬��������ջ�����������н�㱻������ų�ջ
//        for(j=0;j<vex_num;j++)//ɨ����һ�У������ڽӵ�
//        {
//           // u=s.top();//��¼�±꣬��ʼ�ң�������i
//            if(edge[i][j]==1)//�ҵ����ڽӵ㣬���ʣ�������ȫ���ʣ���Ҫ��¼֮ǰ���ʵ���˭���������
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
//   cout<<"���������������·���������յ㣨��������ab�������������a���յ���b�ļ�·����"<<endl;
//   cin>>a>>b;
//   int i,j;
//   i=search_index(a);
//   j=search_index(b);
//   int visited[MAX]={0};//visited�������㣬��δ�����ʹ�
//   //int k;
//   for(k=i;k<vex_num;k++)//��k��ʼ��������ֹ����ͨ��
//   {
//
//   }
//   cout<<vex[i]<<" ";
//   visited[i]=1;//����㿪ʼ����
//   s.push(i);//���±���ջ
//   int k;
//
//   ��Ϊ���������������һ��·�ߵ��ڣ�ֻҪ������㵽�յ�Ϳ����ˣ��Ѿ����ʹ���һ��������֡�
//   ���Ǽ�·��Ҳ���ж���������Ҫ��δ�����������
//
//
//   while(!s.empty())//��ջ����Ϊ�յ�ʱ�����б�������ջ��Ϊ�յ㣬֤���յ��ѱ����ʹ��ˣ��Ѿ�����
//   {
//       int u;
//       u=s.top();
//       for(k=0;k<vex_num;k++)//ɨ��ÿ�У����ڽӵ�
//       {
//           if(edge[u][k]!=MAX_INIT&&visited[k]!=1)//�ҵ���һ���ڽӵ�
//            {
//                visited[k]=1;//��Ǳ����ʹ�
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

