#ifndef STACK_H_
#define STACK_H_

const int MAXSIZE=100;

class Stack
{
    private:
        int top;//栈顶指针
        char s_c[MAXSIZE];//代表着整个栈的数组
        int length;//栈中元素个数
    public:
        Stack();//创建一个空栈
        bool is_empty_s();
        bool is_full();
        void push(char c);
        void pop(char & c);
        void make_empty();//清空栈
        void judge_symmetric();//判断中心对称
        void match_brackets();//匹配括号

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
        Node n;//头结点
        Node *tail;
        int length;
    public:
        Queue();
        void enter1(int n);
        void enter(int e);//入队尾插
        int leave();//出队，先出离头结点近的
        int show_queue();
        void make_empty();

};
void menu();
void menu2();
#endif // STACK_H_
