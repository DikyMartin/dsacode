#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char*name; // tidak pakai array of char / statis
    struct node*next;
}*head=NULL;

typedef struct node list;

void pushHead(const char*name){ // akan muncul warning ungu, kalau mau ilangin pakai const
    list*newList=(list*)malloc(sizeof(list));
    // newList->name=strdup(name); // bisa pakai strdup kalau pakai devc
    newList->name=(char*)malloc(strlen(name)+1); // Alokasi memori dinamis untuk menampung string
    strcpy(newList->name,name);  // jika tidak pakai array of char tidak bisa langsung strcpy
    newList->next=head;
    head=newList;
}

void popHead(){
    if(!head)return;
    list*curr=head;
    head=head->next;
    free(curr);
}

void printList(){
    list*curr=head;
    while(curr){
        printf("%s -> ",curr->name);
        curr=curr->next;
    }
    printf("NULL\n");
}

int main(){
    pushHead("Tinn");
    pushHead("Asep");
    pushHead("Aje");
    pushHead("Ben");

    printList();
    popHead();
    printList();

    return 0;
}