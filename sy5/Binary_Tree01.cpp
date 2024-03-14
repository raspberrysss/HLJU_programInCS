#include<iostream>
#include"Binary_Tree00.h"

using namespace std;

Bin_tree_node::Bin_tree_node()
{
    elem='0';
    l_tree=NULL;
    r_tree=NULL;

}

char Bin_tree_node::get_e()
{
    return elem;
}

Bin_tree_node* Bin_tree_node::get_l()
{
    return l_tree;
}

Bin_tree_node* Bin_tree_node::get_r()
{
    return r_tree;
}

void Bin_tree_node::set_e(char e)
{
    elem=e;
}

void Bin_tree_node::set_l(Bin_tree_node *l)
{
    l_tree=l;
}

void Bin_tree_node::set_r(Bin_tree_node *r)
{
    r_tree=r;
}

/*Bin_tree::Bin_tree()
{
    tree=NULL;
}
*/
Bin_tree_node* creat_bin_tree()
{
    Bin_tree_node *tree=new Bin_tree_node;
    cout<<"������һ��Ԫ��"<<endl;
    char e;
    cin>>e;
    tree->set_e(e);
    cout<<"�Ƿ�ҪΪ"<<e<<"������������Y/N��"<<endl;
    char c;
    cin>>c;
    if(c=='Y')
    {
        tree->set_l(creat_bin_tree());
    }
    else
    {
        tree->set_l(NULL);
    }
    cout<<"�Ƿ�ҪΪ"<<e<<"������������Y/N)"<<endl;
    cin>>c;
    if(c=='Y')
    {
        tree->set_r(creat_bin_tree());
    }
    else
    {
        tree->set_r(NULL);
    }
    return tree;
}

Bin_tree_node* creat_bin_tree2()
{
    //Bin_tree_node * tree=new Bin_tree_node;
    Bin_tree_node *tree;//�Ƚ���ָ�룬��Ϊ�����ռ䣬����Ϊ#ʱ�ŷ���ռ�
    char c;
    cin>>c;
    if(c=='#')
    {
        tree=NULL;//!���ڣ�������Ͳ��ٵݹ���
    }
    else
    {
        tree=new Bin_tree_node;//����ռ�
        tree->set_e(c);
        tree->set_l(creat_bin_tree2());
        tree->set_r(creat_bin_tree2());//�ֱ𴴽���������
    }
    return tree;
}

void pre_order(Bin_tree_node *tree)
{
    //if(tree==NULL)
    //{
      //  cout<<"����Ϊ����"<<endl;
    //}
     if(tree!=NULL)
    {

        cout<<tree->get_e();
        pre_order(tree->get_l());
        pre_order(tree->get_r());
    }

}

int count_depth(Bin_tree_node *tree)
{
    int l_depth,r_depth;//�����������
    if(tree==NULL)
    {
        return 0;
    }
    else
    {
        l_depth=count_depth(tree->get_l());
        r_depth=count_depth(tree->get_r());
        return (l_depth>r_depth)?(l_depth+1):(r_depth+1);
        /*if(l_depth>r_depth)
            return l_depth+1;�����޷���ֵ����Ϊʲô
        else if(r_depth>l_depth)
            return r_depth+1;*/

    }
}

Stack::Stack()
{
    top=0;
}

