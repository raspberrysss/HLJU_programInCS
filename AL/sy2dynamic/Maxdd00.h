#ifndef MAXD_H_
#define MAXD_H_

#include<string>
#include<iostream>

using namespace std;//��stringʱҪ�õ�

class Maxsegment_d
{
    private:
        int array_d[100];//����ȫ�����±���1��ʼ��
        int dynamic[101];//��̬�滮����
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
        char str1[100];//������������
        char str2[100];
        int max_value[101][101];//����󳤶ȵ�����
        char s_ter[101][101];//���ǵ����飬���ݱ�ǵ��þͿ���
        int besti;
        int bestj;
        int flag;//����ȷ���Ƿ��й���������
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
        void LCS(int i,int j);//�ݹ����
        int get_flag(){return flag;}
        int get_len1(){return len1;}
        int get_len2(){return len2;}
        void LCS_many(int i_m,int j_m);
        void s_w(){cout<<w;}

};
void menu();

#endif // MAXD_H_

