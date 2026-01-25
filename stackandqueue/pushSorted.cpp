#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
}*head=NULL;

typedef struct node list;

void pushSorted(int data){
    list*newList=(list*)malloc(sizeof(list));
    newList->data=data;
    newList->next=NULL;

    if(!head||data<head->data){
        newList->next=head;
        head=newList;
    }else{
        list*curr=head;
        while(curr->next&&curr->next->data<data)curr=curr->next;
        newList->next=curr->next;
        curr->next=newList;
    }
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
    pushSorted(50);
    pushSorted(10);
    pushSorted(30);
    printList();
    
    pushSorted(20);
    printList();

    return 0;
}