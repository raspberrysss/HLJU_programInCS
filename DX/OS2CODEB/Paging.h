#ifndef PAGING_H_
#define PAGING_H_
#include<vector>
#include<queue>

using std::vector;
using std::queue;

const int row=8;
const int column=8;
const int MAX=100;
/*
class Paging_table_item//ҳ����
{
    private:
      int id;
      int num_piece;//���
      bool now;//״̬λ
    public:
        Paging_table_item();
        ~Paging_table_item();

};

class Paging_table
{
    private:
       Paging_table_item v[100];
    public:
        Paging_table();
        ~Paging_table();
};*/

class location_gra
{
    private:
        int lo[row][column];
        int count_spare;
    public:
        location_gra();
        ~location_gra();
        location_gra(const location_gra &lg);//���ƹ���
        void set_random(int cs);
        void show();
        bool is_have_spare();
        void de_c(){count_spare--;}
        int find_s();
};

struct page_table
{
    int number;
    int num_piece;
    bool now;
};

class FIFO
{
    private:
        //fifoҳ��
        int c_v;//���ʴ���
        int c_m;//���д���
        int c_q;//ȱҳ����
        int c_z;//�û�����
        int len_pf;
    public:
        page_table pf[MAX];//�����޷�������ֵ����ôд������
        vector<int> q1;
        FIFO();
        ~FIFO();
        void init_pf(int pf_len);
        void show();
        void show1();
        int get_len_pf();
        int get_cm(){return c_m;};
        int get_cq(){return c_q;};
        int get_cz(){return c_z;};
        int get_cv(){return c_v;};
        void cm_add(){c_m++;};
        void cq_add(){c_q++;};
        void cz_add(){c_z++;};
        void cv_add(){c_v++;};
        void show_rate_qy();

        //void ca(int add);
};

class LRU
{
    private:
        int len_pl;
        int c_v;//���ʴ���
        int c_m;//���д���
        int c_q;//ȱҳ����
        int c_z;//�û�����
    public:
        page_table pl[MAX];
        vector<int> q2;
    public:
        LRU();
        ~LRU();
        int get_cm(){return c_m;};
        int get_cq(){return c_q;};
        int get_cz(){return c_z;};
        int get_cv(){return c_v;};
        void cm_add(){c_m++;};
        void cq_add(){c_q++;};
        void cz_add(){c_z++;};
        void cv_add(){c_v++;};
        void init_pl(int pl_len);
        void show();
        void show1();
        void show_rate_qy();
};

void menu();
void menu2();
int ca_f(FIFO &f1,location_gra &lg,int add,int piec);
int ca_l(LRU &l1,location_gra &lg,int add,int piec);
int ca_fh(FIFO &f1,location_gra &lg,int add,int piec);
int ca_lh(LRU &l1,location_gra &lg,int add,int piec);

#endif // PAGING_H_
