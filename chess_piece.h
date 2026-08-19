#ifndef CHESS_PIECE
#define CHESS_PIECE
typedef struct piece{
       int moving_distance;
    char moving_direction;
    int current_position[2];
    char color;
    char piece_name;

}piece;
#define KING 'K'||'k'
#define QUEEN 'Q'||'q'
#define PAWN 'P'||'p'
#define KNIGHT 'N'||'n'
#define BISHOP 'B'||'b'
#define ROOK 'R'||'r'


#endif