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
        int length;//������
        Node* head;
        Node nh;//ͷ���
    public:
        List();//����������
        List(int n);//������������
        void insert_list(int node_d);
        void creat_list_tail(int n);//β�彨�������Լ���������
        void show_list();
        void reverse_l();
        void add_list_decline(List &L1);//�ݼ��ϲ�����������������
        void reverse_me();
        void add_me(List &L1);


};
void menu();
#endif // LIST00_H_
