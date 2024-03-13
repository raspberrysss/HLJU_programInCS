#include<stdio.h>
struct queue
{
    int a[100000];//数据要对应！
    int head;
    int back;
};
int main()
{
    int n,b,i,c;
    struct queue q;
    q.head=0;
    q.back=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&c);
            if(c==1)
            {
                scanf("%d",&q.a[q.back]);
                q.back++;


            }
            if(c==2)
            {
                if(q.head<q.back)
                {
                    printf("%d\n",q.a[q.head]);
                }
            }
            if(c==3)
            {
                if(q.head<q.back)
                {
                    q.head++;
                }
            }
        }
    }
    return 0;
}
