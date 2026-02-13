#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

typedef struct dob{
    int day,month,year;
}dob;

struct node{
    char id[10],name[100];
    struct dob dob;
    struct node*left,*right;
};

typedef struct node node;

node*createNode(char*id,char*name,dob dmy){
    node*newN=(node*)malloc(sizeof(node));
    strcpy(newN->name,name);
    strcpy(newN->id,id);
    newN->dob=dmy;
    newN->left=newN->right=NULL;
    return newN;
}

node*insert(node*root,char*id,char*name,dob dmy){
    if(!root)return createNode(id,name,dmy);
    int cmp=strcmp(id,root->id);
    if(cmp<0)root->left=insert(root->left,id,name,dmy);
    else root->right=insert(root->right,id,name,dmy);
    return root;
}

node*search(node*root,char*id){
    if(!root)return NULL;
    int cmp=strcmp(id,root->id);
    if(cmp==0)return root;
    return search((cmp<0)?root->left:root->right,id);
}

node*pop(node*root,char*id){
    if(!root)return NULL;
    int cmp=strcmp(id,root->id);
    if(cmp<0)root->left=pop(root->left,id);
    else if(cmp>0)root->right=pop(root->right,id);
    else{
        if(!root->left||!root->right){
            node*temp=root->left?root->left:root->right;
            free(root);
            return temp;
        }else{
            node*temp=root->left;
            while(temp->right)temp=temp->right;
            strcpy(root->id,temp->id);
            root->left=pop(root->left,temp->id);
        }
    }
    return root;
}

void inOrder(node*root){
    if(!root)return;
    inOrder(root->left);
    printf("%s %s %d-%d-%d\n",root->name,root->id,root->dob.day,root->dob.month,root->dob.year);
    inOrder(root->right);
}

void genId(char*id,char*name){
    id[0]=toupper(name[0]);
    id[1]=toupper(name[1]);
    for(int i=2;i<5;i++){
        id[i]=rand()%10+'0';
    }
    id[5]='\0';
}

node*insertName(node*root){
    char name[100],id[10];
    dob temp;

    do{
        printf("Input Name[<30]: ");
        scanf(" %[^\n]",name);getchar();
        }while(strlen(name)>30);

    genId(id,name);
    
    do{
        printf("Input day:");
        scanf("%d",&temp.day);getchar();
    }while(temp.day>31);

    do{
        printf("Input month:");
        scanf("%d",&temp.month);getchar();
    }while(temp.month>12);

    do{
        printf("Input year:");
        scanf("%d",&temp.year);getchar();
    }while(temp.year<1900||temp.year>2026);

    return insert(root,id,name,temp);
}

node*update(node*root,char id[]){
    node*curr=search(root,id);
    if(!curr)printf("Id tidak ditemukan\n");
    else{
        char name[100];
        dob temp;

        do{
            printf("Input Name[<30]: ");
            scanf(" %[^\n]",name);getchar();
        }while(strlen(name)>30);

        do{
            printf("Input day:");
            scanf("%d",&temp.day);getchar();
        }while(temp.day>31);

        do{
            printf("Input month:");
            scanf("%d",&temp.month);getchar();
        }while(temp.month>12);

        do{
            printf("Input year:");
            scanf("%d",&temp.year);getchar();
        }while(temp.year<1900||temp.year>2026);

        strcpy(curr->name,name);
        curr->dob=temp;
        printf("Update Success\n");
    }
    return root;
}

int main(){
    srand(time(NULL));
    int ipt=0;
    node*root=NULL;
    char id[10];

    do{
        puts("1. Insert");
        puts("2. Update");
        puts("3. View");
        puts("4. Delete");
        puts("0. Exit");
        scanf("%d",&ipt);getchar();

        switch(ipt){
            case 1:
                root=insertName(root);
                getchar();
            break;

            case 2:
                printf("Masukan ID: ");
                scanf(" %s",id);
                root=update(root,id);
                getchar();
            break;

            case 3:
                inOrder(root);
                getchar();
            break;

            case 4:
                printf("Masukan ID: ");
                scanf(" %s",id);
                root=pop(root,id);
            break;

            case 0:
                puts("Exit");
                return 0;
            break;

            default:
                puts("Input Between 1-5\n");
            break;
        }
    }while(ipt!=0);

    return 0;
}

