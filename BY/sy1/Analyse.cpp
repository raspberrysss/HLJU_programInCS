/**
       ���б�ʶ����Ϊһ�࣬��ʶ�����û��Լ�����ı�������ֻ������ĸ��ͷ�����Դ��Ĺؼ���Ҫ������
       ������������
       �ؼ��ּ�Ϊint main class ��һ��Ĺؼ��֣���Ϊһ��
       �ֽ����һЩ�磬�����������ķ��ţ���Ϊһ��
       �����+ - * / ��Ϊһ��
       ��������ǰ�������鷽��ԱȲ�ѯ�������ڶ�ȡĿ���ļ�ʱֱ�Ӽ�¼
       ���̣���ȡ�ļ�-ʶ�����-���ʶ����
       �����ʽ����� ���� ���� �ؼ��� int
*/


/**
       ���ļ�ʱ��һ����ĸ������ʱҪ��ɵ��ʷ�����ע������
       ����һ������ʱ�����̵���һ���ַ�����else if �йأ���һ�£�û������
       ϸ�ڷ���û������ĸ��Сд����λ�����������ַ����ո񣬻س������У�
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string keyword[12]={"int","main","double","include","iostream","namespace","using","std","double","float","for","while"};
char divide[11]={'#',',',';','(',')','{','}','[',']','<','>'};
char operator_a[5]={'+','-','*','/','='};

bool is_number(char c);
bool is_letter(char c);
bool is_keyword(string s);
bool is_divide(char c);
bool is_operator_a(char c);
void analyse(string filename);

int main()
{
    string filename;//���ַ��������ļ���
    cout<<"��������Ҫ���дʷ��������ļ���"<<endl;
    cin>>filename;
    analyse(filename);//�ʷ�����
    return 0;
}

void analyse(string filename)//�����ʷ�
{
    char ch;
    string word="";
    ifstream fin;//��ȡ�ļ������е�׼��
    fin.open(filename.c_str(),ios_base::in);//ֻ������ʱ��filenameת��Ϊchar
    if(fin.is_open())//����򿪳ɹ���������һ������
    {
        cout<<"�ʷ���������"<<endl;
        while((ch=fin.get())!=EOF)//��Ϊ�վͼ������ļ�
        {
            word="";//!�������,��Ȼ�´ζ������Ļ�ֱ�������Ѿ�������Ĵʺ���
            //cout<<ch<<endl;
            if(is_letter(ch))
            {
             //!�жϹؼ���ʱҪע�����һ���������ʲ��ǹؼ���
              while(is_letter(ch))
              {
                  //cout<<"1"<<ch<<endl;
                 word+=ch;//word���϶����ĵ��ʣ�Ȼ���������һ��������һ��Ϊ��ĸ�ټ����ж�
                 ch=fin.get();//!���������һ���ַ������ǳ�ѭ��Ӧ�ò����͵�����
                 //cout<<"2"<<ch<<endl;
              }
              if(is_keyword(word))
              {
                cout<<"�ؼ���"<<" "<<word<<endl;
              }
              else
              {
                  cout<<"��ʶ��"<<" "<<word<<endl;
              }
            }
           // cout<<"3"<<ch<<endl;
          if(is_number(ch))//!else if�ͻ��̣���
           {
               cout<<"����"<<" "<<ch<<endl;
           }
           else if(is_operator_a(ch))
           {
               //cout<<"!!!!"<<endl;
                cout<<"�����"<<" "<<ch<<endl;
           }
           else if(is_divide(ch))
           {
               cout<<"�ָ���"<<" "<<ch<<endl;
           }
        }
    }

}

bool is_number(char c)
{
    if(c>='0'&&c<='9')
    {
        return true;
    }
    return false;
}

bool is_letter(char c)
{
    if(c>='a'&&c<='z')
    {
        return true;
    }
    return false;
}

bool is_keyword(string s)
{
    for(int i=0;i<12;i++)
    {
        if(s==keyword[i])
        {
            return true;
        }
    }
    return false;
}

bool is_divide(char c)
{
    for(int i=0;i<11;i++)
    {
        if(c==divide[i])
        {
            return true;
        }
    }
    return false;
}

bool is_operator_a(char c)
{
    for(int i=0;i<5;i++)
    {
        if(c==operator_a[i])
        {
            return true;
        }
    }
    return false;
}

