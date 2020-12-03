
#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct positionking{
	int player;

	int BKx;
	int BKy;
	int BKcheck;

	int WKx;
	int WKy;
	int WKcheck;
}PosKing;

void isWhiteKinginCheck(Piece* Tablero[8][8], PosKing* PKing);

void Pawn(Piece* Tablero[8][8], int, int, int, int*);
void Rook(Piece* Tablero[8][8], int, int, int, int*);
void Bishop(Piece* Tablero[8][8], int, int, int, int*);
void Knight(Piece* Tablero[8][8], int, int, int, int*);
void Queen(Piece* Tablero[8][8], int, int, int, int*);
void King(Piece* Tablero[8][8], int, int, int, int*, PosKing* PKing);

void InitGame(Piece* Tablero[8][8], FILE*, PosKing* PKing);

#endif