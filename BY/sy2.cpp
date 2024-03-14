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
char E1se2[2]={'#',')'};//���ཻ������Ԥ����������,����ll��1���ķ�
char T1se1[1]={'*'};
char T1se2[3]={'+',')','#'};
char F1se1[1]={'i'};
char F1se2[1]={'('};

struct Table_element//�ṹ�����в���ʽ
{
    string left_s;//��
    string right_s;//�Ҳ�
};

//!��ʼ��ֱ��һ��һ����ʼ�����ö��Ÿ���
struct Table_element table[5][6]={//��ά������鸳ֵ !Ҫ����һ��һ������ʼ��
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
};//5��6�е�Ԥ�������

/* vector<vector<Table_element>> table(5);
    for(int i=0;i<5;i++)
    {
        table[i].resize(6);
    }
    //��vector������ά�ṹ������
    table[0][0].push_back()*/

void find_cout(char c1,char c2)
{
    cout<<"�������ʽΪ"<<endl;
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
   //Ԥ���������ȷ
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            cout<<table[i][j].left_s<<"->"<<table[i][j].right_s<<" ";
        }
        cout<<endl;
    }*/
    stack<char> s1;//�����ʽ��ջ
    queue<char> q1;//��������Ŵ��Ķ��У��Ƚ��ȳ�
    s1.push('#');
    s1.push('E');//�ȷ���#�Ϳ�ʼ����E

    cout<<"��������Ŵ�����"<<endl;
    int n;
    cin>>n;
    string str1;
    cout<<"�������ַ���"<<endl;
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
*///!queue��stack�޵�����
  /* while(!q1.empty())
   {
       cout<<q1.front()<<" ";
       q1.pop();
   }*///���q1���ݣ��������ȷ
   //cout<<s1.top()<<endl;
   //cout<<q1.front()<<endl;

   //cout<<"�ڷ���������Ĳ���ʽΪ"<<endl;
   while(!s1.empty())//��ջ��Ϊ�յ�ʱ��һֱƥ��
   {

         cout<<"��ʱջ��Ϊ"<<s1.top()<<endl;
         cout<<"��ʱ����ͷΪ"<<q1.front()<<endl;
       //!ƥ�䲢������ȣ����Ƕ�Ӧ���в���erro
       if(find_position(s1.top(),q1.front()))
       {
            find_cout(s1.top(),q1.front());//ƥ�����
            //��������ջ�����У���Ȼ����ѭ��
            //ջ��Ҫ����������ջ
            char c=s1.top();
            string s;
            s=find_need_push(c,q1.front());

            s1.pop();
            //cout<<s<<"!!!"<<endl;
            if(s!=""&&s!="no")//��Ϊ�վ͵�����ջ
            {
                reverse(s.begin(),s.end());
                int len=s.size();
                const char *temp=s.c_str();//string��Ϊ�ַ����飬��ָ���ס����char temp��size��Ҳ����
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
                //����s�������ջ
            }
            //cout<<"Ŀǰ��ջ��Ϊ"<<s1.top()<<endl;//ջ����T�Ŷ�
            //cout<<"Ŀǰ����ͷΪ"<<q1.front()<<endl;
             if(s1.top()==q1.front())//��ȵ�ʱ����������
               {
                   s1.pop();
                   q1.pop();
               }//���ں��棬��ֹջpop��������
         if(!s1.empty())
         {
             cout<<"����ƥ�������"<<endl;
             cout<<"��ʱջ��Ϊ"<<s1.top()<<endl;
             cout<<"��ʱ����ͷΪ"<<q1.front()<<endl;
         }

       }
   }
    return 0;
}
