#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 26

struct node{
    char title[100],author[100];
    int year;
    struct node*next;
}*head[MAX]={NULL};

typedef struct node node;

int titleKey(char title[]){
    char c=tolower(title[0]);
    return c-'a';
}

node*createNode(char title[],char author[],int year){
    node*newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->title,title);
    strcpy(newNode->author,author);
    newNode->year=year;
    newNode->next=NULL;
    return newNode;
}

void push(char title[],char author[],int year){
    node*newNode=createNode(title,author,year);
    int idx=titleKey(title);
    newNode->next=head[idx];
    head[idx]=newNode;
}

void searchBook(char title[]){
    int idx=titleKey(title);
    int i=0;
    printf("Search Result\n");
    node*curr=head[idx];
    while(curr){
        if(strcmp(curr->title,title)==0)
            printf("%d. %s - %s - %d\n",++i,curr->title,curr->author,curr->year);
        curr=curr->next;
    }
    if(!i)printf("%s not found\n",title);
}

void searchAll(){
    for(int i=0;i<MAX;i++){
        node*curr=head[i];
        if(curr){
            printf("%c\n",'A'+i);
            printf("=====\n");
            int j=0;
            while(curr){
                printf("%d. %s - %s - %d\n",++j,curr->title,curr->author,curr->year);
                curr=curr->next;
            }
        }
        printf("\n");
    }
}

void addBook(){
    char title[100],author[100];
    int year;

    do{
        printf("Input title [3-25 char]: ");
        scanf("%[^\n]",title);getchar();
    }while(strlen(title)<3||strlen(title)>25);

    do{
        printf("Input author [3-25 char]: ");
        scanf("%[^\n]",author);getchar();
    }while(strlen(author)<3||strlen(author)>25);

    do{
        printf("Input year [>=1800]: ");
        scanf("%d",&year);getchar();
    }while(year<1800);
    printf("Inserted!\n");
    push(title,author,year);
}

void inputSearchBook(){
    char title[100];
    do{
        printf("Input title [3-25 char]: ");
        scanf("%[^\n]",title);getchar();
    }while(strlen(title)<3||strlen(title)>25);
    searchBook(title);
}

int main(){
    int input=0;
    do{
        printf("--Library--\n");
        printf("1. Add book\n");
        printf("2. Search book by title\n");
        printf("3. View all books\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d",&input);getchar();

        switch(input){
            case 1:addBook();break;
            case 2:inputSearchBook();break;
            case 3:searchAll();break;
            case 4:
                printf("Thank you!\n");
                return 0;
            break;
            default:puts("Input Wrong");break;
        }
    }while(1);

    return 0;
}