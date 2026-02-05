#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    char code[50];
    int price;
    struct node*left,*right;
};

typedef struct node node;

node*createNode(char*code,int price){
    node*newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->code,code);
    newNode->price=price;
    newNode->left=newNode->right=NULL;
    return newNode;
}

int getLevel(node*root){
    if(!root)return 0;
    int leftH=getLevel(root->left);
    int rightH=getLevel(root->right);
    return(leftH>rightH?leftH:rightH)+1;
}

node*searchTree(node*root,char*code){
    if(!root)return NULL;
    if(strcmp(root->code,code)==0)return root;
    return(strcmp(code,root->code)<0)?searchTree(root->left,code):searchTree(root->right,code);
}

node*insertTree(node*root,char*code,int price){
    if(!root)return createNode(code,price);
    else if(strcmp(code,root->code)<0)root->left=insertTree(root->left,code,price);
    else root->right=insertTree(root->right,code,price);
    return root;
}

int validateCode(char*code){
    if(strlen(code)!=5)return 0;
    if(code[0]!='N')return 0;
    if(code[1]<'1'||code[1]>'9')return 0; 
    for(int i=2;i<5;i++) if(code[i]<'0'||code[i]>'9')return 0; 
    return 1;
}

void freeTree(node*root) {
    if(!root)return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void preOrder(node*root){
    if(!root)return;
    printf("%s [ $ %d ]\n",root->code,root->price); 
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node*root){
    if(!root)return;
    inOrder(root->left);
    printf("%s [ $ %d ]\n",root->code,root->price);
    inOrder(root->right);
}

void postOrder(node*root){
    if(!root)return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%s [ $ %d ]\n",root->code,root->price);
}

int main(){
    node*root=NULL;
    int input;
    do{
        printf("NOKIYEM CELLULAR PHONE\n");
        printf("1. Add New Phone\n");
        printf("2. Update Phone Price\n");
        printf("3. InOrder, PreOrder, PostOrder\n");
        printf("4. Exit\n");
        printf(">>> Input: ");
        scanf("%d",&input);getchar();

        switch(input){
            case 1: {
                if(getLevel(root)>=4) {
                    printf("Maximum Tree Level is 4\n\n");
                    break;
                }

                char code[50];
                int price;
                do{
                    printf("Input Phone Code N[1-9][0-9][0-9][0-9]: ");
                    scanf("%s",code);getchar();
                }while(!validateCode(code));

                if(searchTree(root,code)){ 
                    printf("Add New Phone Failure\n");
                    printf("Phone Code Already Exists\n\n");
                    break;
                }

                do{
                    printf("Input Phone Price [$50..$999]: ");
                    scanf("%d",&price);getchar();
                }while(price<50||price>999); 

                root=insertTree(root,code,price);
                printf("\n Add New Phone Success \n\n");
                break;
            }
                
            case 2: {
                char code[50];
                printf("Input Phone Code N[1-9][0-9][0-9][0-9]: ");
                scanf("%s",code);getchar();
                
                node*temp=searchTree(root,code);
                if(!temp)printf(" Phone Code is Not Found \n\n");
                else{
                    printf("\nPhone Code : %s\n",temp->code);
                    printf("Phone Price  : $ %d\n",temp->price);
                    int price;
                    do{
                        printf("Input New Phone Price [$50..$999]: ");
                        scanf("%d",&price);getchar();
                    }while(price<50||price>999); 
                    
                    temp->price=price;
                    printf("\nUpdate Phone Price Success\n\n");
                }
                break;
            }

            case 3:
                if(!root)printf("There is No Phone in The Tree\n\n");
                else{
                    printf("\nPreorder\n");
                    preOrder(root);
                    printf("\nInorder\n");
                    inOrder(root);
                    printf("\nPostorder\n");
                    postOrder(root);
                    printf("\n");
                }
                break;
            case 4:
                freeTree(root);
                printf("Program ends.\n");
                break;
        }
    }while(input!=4);

    return 0;
}