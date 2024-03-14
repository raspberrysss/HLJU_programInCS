#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int index(char c);
bool is_vt(char c);

//������ȱ�
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
    cout<<"��������Ŵ�����"<<endl;
    int n;
    cin>>n;
    string str1;
    cout<<"�������ַ���"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>str1[i];
        q.push(str1[i]);
    }
    q.push('#');
    int x=-1;
    while(s.top()!='S')
    {
        if(s.top()=='#')//#�������з��ս��ַ�����ջ
        {
            s.push(q.front());
            q.pop();
            cout<<"�ƽ�"<<endl;
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
            //cout<<"��ջ��"<<s.top()<<endl;
            x=index(s.top());
            //�ٰѳ�ջ��������ջ
            for(vector<char>::iterator vcp=temp1.end();vcp!=temp1.begin();vcp--)//��������ָ������
            {
                s.push(*vcp);
            }
        }
        int y=index(q.front());
        if(table[x][y]=='<'||table[x][y]=='=')
        {
            s.push(q.front());
            q.pop();
            cout<<"�ƽ�"<<endl;
        }

        else if(table[x][y]=='>')
        {
            //�����ʵ������д����?��Լ�ĳ���������ۿ�
            cout<<"��Լ"<<endl;
            if(s.top()=='b')
            {
                s.pop();
                if(s.top()=='A')
                {
                    cout<<"��ԼΪA"<<endl;
                    s.pop();
                    s.push('A');
                }
                else
                {
                    cout<<"��ԼΪA"<<endl;
                    s.push('A');
                }
            }
            else if(s.top()=='d')
            {
                s.pop();
                cout<<"��ԼΪB"<<endl;
                s.push('B');
            }
            else
            {
                cout<<"��ԼΪS"<<endl;
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

//�ϴ���
// vector<char> temp2;//�������
            //!!��Ŀ����Ѱ�����ȼ�С����ߵ��Ǹ�vt�������ұ�ȫ����ջ��Լ
            //!����vt�Ƚϣ�����vtֱ����

//            if(is_vt(s.top()))//���ջ����vt��������ߵĵ�һ��vt���бȽ�
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
            //�жϹ�Լ����ʲô��Ȼ����ջ
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
//                cout<<"��ԼΪA"<<endl;
//                s.push('A');
//            }
//            if(!strcmp(str_temp,"d"))
//            {
//                cout<<"��ԼΪB"<<endl;
//                s.push('B');
//            }
//            if(!strcmp(str_temp,"bA"))
//            {
//                cout<<"��ԼΪA"<<endl;
//                s.push('A');
//            }
//            if(!strcmp(str_temp,"eBcAa"))
//            {
//                cout<<"��ԼΪS"<<endl;
//                s.push('S');
//            }
            /*if(s.top()=='b')
            {
                s.pop();
                s.push('A');
                cout<<"��ԼΪA"<<endl;
            }
            else if(s.top()=='d')
            {
                s.pop();
                s.push('B');
                cout<<"��ԼΪB"<<endl;
            }

            */
           /* vector<char> tem;//��ʱ���飬�������ջ
            char ct=s.pop();
            int xs=index(s.top());
            int ys=index(ct);
            if(table[xs][ys]=='>'*/
