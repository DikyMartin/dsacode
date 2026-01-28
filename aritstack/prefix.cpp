#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

struct node{
    int val;
    struct node*next;
}*head=NULL;
typedef struct node list;

void pushHead(int val){
    list*newList=(list*)malloc(sizeof(list));
    newList->val=val;
    newList->next=head;
    head=newList;
}

int popHead(){
    if(!head)return 0;
    int val=head->val;
    list*temp=head;
    head=head->next;
    
    free(temp);
    return val;
}

int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int prefix(char*expr){
    for(int i=strlen(expr)-1;i>=0;i--){
        char c=expr[i];

        if(isdigit(c))pushHead(c - '0'); 
        else if(isOperator(c)){
            int op1=popHead(); 
            int op2=popHead();
            
            int result=0;
            switch(c){
                case '+': 
                    result=op1+op2; break;
                case '-': 
                    result=op1-op2; break;
                case '*': 
                    result=op1*op2; break;
                case '/': 
                    result=op1/op2; break;
            }
            pushHead(result);
        }
    }
    return popHead();
}

int main(){
    char input[]="*/843"; 

    int hasil=prefix(input);

    printf("%d\n", hasil);

    return 0;
}

