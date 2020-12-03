#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <stdlib.h>

typedef enum Pieces{pawn,rook,knight,bishop,king,queen,symbol}PIECES;

typedef struct piezas{
   int player; // Determine which player the piece belongs to
   int x;
   int y;
   int initpos; // this flag determine the initial position of king, pawn and rook
   PIECES type; // type of piece
}Piece;

void CreateBoard(Piece* Tablero[8][8]); // create chess board
void PrintBoard(Piece* Tablero[8][8]); // print chess board

#endif