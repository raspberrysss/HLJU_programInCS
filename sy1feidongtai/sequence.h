#ifndef SEQUENCE_H_
#define SEQUENCE_H_

class Elemt
{
    private:
        int e;//顺序表所包含元素
    public:
        void set_e();
        void show_e();
        int get_e();
        void assignment(int el);

};

class Sequence
{
    private:
        Elemt *e_p;//基地址
        int length;//元素个数，即顺序表长度
    public:
        Sequence();//默认构造，这里先不写有参构造，没有什么作用
        ~Sequence();
        void set_sequence();//建立数组，自己输入
        void show_sequence();//展示当前数组
        void insert_value(int c);//按数值插入，保持有序
        void reverse_e();//逆置顺序表
        //void swap(int *a,int *b);
        void move_s(int k);//向右移动k次位

};
void menu();

#endif // SEQUENCE_H_
