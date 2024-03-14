#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

const int MAXSIZE=100;

class Bin_tree_node
{
    private:
        char elem;
        Bin_tree_node * l_tree;
        Bin_tree_node * r_tree;
    public:
        Bin_tree_node();
        Bin_tree_node* get_l();
        Bin_tree_node* get_r();
        char get_e();
        void set_e(char e);
        void set_l(Bin_tree_node *l);
        void set_r(Bin_tree_node *r);
};



   // private:
     //   Bin_tree_node *tree;//根节点指针
    //public:
      //  Bin_tree();
        Bin_tree_node* creat_bin_tree();
        Bin_tree_node* creat_bin_tree2();
        void pre_order(Bin_tree_node *tree);//先序遍历
        int count_depth(Bin_tree_node* tree);//计算深度（层数）

class Stack
{
    private:
        int s[MAXSIZE];
        int top;
    public:
        Stack();
        void push(int e);
        void pop();
        int get_top();
        bool is_empty_s();
        bool is_full();
};

class Stack2
{
    private:
        Bin_tree_node* s[MAXSIZE];
        int top;
    public:
        Stack2();
        void push(Bin_tree_node* e);
        void pop();
        Bin_tree_node* get_top();
        void get_top2(Bin_tree_node* &e);
        bool is_empty_s();
        bool is_full();
};

void pre_full(char e[],int n);
void menu();
void pre_through_s(Bin_tree_node *tree);
void mid_through_s(Bin_tree_node* tree);
void tail_through_s(Bin_tree_node *tree);

#endif // BINARY_TREE_H_
