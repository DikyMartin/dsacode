#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct node{
    char name[30];
    int age;
};
typedef struct node node;

node*hashTable[SIZE]={NULL};
int cnt=0;

node*createNode(char name[],int age){
    node*newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->name,name);
    newNode->age=age;
    return newNode;
}

int getKey(char*name){
    int asci=0;
    for(int i=0;i<strlen(name);i++)asci+=name[i];
    return asci;
}

void insertNode(char name[],int age){
    int hashKey=getKey(name);
    int idx=hashKey%SIZE;
    
    if(cnt==SIZE)return;
    while(hashTable[idx])idx=(idx+1)%SIZE;
    
    hashTable[idx]=createNode(name,age);
    cnt++;
}

int search(char*name){
    int hashKey=getKey(name);
    int idx=hashKey%SIZE;

    do{
        if(hashTable[idx]&&strcmp(hashTable[idx]->name,name)==0)return idx;
        idx=(idx+1)%SIZE;
    }while(idx!=hashKey%SIZE);

    printf("Not Found\n");
    return -1;
}

void pop(char*name){
    int idx=search(name);
    if(idx==-1){
        printf("Data Not found\n");
        return;
    }
    free(hashTable[idx]);
    hashTable[idx]=NULL;
    cnt--;
}

void printTable(){
    for(int i=0;i<SIZE;i++){
        if(hashTable[i])printf("[%d] - %s (%d)\n",i,hashTable[i]->name,hashTable[i]->age);
        else printf("[%d] - No data\n", i);
    }
}

int main(){
    insertNode("Louis",10);
    insertNode("Gazent",6);
    insertNode("Rico",8);

    pop("Louis");
    printTable();

    int idx=search("Rico");
    if(idx!=-1){
        node*data=hashTable[idx];
        printf("%s %d",data->name,data->age);
    }else printf("No data\n");

    return 0;
}