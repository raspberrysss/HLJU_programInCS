#ifndef STACK00_H_
#define STACK00_H_
//!�����ָ����top�������±꣨int�����±꣡

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
    Elem *base;//ջ��ָ�롢
    Elem *top;//ջ��ָ��
    int length;//Ԫ�ظ���
    int size_of_stack;
  public:
    Stack();
    int push(Elem e);//��ջ
    int pop();//��ջ
    void get_top_elem(char &c);//ȡջ��Ԫ��
    void show_stack();//չʾȫ��ջԪ��
    bool judge_symmetric();//�ж��Ƿ������ĶԳ�
};


#endif // STACK00_H_
