#ifndef LIST00_H_
#define LIST00_H_

class Node
{
    private:
        int data;
        Node * next;
    public:
        Node();
        //Node(int d_n);
        Node* get_next();
        void set_next(Node *next_n);
        void set_data();
        void set_data2(int data_n);
        void show_data();
        int get_data();

};

class List
{
    private:
        int length;//链表长度
        Node* head;
        Node nh;//头结点
    public:
        List();//建立空链表
        List(int n);//建立有序链表
        void insert_list(int node_d);
        void creat_list_tail(int n);//尾插建立链表，自己输入有序
        void show_list();
        void reverse_l();
        void add_list_decline(List &L1);//递减合并两个链表，不另建链表
        void reverse_me();
        void add_me(List &L1);


};
void menu();
#endif // LIST00_H_