bool Stack::is_empty_s()
{
    if(top==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::is_full()
{
    if(top==MAXSIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::push(int e)
{
    if(is_full())
    {
        cout<<"��ջ�������޷���ջ"<<endl;
        exit(0);
    }
    s[top++]=e;
}

void Stack::pop()
{
    if(is_empty_s())
    {
        cout<<"��ջ�ѿգ��޷���ջ"<<endl;
        exit(0);
    }
    top--;
    //c=s[top];//�������ܸ��õİ�cչʾ����
}

int Stack::get_top()//�õ�ջ���ֳ�ջ
{
    if(is_empty_s())
    {
        cout<<"��ջ�ѿգ��޷�ȡջ��Ԫ��"<<endl;
        exit(0);
    }
    top--;
    return s[top];
}

Stack2::Stack2()
{
    top=0;
}

bool Stack2::is_empty_s()
{
    if(top==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack2::is_full()
{
    if(top==MAXSIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack2::push(Bin_tree_node* e)
{
    if(is_full())
    {
        cout<<"��ջ�������޷���ջ"<<endl;
        exit(0);
    }
    s[top++]=e;
}

void Stack2::pop()
{
    if(is_empty_s())
    {
        cout<<"��ջ�ѿգ��޷���ջ"<<endl;
        exit(0);
    }
    top--;
    //c=s[top];//�������ܸ��õİ�cչʾ����
}

void Stack2::get_top2(Bin_tree_node* &e)//��ȡ��ջ��������ջ
{
    if(is_empty_s())
    {
        cout<<"��ջ�ѿգ��޷�ȡջ��Ԫ��"<<endl;
        exit(0);
    }
    top--;
    e=s[top];
    top++;
}
Bin_tree_node* Stack2::get_top()//�õ�ջ���ֳ�ջ
{
    if(is_empty_s())
    {
        cout<<"��ջ�ѿգ��޷�ȡջ��Ԫ��"<<endl;
        exit(0);
    }
    top--;
    return s[top];
}

void pre_full(char e[],int n)
{
    Stack s1;
    int i=1;
    /*for(i=1;i<=n;i++)
    {
        cout<<e[i];
    }*/
    while(i<=n||!s1.is_empty_s())
    {
        while(i<=n)
        {
            cout<<e[i];
            s1.push(i);
            i=i*2;//!Ҫת����������ʹ�ò�ͬ��i���ٿ�����
        }
        if(!s1.is_empty_s())
        {
            i=s1.get_top();//��ʱ�õ�ջ���ֳ�ջ��
            i=2*i+1;
        }
    }


    /*
    //int flag=1;

    while(!s1.is_empty_s())
    {
        //cout<<"h"<<endl;
        int i2=1;
        i2=s1.get_top();
       // cout<<i2<<endl;
        //i2=i2/2;
       // cout<<i2<<endl;
        //s1.pop();
        i2=i2*2+1;
        //cout<<i2<<endl;
        if(i2<=n)
        {
            cout<<e[i2];
            s1.push(i2);
        }

        //cout<<"��"<<e[i2]<<endl;
    }
    */

}

void pre_through_s(Bin_tree_node *tree)
{
    Stack2 s;
    while(tree!=NULL||!s.is_empty_s())
    {
        while(tree!=NULL)
        {
            cout<<tree->get_e();
            s.push(tree);
            tree=tree->get_l();
        }
        Bin_tree_node *p=s.get_top();
        tree=p->get_r();
    }

}

void mid_through_s(Bin_tree_node* tree)
{
    Stack2 s;
    while(tree!=NULL||!s.is_empty_s())
    {
        while(tree!=NULL)
        {
            s.push(tree);
            tree=tree->get_l();
        }
        Bin_tree_node *p=s.get_top();
        cout<<p->get_e();
        tree=p->get_r();
    }
}

void tail_through_s(Bin_tree_node *tree)
{
    Bin_tree_node *pre;
    pre=NULL;
    Stack2 s;
    while(tree!=NULL||!s.is_empty_s())
    {
        while(tree!=NULL)
        {
            s.push(tree);
            tree=tree->get_l();
        }
        Bin_tree_node *p;
        s.get_top2(p);
        if(p->get_r()==NULL||p->get_r()==pre)//��������Ϊ��,���߱����ʹ�,�����
        {
            cout<<p->get_e();
            s.pop();
            pre=p;
        }
        else
            {
                tree=p->get_r();//!��δ���ʹ��ң����Ҳ�Ϊ�գ���Ҫ���������������ٽ���whileѭ��
                //!��whileѭ������������������,��������ѭ��
            }
    }
}

void menu()
{
    cout<<"1.����������"<<endl;
    cout<<"2.�ǵݹ��������洢����ȫ������"<<endl;
    cout<<"3.�ǵݹ������������"<<endl;
    cout<<"4.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;

}
