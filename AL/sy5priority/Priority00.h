#ifndef PRIORITY_H_
#define PRIORITY_H_

class Node
{
    private:
        char name_node;
        int length;//原点到扩展结点的长度
    public:
        Node();
        ~Node();
        void set_name(char c){name_node=c;}
        void set_length(int l){length=l;}
        int get_len(){return length;}
        char get_name(){return name_node;}
};


class Priority_s
{
    private:
        int edge[100][100];//邻接矩阵
        int distance[100];//距离
        char v[100];//顶点数组
        char pre_v[100];//前驱点
        int v_n;
        int c_n;//边的个数
        Node n_s;//源点
        Node n[100];
        int se;//堆的当前位置
    public:
        Priority_s();
        ~Priority_s();
        void set_graph();
        int index(char c);
        void show_every();
        void find_shortpath();
        void insert_pq(Node n_n);//入队，入node类型数组
        Node pop_pq();
        void output_pre();

};
#endif // PRIORITY_H_
