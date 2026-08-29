#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack_For_chess.h"
int isFULL(stack* new_stack){
    if(new_stack->top==NULL){

    }

}
int isEmpty(stack* new_stack){
    if(new_stack->top==NULL){
        return true ;
    }
    return false;

}
stack* stack_init(int size){
    stack* new=(stack*)malloc(sizeof(stack));
    if(new==NULL){
        printf("Memory Allocation Failed!!\n");
        return NULL;
    }
    new->size=size;
    new->top=NULL;
    return new;
}
void stack_destroy(stack* new_stack){
    struct node* p=new_stack->top;
    while(p!=NULL){
        struct node* temp=p;
        p=p->next;
        free(temp);
    }
    free(new_stack);
}
int push(stack* new_stack,piece* c_piece){
    struct node* p=new_stack->top;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Memory Allocation Failed !!\n");
        return 0;
    }
    ptr->data=c_piece;
    ptr->next=p;
    new_stack->top=ptr;
    return 1;


}
piece* pop(stack* new_stack){
    struct node* p=new_stack->top;
    if(isEmpty(new_stack)){
        printf("Stack UnderFlow!!\n");;
        return NULL;
    }
    piece* temp=p->data;
    new_stack->top=p->next;
    free(p);
    return temp;



}
