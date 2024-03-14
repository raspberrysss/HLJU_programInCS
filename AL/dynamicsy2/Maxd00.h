#ifndef MAXD_H_
#define MAXD_H_

class Maxsegment_d
{
    private:
        int array_d[100];//数组全部从下标是1开始存
        int dynamic[101];//动态规划数组
        int length_d;
        int sta;
        int ter;
    public:
        Maxsegment_d();
        ~Maxsegment_d();
        void set_array_d();
        int find_Maxsegement();

};
#endif // MAXD_H_
