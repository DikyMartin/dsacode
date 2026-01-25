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

void popHead(){
    if(!head)return;

    list*curr=head;
    if(head==tail)head=tail=NULL;
    else{
        head=head->next;
        head->prev=NULL;
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
    pushHead(10);
    pushHead(20);
    pushHead(30);
    pushHead(40);
    pushHead(50);
    printList();

    popHead();
    printList();

    return 0;
}