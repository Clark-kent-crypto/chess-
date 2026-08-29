#ifndef STACKLIST_H
#define STACKLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"chess_piece.h"
struct node{//each node of a list
    int data;
    char cdata;
    struct node* next;
};
struct stack{//used to declare a stack
    struct node* listhead;
    int size;
    int counter;
};
struct stack* stack_init(int size);//used to initialize a stack used along side a struct stack* variable
void traverseList(struct stack* s);//used to traverse the whole list with int data types
int push(struct stack* s,int data);//used to push int data  to the stack
int pop(struct stack* s);//pops int data from the stack
bool isFUll(struct stack* s);//checks if the list is empty i know naming is bit contradictory
int  peek(struct stack* s,int pos);//looks into data at a particular node
char peekTop(struct stack* s);//looks into data at the top of the stack
void stackDestroy(struct stack* s);
void traverseList(struct stack* s){
    struct node* p=s->listhead;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}
int push(struct stack* s,int data){
    if(s->counter==s->size){
        printf("The stack is Full\n");
        return 0;
    }
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Memory allocation failed!!\n");
        return 0;
    }
    struct node* p=s->listhead;
    ptr->data=data;
    ptr->next=p;
    s->listhead=ptr;
    s->counter++;
    return 1;//its indicator that the programme ran fine 

}
int pop(struct stack* s){
    if(s->listhead==NULL){
        printf("Stack Underflow!!\n");
        return -1;
    }
    struct node* p=s->listhead;
    s->listhead=p->next;
    int data=p->data;
    s->counter--;
    free(p);
    return data;//its sending back the data that has been poped

    
}
bool isFUll(struct stack* s){
    struct node* p=s->listhead;
    if(p==NULL){
        // printf("The Stack is empty\n");
        return false;
    }
    else{
        return true;

    }
}
int  peek(struct stack* s,int pos){
    struct node* p=s->listhead;
    int i=0;
    while(i!=pos){
        p=p->next;
        i++;
    }
    int returnValue;
    returnValue=p->data;
    return returnValue;

}
int pushc(struct stack* s,char cdata){
   
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=s->listhead;
    ptr->next=p;
    ptr->cdata=cdata;
    s->listhead=ptr;
    return 1;

}
int popc(struct stack*s){
    struct node* p=s->listhead;
    if(!isFUll(s)){
        // printf("Stack Underflow!!\n");
        return 0;
    }
    s->listhead=p->next;
    char cd=p->cdata;
    free(p);
    return cd;
    

  
}
void traverseListC(struct stack* s){
    struct node* p=s->listhead;
    if(p=NULL){
        printf("stack is empty !!\n");
        return;
    }
    while(p!=NULL){
        printf("%c\n",p->cdata);
        p=p->next;
    }
}
char peekTop(struct stack* s){
    struct node* p=s->listhead;
    char returnValue=p->cdata;
    return returnValue;
}
int peekTopint(struct stack* s){
    struct node* p=s->listhead;
    int returnValue=p->data;
    return returnValue;
}
struct stack* stack_init( int size){
    struct stack* s =(struct stack*)malloc(sizeof(struct stack));
    
  
    
    s->listhead=NULL;
    s->size=size;
    s->counter=0;
    return s;
    
}
void stackDestroy(struct stack* s){
    struct node* p=s->listhead;
    while(p!=NULL){
        struct node* temp=p;
        p=p->next;
        free(temp);
    }
    free(s);
}
#endif