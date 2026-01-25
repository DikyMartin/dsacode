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

list *search(int x){
    list*curr=head;
    while(curr){
        if(curr->data==x)return curr;
        curr=curr->next;
    }
    return NULL;
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
    pushHead(42);
    pushHead(65);
    pushHead(95);

    printList();

    list*temp=search(30);
    temp?puts("ada"):puts("tidak ada");

    return 0;
}