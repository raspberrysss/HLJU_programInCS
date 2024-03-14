#include<iostream>
#include"link_cycle00.h"

using namespace std;

Node::Node()
{
    data=0;
    next=NULL;
}

void Node::set_data()
{
    cin>>data;
}

void Node::set_next(Node* p)
{
    next=p;
}

int Node::get_data()
{
    return data;
}

Node* Node::get_next()
{
    return next;
}

void Node::show_data()
{
    cout<<data<<" ";
}

Link_cycle::Link_cycle()
{
    tail=NULL;
    length=0;
}

void Link_cycle::creat_link_c(int n)//��ͷ����β�壬������ͷ���
{
       //Node *text=new Node;
       //cout<<text->get_data()<<endl;
        length=n;
        Node *p_h;//����һ��ͷָ�븨����������
        p_h=NULL;
        cout<<"�������������뽨���������Ԫ��"<<endl;
        int i;
        for(i=0;i<n;i++)
        {
            Node *p=new Node;
            p->set_data();
            p->set_next(NULL);
            if(p_h==NULL)
            {
                p_h=p;
                tail=p;
            }
            else
            {
                tail->set_next(p);
                tail=p;
            }
        }
        tail->set_next(p_h);//����ͷ���
}

void Link_cycle::show_link()
{
    Node *p;
    p=tail->get_next();
    do
    {
        p->show_data();
        p=p->get_next();
    }while(p!=tail->get_next());//!��do whileѭ��������������н�������  ������
     cout<<endl;
        /*�������������������������ѭ��
        Node *p;
        p=NULL;
        while(p!=tail->get_next())
        {
            p=tail->get_next();//��Ϊÿ��ѭ�����������ˣ����Գ�������
            p->show_data();
            p=p->get_next();
        }*/
}

void Link_cycle::delete_pre(int node_d)
{

    Node *find_p,*pre,*p_pre;
    find_p=tail;
    pre=tail;
    p_pre=tail;
    //���û�������������ڣ���i��¼ѭ����������length���жԱȣ�д����Ҫ����д
    while(find_p->get_data()!=node_d)//���ҵ����,�˳�ѭ��ʱfind_pָ��node_d���ڵĽ��
    {
        p_pre=pre;
        pre=find_p;//��¼ǰ�����
        find_p=find_p->get_next();
    }
    //��һ��ѭ���Ͳ�����ѭ���������p_pre����ָ��������ָ���λ��
    if(tail->get_data()==node_d)//tail����Ҫ�ҵĽ�㣬������ѭ�������
    {

        while(pre->get_next()!=tail)//�ҵ�tail��ǰǰ�ú�ǰ�ã�p_pre,pre
        {
            p_pre=pre;
            pre=pre->get_next();
        }
    }
    else if(find_p==tail->get_next())//ֻ������һ��ѭ����Ҫɾ������tail
    {
        while(p_pre->get_next()!=tail)//�ҵ�tailǰ��,�ŵ�p_pre�pre����tail
        {
            p_pre=p_pre->get_next();
        }
        pre=tail;
    }
    p_pre->set_next(find_p);
    pre->set_next(NULL);
    if(pre==tail)
    {
        tail=p_pre;
    }
    delete pre;
}//�Լ�д������û�����������ϣ�ţţţ��

Node_c::Node_c()
{
    data='n';//''�ַ������ַ���?
    next=NULL;
}

void Node_c::set_data()
{
     //cin.getchar()=data;
    cin>>data;
}

void Node_c::set_next(Node_c *p)
{
    next=p;
}

char Node_c::get_data()
{
    return data;
}

Node_c *Node_c::get_next()
{
    return next;
}

void Node_c::show_data()
{
    cout<<data<<" ";
}

List_ch::List_ch()
{
    length=1;
    head=&nch;
    nch.set_next(NULL);
}

void List_ch::creat_tail()
{
    cout<<"����������Ԫ�ظ���"<<endl;//!�ʣ��ո�ͻس�������
    int n;
    cin>>n;
    length=length+n;
    int i;
    Node_c *tail;
    tail=head;
    cout<<"����������Ԫ�ص�ֵ"<<endl;
    for(i=0;i<n;i++)
    {
        Node_c *p=new Node_c;
        p->set_data();
        p->set_next(NULL);
        tail->set_next(p);
        tail=p;
    }
}

void List_ch::show_tail()
{
   Node_c *h=head->get_next();
   while(h!=NULL)
   {
       h->show_data();
       h=h->get_next();
   }
   cout<<endl;
}

