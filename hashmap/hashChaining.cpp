#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct node{
    char name[30];
    int age;
    struct node*next;
}*head[SIZE]={NULL};

typedef struct node node;

node*createNode(char name[],int age){
    node*newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->name,name);
    newNode->age=age;
    newNode->next=NULL;
    return newNode;
}

int getKey(char*name){
    int asci=0;
    for(int i=0;i<strlen(name);i++)asci+=name[i];
    return asci;
}

void insertNode(char*name,int age){
    node*newNode=createNode(name,age);
    int idx=getKey(name)%SIZE;

    if(!head[idx])head[idx]=newNode;//pushTail
    else{
        node*curr=head[idx];
        while(curr->next)curr=curr->next;
        curr->next=newNode;
    }
}

void pop(char*name){
    int idx=getKey(name)%SIZE;//popMid
    node*curr=head[idx];
    node*prev=NULL;

    while(curr){
        if(strcmp(curr->name,name)==0){
            if(!prev)head[idx]=curr->next;
            else prev->next=curr->next;
            free(curr);
            return;
        }
        prev=curr;
        curr=curr->next;
    }
}

void printTable(){
    for(int i=0;i<SIZE;i++){
        node*curr=head[i];
        printf("[%d] ",i);
        while(curr){
            printf("%s (%d)->",curr->name,curr->age);
            curr=curr->next;
        }
        printf("NULL\n");
    }
}

int main(){
    insertNode("Louis",10);
    insertNode("Gazent",6);
    insertNode("Rico",8);

    printTable();
    pop("Rico");
    printTable();

    return 0;
}