#ifndef BACKTRACK_H_
#define BACKTRACK_H_

class N_queen
{
    private:
        int result[100];//�����飬�����i���ڵڼ���
        int n;//���̸�����
        int sum;
    public:
        N_queen();
        ~N_queen();
        void set_n();
        bool is_place(int d);//�ж��Ƿ���԰ڷ��������
        void backtrack(int t);
        int get_sum(){return sum;};

};

class Subset
{
   private:
      int S[100];
      int M;
      int n;
      int result[100];
      int flag;
      //int sum_m;
      //int sum_n;//δ��ѡ������ĺ�
      int sum;
      int number;
   public:
       Subset();
       ~Subset();
       void set_in();
       void backtrack(int sm,int sn,int t);
       //int get_sm(){return sum_m;};
       int get_sn();
       int get_flag(){return flag;};
       int get_num(){return number;};
       void backtrack_f(int f);
       int get_M(){return M;};

} ;

void menu();
#endif // BACKTRACK_H_

