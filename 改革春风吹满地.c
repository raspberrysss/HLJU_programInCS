#include<stdio.h>
#include<math.h>
int main()
{   int n;
    while(scanf("%d",&n),n!=0)
    {
        int x[100],y[100];
        double s=0.0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            scanf("%d",&y[i]);

        }
        for(int i=0;i<n-1;i++)
        {
            s=s+x[i]*y[i+1]-x[i+1]*y[i];

        }
        s=s+x[n-1]*y[0]-x[0]*y[n-1];
        s=s/2;
        printf("%.1lf\n",fabs(s));

    }
       return 0;
}
