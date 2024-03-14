#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool sushu(int n)//判断素数不能一个一个判断，会超时！
{
    int i;
     /*if (n< 2) {
            return false;
        }
        if (n == 2) {
            return true;
        }*/
        for ( i = 2;i<=sqrt(n);i++){
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }


int main()
{
    int n1,n2;
    int num=2;
    int count_su=0;
    vector<int> ve;
    cin>>n1>>n2;
          while(count_su<n2)
          {
              if(sushu(num))
              {
                  count_su++;
                  if(count_su>=n1)
                {
                  ve.push_back(num);
                }
              }
              num++;
          }

    count_su=0;
    int i;
    for(i=0;i<ve.size();i++)
    {
        count_su++;
        if(count_su%10!=1){
            printf(" ");
        }
        printf("%d",ve[i]);
        if(count_su%10==0){
            printf("\n");
        }
    }

    return 0;
}
