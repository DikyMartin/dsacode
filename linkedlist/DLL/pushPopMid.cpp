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

// main code pushMid
void pushMid(int data,int target){
    if(!head){
        pushHead(data);
        return;
    }

    list*curr=head;
    while(curr&&curr->data!=target)curr=curr->next; // curr!=NULL
    if(!curr)return;

    if(curr==tail){
        pushTail(data);
        return;
    }

    list*newList=(list*)malloc(sizeof(list));
    list*after=curr->next;
    newList->data=data;

    newList->next=after;
    newList->prev=curr;
    after->prev=newList;
    curr->next=newList;
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

void popMid(int target){
    if(!head)return;

    list*curr=head;
    while(curr&&curr->data!=target)curr=curr->next;

    if(!curr)return;

    if(curr==head)popHead();
    else if(curr==tail)popTail();
    else{
        list*before=curr->prev;
        list*after=curr->next;
        before->next=after;
        after->prev=before;
        free(curr);
    }
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
    pushTail(21);
    pushTail(31);
    pushTail(61);

    printList(); 

    pushMid(99, 10); 
    printList();

    pushMid(100, 999);
    printList();

    popTail();
    printList();

    return 0;
}