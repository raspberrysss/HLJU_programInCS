#ifndef LINK_H_
#define LINK_H_
class Node//��дʱҪ˼�������Ҫ��ʲô����ʲô���ԣ���Ҫʲô���ķ���
{
     private:
         int data;
         Node *next;
     public:
       Node();//�޲�Ĭ�Ϲ��죬�����д�����ᱨ������ֻд�вι������д���ᱨ��
       // Node(int date_n,Node *next_n);//ǰ���������������Ǵ���һ���ڵ㣬�������ýڵ�������ָ��
      ~Node();//������ɾ��һ���ڵ�,�ڵ�û���õ�new�����Ͳ���delete
      void setdata();
      void setdata_inter(int x);
      void setdata_delete(int x);
      void setnext(Node*p);
      int getdata();//�õ���ǰ�ڵ������
      Node* getnext();//�õ���ǰ�ڵ��ָ��,�����޷�ֱ�ӷ���ָ��
};

class Link
{
    private :
        //Node no;
        Node* head;
        int num;
    public:
        Link();//�������б�
        void creatlink(int n);//�����б�n���ڵ�,����ǹ��캯���ǲ��ܴ���������
        Node* gethead();
        void output();
        void insert_link(int x);
        void delete_link(int x);
        ~Link();




};
#endif // LINK_H_
