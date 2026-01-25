#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node{
    int data;
    struct node*next,*prev;
};

typedef struct node list;
list*head[MAX]={NULL};
list*tail[MAX]={NULL};

list*createList(int data){
    list*newList=(list*)malloc(sizeof(list));
    newList->data=data;
    newList->next=newList->prev=NULL;
    return newList;
}

int getHash(int value){
    return value%MAX;
}

void push(int data){
    list*newList=createList(data);
    int idx=getHash(data);

    if(!head[idx])head[idx]=tail[idx]=newList;
    else if(data<head[idx]->data){// data terkecil di index
        newList->next=head[idx];
        head[idx]->prev=newList;
        head[idx]=newList;
    }else if(data>=tail[idx]->data){// data terbesar di index
        newList->prev=tail[idx];
        tail[idx]->next=newList;
        tail[idx]=newList;
    }else{// data di tengah
        list*curr=head[idx];
        while(curr&&curr->data<data)curr=curr->next;
        
        list*before=curr->prev; 
        
        newList->next=curr;
        newList->prev=before;
        before->next=newList;
        curr->prev=newList;
    }
}

void pop(int data){
    int idx=getHash(data);
    list*curr=head[idx];

    while(curr&&curr->data!=data)curr=curr->next;
    if(!curr)return;

    list*before=curr->prev;
    list*after=curr->next;

    if(before)before->next=after;
    else head[idx]=after;

    if(after)after->prev=before;
    else tail[idx]=before;

    free(curr);
}

void view(){
    for(int i=0;i<MAX;i++){
        printf("No. %d | ",i+1);
        list*curr=head[i];
        if(!curr){
            printf("No data\n");
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
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);

    push(1);
    push(6);
    push(11);
    push(16);
    push(21);

    push(2);
    push(7);
    push(12);
    push(17);
    push(22);

    push(3);
    push(8);
    push(13);
    push(18);
    push(23);

    push(4);
    push(9);
    push(14);
    push(19);
    push(24);

    view();

    return 0;
}