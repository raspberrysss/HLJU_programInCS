#ifndef SEQUENCE_H_
#define SEQUENCE_H_

class Sequence_elem
{
    private:
        int a;
    public:
        Sequence_elem();
        ~Sequence_elem();
        int get_elem();//�õ���ǰ�ڵ��Ԫ��ֵ
        void set_elem();

};

class Sequence
{
    private:
        Sequence_elem * se_q;
        int size_s;//Ԫ�ظ���
        int length;//��̬���鳤��
    public:
        Sequence();//����һ����˳���
        Sequence(int len_s);//����һ���о���ռ��˳���
        ~Sequence();
        void add(Sequence_elem e);//����һ����ֵ
       // void set_se();//������ֵ������˳���
        //int find_index();//������ֵ�������±�
        void insert_se(Sequence_elem e);//������ֵ������
        int get_len();

};
#endif // SEQUENCE_H_
