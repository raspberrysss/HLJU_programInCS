#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,i,j,k;
    system("cls");
    printf("请输入数字选择九九乘法表\n");
    printf("1.下三角形九九乘法表\n");
    printf("2.上三角形九九乘法表\n");
    printf("3.正三角形九九乘法表\n");
    printf("4.倒三角形九九乘法表\n");
    while(scanf("%d",&a)!=EOF)
    {

       switch(a)

        {
        case 1:
            for(i=1; i<=9; i++) //实现行数
            {
                for(j=1; j<=i; j++) //实现行数中的列数
                {
                    printf("%d*%d=%2d ",j,i,j*i);
                }
                printf("\n");//做完一切再换行
                //格式还是有点问题，看着很奇怪
            }
            break;
        case 2:
            for(i=1; i<=9; i++)
            {
                for(k=1; k<i; k++)
                {
                    printf("       ");//用空格控制格式，七个空格
                }
                for(j=i; j<=9; j++) //第一项为i，后面是从i到9的数，由此实现循环
                {
                    printf("%d*%d=%2d ",i,j,i*j);//先i再j
                }
                printf("\n");
            }
            break;
        case 3:
            for(int i=1; i<=9; i++)
            {
                for(k=1; k<=9-i; k++)
                {
                    printf("    ");//最后一行无空格，所以用9-i实现格式
                }
                for(int j=1; j<=i; j++)
                {
                    printf("%d*%d=%d  ",j,i,i*j);//先列后行，后面带两个空格
                }
                printf("\n");
            }
            break;
        case 4:
            for(int i=9; i>=1; i--) //从九开始计算
            {
                for(int k=0; k<i-1; k++) //与上个格式一样
                {
                    printf("    ");
                }
                for(int j=i; j<=9; j++) //要实现从i乘到九
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

