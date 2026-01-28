#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node*left,*right;
};
typedef struct node node;

node*createNode(int val){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->val=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node*insertTree(node*root,int x){
    if(!root)return createNode(x);
    if(x<root->val)root->left=insertTree(root->left, x);
    else root->right=insertTree(root->right,x);
    return root;
}

void preOrder(node*root) {
    if(!root)return;
    printf("%d ",root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node*root) {
    if(!root)return;
    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}

void postOrder(node*root) {
    if(!root)return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->val);
}

int search(node*root,int target){
    if(!root)return -1;

    if(root->val==target)return 1;
    else if(target>root->val)return search(root->right,target);
    else return search(root->left,target);
}


int main(){
    node*root=NULL;
    root=insertTree(root,30);
    root=insertTree(root,12);
    root=insertTree(root,54);
    root=insertTree(root,24);
    root=insertTree(root,64);

    preOrder(root);// print kiri kanan
    puts("");
    inOrder(root);// kiri print kanan
    puts("");
    postOrder(root);// kiri kanan print

    printf("\n%d",search(root,24));

    return 0;
}