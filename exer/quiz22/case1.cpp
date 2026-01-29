#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char title[100];
    int dur;
    struct node*next,*prev;
}*head=NULL,*tail=NULL;

typedef struct node node;

node*createNode(char title[],int dur){
    node*newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->title,title);
    newNode->dur=dur;
    newNode->next=newNode->prev=NULL;
    return newNode;
}

void pushSong(char target[],char tittle[],int dur){
    node*newNode=createNode(tittle,dur);
    if(!head){
        head=tail=newNode;
        return;
    }

    if(strcmp(target,"-")==0){
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
        return;
    }

    node*curr=head;
    while(curr&&strcmp(curr->title,target)!=0)curr=curr->next;

    if(!curr){
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        return;
    }

    newNode->next=curr->next;
    newNode->prev=curr;

    if(curr->next)curr->next->prev=newNode;
    else tail=newNode;

    curr->next=newNode;
}

void convertDur(int dur){
    int mins=dur/60;
    int secs=dur%60;
    printf("%.2d:%.2d\n",mins,secs);
}

void printSong(int m){
    if(m==1){
        node*curr=head;
        while(curr){
            printf("%s - ",curr->title);
            convertDur(curr->dur);
            curr=curr->next;
        }
    }else if(m==0){
        node*curr=tail;
        while(curr){
            printf("%s - ",curr->title);
            convertDur(curr->dur);
            curr=curr->prev;
        }
    }
}

int main(){
    int n;scanf("%d",&n);getchar();

    int dur;
    char target[100],tittle[100];
    for(int i=0;i<n;i++){
        scanf(" %[^#]#%[^#]#%d",target,tittle,&dur);
        pushSong(target,tittle,dur);
    }
    int m;scanf("%d",&m);
    printSong(m);

    return 0;
}