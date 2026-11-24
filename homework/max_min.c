#include<string.h>
#include<stdio.h> 
int main(void)
{
    char word[21];
    char largest[21],smallest[21];
    int hasword=0;
    while(1){
        printf("Enter word:");
        scanf("%s",&word);
        if (hasword==0){
        hasword=1;
        strcpy(largest,word);
        strcpy(smallest,word);
        }
        else{
            if(strcmp(word,largest)>0)
            strcpy(largest,word);
            if(strcmp(word,smallest)<0)
            strcpy(smallest,word);
        }
        if(strlen(word)==4)
        break;
        

    }
    printf("\nSmallest word: %s\n",smallest);
    printf("Largest word: %s",largest);   
    return 0;

}