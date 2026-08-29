#include<stdio.h>
#include<stdlib.h>
#include"input_function.h"
#include"chess_piece.h"
#include<stdbool.h>

#define INPUT_SIZE 3
#define MAX_POSITIONS 8
#define X 0
#define Y 1
void parser_for_chess(struct chess_game* game){
    int Yposition;
    char Xposition;
    char input_var[INPUT_SIZE+1];// plus 1 for null terminator
    printf("Enter your choice of move :");
    scanf(" %s",&input_var);//suppose user input is A-7
    Xposition=input_var[0];
    Yposition=input_var[2];
    int* arr=(int*)malloc(2*sizeof(int));
    char new_arr[2]={Xposition,Yposition};
    translate_position(new_arr,arr);
    game->move_position_x=arr[X];
    game->move_position_y=arr[Y];
    

}
void translate_position(char arr[2],int *pReturnArr){
    char all_possible_positionX[MAX_POSITIONS]={A,B,C,D,E,F,G,H};
    char all_possible_position_inputX[MAX_POSITIONS]={'A','B','C','D','E','F','G','H'};

    char all_possible_positionY[MAX_POSITIONS]={'1','2','3','4','5','6','7','8'};
    bool X_Taken=false;//checking if the x inputs are translated 
    bool Y_Taken=false;//checking if the y inputs are transalted 
    
    for(int i=0;i<MAX_POSITIONS;i++){

        if(X_Taken && Y_Taken){
            return;
        }
        if(arr[X]==all_possible_position_inputX[i]){
            *(pReturnArr+X)=all_possible_positionX[i];
            X_Taken=true;

        }
        if(arr[Y]==all_possible_positionY[i]){
            *(pReturnArr+Y)=i+1;//as the actual position is 1 more than the index 
            Y_Taken=true;
        }
    }
  

}