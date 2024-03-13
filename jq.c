#include <stdio.h>
#include <string.h>
int Mystrcmp(const char *p1,const char *p2,char s1[],char s2[]);
int main()
{
	char s1[10],s2[10];
	char *p1,*p2;
    int i,max,a = 0;
    gets(s1);
    gets(s2);
    p1=s1;
    p2=s2;
    max = strlen(s1);
    if(max < strlen(s2))
    max = strlen(s2);
    Mystrcmp(*p1,*p2,s1,s2);
    return 0;
 }
int Mystrcmp(const char *p1,const char *p2,char s1[],char s2[])
{
    int i,max,a=0;
    for(i = 0;i < max;i++)
    {
    	a = s1[i] - s2[i];
    	if(a > 0)
    	{
    		printf("1\n");
    		printf("两个字符串的差值是：%d\n",a);
    		break;
		}

		if(a < 0)
		{
			printf("-1\n");
    		printf("两个字符串的差值是：%d\n",a);
    		break;
		}
		if(a == 0)
        {
		    printf("0\n");
		    break;
	    }
	}
}
