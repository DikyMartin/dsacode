#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char name[100],stat[100];
    int age;
    struct node*next;
}*head=NULL;

typedef struct node node;

node*createNode(char name[],int age,char stat[]){
    node*newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->name,name);
    strcpy(newNode->stat,stat);
    newNode->age=age;
    newNode->next=NULL;
    return newNode;
}

int status(char stat[]){
    if(strcmp(stat,"Low")==0)return 3;
    else if(strcmp(stat,"Mid")==0)return 2;
    else return 1;
}

void pushHead(char name[],int age,char stat[]){
    node*newNode=createNode(name,age,stat);
    
    if(!head||status(stat)<status(head->stat)){
        newNode->next=head;
        head=newNode;
    }else{
        node*curr=head;
        while(curr->next&&status(curr->next->stat)<=status(stat))curr=curr->next;
        newNode->next=curr->next;
        curr->next=newNode;
    }
}

void popHead(){
    if(!head)return;
    node*temp=head;
    head=head->next;
    free(temp);
}

void view(){
    node*curr=head;
    while(curr){
        printf("%s %d %s\n",curr->name,curr->age,curr->stat);
        curr=curr->next;
    }
}

int main(){
    pushHead("Rizki",33,"Low");
    pushHead("Richard",26,"Low");
    pushHead("Andi",16,"High");
    pushHead("Nur",74,"Mid");
    pushHead("Coki",66,"Low");

    view();
    printf("\n");

    popHead();
    popHead();
    popHead();

    view();

    return 0;
}