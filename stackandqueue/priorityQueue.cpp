#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[100];
    int prio;
    struct node*next;
}*head=NULL;

typedef struct node list;

void pushPrio(const char name[],int prio){
    list*newList=(list*)malloc(sizeof(list));
    strcpy(newList->name,name);
    newList->prio=prio;
    newList->next=NULL;

    if(!head||prio<head->prio){
        newList->next=head;
        head=newList;
    }else{
        list*curr=head;
        while(curr->next&&curr->next->prio<prio)curr=curr->next;
        newList->next=curr->next;
        curr->next=newList;
    }
}

void view(){
    list*curr=head;
    while(curr){
        printf("%s, %d -> ",curr->name,curr->prio);
        curr=curr->next;
    }
    puts("NULL");
}

int main(){
    pushPrio("Budi", 10);
    view();
    pushPrio("Andi", 5);
    view();
    pushPrio("Citra", 20);
    view();
    pushPrio("Doni", 10);
    view();

    return 0;
}