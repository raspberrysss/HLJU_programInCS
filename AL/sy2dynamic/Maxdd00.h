#ifndef MAXD_H_
#define MAXD_H_

#include<string>
#include<iostream>

using namespace std;//用string时要用到

class Maxsegment_d
{
    private:
        int array_d[100];//数组全部从下标是1开始存
        int dynamic[101];//动态规划数组
        int length_d;
        int sta;
        int ter;
    public:
        Maxsegment_d();
        ~Maxsegment_d();
        void set_array_d();
        int find_Maxsegement();
        int get_sta(){return sta;}
        int get_ter(){return ter;}

};

class Max_order
{
    private:
        int len1;
        int len2;
        char str1[100];//两个输入数组
        char str2[100];
        int max_value[101][101];//存最大长度的数组
        char s_ter[101][101];//存标记的数组，根据标记倒置就可以
        int besti;
        int bestj;
        int flag;//用于确认是否有公共子序列
        string w;
        //set<string> lcs;
    public:
        Max_order();
        ~Max_order();
        void set_str12();
        void set_value_ter();
        void show_a();
        int get_besti(){return besti;}
        int get_bestj(){return bestj;}
        void LCS(int i,int j);//递归回溯
        int get_flag(){return flag;}
        int get_len1(){return len1;}
        int get_len2(){return len2;}
        void LCS_many(int i_m,int j_m);
        void s_w(){cout<<w;}

};
void menu();

#endif // MAXD_H_

