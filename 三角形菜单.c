#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,i,j,k;
    system("cls");
    printf("����������ѡ��žų˷���\n");
    printf("1.�������ξžų˷���\n");
    printf("2.�������ξžų˷���\n");
    printf("3.�������ξžų˷���\n");
    printf("4.�������ξžų˷���\n");
    while(scanf("%d",&a)!=EOF)
    {

       switch(a)

        {
        case 1:
            for(i=1; i<=9; i++) //ʵ������
            {
                for(j=1; j<=i; j++) //ʵ�������е�����
                {
                    printf("%d*%d=%2d ",j,i,j*i);
                }
                printf("\n");//����һ���ٻ���
                //��ʽ�����е����⣬���ź����
            }
            break;
        case 2:
            for(i=1; i<=9; i++)
            {
                for(k=1; k<i; k++)
                {
                    printf("       ");//�ÿո���Ƹ�ʽ���߸��ո�
                }
                for(j=i; j<=9; j++) //��һ��Ϊi�������Ǵ�i��9�������ɴ�ʵ��ѭ��
                {
                    printf("%d*%d=%2d ",i,j,i*j);//��i��j
                }
                printf("\n");
            }
            break;
        case 3:
            for(int i=1; i<=9; i++)
            {
                for(k=1; k<=9-i; k++)
                {
                    printf("    ");//���һ���޿ո�������9-iʵ�ָ�ʽ
                }
                for(int j=1; j<=i; j++)
                {
                    printf("%d*%d=%d  ",j,i,i*j);//���к��У�����������ո�
                }
                printf("\n");
            }
            break;
        case 4:
            for(int i=9; i>=1; i--) //�Ӿſ�ʼ����
            {
                for(int k=0; k<i-1; k++) //���ϸ���ʽһ��
                {
                    printf("    ");
                }
                for(int j=i; j<=9; j++) //Ҫʵ�ִ�i�˵���
                {
                    printf("%d*%d=%2d  ",i,j,i*j);
                }
                printf("\n");
            }
            break;
        default:
            break;

        }
         system("pause");
    }

    }

