#ifndef SEQUENCE_H_
#define SEQUENCE_H_

class Sequence_elem
{
    private:
        int a;
    public:
        Sequence_elem();
        ~Sequence_elem();
        int get_elem();//得到当前节点的元素值
        void set_elem();

};

class Sequence
{
    private:
        Sequence_elem * se_q;
        int size_s;//元素个数
        int length;//动态数组长度
    public:
        Sequence();//建立一个空顺序表
        Sequence(int len_s);//建立一个有具体空间的顺序表
        ~Sequence();
        void add(Sequence_elem e);//输入一个数值
       // void set_se();//输入数值，建立顺序表
        //int find_index();//查找数值，返回下标
        void insert_se(Sequence_elem e);//插入数值仍有序
        int get_len();

};
#endif // SEQUENCE_H_
