#include<iostream>
#include<vector>
#include<algorithm>
//太久不写，好多操作都不熟练了
using namespace std;

int main(void)
{
    int i;
    vector<int> v1;
    int n;
    int a,b,c,d;
    cin>>n;
    //cout<<v;
   /* v1[0]=v/1000;
    v1[1]=(v%1000)/100;
    v1[2]=((v%1000)%100)/10;
    v1[3]=((v%1000)%100)%10;
   //sort(v1.begin(),v1.end());
*/
    a=n/1000;
    b=(n%1000)/100;
    c=((n%1000)%100)/10;
    d=((n%1000)%100)%10;
    v1.push_back(a);//vector 输入要用这个！
    v1.push_back(b);
    v1.push_back(c);
    v1.push_back(d);
    sort(v1.begin(),v1.end());
      for(i=0;i<4;i++)
      {
          cout<<v1[i];
      }
    return 0;

}
