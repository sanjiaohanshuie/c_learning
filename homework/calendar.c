#include<stdio.h>
#include<windows.h>

int main(void)
{
    system("chcp 65001 >nul");
    printf("Enter number of days in month:");
    int days,start;
    scanf("%d",&days);
    printf("Enter starting day of the week(1=Sun, 7=Sat):");
    scanf("%d",&start);
    printf("日 一 二 三 四 五 六\n");
    for(int i=1;i<start;i++)
    {   printf("   ");}
    for(int d=1;d<=days;d++){
        printf("%2d ",d);
        if ((d+start-1)%7==0){
            printf("\n");
        }
    }
    return 0;
}