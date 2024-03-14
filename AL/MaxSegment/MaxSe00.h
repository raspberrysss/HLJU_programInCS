#ifndef MAXSE_H_
#define MAXSE_H_

class MaxSe
{
    private:
        int length;
        int array_m[100];
        int sta;
        int ter;
        //int* array_m;
        //static int count_m;//记录递归次数
    public:
        MaxSe();
        ~MaxSe();
        void set_array();
        void show_array();
        int get_length();
        int get_Max(int left,int right);//起始下标，终止下标
        int get_sta(){return sta;}
        int get_ter(){return ter;}

};

struct momu
{
    int mid;
    int mul;//中位数及其重数
};

class Mode
{
    private:
       momu m[100];
       int array_mo[100];
       int length;
       int mode;
       int multiplicity;
       int s[100];//若有相同重数，使用这个数组
       int h;//控制相同数组
       int flag_s;//控制输出数组还是mo
       //!需要一个判断条件，判断什么有多个众数
    public:
        Mode();
        ~Mode();
        int get_length(){return length;}
        void set_array_mo();
        void show_array_mo();
        void get_mo_mu(int left,int right);
        int get_mo(){return mode;}
        int get_mu(){return multiplicity;}
        void show_s();
        int get_s0(){return s[0];}
        int get_flags(){return flag_s;}
        int get_h(){return h;}
        void show_m();
        void find_max_mu();
};

void menu();


#endif // MAXSE_H_