void List_ch::classify(List_ch &L1,List_ch &L2)
{
    Node_c *p,*t1,*t2;//����ָ�������ǰ��ָ�룬����Ͽ���,����βָ�룬β��
    t1=L1.head;
    t2=L2.head;
    Node_c *pre;
    pre=head;//pre�ʼָ��ͷ���
    p=head->get_next();//��ͷ������һ����ʼ����
    while(p!=NULL)
    {
            if(p->get_data()>='0'&&p->get_data()<='9')//���������ַ�
            {
               // head->set_next(p->get_next());//!������������⣬����һ�������ַ����ڶ���ʱԽ���˵�һ���ַ�
                t1->set_next(p);
                t1=p;
                p=p->get_next();
            }
            else if((p->get_data()>='a'&&p->get_data()<='z')||(p->get_data()>='A'&&p->get_data()<='Z'))
            {
                //head->set_next(p->get_next());
                t2->set_next(p);
                t2=p;
                p=p->get_next();
            }
            else
            {
               //!�ʣ����������ָ��ʵ�֣�head->set_next(p);//!�ӵ�����Ҳ���ԣ�����ֻ�ܵõ�һ�������ַ�
                pre=p;
                p=p->get_next();//����дֻ������������ַ�ʱ�������ã���Ȼ�����
            }
    }
    //���ı䵱ǰβָ�룬����ָ���µĵط����Ͽ�֮ǰ��ָ��
    t1->set_next(L1.head);
    t2->set_next(L2.head);//���ѭ������
    pre->set_next(head);

}//������ȫ�Լ���˼·������

void List_ch::classify2(List_ch &L1,List_ch &L2,List_ch &L3)
{
    Node_c *p,*t1,*t2,*t3;//����ָ�������ǰ��ָ�룬����Ͽ���,����βָ�룬β��
    t1=L1.head;
    t2=L2.head;
    t3=L3.head;
   /* Node_c *pre;
    pre=head;//pre�ʼָ��ͷ���*/
    p=head->get_next();//��ͷ������һ����ʼ����
    while(p!=NULL)
    {
            if(p->get_data()>='0'&&p->get_data()<='9')//���������ַ�
            {
               // head->set_next(p->get_next());//!������������⣬����һ�������ַ����ڶ���ʱԽ���˵�һ���ַ�
                t1->set_next(p);
                t1=p;
                p=p->get_next();
            }
            else if((p->get_data()>='a'&&p->get_data()<='z')||(p->get_data()>='A'&&p->get_data()<='Z'))
            {
                //head->set_next(p->get_next());
                t2->set_next(p);
                t2=p;
                p=p->get_next();
            }
            else
            {
               t3->set_next(p);
               t3=p;
               p=p->get_next();
            }
    }
    //���ı䵱ǰβָ�룬����ָ���µĵط����Ͽ�֮ǰ��ָ��
    t1->set_next(L1.head);
    t2->set_next(L2.head);//���ѭ������
    t3->set_next(L3.head);

}//������ȫ�Լ���˼·������

void List_ch::show_classify_cycle()
{
    Node_c *h=head->get_next();
    while(h!=head)//��ͷ���Ͳ���dowhileѭ����
    {
        h->show_data();
        h=h->get_next();
    }
    cout<<endl;
}

D_node::D_node()
{
    data="no name";
    freq=0;
    prior=NULL;
    next=NULL;
}

string D_node::get_data()
{
    return data;
}

int D_node::get_freq()
{
    return freq;
}

D_node* D_node::get_prior()
{
    return prior;
}

D_node* D_node::get_next()
{
    return next;
}

void D_node::set_data()
{
    cin>>data;
}

void D_node::set_freq(int f)
{
    freq=f;
}

void D_node::add_freq()
{
    freq++;
}

void D_node::set_prior(D_node * p)
{
    prior=p;
}

void D_node::set_next(D_node *n)
{
    next=n;
}

void D_node::show_data_freq()
{
   cout<<"��ҳ���� "<<data<<" ���ʴ��� "<<freq<<endl;
}

List_d::List_d()
{
    head=&nd;
    head->set_next(NULL);
    head->set_prior(NULL);
}

