#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct node{
    char c;
    struct node*next,*prev;
}*head=NULL,*tail=NULL;

typedef struct node list;

void pushHead(char c){
    list*newList=(list*)malloc(sizeof(list));
    newList->c=c;
    newList->prev=NULL;
    newList->next=head;
    
    if(!head)head=tail=newList;
    else{
        head->prev=newList;
        head=newList;
    }
}

void printListHead(){
    list*curr=head;
    while(curr){
        printf("%c -> ",curr->c);
        curr=curr->next;
    }
    printf("TAIL\n");
}

void printListTail(){
    list*curr=tail;
    while(curr){
        printf("%c -> ",curr->c);
        curr=curr->prev;
    }
    printf("HEAD\n");
}

int main(){
    char name[]="MARTIN";
    for(int i=0;i<strlen(name);i++)pushHead(name[i]);

    printListHead();
    printListTail();
    
    return 0;
}