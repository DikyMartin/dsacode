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

list*createNode(int data){
    list*newList=(list*)malloc(sizeof(list));
    newList->data=data;
    newList->next=newList->prev=NULL;   
    return newList;
}

int getHash(int data){
    return data%MAX;
}

void push(int data){
    list*newList=createNode(data);
    int idx=getHash(data);

    if(!head[idx])head[idx]=tail[idx]=newList;
    else if(data<head[idx]->data){
        newList->next=head[idx];
        head[idx]->prev=newList;
        head[idx]=newList;
    }else if(data>=tail[idx]->data){
        newList->prev=tail[idx];
        tail[idx]->next=newList;
        tail[idx]=newList;
    }else{
        list*curr=head[idx];
        while(curr&&curr->data<data)curr=curr->next;
        if(!curr)return;

        list*before=curr->prev; 
        newList->next=curr;
        newList->prev=before;
        before->next=newList;
        curr->prev=newList;
    }
}

void pop(int data){
    int idx=getHash(data);
    if(!head[idx])return;

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

void search(int data) {
    int idx=getHash(data);
    list*curr=head[idx];

    while(curr){
        if(curr->data==data) {
            printf("Data %d ditemukan pada index %d!\n", data, idx);
            return;
        }
        if(curr->data>data)break;
        curr=curr->next;
    }
    printf("Data %d tidak ditemukan.\n", data);
}

void view(){
    for(int i=0;i<MAX;i++){
        printf("NO %d. ",i+1);
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

    push(10);
    push(23);
    push(22);
    push(76);
    push(2);

    view();
    puts("");

    pop(10);

    view();

    return 0;
}