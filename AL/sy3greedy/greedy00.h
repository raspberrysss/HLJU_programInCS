#ifndef GREEDY_H_
#define GREEDY_H_

class Knapsack_g//背包问题
{
    private:
        int num;//物品的总数量
        double weight[100];//每个物品的重量数组
        double value[100];//每个物品的价值数组
        double weight_can;//能承受的总质量
        double result[100];//解数组
        double perw_va[100];//单位价值数组
        double max_value;
    public:
        Knapsack_g();
        ~Knapsack_g();
        void set_information();
        void greedy();//贪心算法
        void sort_withper();

};

class Activity_g
{
    private:
        int n;//活动个数
        int s[100];//开始时间
        int t[100];//结束时间
        int choice[100];//选择数组
    public:
        Activity_g();
        ~Activity_g();
        void set_in();
        void greedy();
        void sort_witht();
};

void menu();


#endif // GREEDY_H_
