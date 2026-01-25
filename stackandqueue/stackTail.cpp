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
    pushTail(12);
    pushTail(54);
    pushTail(76);
    pushTail(32);
    pushTail(98);

    printList(); // LIFO Last in Frist Out  
    popTail();
    printList();

    return 0;
}