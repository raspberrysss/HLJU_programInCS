#ifndef SEQUENCE_H_
#define SEQUENCE_H_

class Elemt
{
    private:
        int e;//˳���������Ԫ��
    public:
        void set_e();
        void show_e();
        int get_e();
        void assignment(int el);

};

class Sequence
{
    private:
        Elemt *e_p;//����ַ
        int length;//Ԫ�ظ�������˳�����
    public:
        Sequence();//Ĭ�Ϲ��죬�����Ȳ�д�вι��죬û��ʲô����
        ~Sequence();
        void set_sequence();//�������飬�Լ�����
        void show_sequence();//չʾ��ǰ����
        void insert_value(int c);//����ֵ���룬��������
        void reverse_e();//����˳���
        //void swap(int *a,int *b);
        void move_s(int k);//�����ƶ�k��λ

};
void menu();

#endif // SEQUENCE_H_
