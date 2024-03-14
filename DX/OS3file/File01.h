///*创建目录：md 先有一个空的根目录，然后再在根目录上用户可建立
///*列出目录: dir（显示目录中文件）：如果是空，只有. ..，也展示
///*创建文件：mk 加路径 ，还是cd 加名字，在这个目录里直接创建，同时要考虑磁盘块是不是满
///*删除文件：del 删除同理
///*删除空目录：rd 如果目录只有 . .. 就为空，直接删除，不为空给提示
///*切换目录：cd 树结点变换
#ifndef FILE01_H_
#define FILE01_H_

#include<string>
#include<sstream>

using std::string;

//叶子结点就是文件或清空的目录，非叶子结点就是有文件的目录

const int MAX=100;

class FCB//文件结点
{
    private:
        string name;//文件名
        int size;//文件大小
        int flag;//1是文件，2是目录
        int first_b;//第一块块号
        int year;
        int month;
        int date;
        int hour;
        int minute;
        int second;
        //string date;//创建时间
        FCB *next;//下一个兄弟结点
        FCB *child;//第一个孩子结点
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
        int get_flag(){return flag;};//2目录，1文件
        string get_name(){return name;};
        int get_size(){return size;};
        int get_first(){return first_b;};
        void show();
};


//把目录结点和文件结点都放在一棵树上

class FAT
{
    private:
       int fat_table[MAX];
    public:
        FAT();
        ~FAT();
        void makefat();//随机生成fat表
        int find_spare();
        void zhanyong(int i){fat_table[i]=-1;};//占用且结束
        void show_fat();
        void union_forfile(int s,int start);
        int ca_0();
        void delete_f(int f_f,int size_f);
        void delete_d(int first);

};

class FCB_tree
{
    public:
        FCB *root;//根节点
        FCB *now;//当前目录的指针，当前目录指上一层，当前东西都是上一层目录带来的
        //FCB *tail;//指向一层的尾
        //是不是想的太复杂了啊啊啊啊啊啊啊啊
    public:
        FCB_tree();
        ~FCB_tree();
        //void init();//初始化这棵树
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
bool is_samename(FCB_tree &ft,string n);//判断当前目录下，是否有目录或文件与要创建的重名

/*class MU//目录结点
{
    private:
        string name;
    public:
        MU();
        ~MU();
        void set_MU(string);
};*/

#endif // FILE01_H_
