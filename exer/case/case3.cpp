#include<stdio.h>
#include<stdlib.h>

int MAX=0;

struct node{
    int x,y;
    struct node*next;
}*head=NULL;

typedef struct node node;

node*cNode(int x,int y){
    node*newN=(node*)malloc(sizeof(node));
    newN->x=x;
    newN->y=y;
    newN->next=NULL;
    return newN;
}

void push(int x,int y){
    node*newN=cNode(x,y);
    if(!head)head=newN;
    else{
        node*curr=head;
        while(curr->next)curr=curr->next;
        curr->next=newN;
    }
}

void view(){
    int cnt=0;
    node*curr=head;
    while(curr){
        cnt=cnt+curr->y;
        if(cnt>MAX)printf("%d ",curr->x);
        curr=curr->next;
    }
    if(cnt<=MAX)printf("Completed");
}

int main(){
    int a;scanf("%d %d",&a,&MAX);
    for(int i=0;i<a;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        push(x,y);
    }
    view();
    return 0;
}