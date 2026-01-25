#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char*name;
    struct node*next,*prev;
}*head=NULL,*tail=NULL;

typedef struct node list;

void pushTail(const char*name){
    list*newList=(list*)malloc(sizeof(list));

    newList->name=(char*)malloc(strlen(name)+1);
    strcpy(newList->name,name);
    newList->next=NULL;
    newList->prev=tail;

    if(!tail)head=tail=newList;
    else{
        tail->next=newList;
        tail=newList;
    }
}

void popTail(){
    if(!tail)return;

    list*curr=tail;
    if(head==tail)head=tail=NULL;
    else{
        tail=tail->prev;
        tail->next=NULL;
    }
    free(curr);
}

void printList(){
    list*curr=tail;
    while(curr){
        printf("%s -> ",curr->name);
        curr=curr->prev;
    }
    printf("HEAD\n");
}

int main(){
    pushTail("asep");
    pushTail("mapren");
    pushTail("mesa");
    pushTail("pine");
    pushTail("nayue");

    printList();
    popTail();
    printList();

    return 0;
}