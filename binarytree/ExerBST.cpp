#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    int id;
    char name[40];
    struct node*left,*right;
};

typedef struct node node;

node*createNode(int id,char*name){
    node*newNode=(node*)malloc(sizeof(node));
    newNode->id=id;
    strcpy(newNode->name,name);
    newNode->left=newNode->right=NULL;
    return newNode;
}

node*insertTree(node*root,int id,char*name){
    if(!root)return createNode(id,name);
    else if(id<root->id)root->left=insertTree(root->left,id,name);
    else root->right=insertTree(root->right,id,name);
    return root;
}

void inOrder(node*root){
    if(!root)return;
    inOrder(root->left);
    printf("BN%.4d - %s\n",root->id,root->name);
    inOrder(root->right);
}

int main(){
    node*root=NULL;
    int n;scanf("%d",&n);getchar();
    char name[40];
    int id;
    for(int i=0;i<n;i++){   
        scanf(" %d %[^\n]",&id,name);
        root=insertTree(root,id,name);
    }
    puts("");
    inOrder(root);

    return 0;
}

/*
10
67 Craig Jones
29 Joey Jordison
798 Shawn Crahan
1 Sid Wilson
367 Paul Gray
8512 Mick Thomson
9 Corey Taylor
4876 Greg Welts
10 Oliver Sykes
113 Jordan Fish
*/