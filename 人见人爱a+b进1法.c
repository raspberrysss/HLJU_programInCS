#include<stdio.h>
int main()
{
   int n;
   int ah,am,as,bh,bm,bs;
   int h,m,s;
   while(scanf("%d",&n)!=EOF)
   {
       while(n--)
       {
           scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
           {
               h=ah+bh;
               m=am+bm;
               s=as+bs;
               if(s>=60)
               {
                   m++;
                   s=s-60;
               }
               if(m>=60)
               {
                   h++;
                   m=m-60;
               }
               printf("%d %d %d\n",h,m,s);
           }
       }
   }
}
