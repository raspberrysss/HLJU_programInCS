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
    cout<<"请输入一个元素"<<endl;
    char e;
    cin>>e;
    tree->set_e(e);
    cout<<"是否要为"<<e<<"建立左子树（Y/N）"<<endl;
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
    cout<<"是否要为"<<e<<"建立右子树（Y/N)"<<endl;
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
    Bin_tree_node *tree;//先建立指针，不为其分配空间，当不为#时才分配空间
    char c;
    cin>>c;
    if(c=='#')
    {
        tree=NULL;//!出口，到这里就不再递归了
    }
    else
    {
        tree=new Bin_tree_node;//分配空间
        tree->set_e(c);
        tree->set_l(creat_bin_tree2());
        tree->set_r(creat_bin_tree2());//分别创建左右子树
    }
    return tree;
}

void pre_order(Bin_tree_node *tree)
{
    //if(tree==NULL)
    //{
      //  cout<<"此树为空树"<<endl;
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
    int l_depth,r_depth;//左右子树深度
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
            return l_depth+1;出现无返回值错误，为什么
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
        cout<<"此栈已满，无法入栈"<<endl;
        exit(0);
    }
    s[top++]=e;
}

void Stack::pop()
{
    if(is_empty_s())
    {
        cout<<"此栈已空，无法出栈"<<endl;
        exit(0);
    }
    top--;
    //c=s[top];//这样不能更好的把c展示出来
}

int Stack::get_top()//得到栈顶又出栈
{
    if(is_empty_s())
    {
        cout<<"此栈已空，无法取栈顶元素"<<endl;
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
        cout<<"此栈已满，无法入栈"<<endl;
        exit(0);
    }
    s[top++]=e;
}

void Stack2::pop()
{
    if(is_empty_s())
    {
        cout<<"此栈已空，无法出栈"<<endl;
        exit(0);
    }
    top--;
    //c=s[top];//这样不能更好的把c展示出来
}

void Stack2::get_top2(Bin_tree_node* &e)//仅取出栈顶，不出栈
{
    if(is_empty_s())
    {
        cout<<"此栈已空，无法取栈顶元素"<<endl;
        exit(0);
    }
    top--;
    e=s[top];
    top++;
}
Bin_tree_node* Stack2::get_top()//得到栈顶又出栈
{
    if(is_empty_s())
    {
        cout<<"此栈已空，无法取栈顶元素"<<endl;
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
            i=i*2;//!要转回来，不能使用不同的i，再看看！
        }
        if(!s1.is_empty_s())
        {
            i=s1.get_top();//此时得到栈顶又出栈了
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

        //cout<<"这"<<e[i2]<<endl;
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
        if(p->get_r()==NULL||p->get_r()==pre)//当右子树为空,或者被访问过,才输出
        {
            cout<<p->get_e();
            s.pop();
            pre=p;
        }
        else
            {
                tree=p->get_r();//!若未访问过右，且右不为空，需要访问其右子树，再进入while循环
                //!从while循环继续访问其左子树,继续进入循环
            }
    }
}

void menu()
{
    cout<<"1.求二叉树深度"<<endl;
    cout<<"2.非递归遍历数组存储的完全二叉树"<<endl;
    cout<<"3.非递归遍历二叉链表"<<endl;
    cout<<"4.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;

}
