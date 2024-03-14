#ifndef SORT_H_
#define SORT_H_

//随机生成两组数据，这两种数据分别用希尔排序和快排序排序

const int MAX=100;

class Shell_Quick//希尔排序与快排放在一起写，使用同一待排序随机数列
{
    //两者均用到递归进行排序
    private:
       // int d1[MAX];//递增序列1
       // int d2[MAX];//递增序列2
        int s1[MAX];//待排序数列1
        int s2[MAX];//待排序数列2
    public:
        Shell_Quick();
        ~Shell_Quick();
        void make_s1_s2();//随机生成待排序数列
        void Shell(int n_s1,int n_s2);//参数为数列中元素个数，由参数实现递增量

};

#endif // SORT_H_
