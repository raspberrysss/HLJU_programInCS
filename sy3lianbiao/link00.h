#ifndef LINK_H_
#define LINK_H_
class Node//编写时要思考这个类要做什么，有什么特性，需要什么样的方法
{
     private:
         int data;
         Node *next;
     public:
       Node();//无参默认构造，如果单写它不会报错，但是只写有参构造而不写它会报错
       // Node(int date_n,Node *next_n);//前两个函数的作用是创建一个节点，包括设置节点数据与指针
      ~Node();//析构，删除一个节点,节点没有用到new析构就不用delete
      void setdata();
      void setdata_inter(int x);
      void setdata_delete(int x);
      void setnext(Node*p);
      int getdata();//得到当前节点的数据
      Node* getnext();//得到当前节点的指针,对象无法直接访问指针
};

class Link
{
    private :
        //Node no;
        Node* head;
        int num;
    public:
        Link();//建立空列表
        void creatlink(int n);//建立列表，n个节点,如果是构造函数是不能传进变量吗
        Node* gethead();
        void output();
        void insert_link(int x);
        void delete_link(int x);
        ~Link();




};
#endif // LINK_H_
