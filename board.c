#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void CreateBoard(Piece* Tablero[8][8]){
   int i, j;
   int OrderPieces[8] = {1,2,3,5,4,3,2,1};

   for(i = 0; i < 8; i++){
      int piece = 0;
      for(j = 0; j < 8; j++){
         if(i == 0){
            Tablero[i][j] = malloc(sizeof(Piece));
            Tablero[i][j]->type = OrderPieces[piece];
            Tablero[i][j]->x = i;
            Tablero[i][j]->y = j;
            Tablero[i][j]->player = 0;
            if(Tablero[i][j]->type == king || Tablero[i][j]->type == rook){
               Tablero[i][j]->initpos = 1;
            }
            else{
               Tablero[i][j]->initpos = 0;
            }
            piece++;
         }
         else if(i == 1){
            Tablero[i][j] = malloc(sizeof(Piece));
            Tablero[i][j]->type = pawn;
            Tablero[i][j]->x = i;
            Tablero[i][j]->y = j;
            Tablero[i][j]->initpos = 1;
            Tablero[i][j]->player = 0;
         }
         else if(i > 1  && i < 6){
            Tablero[i][j] = malloc(sizeof(Piece));
            Tablero[i][j]->type = symbol;
            Tablero[i][j]->x = i;
            Tablero[i][j]->y = j;
            Tablero[i][j]->initpos = 0;
            Tablero[i][j]->player = 3;
         }
         else if(i == 6){
            Tablero[i][j] = malloc(sizeof(Piece));
            Tablero[i][j]->type = pawn;
            Tablero[i][j]->x = i;
            Tablero[i][j]->y = j;
            Tablero[i][j]->initpos = 1;
            Tablero[i][j]->player = 1;
         }
         else {
            Tablero[i][j] = malloc(sizeof(Piece));
            Tablero[i][j]->type = OrderPieces[piece];
            Tablero[i][j]->x = i;
            Tablero[i][j]->y = j;
            Tablero[i][j]->player = 1;
            if(Tablero[i][j]->type == king || Tablero[i][j]->type == rook){
               Tablero[i][j]->initpos = 1;
            }
            else{
               Tablero[i][j]->initpos = 0;
            }
            piece++;
         }
      }
   }
}

void PrintBoard(Piece* Tablero[8][8]){
   int i, j;
   for(i = 0; i < 8; i++){
      for(j = 0; j < 8; j++){
         if(Tablero[i][j]->type == king)
            printf("K ");
         if(Tablero[i][j]->type == pawn)
            printf("P ");
         if(Tablero[i][j]->type == rook)
            printf("R ");
         if(Tablero[i][j]->type == knight)
            printf("C ");
         if(Tablero[i][j]->type == queen)
            printf("Q ");
         if(Tablero[i][j]->type == bishop)
            printf("B ");
         if(Tablero[i][j]->type == symbol)
            printf("· ");
      }
      printf("\n");
   }
}