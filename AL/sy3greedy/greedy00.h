#ifndef GREEDY_H_
#define GREEDY_H_

class Knapsack_g//��������
{
    private:
        int num;//��Ʒ��������
        double weight[100];//ÿ����Ʒ����������
        double value[100];//ÿ����Ʒ�ļ�ֵ����
        double weight_can;//�ܳ��ܵ�������
        double result[100];//������
        double perw_va[100];//��λ��ֵ����
        double max_value;
    public:
        Knapsack_g();
        ~Knapsack_g();
        void set_information();
        void greedy();//̰���㷨
        void sort_withper();

};

class Activity_g
{
    private:
        int n;//�����
        int s[100];//��ʼʱ��
        int t[100];//����ʱ��
        int choice[100];//ѡ������
    public:
        Activity_g();
        ~Activity_g();
        void set_in();
        void greedy();
        void sort_witht();
};

void menu();


#endif // GREEDY_H_
