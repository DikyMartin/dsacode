#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next,*prev;
}*head=NULL,*tail=NULL;

typedef struct node list;

void pushTail(int data){
    list*newList=(list*)malloc(sizeof(list));
    newList->data=data;
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
        printf("%d -> ",curr->data);
        curr=curr->prev;
    }
    printf("HEAD\n");
}

int main(){
    pushTail(10);
    pushTail(20);
    pushTail(30);
    pushTail(40);
    pushTail(50);

    printList();
    popTail();
    printList();

    return 0;
}