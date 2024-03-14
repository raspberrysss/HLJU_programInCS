#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

/*
    E1=A
    T1=B

*/

char Efi[2]={'i','('};
char E1fi[2]={'+','k'};
char Tfi[2]={'i','(',};
char T1fi[2]={'*','k'};
char Ffi[2]={'i','('};

char Efo[2]={')','#'};
char E1fo[2]={')','#'};
char Tfo[3]={'+',')','#'};
char T1fo[3]={'+',')','#'};
char Ffo[4]={'+','+',')','#'};

char E1se1[1]={'+'};
char E1se2[2]={'#',')'};//不相交，满足预测表分析条件,满足ll（1）文法
char T1se1[1]={'*'};
char T1se2[3]={'+',')','#'};
char F1se1[1]={'i'};
char F1se2[1]={'('};

struct Table_element//结构体存表中产生式
{
    string left_s;//左部
    string right_s;//右部
};

//!初始化直接一个一个初始化，用逗号隔开
struct Table_element table[5][6]={//二维数组分组赋值 !要按照一行一行来初始化
    {
        "E",
        "TA"
    ,
        "error",
        "error"
    ,

        "error",
        "error"
    ,

        "E",
        "TA"
   ,
        "error",
        "error"
        ,
        "error",
        "error"
    },//1
    {
        "error",
        "error"
    ,
        "A",
        "+TA"
    ,
        "error",
        "error"
    ,
        "error",
        "error"
   ,
        "A",
        "k"
    ,
        "A",
        "k"
    },//2
    {
        "T",
        "FB"
    ,
        "error",
        "error"
    ,
        "error",
        "error"
    ,
        "T",
        "FB"
   ,
        "error",
        "error"
   ,
        "error",
        "error"
    },//3
    {
        "error",
        "error"
    ,
        "B",
        "k"
   ,
        "B",
        "*FB"
    ,
        "error",
        "error"
    ,
        "B",
        "k"
    ,
        "B",
        "k"
    },//4
    {
        "F",
        "i"
    ,
        "error",
        "error"
    ,
       "error",
        "error"
    ,
        "F",
        "(E)"
   ,
        "error",
        "error"
    ,
        "error",
        "error"
    }
};//5行6列的预测分析表

/* vector<vector<Table_element>> table(5);
    for(int i=0;i<5;i++)
    {
        table[i].resize(6);
    }
    //用vector构建二维结构体数组
    table[0][0].push_back()*/

void find_cout(char c1,char c2)
{
    cout<<"输出产生式为"<<endl;
    if(c1=='E'&&c2=='i')
    {
        cout<<table[0][0].left_s<<"->"<<table[0][0].right_s<<endl;
    }
    if(c1=='E'&&c2=='(')
    {
        cout<<table[0][3].left_s<<"->"<<table[0][3].right_s<<endl;
    }
    if(c1=='A'&&c2=='+')
    {
        cout<<table[1][1].left_s<<"->"<<table[1][1].right_s<<endl;
    }
    if(c1=='A'&&c2==')')
    {
        cout<<table[1][4].left_s<<"->"<<table[1][4].right_s<<endl;
    }
    if(c1=='A'&&c2=='#')
    {
        cout<<table[1][5].left_s<<"->"<<table[1][5].right_s<<endl;
    }
    if(c1=='T'&&c2=='i')
    {
        cout<<table[2][0].left_s<<"->"<<table[2][0].right_s<<endl;
    }
    if(c1=='T'&&c2=='(')
    {
        cout<<table[2][3].left_s<<"->"<<table[2][3].right_s<<endl;
    }
    if(c1=='B'&&c2=='+')
    {
        cout<<table[3][1].left_s<<"->"<<table[3][1].right_s<<endl;
    }
    if(c1=='B'&&c2=='*')
    {
        cout<<table[3][2].left_s<<"->"<<table[3][2].right_s<<endl;
    }
    if(c1=='B'&&c2==')')
    {
        cout<<table[3][4].left_s<<"->"<<table[3][4].right_s<<endl;
    }
    if(c1=='B'&&c2=='#')
    {
        cout<<table[3][5].left_s<<"->"<<table[3][5].right_s<<endl;
    }
    if(c1=='F'&&c2=='i')
    {
        cout<<table[4][0].left_s<<"->"<<table[4][0].right_s<<endl;
    }
    if(c1=='F'&&c2=='(')
    {
        cout<<table[4][3].left_s<<"->"<<table[4][3].right_s<<endl;
    }

}

