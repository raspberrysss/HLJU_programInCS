#ifndef MAXD_H_
#define MAXD_H_

class Maxsegment_d
{
    private:
        int array_d[100];//����ȫ�����±���1��ʼ��
        int dynamic[101];//��̬�滮����
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
