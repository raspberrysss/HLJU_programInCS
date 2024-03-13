#include<stdio.h>
struct student
{
    long num;
    char sex;
    char name;
    int year;
    int month;
    int day;
    int c;
    int gs;
    int xd;
    int rank;

};
void pjf(int g,int x,int c)
{
    double avg;
    avg=(g+x+c)/3;
    printf("%lf",avg);
}
int main()
{
    struct student s;
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%ld",&s.num);
        scanf("%s",s.sex);
        scanf("%s",s.name);
        scanf("%d",s.year);
        scanf("%d",s.month);
        scanf("%d",s.day);
        scanf("%d",s.c);
        scanf("%d",s.gs);
        scanf("%d",s.xd);
        scanf("%d",s.rank);
        pjf(s.gs,s.xd,s.c);

    }

}
