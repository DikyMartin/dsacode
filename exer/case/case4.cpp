#include<stdio.h>
#include<stdlib.h>

struct node{
    int x;
    struct node*R,*L;
};

typedef struct node node;

struct print{
    int x;
    struct print*next,*prev;
}*head=NULL,*tail=NULL;

typedef struct print print;

node*createNode(int x){
    node*newN=(node*)malloc(sizeof(node));
    newN->x=x;
    newN->L=newN->R=NULL;
    return newN;
}

int search(node*root,int x){
    if(!root)return -1;
    if(root->x=x)return 1;
    return(x<root->x)?search(root->L,x):search(root->R,x);
}

node*insertNode(node*root,int x){
    if(!root)return createNode(x);
    (x<root->x)?root->L=insertNode(root->L,x):root->R=insertNode(root->R,x);
    return root;
}

void push(int x){
    print*node=(print*)malloc(sizeof(print));
    node->x=x;
    node->next=node->prev=NULL;
    if(!head)head=tail=node;
    else{
        node->next=head;
        head->prev=node;
        head=node;
    }
}

int main(){
    int n;scanf("%d",&n);
    node*root=NULL;
    int temp,x=1;
    for(int i=1;i<n+1;i++){
        temp=x;
        scanf("%d",&x);
        if(i%2==1)x=x*temp;
        // if(!search(root,x))
        root=insertNode(root,x);
        push(x);
    }

    puts("");

    print*curr=tail;
    while(curr){
        printf("%d\n",curr->x);
        curr=curr->prev;
    }

    return 0;
}
