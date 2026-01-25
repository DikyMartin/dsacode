#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
}*head=NULL;

typedef struct node list;

void pushHead(int data){
    list*newList=(list*)malloc(sizeof(list));
    newList->data=data;
    newList->next=head;
    head=newList;
}

void popHead(){
    if(!head) return;
    list*curr=head;
    head=head->next;
    free(curr);
}

void printList(){
    list*curr=head;
    while(curr){
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
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
    popHead(); 
    printList();

    return 0;
}