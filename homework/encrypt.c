#include <stdio.h> 
#include<string.h>
int main(void)
{
    // int length,volume;
    // printf("Enter length: ");
    // scanf("%d",&length);
    // volume = length * length * length;
    // SetConsoleOutputCP(CP_UTF8);
    // printf("length = %d,volume = %d\n",length,volume);
    // printf("Item\tUnit\tPurchase\n\twww\t666\n");
    // printf("\"hello\"\n");
    // return 0;
    // char ch;
    // ch=getchar();
    // putchar(ch);
    // double a,c,d;
    // printf("输入两个数");
    // scanf("%lf %lf",&c,&d);
    // a=average(c,d);
    // printf("%lf",a);
    // return 0;
    // int n;
    // bool prime;
    // printf("enter a number:");
    // scanf("%d",&n);
    // prime=is_prime(n);
    // if(prime==true){
    //     printf("prime\n");
    // }
    // else
    // printf("not prime\n");
    // system("pause");
    // char word[21];
    // char largest[21],smallest[21];
    // int hasword=0;
    // while(1){
    //     printf("Enter word:");
    //     scanf("%s",&word);
    //     if (hasword==0){
    //     hasword=1;
    //     strcpy(largest,word);
    //     }
    //     else{
    //         if(strcmp(word,largest)>0)
    //         strcpy(largest,word);
    //         if(strcmp(word,smallest)<0)
    //         strcpy(smallest,word);
    //     }
    //     if(strlen(word)==4)
    //     break;
        

    // }
    // printf("\nSmallest word:%s\n",smallest);
    // printf("Largest word:%s",largest);   
    // return 0;
    char word[100],after[100];
    after[0]='\0';
    int shift;
    printf("Enter message to be encrypted:");
    scanf("%[^\n]",word);
    printf("Enter shift amount (1-25):");
    scanf("%d",&shift);
        for(int i=0;i<strlen(word);i++){
            if (word[i]>='a' && word[i]<='z')
            after[i]=(word[i]-'a'+shift)%26+'a';
            else if (word[i]>='A' && word[i]<='Z')
            after[i]=(word[i]-'A'+shift)%26+'A';
            else
            after[i]=word[i];
        }
        
    printf("Encrypted message:%s",after);


}