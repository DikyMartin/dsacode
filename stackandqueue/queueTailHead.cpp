#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*prev,*next;
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

void popHead(){
    if(!head)return;

    list*curr=head;
    if(tail==head)tail=head=NULL;
    else{
        head=head->next;
        head->prev=NULL;
    }
    free(curr);
}

void printList(){
    list*curr=tail;
    while(curr){
        printf("%d -> ",curr->data);
        curr=curr->prev;
    }
    printf("Head\n");
}

int main(){
    pushTail(231);
    pushTail(43);
    pushTail(94);
    pushTail(21);
    pushTail(432);

    printList();

    popHead();
    printList();
    
    return 0;
}