bool find_position(char c1,char c2)
{
    if(c1=='E'&&c2=='i')
    return true;
    if(c1=='E'&&c2=='(')
    return true;
    if(c1=='A'&&c2=='+')
    return true;
    if(c1=='A'&&c2==')')
    return true;
    if(c1=='A'&&c2=='#')
    return true;
    if(c1=='T'&&c2=='i')
    return true;
    if(c1=='T'&&c2=='(')
    return true;
    if(c1=='B'&&c2=='+')
    return true;
    if(c1=='B'&&c2=='*')
    return true;
    if(c1=='B'&&c2==')')
    return true;
    if(c1=='B'&&c2=='#')
    return true;
    if(c1=='F'&&c2=='i')
    return true;
    if(c1=='F'&&c2=='(')
    return true;
    else
    return false;

}

string find_need_push(char c1,char c2)
{
    if(c1=='E'&&c2=='i')
    return table[0][0].right_s;
    if(c1=='E'&&c2=='(')
    return table[0][3].right_s;
    if(c1=='A'&&c2=='+')
    return table[1][1].right_s;
    if(c1=='A'&&c2==')')
    return "";
    if(c1=='A'&&c2=='#')
    return "";
    if(c1=='T'&&c2=='i')
    return table[2][0].right_s;
    if(c1=='T'&&c2=='(')
    return table[2][3].right_s;
    if(c1=='B'&&c2=='+')
    return "";
    if(c1=='B'&&c2=='*')
    return table[3][2].right_s;
    if(c1=='B'&&c2==')')
    return "";
    if(c1=='B'&&c2=='#')
    return "";
    if(c1=='F'&&c2=='i')
    return table[4][0].right_s;
    if(c1=='F'&&c2=='(')
    return table[4][3].right_s;
    else
    return "no";
}

int main()
{
  /*
   //预测分析表正确
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            cout<<table[i][j].left_s<<"->"<<table[i][j].right_s<<" ";
        }
        cout<<endl;
    }*/
    stack<char> s1;//存产生式的栈
    queue<char> q1;//存输入符号串的队列，先进先出
    s1.push('#');
    s1.push('E');//先放入#和开始符号E

    cout<<"请输入符号串长度"<<endl;
    int n;
    cin>>n;
    string str1;
    cout<<"请输入字符串"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>str1[i];
        //cout<<str1[i];
        q1.push(str1[i]);
    }
    q1.push('#');
/*    for(queue<char>::iterator qp=q1.front();qp!=q1.back();qp++)
    {
        cout<<*qp<<" ";
    }
*///!queue和stack无迭代器
  /* while(!q1.empty())
   {
       cout<<q1.front()<<" ";
       q1.pop();
   }*///输出q1内容，入队列正确
   //cout<<s1.top()<<endl;
   //cout<<q1.front()<<endl;

   //cout<<"在分析中输出的产生式为"<<endl;
   while(!s1.empty())//在栈不为空的时候一直匹配
   {

         cout<<"此时栈顶为"<<s1.top()<<endl;
         cout<<"此时队列头为"<<q1.front()<<endl;
       //!匹配并不是相等，而是对应行列不是erro
       if(find_position(s1.top(),q1.front()))
       {
            find_cout(s1.top(),q1.front());//匹配输出
            //输出后需出栈出队列，不然是死循环
            //栈需要弹出后再入栈
            char c=s1.top();
            string s;
            s=find_need_push(c,q1.front());

            s1.pop();
            //cout<<s<<"!!!"<<endl;
            if(s!=""&&s!="no")//不为空就倒置入栈
            {
                reverse(s.begin(),s.end());
                int len=s.size();
                const char *temp=s.c_str();//string变为字符数组，用指针接住，用char temp【size】也可以
               // cout<<temp<<endl;
                for(int i=0;i<len;i++)
                {
                    s1.push(temp[i]);
                }

                /*char temp[3];
                strcpy(temp,s.c_str());
                for(int i=0;temp[i]!='\0';i++)
                {
                    cout<<temp[i]<<" ";
                    s1.push(temp[i]);
                }*/
                //cout<<s<<"!!!"<<endl;
                //倒置s后如何入栈
            }
            //cout<<"目前的栈顶为"<<s1.top()<<endl;//栈顶是T才对
            //cout<<"目前队列头为"<<q1.front()<<endl;
             if(s1.top()==q1.front())//相等的时候两个都弹
               {
                   s1.pop();
                   q1.pop();
               }//放在后面，防止栈pop出现问题
         if(!s1.empty())
         {
             cout<<"经过匹配操作后"<<endl;
             cout<<"此时栈顶为"<<s1.top()<<endl;
             cout<<"此时队列头为"<<q1.front()<<endl;
         }

       }
   }
    return 0;
}
