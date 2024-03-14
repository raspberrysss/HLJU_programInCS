#ifndef PRIORITY_H_
#define PRIORITY_H_

class Node
{
    private:
        char name_node;
        int length;//ԭ�㵽��չ���ĳ���
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
        int edge[100][100];//�ڽӾ���
        int distance[100];//����
        char v[100];//��������
        char pre_v[100];//ǰ����
        int v_n;
        int c_n;//�ߵĸ���
        Node n_s;//Դ��
        Node n[100];
        int se;//�ѵĵ�ǰλ��
    public:
        Priority_s();
        ~Priority_s();
        void set_graph();
        int index(char c);
        void show_every();
        void find_shortpath();
        void insert_pq(Node n_n);//��ӣ���node��������
        Node pop_pq();
        void output_pre();

};
#endif // PRIORITY_H_
