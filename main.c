#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include <string.h>
#include "game.h"

int main()
{
   int NewGame = 0;
   int init = 0;

   FILE* Game;

   //FILE* Board;

   Piece* Tablero[8][8];

	PosKing* PKing;

   while(init != 1){
      //printf("Do you want to new game or upload game ? (New game = 0) (Upload game = 1) ");
      //scanf("%d", &NewGame);

      if(NewGame == 0){
         CreateBoard(Tablero);
			PKing->player = 1;
		   PKing->BKx = 5;
			PKing->BKy = 1;
		   PKing->BKcheck = 0;
		   PKing->WKx = 5;
			PKing->WKy = 8;
			PKing->WKcheck = 0;
         InitGame(Tablero, Game, PKing);
         break;
      }
      else if(NewGame == 1){
         /*
         char tmproot[1000] = "";
         char fullroot[1000] = "";
         char slot[1];
         printf("Escribe el numero del slot de guardado (Solo poner no. de slot)  ");
         scanf("%s", slot);

			strcat(tmproot, "./Guardado");
         strcat(tmproot, slot);
			strcat(fullroot, tmproot);
         strcat(fullroot, ".bin");
         Game = fopen(fullroot, "rb");
         rewind(Game);
			fread(PKing, sizeof(PosKing), 1, Game);
         fclose(Game);

         char Boardtmproot[1000] = "";
         char Boardroot[1000] = "";
         int i = 0;
         int j = 0;
         int pl, x, y, pos, tpe;
         strcat(Boardtmproot, "./Tablero");
         strcat(Boardtmproot, slot);
			strcat(Boardroot, Boardtmproot);
         strcat(Boardroot, ".bin");
         Board = fopen(Boardroot,"rb");
         rewind(Board);
         while(fscanf(Board,"%d%d%d%d%d", &pl, &x, &y, &pos, &tpe) != EOF){
            Tablero[i][j]->player = pl;
            Tablero[i][j]->x = x;
            Tablero[i][j]->y = y;
            Tablero[i][j]->initpos = pos;
            Tablero[i][j]->type = tpe;
            j++;
            if(j == 8){
               i++;
               j = 0;
            }
         }
         fclose(Board);

         InitGame(Tablero, Game, Board, PKing);
         */
         break;
      }
      else{
         printf("Invalid command\n");
      }
   }

   return 0;
}