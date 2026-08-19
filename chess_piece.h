#ifndef CHESS_PIECE
#define CHESS_PIECE
typedef struct piece{
       int moving_distance;
    char moving_direction;
    int current_position[2];
    char color;
    char piece_name;

}piece;
#define KING 'K'
#define QUEEN 'Q'
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'


#endif