
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#define TIME_INTERVAL (CLOCKS_PER_SEC / 50)
int main(int argc, char* argv[])
{
    int i, j;
    long c;
    char str[80] = "Hello world!";
    int l = strlen(str);
    char sleft[80];
    char sright[80];
    int scrwidth = 79;

    while (1)
    {
        for (i = 0; i <= scrwidth; i++)
        {
            if (i <= scrwidth - l)
            {
                c = clock();
                for (j = 0; j < i; j++)
                {
                    printf(" ");
                }
                printf("%s ", str);
                while (clock() - c <= TIME_INTERVAL)
                    ;
            }
            else
            {
                c = clock();
                strcpy(sleft, str);
                strcpy(sright, str + l - (i - (scrwidth - l)));
                *(sleft + l - (i - (scrwidth - l))) = NULL;
                for (j = 0; j < i; j++)
                {
                    printf(" ");
                }
                printf("%s ", sleft);
                printf("%s ", sright);
                while (clock() - c <= TIME_INTERVAL)
                    ;
            }
        }
    }

    return 0;
}
