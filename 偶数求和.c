#include<stdio.h>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF){
        int q,e;
		q=n/m;
		e=n%m;
		printf("%d",(2+2*m)/2);
		for(int i=1;i<q;i++)
			printf(" %d",(2+2*m)/2+2*m*i);
		if(e != 0)
			printf(" %d\n",(2*m*q+2+2*m*q+2*e)/2);

	}
	return 0;
}
