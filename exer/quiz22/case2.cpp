#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct node{
    char adr[100];
    char id[100];
    char type[100];
    struct node*next;
}*head=NULL;

typedef struct node node;

node*createNode(char*adr,char*id,char*type){
    node*newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->adr,adr);
    strcpy(newNode->id,id);
    strcpy(newNode->type,type);
    newNode->next=NULL;
    return newNode;
}

int priority(char*type){
    if(strcmp(type,"Instant")==0)return 1;
    else if(strcmp(type,"Standard")==0)return 2;
    else return 3;
}

void insertPackage(char*adr,char*id,char*type){
    node*newNode=createNode(adr,id,type);
    if(!head||priority(type)<priority(head->type)){
        newNode->next=head;
        head=newNode;
    }else{
        node*curr=head;
        while(curr->next&&priority(curr->next->type)<priority(type))curr=curr->next;
        newNode->next=curr->next;
        curr->next=newNode;
    }   
}

void popPackage(){
    if(!head)return;
    node*temp=head;
    head=head->next;
    free(temp);
}

void viewAll(){
    node*curr=head;
    while(curr){
        printf("%s - %s - %s\n",curr->id,curr->type,curr->adr);
        curr=curr->next;
    }
}

void genId(char*id){
    char set[100]="ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    id[0]='C';
    id[1]='P';
    id[2]='X';
    for(int i=3;i<6;i++)id[i]=set[rand()%36];
    id[6]='\0';    
}

int main(){
    srand(time(NULL));
    int input;
    do{
        puts("Copi Xpress");
        puts("1. Insert new package");
        puts("2. Send a package");
        puts("3. View all package");
        puts("4. Exit");
        scanf("%d",&input);getchar();
        switch(input){
            case 1:
                char adr[100],type[100],id[10];
                do{
                    printf("Address (must start with \"Jl. \",5-20 character [inclusive]): ");
                    scanf(" %[^\n]",adr);
                }while(strncmp(adr,"Jl. ",4)!=0||strlen(adr)<5||strlen(adr)>20);
                do{
                    printf("Package type (Economy/Standard/Instant [case sensitive]): ");
                    scanf("%s",type);
                }while(strcmp(type,"Instant")!=0&&strcmp(type,"Standard")!=0&&strcmp(type,"Economy")!=0);
                genId(id);
                insertPackage(adr,id,type);
                printf("Package inserted\n\n");
                getchar();
            break;

            case 2:
                if(!head)printf("No data\n");
                else{
                    node*curr=head;
                    printf("%s (%s) successfully sent to %s\n",curr->id,curr->type,curr->adr);
                    popPackage();
                }
                getchar();
            break;

            case 3:
                if(!head)printf("No data\n");
                else viewAll();
                getchar();
            break;

            case 4:
                while(head){
                    printf("%s (%s) successfully sent to %s\n",head->id,head->type,head->adr);
                    node*temp=head;
                    head=head->next;
                    free(temp);
                }
                printf("Exit Program\n");
                getchar();
            break;

            default:
                puts("Input Salah");
            break;
        }
    }while(input!=4);
    return 0;
}