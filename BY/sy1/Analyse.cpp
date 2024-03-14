/**
       所有标识符分为一类，标识符即用户自己定义的变量名，只能用字母开头，与自带的关键字要有区别
       常数单独分类
       关键字即为int main class 这一类的关键字，分为一类
       分界符即一些如，；“”这样的符号，分为一类
       运算符+ - * / 分为一类
       保留字提前建立数组方便对比查询，其余在读取目标文件时直接记录
       过程：读取文件-识别句子-输出识别结果
       输出格式（类别 本身） 例如 关键字 int
*/


/**
       读文件时读一个字母，分析时要组成单词分析，注意清零
       读完一个单词时，会吞掉下一个字符？与else if 有关，问一下，没问明白
       细节方面没考虑字母大小写，多位常数，其他字符（空格，回车，换行）
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
    string filename;//用字符串定义文件名
    cout<<"请输入想要进行词法分析的文件名"<<endl;
    cin>>filename;
    analyse(filename);//词法分析
    return 0;
}

void analyse(string filename)//分析词法
{
    char ch;
    string word="";
    ifstream fin;//读取文件所进行的准备
    fin.open(filename.c_str(),ios_base::in);//只读，读时把filename转换为char
    if(fin.is_open())//如果打开成功，进行下一步操作
    {
        cout<<"词法分析如下"<<endl;
        while((ch=fin.get())!=EOF)//不为空就继续读文件
        {
            word="";//!！！清空,不然下次读进来的会直接连在已经分析完的词后面
            //cout<<ch<<endl;
            if(is_letter(ch))
            {
             //!判断关键词时要注意组成一个完整单词才是关键字
              while(is_letter(ch))
              {
                  //cout<<"1"<<ch<<endl;
                 word+=ch;//word加上读到的单词，然后继续读下一个，若下一个为字母再继续判断
                 ch=fin.get();//!这里读了下一个字符，但是出循环应该不会屯掉啊？
                 //cout<<"2"<<ch<<endl;
              }
              if(is_keyword(word))
              {
                cout<<"关键字"<<" "<<word<<endl;
              }
              else
              {
                  cout<<"标识符"<<" "<<word<<endl;
              }
            }
           // cout<<"3"<<ch<<endl;
          if(is_number(ch))//!else if就会吞？问
           {
               cout<<"常数"<<" "<<ch<<endl;
           }
           else if(is_operator_a(ch))
           {
               //cout<<"!!!!"<<endl;
                cout<<"运算符"<<" "<<ch<<endl;
           }
           else if(is_divide(ch))
           {
               cout<<"分隔符"<<" "<<ch<<endl;
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

