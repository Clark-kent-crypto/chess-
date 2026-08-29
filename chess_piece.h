#ifndef CHESS_PIECE
#define CHESS_PIECE
struct chess_game{
    piece* b_pawn1;
    piece* b_pawn2;
    piece* b_pawn3;
    piece* b_pawn4;
    piece* b_pawn5;
    piece* b_pawn6;
    piece* b_pawn7;
    piece* b_pawn8;
    piece* b_knight_L;
    piece* b_kngiht_R;
    piece* b_bishop_L;
    piece* b_bishop_R;
    piece* b_rook_R;
    piece* b_rook_L;
    piece* b_king;
    piece* b_queen;


    piece* w_pawn1;
    piece* w_pawn2;
    piece* w_pawn3;
    piece* w_pawn4;
    piece* w_pawn5;
    piece* w_pawn6;
    piece* w_pawn7;
    piece* w_pawn8;
    piece* w_knight_L;
    piece* w_kngiht_R;
    piece* w_bishop_L;
    piece* w_bishop_R;
    piece* w_rook_R;
    piece* w_rook_L;
    piece* w_king;
    piece* w_queen;


    

      

    int turn_tracker;
    int run_state;
    int move_position_x;
    int move_position_y;
    // char (*board_state)[8];

};
typedef struct piece{
       int moving_distance;
    char moving_direction;
    int current_position[2];
    char color;
    char piece_name;
    char piece_type;

}piece;
#define KING 'K'
#define QUEEN 'Q'
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7



#endif