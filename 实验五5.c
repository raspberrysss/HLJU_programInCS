#include<stdio.h>
int main()
{
    int n,m,i,j,k;
    double sum,ave;
    int max_hxb,max_lxb,bujige;
    int c[2];
    int a[100][100];//�ʣ����鿪̫���޷�����a��1000��
    long long b[100],d[100];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum=0.0;
        printf("������ѧ������\n");
        for(k=0;k<n;k++)
        {
            scanf("%d",&b[k]);
        }
        printf("������γ̺�\n");
        for(k=0;k<m;k++)
        {
            scanf("%d",&d[k]);
        }
        printf("����������ѧ�����Ƴɼ�\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        max_hxb=0;
        max_lxb=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]>a[max_hxb][max_lxb])
                {
                    max_hxb=i;
                    max_lxb=j;

                }
                if(a[i][j]<60)
                {
                    bujige=i;
                }
            }
        }
        printf("��߳ɼ���ѧ�ż��γ̺�Ϊ\n");
        printf("%ld %ld\n",b[max_hxb],d[max_lxb]);
        printf("������ͬѧ��ѧ�ż�ȫ���γ̷���Ϊ\n");
        printf("%ld ",b[bujige]);
        for(j=0;j<m;j++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",a[bujige][j]);
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                sum=sum+a[i][j];
            }
        }
        ave=sum/n;
        printf("ѧ������ƽ����Ϊ\n");
        printf("%.2lf\n",ave);




    }
}
