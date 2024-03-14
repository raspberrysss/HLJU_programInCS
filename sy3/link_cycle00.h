#ifndef LINKC_H_
#define LINKC_H_

#include<iostream>

using namespace std;

class Node
{
    private:
        int data;
        Node* next;
    public:
        Node();
        int get_data();
        Node* get_next();
        void set_next(Node *p);
        void set_data();
        void show_data();
        //~Node();
};

class Link_cycle//����ͷ����ѭ������
{
    private:
        Node * tail;
        int length;
    public:
        Link_cycle();
        void creat_link_c(int n);//����ѭ������ʱ����һ��ͷָ����и���
        void delete_pre(int node_d);//ɾ��ǰ�ý��
        void show_link();
        //~Link_cycle();

};

class Node_c
{
    private:
        char data;
        Node_c *next;
    public:
        Node_c();
        void set_data();
        void set_next(Node_c *p);
        char get_data();
        Node_c* get_next();
        void show_data();
        //~Node_c();
};

class List_ch//��ͷ������������������β�嵥�����ѭ������
{
        private:
            int length;
            Node_c nch;//ͷ���
            Node_c *head;//ͷָ��
        public:
            List_ch();
            //~List_ch();
            void creat_tail();//����β�岻ѭ��������
            //!�ʣ�void creat_tail_with_space();//�����ַ����ǿո�
            void show_tail();//չʾβ������
            void classify(List_ch &L1,List_ch &L2);//!�ʣ� ���ཨ��ѭ������,�½�������ԭ�����Ǹ��ٱ��ѭ����������ȫ������ͷ����ѭ������
            void classify2(List_ch &L1,List_ch &L2,List_ch &L3);
            void show_classify_cycle();//չʾѭ������

};

class D_node
{
    private:
        string data;
        int freq;//Ƶ��
        D_node* prior;
        D_node* next;
    public:
        D_node();
        string get_data();
        int get_freq();
        D_node * get_prior();
        D_node * get_next();
        void set_data();
        void set_freq(int f);
        void add_freq();
        void set_prior(D_node * p);
        void set_next(D_node * n);
        void show_data_freq();

};

class List_d
{
    private:
        D_node * head;
        D_node nd;
        int length;
    public:
        List_d();
        void creat_tail();//����β�壬δ����freq������
        void show_list_d();
        void locate(string d);

};
void menu();
#endif // LINKC_H_
