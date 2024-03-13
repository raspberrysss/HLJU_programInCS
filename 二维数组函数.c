#include<stdio.h>
void input(int a[100][100],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
//void output()ÎÊÒ»ÏÂ
//{
//    int i,j;

//}
void max(int a[100][100],int n,int m)
{
    int i,j;
    int max1,max2;
    max1=0;
    max2=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]>a[max1][max2])
            {
                max1=i;
                max2=j;
            }
        }
    }
    printf("%d",a[max1][max2]);
}


int main()
{
    int n,m;
    int a[100][100];
    scanf("%d%d",&n,&m);
    input(a,n,m);
    max(a,n,m);
    //output()

}
