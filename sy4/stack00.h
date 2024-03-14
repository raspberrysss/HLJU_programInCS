#ifndef STACK00_H_
#define STACK00_H_
//!这边是指针做top，不是下标（int）做下标！

class Elem
{
    private:
        char e;
    public:
        Elem();
        char get_e();
        void set_e();
        void show_e();
};

class Stack
{
  private:
    Elem *base;//栈底指针、
    Elem *top;//栈顶指针
    int length;//元素个数
    int size_of_stack;
  public:
    Stack();
    int push(Elem e);//入栈
    int pop();//出栈
    void get_top_elem(char &c);//取栈顶元素
    void show_stack();//展示全部栈元素
    bool judge_symmetric();//判断是否是中心对称
};


#endif // STACK00_H_
