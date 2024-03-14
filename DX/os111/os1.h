#ifndef OS1_H_
#define OS1_H_

class Node_PCB
{
    private:
        std::string s;//数据域
        int size_p;//占内存的大小
        int b;//开始地址
        Node_PCB *next;//指针域
    public:
        Node_PCB();
        ~Node_PCB();
        Node_PCB(std::string s_n,Node_PCB *p,int sp,int bp);
        void set_s(std::string s_s);
        void set_next(Node_PCB *p_s);
        void set_size(int s);
        int get_size();
        void set_b(int bp);
        int get_b();
        Node_PCB* get_next();
        std::string get_s();
};

class Link_PCB
{
    private:
        Node_PCB *head;//头指针
        Node_PCB *tail;
        int length;
    public:
        Link_PCB();
        ~Link_PCB();
        Link_PCB(Node_PCB *l,Node_PCB *t,int lc);
        void set_link(Node_PCB *ll,Node_PCB *tl,int lcl);
        void create_link(std::string s_l,int s,int b);
        void show_link();
        //int end_link(std::string s_d);
        //bool end_link_exe2();
        //void end_link(std::string s_d,int &f);//f控制不重复输出错误
        //bool end_link_exe(std::string s_de);//!只中止执行的，想错了
        int find_from_link(std::string s_f);//查重名，不允许
        bool is_empty_list();
        int get_len();
        Node_PCB* get_head();
        Node_PCB* get_tail();
        void set_head(Node_PCB * sh);
        //bool block();

};

class Node_zone//空白分区节点
{
    private:
        int begin_z;//起始地址
        int size_z;//大小
        Node_zone* next;
        Node_zone* pre;
    public:
        Node_zone();
        Node_zone(int b,int s,Node_zone* n,Node_zone* p);
        ~Node_zone();
        void set_beginz(int bz);
        void set_sizez(int sz);
        void set_nextz(Node_zone* nz);
        void set_prez(Node_zone* pz);
        int get_bz();
        int get_sz();
        Node_zone* get_n();
        Node_zone* get_pre();



};

class Link_Zone//空闲双向链表
{
    private:
        Node_zone *head_z;
        Node_zone *tail_z;
        int length_z;
    public:
        Link_Zone();
        Link_Zone(Node_zone *h,Node_zone *t,int l);
        ~Link_Zone();
        void create_link_zone(int b,int s);//有序插入，起始地址小的插在前面
        void show_link_zone();
        Node_zone* get_headz();
        int get_lenz();
        void set_headz(Node_zone *z);

};

void menu();
void ready_to_exe_auto(Link_PCB &l1,Link_PCB &l2);
//!必须用引用才会变！！！不用引用是不是也可以改变
void show_three(Link_PCB l11,Link_PCB l22,Link_PCB l33);
void end_three(Link_PCB &l1e,Link_PCB &l2e,Link_PCB &l3e,std::string see,int &fl);
bool is_repeat(Link_PCB l1r,Link_PCB l2r,Link_PCB l3r,std::string srr);
bool block(Link_PCB &l1b,Link_PCB &l2b);//把执行的一个挂在阻塞尾
bool wake(Link_PCB &l1w,Link_PCB &l2w);//把阻塞头挂在就绪尾
bool time(Link_PCB &l1t,Link_PCB &l2t);//把执行挂在就绪尾
bool is_spare(Link_Zone &lz,int size_pcb,int &be_node_pcb);//判断加进来的进程是否还有空闲内存给它
bool end_exe3(Link_PCB &le,Link_Zone &lz);
void merge_lz(Link_Zone &lz);//合并地址相邻空闲空间
//void delete_same(Link_Zone &lz);//去除开始地址相同的

#endif // LIST_P00_H_

