#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next,*prev;
}*head=NULL,*tail=NULL;

typedef struct node list;

list*createNode(int data){
    list*newNode=(list*)malloc(sizeof(list));
    newNode->data=data;
    newNode->next=newNode->prev=NULL;
    return newNode;
}

void pushMid(int data,int target){
    list*newList=createNode(data);
    if(!head){
        head=tail=newList;
        return;
    }

    list*curr=head;
    while(curr&&curr->data!=target)curr=curr->next;

    if(!curr)return;

    newList->next=curr->next;
    newList->prev=curr;

    if(curr->next)curr->next->prev=newList;
    else tail=newList;

    curr->next=newList;
}

void popMid(int target){
    if(!head)return;

    list*curr=head;
    while(curr&&curr->data!=target)curr=curr->next;
    if(!curr)return;

    list*before=curr->prev;
    list*after=curr->next;

    if(before)before->next=after;
    else head=after;

    if(after)after->prev=before;
    else tail=before;

    free(curr);
}

void printList() {
    list*curr=head;
    while(curr){
        printf("%d <-> ", curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

int main(){
    pushMid(10,0);
    pushMid(20,10);
    pushMid(30,20);  
    pushMid(15,10);

    printList();

    popMid(10);
    popMid(30);
    popMid(20); 

    printList();

    return 0;
}