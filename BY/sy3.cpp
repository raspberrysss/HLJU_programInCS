#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int index(char c);
bool is_vt(char c);

//算符优先表
char table[5][5]={'e','<','=','e','e',
            'e','>','>','e','e',
            'e','e','e','<','=',
            'e','e','e','e','>',
            'e','e','e','e','e'};

//S->aAcBe
//A->b|Ab
//B->d

int main(void)
{
    stack<char> s;
    queue<char> q;
    s.push('#');
    cout<<"请输入符号串长度"<<endl;
    int n;
    cin>>n;
    string str1;
    cout<<"请输入字符串"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>str1[i];
        q.push(str1[i]);
    }
    q.push('#');
    int x=-1;
    while(s.top()!='S')
    {
        if(s.top()=='#')//#低于所有非终结字符，入栈
        {
            s.push(q.front());
            q.pop();
            cout<<"移进"<<endl;
        }
        if(is_vt(s.top()))
        {
             x=index(s.top());
        }
        else
        {
            vector<char> temp1;
            while(!is_vt(s.top()))
            {
               temp1.push_back(s.top());
               s.pop();
            }
            //cout<<"出栈完"<<s.top()<<endl;
            x=index(s.top());
            //再把出栈的重新入栈
            for(vector<char>::iterator vcp=temp1.end();vcp!=temp1.begin();vcp--)//迭代器与指针类似
            {
                s.push(*vcp);
            }
        }
        int y=index(q.front());
        if(table[x][y]=='<'||table[x][y]=='=')
        {
            s.push(q.front());
            q.pop();
            cout<<"移进"<<endl;
        }

        else if(table[x][y]=='>')
        {
            //仅针对实验题所写程序?归约的程序表达，非人眼看
            cout<<"归约"<<endl;
            if(s.top()=='b')
            {
                s.pop();
                if(s.top()=='A')
                {
                    cout<<"归约为A"<<endl;
                    s.pop();
                    s.push('A');
                }
                else
                {
                    cout<<"归约为A"<<endl;
                    s.push('A');
                }
            }
            else if(s.top()=='d')
            {
                s.pop();
                cout<<"归约为B"<<endl;
                s.push('B');
            }
            else
            {
                cout<<"归约为S"<<endl;
                while(s.top()!='#')
                {
                    s.pop();
                }
                break;
            }

        }
    }

    return 0;
}

int index(char c)
{
    if(c=='a')
        return 0;
    if(c=='b')
        return 1;
    if(c=='c')
        return 2;
    if(c=='d')
        return 3;
    if(c=='e')
        return 4;
    else
       return -1;

}

bool is_vt(char c)
{
    if(c=='a'||c=='b'||c=='c'||c=='d'||c=='e')
    {
        return true;
    }
    else
        return false;
}

//废代码
// vector<char> temp2;//方便遍历
            //!!！目的是寻找优先级小于左边的那个vt，把它右边全部出栈归约
            //!若是vt比较，不是vt直接跳

//            if(is_vt(s.top()))//如果栈顶是vt，找它左边的第一个vt进行比较
//            {
//                char t=s.top();
//                s.pop();
//                if(is_vt(s.top()))
//                {
//                    int x0=index(s.top());
//                    int y0=index(t);
//                    if(table[x0][y0]=='='||table[x0][y0]=='>')
//                    {
//
//                    }
//                }
//            }
            /*do
            {
                cout<<s.top()<<"npop"<<endl;
               temp2.push_back(s.top());
               s.pop();
               cout<<s.top()<<"afterpop"<<endl;
            }while(is_vt(s.top()));*/
            //判断归约的是什么，然后入栈
//            char str_temp[]="";
//            int i=0;
//            for(vector<char>::iterator vcp=temp2.begin();vcp!=temp2.end();vcp++)
//            {
//                str_temp[i]=*vcp;
//                cout<<*vcp<<endl;
//                //cout<<str_temp[i]<<"**"<<endl;
//                i++;
//            }
//            for(int j=0;j<i;j++)
//            {
//                //cout<<str_temp[i]<<endl;
//            }
//
//            //cout<<str_temp<<endl;
//            if(!strcmp(str_temp,"b"))
//            {
//                cout<<"归约为A"<<endl;
//                s.push('A');
//            }
//            if(!strcmp(str_temp,"d"))
//            {
//                cout<<"归约为B"<<endl;
//                s.push('B');
//            }
//            if(!strcmp(str_temp,"bA"))
//            {
//                cout<<"归约为A"<<endl;
//                s.push('A');
//            }
//            if(!strcmp(str_temp,"eBcAa"))
//            {
//                cout<<"归约为S"<<endl;
//                s.push('S');
//            }
            /*if(s.top()=='b')
            {
                s.pop();
                s.push('A');
                cout<<"归约为A"<<endl;
            }
            else if(s.top()=='d')
            {
                s.pop();
                s.push('B');
                cout<<"归约为B"<<endl;
            }

            */
           /* vector<char> tem;//临时数组，方便遍历栈
            char ct=s.pop();
            int xs=index(s.top());
            int ys=index(ct);
            if(table[xs][ys]=='>'*/
