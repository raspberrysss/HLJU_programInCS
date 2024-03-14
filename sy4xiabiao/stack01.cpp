#include<iostream>
#include"stack00.h"
#include<string>

using namespace std;

Stack::Stack()
{
    top=0;
    length=0;
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

void Stack::push(char c)
{
    if(is_full())
    {
        cout<<"此栈已满，无法入栈"<<endl;
        exit(0);
    }
    else{
            s_c[top++]=c;//s_c[top]=c;top++
            length++;

    }


}

void Stack::pop(char & c)
{
    if(is_empty_s())
    {
        cout<<"此栈已空，无法继续出栈"<<endl;
        exit(0);
    }
    else{
        top--;//先往后移动一位，让其不指向空
        c=s_c[top];//c为承接出栈元素的元素
        length--;
    }

}

void Stack::judge_symmetric()//判断其是否是中心对称
{
    //若出栈和入栈是相等的，就是中心对称
    int i;
    char a;
    char c;
    int j;
    j=0;//j=length;
    int flag=1;
    int n=length;
    for(i=0;i<n;i++)
    {
        a=s_c[j];
        //cout<<a<<" "<<length<<endl;
        j++;
        pop(c);
        if(c!=a)
        {
            cout<<"此字符串不是中心对称"<<endl;
            flag=0;
            break;

        }
    }
    if(flag==1)
    {
        cout<<"此字符串是中心对称"<<endl;
    }

}

void Stack::make_empty()
{
    length=0;
    top=0;
}

void Stack::match_brackets()
{
   /*把算式数组全部存进去，再去判断
     匹配成功：并且栈空了
     匹配失败：数组走完了，但栈未空 左括号多了
               栈空了该出栈却无法再出栈 */
   string s;
   cout<<"请输入算数表达式"<<endl;
   cin>>s;
   int l=s.length();
   int i;
   int flag=1;
   for(i=0;i<l;i++)
   {
       /*if(s[0]==')')
       {
           flag=3;
           break;
       }*/

       if(s[i]=='(')
       {
           push(s[i]);
       }
       if(s[i]==')')
       {
           if(is_empty_s())
           {
               cout<<"匹配失败"<<endl;
               flag=0;
               break;
           }
           top--;
           length--;
           //char c;
           //pop(c);
       }
   }
   if(is_empty_s()&&flag==1)
   {
       cout<<"匹配成功"<<endl;
   }
   else if(!is_empty_s()&&flag==1)
   {
       cout<<"匹配失败"<<endl;
   }

}

Node::Node()
{
    data=0;
    next=NULL;
}

int Node::get_data()
{
        return data;
}

Node* Node::get_next()
{
    return next;
}

void Node::set_data()
{
    cin>>data;
}

void Node::set_data2(int d)
{
     data=d;
}

void Node::set_next(Node *p)
{
    next=p;
}

void Node::show_data()
{
    cout<<data<<" ";
}

Queue::Queue()
{
    tail=&n;
    n.set_next(tail);
    length=1;

}

void Queue::enter(int e)
{
    if(length==1)
    {
        tail=&n;//解决删除尾指针后无法插入的问题
    }
    //tail=&n;
    Node *s=new Node;
    s->set_data2(e);
    s->set_next(NULL);
    tail->set_next(s);
    tail=s;
    tail->set_next(&n);
    length++;
}

void Queue::enter1(int n_1)
{
    length=length+n_1;
    cout<<"请依次输入入队元素"<<endl;
    int i;
    for(i=0;i<n_1;i++)
    {
        Node *s=new Node;
        s->set_data();
        s->set_next(NULL);
        tail->set_next(s);
        tail=s;
    }
    tail->set_next(&n);
}

int Queue::leave()
{
    if(length==1)
    {
        cout<<"此队列已为空，无法出队"<<endl;
        return 0;
    }
    else
    {
       Node *p;
        p=n.get_next();
        n.set_next(p->get_next());
        p->set_next(NULL);
        delete p;
        length--;
        return 1;
    }

}

int Queue::show_queue()
{
        if(length==1)
        {
            cout<<"此队列已为空"<<endl;
            return 0;
        }
        else
        {
            cout<<"目前的队列为"<<endl;
            Node *p=tail->get_next()->get_next();//n.get_next();//
            while(p!=&n)
            {
                p->show_data();
                p=p->get_next();//!p要后移，别忘
                //p->show_data();
            }
            cout<<endl;
            return 1;
        }


}

void Queue::make_empty()
{
    tail=&n;
    n.set_next(tail);
    length=1;
    cout<<"此队列已置空"<<endl;
}

void menu()
{
    cout<<"1.判断字符串是否为中心对称"<<endl;
    cout<<"2.判断圆括号是否匹配"<<endl;
    cout<<"3.带头结点的循环链表表示队列"<<endl;
    cout<<"4.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;
}

void menu2()
{
    cout<<"1.入队"<<endl;
    cout<<"2.出队"<<endl;
    cout<<"3.置空队"<<endl;
    cout<<"4.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;
}
