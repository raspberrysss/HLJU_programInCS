#include <stdio.h>
int main()
{
    int n, val[100], mini, i;
    while(scanf("%d", &n) != EOF)
        {
        if(n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%d", &val[i]);
            mini = 0;
        for(i=1; i<n; i++)
            if(val[i] < val[mini])
                mini = i;
        int c = val[mini];
        val[mini] = val[0];
        val[0] = c;
        for(i=0; i<n; i++) {
            if(i != 0)
                printf(" ");
            printf("%d", val[i]);
        }
        printf("\n");
    }
    return 0;
}
