#ifndef SORT_H_
#define SORT_H_

//��������������ݣ����������ݷֱ���ϣ������Ϳ���������

const int MAX=100;

class Shell_Quick//ϣ����������ŷ���һ��д��ʹ��ͬһ�������������
{
    //���߾��õ��ݹ��������
    private:
       // int d1[MAX];//��������1
       // int d2[MAX];//��������2
        int s1[MAX];//����������1
        int s2[MAX];//����������2
    public:
        Shell_Quick();
        ~Shell_Quick();
        void make_s1_s2();//������ɴ���������
        void Shell(int n_s1,int n_s2);//����Ϊ������Ԫ�ظ������ɲ���ʵ�ֵ�����

};

#endif // SORT_H_
