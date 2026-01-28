#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int val;
    struct node* next;
}*head=NULL;

typedef struct node list;

void push(int val){
    list*newList=(list*)malloc(sizeof(list));
    newList->val=val;
    newList->next=head;
    head=newList;
}

int pop(){
    if(!head)return 0;
    int val=head->val;
    list*curr=head;
    head=head->next;
    
    free(curr);
    return val;
}

int post(char* oper) {
    for(int i=0;i<strlen(oper);i++) {
        if(isdigit(oper[i]))push(oper[i]-'0');
        else {
            int val2=pop();
            int val1=pop();
            
            switch(oper[i]) {
                case '+': push(val1+val2); break;
                case '-': push(val1-val2); break;
                case '*': push(val1*val2); break;
                case '/': push(val1/val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char num[]="482+*";
    
    int result=post(num);
    printf("%d\n",result);

    return 0;
}