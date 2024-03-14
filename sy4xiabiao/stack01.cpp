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
        cout<<"��ջ�������޷���ջ"<<endl;
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
        cout<<"��ջ�ѿգ��޷�������ջ"<<endl;
        exit(0);
    }
    else{
        top--;//�������ƶ�һλ�����䲻ָ���
        c=s_c[top];//cΪ�нӳ�ջԪ�ص�Ԫ��
        length--;
    }

}

void Stack::judge_symmetric()//�ж����Ƿ������ĶԳ�
{
    //����ջ����ջ����ȵģ��������ĶԳ�
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
            cout<<"���ַ����������ĶԳ�"<<endl;
            flag=0;
            break;

        }
    }
    if(flag==1)
    {
        cout<<"���ַ��������ĶԳ�"<<endl;
    }

}

void Stack::make_empty()
{
    length=0;
    top=0;
}

void Stack::match_brackets()
{
   /*����ʽ����ȫ�����ȥ����ȥ�ж�
     ƥ��ɹ�������ջ����
     ƥ��ʧ�ܣ����������ˣ���ջδ�� �����Ŷ���
               ջ���˸ó�ջȴ�޷��ٳ�ջ */
   string s;
   cout<<"�������������ʽ"<<endl;
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
               cout<<"ƥ��ʧ��"<<endl;
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
       cout<<"ƥ��ɹ�"<<endl;
   }
   else if(!is_empty_s()&&flag==1)
   {
       cout<<"ƥ��ʧ��"<<endl;
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
        tail=&n;//���ɾ��βָ����޷����������
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
    cout<<"�������������Ԫ��"<<endl;
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
        cout<<"�˶�����Ϊ�գ��޷�����"<<endl;
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
            cout<<"�˶�����Ϊ��"<<endl;
            return 0;
        }
        else
        {
            cout<<"Ŀǰ�Ķ���Ϊ"<<endl;
            Node *p=tail->get_next()->get_next();//n.get_next();//
            while(p!=&n)
            {
                p->show_data();
                p=p->get_next();//!pҪ���ƣ�����
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
    cout<<"�˶������ÿ�"<<endl;
}

void menu()
{
    cout<<"1.�ж��ַ����Ƿ�Ϊ���ĶԳ�"<<endl;
    cout<<"2.�ж�Բ�����Ƿ�ƥ��"<<endl;
    cout<<"3.��ͷ����ѭ�������ʾ����"<<endl;
    cout<<"4.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;
}

void menu2()
{
    cout<<"1.���"<<endl;
    cout<<"2.����"<<endl;
    cout<<"3.�ÿն�"<<endl;
    cout<<"4.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;
}
