#ifndef GRAPH_H_
#define GRAPH_H_

const int MAX=100;
const int MAX_INIT=32767;//32767 为什么不是2147483647，int型最大数，随便定义的吗？

class AMG_Graph//邻接矩阵表示
{
    private:
        int vex_num;//顶点个数
        int edge_num;//边的个数
        char vex[MAX];//顶点集
        int edge[MAX][MAX];//边集,邻接矩阵
    public:
        AMG_Graph();//对所有成员初始化
        ~AMG_Graph();
        int search_index(char c);//寻找顶点下标
        void Create_AMG_Graph_underieted();//创建无向图
        void Create_AMG_Graph_derieted();//创建有向图
        void Create_AMG_Graph_derieted_wet();//创建有向网
        void Create_AMG_Graph_underieted_wet();//创建无向网
        void show_AMG_Graph();//输出信息
        void DFS_AMG_simple();//通过深度优先遍历，输出简单路径

};

class Adj_node
{
    private:
        int index;//下标
        Adj_node *next;//指向下一邻接点的指针
        int w;//不用另开一个，不用的时候不显示就好
    public:
        Adj_node();
        ~Adj_node();
        void set_index(int in);
        void set_next(Adj_node *n);
        void set_w(int w_w);
        int get_w();
        int get_index();
        Adj_node * get_next();
};

/*class Adj_node_w
{
    private:
        int index_w;//下标
        Adj_node *next_w;//指向下一邻接点的指针,不变成adj_node_w，方便连接顶点表
        int w;//权值
    public:
        Adj_node_w();
        ~Adj_node_w();
        void set_index_w(int in_w);
        void set_next_w(Adj_node *n_w);
        void set_w(int w_w);
        int get_w();
        int get_index_w();
        Adj_node * get_next_w();
};
*/
class VexNode
{
    private:
        char node;
        Adj_node *first;//指向邻接点表的指针
    public:
        VexNode();
        ~VexNode();
        void set_node(char c);
        void set_first(Adj_node *f);
        char get_node();
        Adj_node *get_first();
};

class ALG_Graph
{
    private:
        int vex_num_l;
        int edge_num_l;
        VexNode Vex[MAX];//顶点表，顶点数组，由其后面引出单链表，成员中只有它就可以
    public:
        ALG_Graph();
        ~ALG_Graph();
        void Create_ALG_Graph_dericted();//创建有向图
        void Create_ALG_Graph_undericted();//无向图
        void Create_ALG_Graph_dericted_wet();//有向网
        void Create_ALG_Graph_undericted_wet();//无向网
        int search_index_l(char c);
        void Create_adj_node_list(int j,int k);//j代表起点下标，k代表终点下标，建立链表
        void Create_adj_node_list_w(int j,int k,int w);
        void Show_ALG_g();
        void Show_ALG_w();
        void BFS_ALG_min();//用广度优先求最短路径
};

void menu();
void menu_AMG();
void menu_ALG();

#endif // GRAPH_H_
