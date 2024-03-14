#ifndef STACK_H_
#define STACK_H_

const int MAXSIZE=100;

class Stack
{
    private:
        int top;//ջ��ָ��
        char s_c[MAXSIZE];//����������ջ������
        int length;//ջ��Ԫ�ظ���
    public:
        Stack();//����һ����ջ
        bool is_empty_s();
        bool is_full();
        void push(char c);
        void pop(char & c);
        void make_empty();//���ջ
        void judge_symmetric();//�ж����ĶԳ�
        void match_brackets();//ƥ������

};

class Node
{
    private:
        int data;
        Node *next;
    public:
        Node();
        int get_data();
        Node* get_next();
        void set_data();
        void set_data2(int d);
        void set_next(Node *p);
        void show_data();

};

class Queue
{
    private:
        Node n;//ͷ���
        Node *tail;
        int length;
    public:
        Queue();
        void enter1(int n);
        void enter(int e);//���β��
        int leave();//���ӣ��ȳ���ͷ������
        int show_queue();
        void make_empty();

};
void menu();
void menu2();
#endif // STACK_H_
