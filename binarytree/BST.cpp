#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node*left,*right;
};
typedef struct node node;

node*createNode(int val){
    node*newNode=(node*)malloc(sizeof(node));
    newNode->val=val;
    newNode->left=newNode->right=NULL;
    return newNode;
}

node*insertTree(node*root,int val){
    if(!root)return createNode(val);
    else if(val<root->val)root->left=insertTree(root->left,val);
    else root->right=insertTree(root->right,val);
    return root;
}

// int searchTree(node*root,int x){
//     if(!root)return 0;
//     if(root->val==x)return 1;
//     else if(x<root->val)return searchTree(root->left,x);
//     else return searchTree(root->right,x);
// }

node*searchTree(node*root,int x){
    if(!root)return NULL;
    if(root->val==x)return root;
    else if(x<root->val)return searchTree(root->left,x);
    else return searchTree(root->right,x);
}

node*deleteTree(node*root,int val){
    if(!root)return NULL;
    if(val<root->val)root->left=deleteTree(root->left,val);
    else if(val>root->val)root->right=deleteTree(root->right,val);
    else{
        // if(!root->left||!root->right){//versi singkat
        //     node*temp=root->left?root->left:root->right;
        //     free(root);
        //     return temp;
        // }
        if(!root->left&&!root->right){//gak ada anak
            free(root);
            return NULL;
        }else if(!root->left){//ada anak kanan doang
            node*temp=root->right;
            free(root);
            return temp;
        }else if(!root->right){//ada anak kiri doang
            node*temp=root->left;
            free(root);
            return temp;
        }else{
            node*temp=root->left;//predecessor/terbesar di kiri
            while(temp->right)temp=temp->right;
            root->val=temp->val;
            root->left=deleteTree(root->left,temp->val);

            // node*temp=root->right;//successor/terkecil di kanan
            // while(temp->left)temp=temp->left;
            // root->val=temp->val;
            // root->right=deleteTree(root->right,temp->val);
        }
    }
    return root;
}

void printTree(node*root,int space){
    if(!root)return;
    space+=5;
    printTree(root->right,space);
    for(int i=5;i<space;i++)printf(" ");
    printf("%d\n",root->val);
    printTree(root->left,space);
}

int main(){
    node*root=NULL;
    root=insertTree(root,10);
    root=insertTree(root,5);
    root=insertTree(root,20);
    root=insertTree(root,15);
    root=insertTree(root,3);
    root=insertTree(root,6);
    root=insertTree(root,30);
    root=insertTree(root,2);
    root=insertTree(root,4);
    root=insertTree(root,7);

    // printTree(root,0);
    // int x=searchTree(root,20);
    // x?printf("Ada\n"):printf("Gak Ada\n");

    // node*x=searchTree(root,20);
    // if(!x)printf("Gak ada\n");
    // else printf("Ada angka %d\n",x->val);

    root=deleteTree(root,5);
    printTree(root,0);
    puts("====================");
    root=deleteTree(root,10);
    printTree(root,0);
    puts("====================");
    root=deleteTree(root,7);
    printTree(root,0);
    puts("====================");
    root=deleteTree(root,20);
    printTree(root,0);
    puts("====================");
    root=deleteTree(root,6);
    printTree(root,0);
    puts("====================");
    root=deleteTree(root,4);
    printTree(root,0);
    puts("====================");

    return 0;
}