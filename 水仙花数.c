#include <stdio.h>

int main(void)
{
    int m, n, count, i, t;


    while(scanf("%d%d", &m, &n) != EOF) {

        count = 0;

        for(i=m; i<=n; i++) {
            int sum = 0;
            t = i;
            while(t) {
               int t2 = t % 10;
               sum += t2 * t2 * t2;

               t /= 10;
            }

            if(sum == i) {
                if(count > 0)
                printf(" %d\n", i);

                count++;
            }
        }

        if(count == 0)
            printf("no\n");

    }

    return 0;
}
