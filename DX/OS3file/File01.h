///*����Ŀ¼��md ����һ���յĸ�Ŀ¼��Ȼ�����ڸ�Ŀ¼���û��ɽ���
///*�г�Ŀ¼: dir����ʾĿ¼���ļ���������ǿգ�ֻ��. ..��Ҳչʾ
///*�����ļ���mk ��·�� ������cd �����֣������Ŀ¼��ֱ�Ӵ�����ͬʱҪ���Ǵ��̿��ǲ�����
///*ɾ���ļ���del ɾ��ͬ��
///*ɾ����Ŀ¼��rd ���Ŀ¼ֻ�� . .. ��Ϊ�գ�ֱ��ɾ������Ϊ�ո���ʾ
///*�л�Ŀ¼��cd �����任
#ifndef FILE01_H_
#define FILE01_H_

#include<string>
#include<sstream>

using std::string;

//Ҷ�ӽ������ļ�����յ�Ŀ¼����Ҷ�ӽ��������ļ���Ŀ¼

const int MAX=100;

class FCB//�ļ����
{
    private:
        string name;//�ļ���
        int size;//�ļ���С
        int flag;//1���ļ���2��Ŀ¼
        int first_b;//��һ����
        int year;
        int month;
        int date;
        int hour;
        int minute;
        int second;
        //string date;//����ʱ��
        FCB *next;//��һ���ֵܽ��
        FCB *child;//��һ�����ӽ��
    public:
        FCB();
        ~FCB();
        void set_FCB(string n,int s,int f,int fb,FCB* ne,FCB* c);
        void set_time();
        void show_n();
        void set_c(FCB*c){child=c;};
        void set_n(FCB*ne){next=ne;};
        FCB* get_n(){return next;};
        FCB* get_c(){return child;};
        int get_flag(){return flag;};//2Ŀ¼��1�ļ�
        string get_name(){return name;};
        int get_size(){return size;};
        int get_first(){return first_b;};
        void show();
};


//��Ŀ¼�����ļ���㶼����һ������

class FAT
{
    private:
       int fat_table[MAX];
    public:
        FAT();
        ~FAT();
        void makefat();//�������fat��
        int find_spare();
        void zhanyong(int i){fat_table[i]=-1;};//ռ���ҽ���
        void show_fat();
        void union_forfile(int s,int start);
        int ca_0();
        void delete_f(int f_f,int size_f);
        void delete_d(int first);

};

class FCB_tree
{
    public:
        FCB *root;//���ڵ�
        FCB *now;//��ǰĿ¼��ָ�룬��ǰĿ¼ָ��һ�㣬��ǰ����������һ��Ŀ¼������
        //FCB *tail;//ָ��һ���β
        //�ǲ������̫�����˰���������������
    public:
        FCB_tree();
        ~FCB_tree();
        //void init();//��ʼ�������
        //FCB* get_root(){return root;};
        //FCB* get_now(){return now;};
        void show_root();
        void show_now();
        //void create_md(string mn);
};

void menu();
void init(FCB_tree &ft,FAT &fa);
void create_md(FCB_tree &ft,FAT &fa,string mn);
void find_m(FCB_tree &ft,string mnf);
void show_dqml(FCB_tree &ft);
void create_mk(FCB_tree &ft,FAT &fa,string fn,int s);
void remove_d(FCB_tree &ft,FAT &fa,string rdn);
bool is_samename(FCB_tree &ft,string n);//�жϵ�ǰĿ¼�£��Ƿ���Ŀ¼���ļ���Ҫ����������

/*class MU//Ŀ¼���
{
    private:
        string name;
    public:
        MU();
        ~MU();
        void set_MU(string);
};*/

#endif // FILE01_H_
