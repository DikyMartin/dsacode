#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node{
    int data;
    struct node*next;
}list;

list*head[MAX]={NULL};
list*tail[MAX]={NULL};

int getHash(int data){
    return data%MAX;
}

list*createList(int data){
    list*newList=(list*)malloc(sizeof(list));
    newList->data=data;
    newList->next=NULL;
    return newList;
}

void push(int data){
    list*newList=createList(data);
    int idx=getHash(data);

    if(!head[idx])head[idx]=tail[idx]=newList;
    else if(data<head[idx]->data){
        newList->next=head[idx];
        head[idx]=newList;
    }else if(data>=tail[idx]->data){
        tail[idx]->next=newList;
        tail[idx]=newList;
    }else{
        list*curr=head[idx];
        while(curr->next&&curr->next->data<data)curr=curr->next;

        newList->next=curr->next;
        curr->next=newList;
    }
}

void view(){
    for(int i=0;i<MAX;i++) {
        printf("Index %d: ",i);
        list*curr=head[i];
        if(!curr){
            printf("Empty\n");
            continue;
        }

        while(curr){
            printf("%d -> ",curr->data);
            curr=curr->next;
        }
        printf("NULL\n");
    }
}

int main(){
    push(10);
    push(5);
    push(15);
    push(7);
    push(2);
    push(20);
    push(13);

    view();

    return 0;
}