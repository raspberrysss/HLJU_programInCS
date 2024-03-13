#include<stdio.h>
#include<string.h>
int main()
{
   int n;
   int i,j,t;
   int k,l;
   char a[100][100];
   char q[10]="male";
   char w[10]="female";
   double b[100],c[100];
   double e,f;
   int d,g;

   while(scanf("%d",&n)!=EOF)
   {
      getchar();
      for(i=0;i<n;i++)
      {
          gets(a[i]);
          d=strcmp(a[i],q[10]);
          printf("%d",d);
          g=strcmp(a[i],w[10]);
          if(d==0)
          {
              printf("h");
              scanf("%d",&e);
              b[i]=e;
          }
          if(g==0)
          {
              scanf("%d",&f);
              c[i]=f;
          }

      }
      k=strlen(b);
      l=strlen(c);
      for(i=0;i<k-1;i++)
      {
          for(j=0;j<k-1-i;j++)
          {
              if(b[j]>b[j+1])
              {
                  t=b[j];
                  b[j]=b[j+1];
                  b[j+1]=t;
              }
          }
      }
      for(i=0;i<l-1;i++)
      {
          for(j=0;j<l-1-i;j++)
          {
              if(c[j]<c[j+1])
              {
                  t=c[j];
                  c[j]=c[j+1];
                  c[j+1]=t;
              }
          }
      }
      for(i=0;i<k;i++)
      {
          if(i!=0)
          {
              printf(" ");
          }
          printf("%.2d",b[i]);
      }
      for(i=0;i<l;i++)
      {
          if(i!=0)
          {
              printf(" ");
          }
          printf("%.2d",c[i]);
      }

   }
}
