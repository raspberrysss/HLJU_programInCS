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

class Link_cycle//不带头结点的循环链表
{
    private:
        Node * tail;
        int length;
    public:
        Link_cycle();
        void creat_link_c(int n);//创建循环链表时，用一个头指针进行辅助
        void delete_pre(int node_d);//删除前置结点
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

class List_ch//带头结点的链表，操作有正常尾插单链表和循环链表
{
        private:
            int length;
            Node_c nch;//头结点
            Node_c *head;//头指针
        public:
            List_ch();
            //~List_ch();
            void creat_tail();//建立尾插不循环单链表
            //!问！void creat_tail_with_space();//其他字符考虑空格
            void show_tail();//展示尾插链表
            void classify(List_ch &L1,List_ch &L2);//!问！ 分类建立循环链表,新建两个，原来的那个再变成循环链表，他们全都是有头结点的循环链表
            void classify2(List_ch &L1,List_ch &L2,List_ch &L3);
            void show_classify_cycle();//展示循环链表

};

class D_node
{
    private:
        string data;
        int freq;//频度
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
        void creat_tail();//正常尾插，未进行freq的增添
        void show_list_d();
        void locate(string d);

};
void menu();
#endif // LINKC_H_