void List_d::creat_tail()
{
    D_node *tail;//βָ��
    tail=head;//βָ�룬ָ��ͷ���
    int n;
    cout<<"�������½������Ԫ�ظ���"<<endl;
    cin>>n;
    length=length+n;
    int i;
    cout<<"����������������ҳ����"<<endl;
    for(i=0;i<n;i++)
    {
        D_node *p=new D_node;
        p->set_data();
        p->set_freq(0);
        p->set_next(NULL);
        p->set_prior(NULL);//!???��װ��pָ��ָ�������!�Ƿ�û�б�Ҫ����ʼ����ʱ���Ѿ���ʼ����
        tail->set_next(p);
        p->set_prior(tail);
        tail=p;
    }
    tail->set_next(NULL);
}

void List_d::show_list_d()
{
        cout<<"��Ŀǰ��������������"<<endl;
        D_node *p=head->get_next();//��ͷָ�����һ����ʼ����
        while(p!=NULL)
        {
            p->show_data_freq();
            p=p->get_next();
        }
}

void List_d::locate(string d)
{
    cout<<"��������"<<d<<"��վһ��"<<endl;
    D_node *find_p;//Ѱ��ָ�룬�ҵ�λ�ã�ʹ��freq����1��
    find_p=head->get_next();//��ͷ���ĺ�һ����ʼ��
    while(find_p!=NULL&&find_p->get_data()!=d)
    {
        find_p=find_p->get_next();
    }
    if(find_p==NULL)
    {
        cout<<"��ǰ��վ����������"<<endl;
        exit(0);
    }
    else
    {
        find_p->add_freq();
        //Ѱ�Һ�����Ƶ��û������ cout<<find_p->get_data()<<" "<<find_p->get_freq()<<" "<<endl;
    }
    //!���룬��Ƶ�ʴ��ڵ�ǰ�任Ƶ�ʽ��Ľ�㣬�ѵ�ǰ�������ҵ��Ľ��֮��
    D_node *find_pre;
    find_pre=find_p->get_prior();//������Ƶ�ʵĽ��֮ǰ�ң���Ϊǰ���ȫ����Ƶ�����ӹ���
    while(find_pre->get_prior()!=NULL&&find_pre->get_freq()<=find_p->get_freq())//!��һ���������ҵ�ͷ��㻹û��Ƶ�ʴ�ģ�����һ�β��룬�˳�ѭ��ʱfind_pre��ͷ���
    {
       find_pre=find_pre->get_prior();//��û�У���ǰ�ƶ���ֱ���ҵ�
    }
    if(find_p->get_next()==NULL)
    {
        find_p->get_prior()->set_next(NULL);

    }//!��find_p��βָ�룬�����Ͽ��Ĵ���������Ĳ�һ��
    else
    {
        find_p->get_prior()->set_next(find_p->get_next());
        find_p->get_next()->set_prior(find_p->get_prior());//��find_pǰ������
    }
    //!�����find_p�Ͽ�������������������find_pre�����̺���
    find_p->set_prior(find_pre);
    find_p->set_next(find_pre->get_next());
    find_pre->get_next()->set_prior(find_p);//!���һ��Ҫ����һ��֮ǰ����Ȼ�Ҳ����˽ڵ����һ�������
    find_pre->set_next(find_p);
    /*
    //!��Ƶ�����ӵĽ��嵽���Ƶ��֮��
    D_node *find_pre;
    find_pre=find_p;
    while(find_pre->get_prior()!=NULL&&find_pre->get_prior()->get_freq()<=find_p->get_freq())
    {
        find_pre=find_pre->get_prior();
    }
    cout<<find_pre->get_freq();
    if(find_p->get_next()==NULL)
    {
        find_p->get_prior()->set_next(NULL);//ǰһ����nextָ��ָ��
        find_p->set_prior(NULL);//��find_pȫ��ժ��
        find_p->set_next(NULL);
    }
    find_p->get_prior()->set_next(find_p->get_next());
    find_p->get_next()->set_prior(find_p->get_prior());//��find_pǰ������
    find_p->set_prior(find_pre);//��find_p����ͷ����ͷ�����һ�����֮��
    find_p->set_next(find_pre->get_next());
    find_pre->get_next()->set_prior(find_p);//!��һ����˳������ǰ����Ȼ�Ҳ���find_pre�ĺ�һ��㣡
    find_pre->set_next(find_p);
     */
}

void menu()
{
    cout<<"1.����ѭ��������ɾ��ֱ��ǰ�����"<<endl;
    cout<<"2.���Է�������"<<endl;
    cout<<"3.���Դ�Ƶ������"<<endl;
    cout<<"4.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;
}
