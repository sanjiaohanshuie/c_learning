#include <stdio.h>
#include <ctype.h>
#define MAX_PARTS 100
#define NAME_LEN 25


struct part{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
}inventory[MAX_PARTS];


int num_parts = 0;
void insert(void);
void search(void);
void update(void);
void print(void);
int find_part(int number);
int read_line(char str[],int n);


int main(void)
{
    char code;
    while(1){
        printf("Enter your operation:");
        while(getchar()!='\n');
        scanf(" %c",&code);
        switch(code){
            case 'i':
            case 'I':insert();break;
            case 's':search();break;
            case 'u':update();break;
            case 'p':print();break;
            case 'q':return 0;
            default:printf("Illegal operation:");break;
        }
        printf("\n");
    }
}


int read_line(char str[],int n){
    int i=0,ch;
    while(isspace(ch=getchar()));
    while(ch!='\n' && ch!=EOF){
        if(i<n)
        str[i++]=ch;
        ch=getchar();
    }
    str[i]='\0';
    return i;

}

void insert()
{
    int number,i;
    if(num_parts == MAX_PARTS){
        printf("dataset is full;can't add more parts.\n");
        return;
    }
    printf("Enter part number:");
    scanf("%d",&number);
    i=find_part(number);
    if(i>=0){
        printf("Part already exists.\n");
        return;
    }
    inventory[num_parts].number=number;
    printf("Enter part name:");
    read_line(inventory[num_parts].name,NAME_LEN);
    printf("Enter part quantity:");
    scanf("%d",&inventory[num_parts].on_hand);
    num_parts++;

}


int find_part(int number)
{
    for(int i=0;i<num_parts;i++)
        if (inventory[i].number==number)
           return i; 
    return -1;
    
}

void search(void){
    int number,i;
    printf("Enter part number");
    scanf("%d",&number);
    i=find_part(number);
    if(i>=0){
        printf("%s\n%d",inventory[i].name,inventory[i].on_hand);
    }
    else{
        printf("Part not found.\n");
    }
}

void update(void){
    int number,change,i;
    printf("Enter part number");
    scanf("%d",&number);
    i=find_part(number);
    printf("%s",inventory[i].name);
    printf("Enter part changes in quantity:");
    scanf("%d",&change);
    inventory[i].on_hand+=change;
}

void print(void){
    int i;
    printf("Part Number\tPart Name\t\tPart Quantity\n");
    for(i=0;i<num_parts;i++){
        printf("%d\t\t%s\t\t%d\n",inventory[i].number,inventory[i].name,inventory[i].on_hand);

    }
}