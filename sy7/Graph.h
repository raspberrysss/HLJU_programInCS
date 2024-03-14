#ifndef GRAPH_H_
#define GRAPH_H_

const int MAX=100;
const int MAX_INIT=32767;//32767 Ϊʲô����2147483647��int�����������㶨�����

class AMG_Graph//�ڽӾ����ʾ
{
    private:
        int vex_num;//�������
        int edge_num;//�ߵĸ���
        char vex[MAX];//���㼯
        int edge[MAX][MAX];//�߼�,�ڽӾ���
    public:
        AMG_Graph();//�����г�Ա��ʼ��
        ~AMG_Graph();
        int search_index(char c);//Ѱ�Ҷ����±�
        void Create_AMG_Graph_underieted();//��������ͼ
        void Create_AMG_Graph_derieted();//��������ͼ
        void Create_AMG_Graph_derieted_wet();//����������
        void Create_AMG_Graph_underieted_wet();//����������
        void show_AMG_Graph();//�����Ϣ
        void DFS_AMG_simple();//ͨ��������ȱ����������·��

};

class Adj_node
{
    private:
        int index;//�±�
        Adj_node *next;//ָ����һ�ڽӵ��ָ��
        int w;//������һ�������õ�ʱ����ʾ�ͺ�
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
        int index_w;//�±�
        Adj_node *next_w;//ָ����һ�ڽӵ��ָ��,�����adj_node_w���������Ӷ����
        int w;//Ȩֵ
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
        Adj_node *first;//ָ���ڽӵ���ָ��
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
        VexNode Vex[MAX];//������������飬�������������������Ա��ֻ�����Ϳ���
    public:
        ALG_Graph();
        ~ALG_Graph();
        void Create_ALG_Graph_dericted();//��������ͼ
        void Create_ALG_Graph_undericted();//����ͼ
        void Create_ALG_Graph_dericted_wet();//������
        void Create_ALG_Graph_undericted_wet();//������
        int search_index_l(char c);
        void Create_adj_node_list(int j,int k);//j��������±꣬k�����յ��±꣬��������
        void Create_adj_node_list_w(int j,int k,int w);
        void Show_ALG_g();
        void Show_ALG_w();
        void BFS_ALG_min();//�ù�����������·��
};

void menu();
void menu_AMG();
void menu_ALG();

#endif // GRAPH_H_
