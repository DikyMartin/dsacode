#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next,*prev;
}*head=NULL,*tail=NULL;

typedef struct node list;

void pushHead(int data){
    list*newList=(list*)malloc(sizeof(list));
    newList->data=data;
    newList->prev=NULL;
    newList->next=head;

    if(!head)head=tail=newList;
    else{
        head->prev=newList;
        head=newList;
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
    list*curr=head;
    while(curr){
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("TAIL\n"); 
}

int main(){
    pushHead(21);
    pushHead(31);
    pushHead(51);
    pushHead(11);
    pushHead(71);

    printList();// FIFO Frist In First Out

    popTail();
    printList();

    popTail();
    printList();

    return 0;
}