#include<stdio.h>
#include<string.h>
int main()
{
    char n[100];
    int i=0,j;
    gets(n);
    j=strlen(n)-1;
    while(i<=j&&n[i]==n[j])//�����ӿ����Գ���
    {
        i++;
        j--;
    }
    if(i<=j)//����ǻ������У����i��jһ���ỻ�ط�
    {
        printf("no\n");
    }
    else{printf("yes\n");}

}
