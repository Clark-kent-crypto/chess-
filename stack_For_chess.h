#ifndef STACK
#define STACK
#include"chess_piece.h"
struct node{
    piece* data;
    struct node* next;
};
typedef struct stack{
    struct node* top;
    int size;

} stack;
int isFULL(stack* new_stack);//dont really need this right now as my stack currently does not have a limit
int isEmpty(stack* new_stack);//checks if the stack is Empty
int push(stack* new_stack,piece* c_piece);//push data inside the satck
piece* pop(stack* new_stack);//pop data out of the stack
stack* stack_init(int size);// initilizes the stack
void stack_destroy(stack* new_stack);//destroy and free all the memory used for the stack
#endif