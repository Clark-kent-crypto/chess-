#include<stdio.h>
#include<stdlib.h>
#include"chess_board.h"
#include"chess_piece.h"
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define BLACK 'b'
#define WHITE 'w'
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define ALL 'A'
// chess_board=((*chess_board)[8])malloc(8*sizeof(char));
char (*chess_board)[8]=NULL;

typedef struct pawn{
    int moving_distance;
    char moving_direction;
    int current_position[2];
    char color;
    char piece_name;


}pawn;
typedef struct knight{
    int moving_distance;
    char moving_direction;
    int current_position[2];
    char color;


}knight;
typedef struct bishop{
    int moving_distance;
   char moving_direction;
    int current_position[2];
    char color;

}bishop;
typedef struct rook{
    int moving_distance;
    char moving_direction;
    int current_position[2];
    char color;
}rook;
typedef struct king{
    int moving_distance;
    char moving_direction;
    int current_position[2];
    char color;
} king;
struct chess_game{
    pawn* b1;
    pawn* b2;
    pawn* b3;
    pawn* b4;
    pawn* b5;
    pawn* b6;
    pawn* b7;
    pawn* b8;
    knight* bL;
    knight* bR;
    bishop* bbL;
    bishop* bbR;
    rook* brR;
    rook* brL;
    king* b;

    

    

    pawn* w1;
    pawn* w2;
    pawn* w3;
    pawn* w4;
    pawn* w5;
    pawn* w6;
    pawn* w7;
    pawn* w8;
    knight* wR;
    knight* wL;
    bishop* wbR;
    bishop* wbL;
    rook* wrR;
    rook* wrL;
    king* w;

    int turn_tracker;
    // char (*board_state)[8];

};
 pawn* pawn_init(char color,int x_position){
    if(color!='b' && color!='w'){
        printf("You can not define that as color");
        return NULL;
    }
    pawn* new=(pawn*)malloc(sizeof(pawn));
    if(new==NULL){
        printf("Memory allocation failed !!");
        return NULL;
    }
    new->color=color;
    if(color=='w'){
        new->current_position[1]=7;
    }
    if(color=='b'){
        new->current_position[1]=2;
    }
    new->current_position[0]=x_position;
    new->moving_direction=FORWARD;
    new->moving_distance=1;
    new->piece_name='P';
    return new;
    

    
}
king* king_init(char color){
    if(color!='b' && color!='w'){
        return NULL;
    }
    king* new_king=(king*)malloc(sizeof(king));
    new_king->color=color;
    new_king->current_position[0]=5;
    new_king->moving_direction=ALL;
    if(color==BLACK){
    new_king->current_position[1]=0;
    }else{
        new_king->current_position[0]=7;
    }
    return new_king;
}
struct chess_game* game_init(){
    struct chess_game* newGame=(struct chess_game*)malloc(sizeof(struct chess_game));
    newGame->b1=pawn_init(BLACK,A);
    newGame->b2=pawn_init(BLACK,B);
    newGame->b3=pawn_init(BLACK,C);
    newGame->b4=pawn_init(BLACK,D);
    newGame->b5=pawn_init(BLACK,E);
    newGame->b6=pawn_init(BLACK,F);
    newGame->b7=pawn_init(BLACK,G);
    newGame->b8=pawn_init(BLACK,H);
    // newGame->board_state=(char(*)[8])malloc(8*sizeof(char));
    chess_board=malloc(8*sizeof(char[8]));
    chess_board[1][0]=newGame->b1->piece_name;
    chess_board[1][1]=newGame->b2->piece_name;
    chess_board[1][2]=newGame->b3->piece_name;
    chess_board[1][3]=newGame->b4->piece_name;
    chess_board[1][4]=newGame->b5->piece_name;
    chess_board[1][5]=newGame->b6->piece_name;
    chess_board[1][6]=newGame->b7->piece_name;
    chess_board[1][7]=newGame->b8->piece_name;    

}
void game_board(struct chess_game* game){
    
    printf("=========================================\n");
    printf("|| %c || %c || %c ||%c || %c || %c || %c || %c ||\n",A8,B8,C8,D8,E8,F8,G8,H8);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||\n",A7,B7,C7,D7,E7,F7,G7,H7);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||\n",A6,B6,C6,D6,E6,F6,G6,H6);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||\n",A5,B5,C5,D5,E5,F5,G5,H5);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||\n",A4,B4,C4,D4,E4,F4,G4,H4);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||\n",A3,B3,C3,D3,E3,F3,G3,H3);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||\n",A2,B2,C2,D2,E2,F2,G2,H2);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||\n",A1,B1,C1,D1,E1,F1,G1,H1);
    printf("=========================================\n");
}
int main(){
    struct chess_game* game=game_init();
    game_board(game);
    return 0;
}
