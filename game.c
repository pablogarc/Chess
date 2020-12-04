#include "board.h"
#include "game.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void PawnCheckBlack(Piece* Tablero[8][8], PosKing* PKing){
   if(((PKing->BKy+1 > 0 && PKing->BKy+1 < 9) && (PKing->BKx+1 > 0 && PKing->BKx+1 < 9))){
      if((Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1+1]->type == pawn && Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1+1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if(((PKing->BKy+1 > 0 && PKing->BKy+1 < 9) && (PKing->BKx-1 > 0 && PKing->BKx-1 < 9))){
      if((Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1-1]->type == pawn && Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1-1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
}

void KingCheckBlack(Piece* Tablero[8][8], PosKing* PKing){
   if((PKing->BKy+1 > 0 && PKing->BKy+1 < 9) && (PKing->BKx+1 > 0 && PKing->BKx+1 < 9)){
      if((Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1+1]->type == king && Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1+1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy+1 > 0 && PKing->BKy+1 < 9) && (PKing->BKx-1 > 0 && PKing->BKx-1 < 9)){
      if((Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1-1]->type == king && Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1-1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if(PKing->BKy+1 > 0 && PKing->BKy+1 < 9){
      if((Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1]->type == king && Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if(PKing->BKx+1 > 0 && PKing->BKx+1 < 9){
      if((Tablero[(PKing->BKy)-1][(PKing->BKx)-1+1]->type == king && Tablero[(PKing->BKy)-1][(PKing->BKx)-1+1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy-1 > 0 && PKing->BKy-1 < 9) && (PKing->BKx+1 > 0 && PKing->BKx+1 < 9)){
      if((Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1+1]->type == king && Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1+1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy-1 > 0 && PKing->BKy-1 < 9)){
      if((Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1]->type == king && Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy-1 > 0 && PKing->BKy-1 < 9) && (PKing->BKx-1 > 0 && PKing->BKx-1 < 9)){
      if((Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1-1]->type == king && Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1-1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if(PKing->BKx-1 > 0 && PKing->BKx-1 < 9){
      if((Tablero[(PKing->BKy)-1][(PKing->BKx)-1-1]->type == king && Tablero[(PKing->BKy)-1][(PKing->BKx)-1-1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
}

void KnightCheckBlack(Piece* Tablero[8][8], PosKing* PKing){
   if((PKing->BKy+2 > 0 && PKing->BKy+2 < 9) && (PKing->BKx+1 > 0 && PKing->BKx+1 < 9)){
      if((Tablero[(PKing->BKy)-1+2][(PKing->BKx)-1+1]->type == knight && Tablero[(PKing->BKy)-1+2][(PKing->BKx)-1+1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy+2 > 0 && PKing->BKy+2 < 9) && (PKing->BKx-1 > 0 && PKing->BKx-1 < 9)){
      if((Tablero[(PKing->BKy)-1+2][(PKing->BKx)-1-1]->type == knight && Tablero[(PKing->BKy)-1+2][(PKing->BKx)-1-1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy-2 > 0 && PKing->BKy-2 < 9) && (PKing->BKx+1 > 0 && PKing->BKx+1 < 9)){
      if((Tablero[(PKing->BKy)-1-2][(PKing->BKx)-1+1]->type == knight && Tablero[(PKing->BKy)-1-2][(PKing->BKx)-1+1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy-2 > 0 && PKing->BKy-2 < 9) && (PKing->BKx-1 > 0 && PKing->BKx-1 < 9)){
      if((Tablero[(PKing->BKy)-1-2][(PKing->BKx)-1-1]->type == knight && Tablero[(PKing->BKy)-1-2][(PKing->BKx)-1-1]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy+1 > 0 && PKing->BKy+1 < 9) && (PKing->BKx+2 > 0 && PKing->BKx+2 < 9)){
      if((Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1+2]->type == knight && Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1+2]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy-1 > 0 && PKing->BKy-1 < 9) && (PKing->BKx+2 > 0 && PKing->BKx+2 < 9)){
      if((Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1+2]->type == knight && Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1+2]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy+1 > 0 && PKing->BKy+1 < 9) && (PKing->BKx-2 > 0 && PKing->BKx-2 < 9)){
      if((Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1-2]->type == knight && Tablero[(PKing->BKy)-1+1][(PKing->BKx)-1-2]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
   if((PKing->BKy-1 > 0 && PKing->BKy-1 < 9) && (PKing->BKx-2 > 0 && PKing->BKx-2 < 9)){
      if((Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1-2]->type == knight && Tablero[(PKing->BKy)-1-1][(PKing->BKx)-1-2]->player != 0)){
         PKing->BKcheck = 1;
         return;
      }
   }
}

void RQCheckBlack(Piece* Tablero[8][8], PosKing* PKing){
   for(int i = PKing->BKy+1; i < 9; i++){
		if((Tablero[-1+i][(PKing->BKx)-1]->type == queen && Tablero[-1+i][(PKing->BKx)-1]->player != 0) || (Tablero[-1+i][(PKing->BKx)-1]->type == rook && Tablero[-1+i][(PKing->BKx)-1]->player != 0)){
			PKing->BKcheck = 1;
         return;
		}
		if(Tablero[-1+i][(PKing->BKx)-1]->player == 0 || Tablero[-1+i][(PKing->BKx)-1]->type == rook || Tablero[-1+i][(PKing->BKx)-1]->type == knight || Tablero[-1+i][(PKing->BKx)-1]->type == pawn || Tablero[-1+i][(PKing->BKx)-1]->type == king){
			break;
		}
	}
	for(int i = PKing->BKy-1; i > 0; i--){
		if((Tablero[-1+i][(PKing->BKx)-1]->type == queen && Tablero[-1+i][(PKing->BKx)-1]->player != 0) || (Tablero[-1+i][(PKing->BKx)-1]->type == rook && Tablero[-1+i][(PKing->BKx)-1]->player != 0)){
			PKing->BKcheck = 1;
         return;
		}
		if(Tablero[-1+i][(PKing->BKx)-1]->player == 0 || Tablero[-1+i][(PKing->BKx)-1]->type == rook || Tablero[-1+i][(PKing->BKx)-1]->type == knight || Tablero[-1+i][(PKing->BKx)-1]->type == pawn || Tablero[-1+i][(PKing->BKx)-1]->type == king){
			break;
		}
	}
	for(int i = PKing->BKx+1; i < 9; i++){
		if((Tablero[(PKing->BKy)-1][i-1]->type == queen && Tablero[(PKing->BKy)-1][i-1]->player != 0) || (Tablero[(PKing->BKy)-1][i-1]->type == rook && Tablero[(PKing->BKy)-1][i-1]->player != 0)){
			PKing->BKcheck = 1;
         return;
		}
		if(Tablero[(PKing->BKy)-1][i-1]->player == 0 || Tablero[(PKing->BKy)-1][i-1]->type == rook || Tablero[(PKing->BKy)-1][i-1]->type == knight || Tablero[(PKing->BKy)-1][i-1]->type == pawn || Tablero[(PKing->BKy)-1][i-1]->type == king){
			break;
		}
	}
	for(int i = PKing->BKx-1; i > 0; i--){
		if((Tablero[(PKing->BKy)-1][i-1]->type == queen && Tablero[(PKing->BKy)-1][i-1]->player != 0) || (Tablero[(PKing->BKy)-1][i-1]->type == rook && Tablero[(PKing->BKy)-1][i-1]->player != 0)){
			PKing->BKcheck = 1;
         return;
		}
		if(Tablero[(PKing->BKy)-1][i-1]->player == 0 || Tablero[(PKing->BKy)-1][i-1]->type == rook || Tablero[(PKing->BKy)-1][i-1]->type == knight || Tablero[(PKing->BKy)-1][i-1]->type == pawn || Tablero[(PKing->BKy)-1][i-1]->type == king){
			break;
		}
	}
}

void BQCheckBlack(Piece* Tablero[8][8], PosKing* PKing){
	int r = PKing->BKx+1;
	for(int i = PKing->BKy+1; i < 9; i++){
		if(r > 8){
		   break;
	   }
		if((Tablero[-1+i][-1+r]->type == queen && Tablero[-1+i][-1+r]->player != 0) || (Tablero[-1+i][-1+r]->type == bishop && Tablero[-1+i][-1+r]->player != 0)){
			PKing->BKcheck = 1;
         return;
		}
		if(Tablero[-1+i][-1+r]->player == 0 || Tablero[-1+i][-1+r]->type == rook || Tablero[-1+i][-1+r]->type == knight || Tablero[-1+i][-1+r]->type == pawn || Tablero[-1+i][-1+r]->type == king){
			break;
		}
		r++;
	}
	r = PKing->BKx-1;
	for(int i = PKing->BKy+1; i < 9; i++){
		if(r < 1){
			break;
		}
		if((Tablero[-1+i][-1+r]->type == queen && Tablero[-1+i][-1+r]->player != 0) || (Tablero[-1+i][-1+r]->type == bishop && Tablero[-1+i][-1+r]->player != 0)){
			PKing->BKcheck = 1;
         return;
		}
		if(Tablero[-1+i][-1+r]->player == 0 || Tablero[-1+i][-1+r]->type == rook || Tablero[-1+i][-1+r]->type == knight || Tablero[-1+i][-1+r]->type == pawn || Tablero[-1+i][-1+r]->type == king){
			break;
		}
		r--;
	}
	r = PKing->BKx+1;
	for(int i = PKing->BKy-1; i > 0; i--){
		if(r > 8){
			break;
		}
		if((Tablero[-1+i][-1+r]->type == queen && Tablero[-1+i][-1+r]->player != 0) || (Tablero[-1+i][-1+r]->type == bishop && Tablero[-1+i][-1+r]->player != 0)){
			PKing->BKcheck = 1;
         return;
		}
		if(Tablero[-1+i][-1+r]->player == 0 || Tablero[-1+i][-1+r]->type == rook || Tablero[-1+i][-1+r]->type == knight || Tablero[-1+i][-1+r]->type == pawn || Tablero[-1+i][-1+r]->type == king){
			break;
		}
		r++;
	}
	r = PKing->BKx-1;
	for(int i = PKing->BKy-1; i > 0; i--){
		if(r < 1){
			break;
		}
		if((Tablero[-1+i][-1+r]->type == queen && Tablero[-1+i][-1+r]->player != 0) || (Tablero[-1+i][-1+r]->type == bishop && Tablero[-1+i][-1+r]->player != 0)){
			PKing->BKcheck = 1;
         return;
		}
		if(Tablero[-1+i][-1+r]->player == 0 || Tablero[-1+i][-1+r]->type == rook || Tablero[-1+i][-1+r]->type == knight || Tablero[-1+i][-1+r]->type == pawn || Tablero[-1+i][-1+r]->type == king){
			break;
		}
		r--;
	}
}

void PawnCheckWhite(Piece* Tablero[8][8], PosKing* PKing){
   if(((PKing->WKy+1 > 0 && PKing->WKy+1 < 9) && (PKing->WKx+1 > 0 && PKing->WKx+1 < 9))){
      if((Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1+1]->type == pawn && Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1+1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if(((PKing->WKy+1 > 0 && PKing->WKy+1 < 9) && (PKing->WKx-1 > 0 && PKing->WKx-1 < 9))){
      if((Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1-1]->type == pawn && Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1-1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
}

void KingCheckWhite(Piece* Tablero[8][8], PosKing* PKing){
   if((PKing->WKy+1 > 0 && PKing->WKy+1 < 9) && (PKing->WKx+1 > 0 && PKing->WKx+1 < 9)){
      if((Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1+1]->type == king && Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1+1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy+1 > 0 && PKing->WKy+1 < 9) && (PKing->WKx-1 > 0 && PKing->WKx-1 < 9)){
      if((Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1-1]->type == king && Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1-1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if(PKing->WKy+1 > 0 && PKing->WKy+1 < 9){
      if((Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1]->type == king && Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if(PKing->WKx+1 > 0 && PKing->WKx+1 < 9){
      if((Tablero[(PKing->WKy)-1][(PKing->WKx)-1+1]->type == king && Tablero[(PKing->WKy)-1][(PKing->WKx)-1+1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy-1 > 0 && PKing->WKy-1 < 9) && (PKing->WKx+1 > 0 && PKing->WKx+1 < 9)){
      if((Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1+1]->type == king && Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1+1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy-1 > 0 && PKing->WKy-1 < 9)){
      if((Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1]->type == king && Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy-1 > 0 && PKing->WKy-1 < 9) && (PKing->WKx-1 > 0 && PKing->WKx-1 < 9)){
      if((Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1-1]->type == king && Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1-1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if(PKing->WKx-1 > 0 && PKing->WKx-1 < 9){
      if((Tablero[(PKing->WKy)-1][(PKing->WKx)-1-1]->type == king && Tablero[(PKing->WKy)-1][(PKing->WKx)-1-1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
}

void KnightCheckWhite(Piece* Tablero[8][8], PosKing* PKing){
   if((PKing->WKy+2 > 0 && PKing->WKy+2 < 9) && (PKing->WKx+1 > 0 && PKing->WKx+1 < 9)){
      if((Tablero[(PKing->WKy)-1+2][(PKing->WKx)-1+1]->type == knight && Tablero[(PKing->WKy)-1+2][(PKing->WKx)-1+1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy+2 > 0 && PKing->WKy+2 < 9) && (PKing->WKx-1 > 0 && PKing->WKx-1 < 9)){
      if((Tablero[(PKing->WKy)-1+2][(PKing->WKx)-1-1]->type == knight && Tablero[(PKing->WKy)-1+2][(PKing->WKx)-1-1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy-2 > 0 && PKing->WKy-2 < 9) && (PKing->WKx+1 > 0 && PKing->WKx+1 < 9)){
      if((Tablero[(PKing->WKy)-1-2][(PKing->WKx)-1+1]->type == knight && Tablero[(PKing->WKy)-1-2][(PKing->WKx)-1+1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy-2 > 0 && PKing->WKy-2 < 9) && (PKing->WKx-1 > 0 && PKing->WKx-1 < 9)){
      if((Tablero[(PKing->WKy)-1-2][(PKing->WKx)-1-1]->type == knight && Tablero[(PKing->WKy)-1-2][(PKing->WKx)-1-1]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy+1 > 0 && PKing->WKy+1 < 9) && (PKing->WKx+2 > 0 && PKing->WKx+2 < 9)){
      if((Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1+2]->type == knight && Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1+2]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy-1 > 0 && PKing->WKy-1 < 9) && (PKing->WKx+2 > 0 && PKing->WKx+2 < 9)){
      if((Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1+2]->type == knight && Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1+2]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy+1 > 0 && PKing->WKy+1 < 9) && (PKing->WKx-2 > 0 && PKing->WKx-2 < 9)){
      if((Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1-2]->type == knight && Tablero[(PKing->WKy)-1+1][(PKing->WKx)-1-2]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
   if((PKing->WKy-1 > 0 && PKing->WKy-1 < 9) && (PKing->WKx-2 > 0 && PKing->WKx-2 < 9)){
      if((Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1-2]->type == knight && Tablero[(PKing->WKy)-1-1][(PKing->WKx)-1-2]->player != 1)){
         PKing->WKcheck = 1;
         return;
      }
   }
}

void RQCheckWhite(Piece* Tablero[8][8], PosKing* PKing){
   for(int i = PKing->WKy+1; i < 9; i++){
		if((Tablero[-1+i][(PKing->WKx)-1]->type == queen && Tablero[-1+i][(PKing->WKx)-1]->player != 1) || (Tablero[-1+i][(PKing->WKx)-1]->type == rook && Tablero[-1+i][(PKing->WKx)-1]->player != 1)){
			PKing->WKcheck = 1;
         return;
		}
		if(Tablero[-1+i][(PKing->WKx)-1]->player == 1 || Tablero[-1+i][(PKing->WKx)-1]->type == rook || Tablero[-1+i][(PKing->WKx)-1]->type == knight || Tablero[-1+i][(PKing->WKx)-1]->type == pawn || Tablero[-1+i][(PKing->WKx)-1]->type == king){
			break;
		}
	}
	for(int i = PKing->WKy-1; i > 0; i--){
		if((Tablero[-1+i][(PKing->WKx)-1]->type == queen && Tablero[-1+i][(PKing->WKx)-1]->player != 1) || (Tablero[-1+i][(PKing->WKx)-1]->type == rook && Tablero[-1+i][(PKing->WKx)-1]->player != 1)){
			PKing->WKcheck = 1;
         return;
		}
		if(Tablero[-1+i][(PKing->WKx)-1]->player == 1 || Tablero[-1+i][(PKing->WKx)-1]->type == rook || Tablero[-1+i][(PKing->WKx)-1]->type == knight || Tablero[-1+i][(PKing->WKx)-1]->type == pawn || Tablero[-1+i][(PKing->WKx)-1]->type == king){
			break;
		}
	}
	for(int i = PKing->WKx+1; i < 9; i++){
		if((Tablero[(PKing->WKy)-1][i-1]->type == queen && Tablero[(PKing->WKy)-1][i-1]->player != 1) || (Tablero[(PKing->WKy)-1][i-1]->type == rook && Tablero[(PKing->WKy)-1][i-1]->player != 1)){
			PKing->WKcheck = 1;
         return;
		}
		if(Tablero[(PKing->WKy)-1][i-1]->player == 1 || Tablero[(PKing->WKy)-1][i-1]->type == rook || Tablero[(PKing->WKy)-1][i-1]->type == knight || Tablero[(PKing->WKy)-1][i-1]->type == pawn || Tablero[(PKing->WKy)-1][i-1]->type == king){
			break;
		}
	}
	for(int i = PKing->WKx-1; i > 0; i--){
		if((Tablero[(PKing->WKy)-1][i-1]->type == queen && Tablero[(PKing->WKy)-1][i-1]->player != 1) || (Tablero[(PKing->WKy)-1][i-1]->type == rook && Tablero[(PKing->WKy)-1][i-1]->player != 1)){
			PKing->WKcheck = 1;
         return;
		}
		if(Tablero[(PKing->WKy)-1][i-1]->player == 1 || Tablero[(PKing->WKy)-1][i-1]->type == rook || Tablero[(PKing->WKy)-1][i-1]->type == knight || Tablero[(PKing->WKy)-1][i-1]->type == pawn || Tablero[(PKing->WKy)-1][i-1]->type == king){
			break;
		}
	}
}

void BQCheckWhite(Piece* Tablero[8][8], PosKing* PKing){
	int r = PKing->WKx+1;
	for(int i = PKing->WKy+1; i < 9; i++){
		if(r > 8){
		   break;
	   }
		if((Tablero[-1+i][-1+r]->type == queen && Tablero[-1+i][-1+r]->player != 1) || (Tablero[-1+i][-1+r]->type == bishop && Tablero[-1+i][-1+r]->player != 1)){
			PKing->WKcheck = 1;
         return;
		}
		if(Tablero[-1+i][-1+r]->player == 1 || Tablero[-1+i][-1+r]->type == rook || Tablero[-1+i][-1+r]->type == knight || Tablero[-1+i][-1+r]->type == pawn || Tablero[-1+i][-1+r]->type == king){
			break;
		}
		r++;
	}
	r = PKing->WKx-1;
	for(int i = PKing->WKy+1; i < 9; i++){
		if(r < 1){
			break;
		}
		if((Tablero[-1+i][-1+r]->type == queen && Tablero[-1+i][-1+r]->player != 1) || (Tablero[-1+i][-1+r]->type == bishop && Tablero[-1+i][-1+r]->player != 1)){
			PKing->WKcheck = 1;
         return;
		}
		if(Tablero[-1+i][-1+r]->player == 1 || Tablero[-1+i][-1+r]->type == rook || Tablero[-1+i][-1+r]->type == knight || Tablero[-1+i][-1+r]->type == pawn || Tablero[-1+i][-1+r]->type == king){
			break;
		}
		r--;
	}
	r = PKing->WKx+1;
	for(int i = PKing->WKy-1; i > 0; i--){
		if(r > 8){
			break;
		}
		if((Tablero[-1+i][-1+r]->type == queen && Tablero[-1+i][-1+r]->player != 1) || (Tablero[-1+i][-1+r]->type == bishop && Tablero[-1+i][-1+r]->player != 1)){
			PKing->WKcheck = 1;
         return;
		}
		if(Tablero[-1+i][-1+r]->player == 1 || Tablero[-1+i][-1+r]->type == rook || Tablero[-1+i][-1+r]->type == knight || Tablero[-1+i][-1+r]->type == pawn || Tablero[-1+i][-1+r]->type == king){
			break;
		}
		r++;
	}
	r = PKing->WKx-1;
	for(int i = PKing->WKy-1; i > 0; i--){
		if(r < 1){
			break;
		}
		if((Tablero[-1+i][-1+r]->type == queen && Tablero[-1+i][-1+r]->player != 1) || (Tablero[-1+i][-1+r]->type == bishop && Tablero[-1+i][-1+r]->player != 1)){
			PKing->WKcheck = 1;
         return;
		}
		if(Tablero[-1+i][-1+r]->player == 1 || Tablero[-1+i][-1+r]->type == rook || Tablero[-1+i][-1+r]->type == knight || Tablero[-1+i][-1+r]->type == pawn || Tablero[-1+i][-1+r]->type == king){
			break;
		}
		r--;
	}
}

void Pawn(Piece* Tablero[8][8], int Posx, int Posy, int player, int* error){
   int PosyPawn;
   int PosxPawn;
   int move = 0;

   printf("Selection: Pawn\n");
   while(move != 1){
      printf("Move position X: ");
      scanf("%d", &PosxPawn);
      printf("Move position Y: ");
      scanf("%d", &PosyPawn);

      if(PosxPawn == 0 && (PosyPawn == 1 || PosyPawn == -1)  && ((PosyPawn+Posy) > 0 && (PosyPawn+Posy) < 9)){
         if(PosyPawn == 1 && player == 1)
            printf("Invalid move\n");
         else if(PosyPawn == -1 && player == 0)
            printf("Invalid move\n");
         else if(Tablero[(Posy-1)+PosyPawn][Posx-1]->type == symbol){
            if((Tablero[(Posy-1)+PosyPawn] == Tablero[0] && player == 1) || (Tablero[(Posy-1)+PosyPawn] == Tablero[7] && player == 0)){
               Tablero[(Posy-1)+PosyPawn][Posx-1]->type = queen;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyPawn][Posx-1]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               Tablero[Posy-1][Posx-1]->initpos = 0;
               PrintBoard(Tablero);
               (*error)++;
               move++;
            }
            else{
               Tablero[(Posy-1)+PosyPawn][Posx-1]->type = pawn;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyPawn][Posx-1]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               Tablero[Posy-1][Posx-1]->initpos = 0;
               PrintBoard(Tablero);
               (*error)++;
               move++;
            }
         }
         else
            printf("Invalid move\n");
      }
      else if((PosxPawn == 1 || PosxPawn == -1) && ((PosyPawn == 1 || PosyPawn == -1) && ((PosyPawn+Posy) > 0 && (PosyPawn+Posy) < 9))){
         if(PosyPawn == 1 && player == 1)
            printf("Invalid move\n");
         else if(PosyPawn == -1 && player == 0)
            printf("Invalid move\n");
         else if(Tablero[(Posy-1)+PosyPawn][(Posx-1)+PosxPawn]->type != symbol && Tablero[(Posy-1)+PosyPawn][(Posx-1)+PosxPawn]->player != player){
            if((Tablero[(Posy-1)+PosyPawn] == Tablero[0] && player == 1) || (Tablero[(Posy-1)+PosyPawn] == Tablero[7] && player == 0)){
               Tablero[(Posy-1)+PosyPawn][(Posx-1)+PosxPawn]->type = queen;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyPawn][(Posx-1)+PosxPawn]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               Tablero[(Posy-1)+PosyPawn][(Posx-1)+PosxPawn]->initpos = 0;
               Tablero[Posy-1][Posx-1]->initpos = 0;
               PrintBoard(Tablero);
               (*error)++;
               move++;
            }
            else{
               Tablero[(Posy-1)+PosyPawn][(Posx-1)+PosxPawn]->type = pawn;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyPawn][(Posx-1)+PosxPawn]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               Tablero[(Posy-1)+PosyPawn][(Posx-1)+PosxPawn]->initpos = 0;
               Tablero[Posy-1][Posx-1]->initpos = 0;
               PrintBoard(Tablero);
               (*error)++;
               move++;
            }
         }
         else
            printf("Invalid move\n");
      }
      else if(PosxPawn == 0 && (PosyPawn == 2 || PosyPawn == -2) && ((PosyPawn+Posy) > 0 && (PosyPawn+Posy) < 9)){
         if(PosyPawn == 2 && player == 1)
            printf("Invalid move\n");
         else if(PosyPawn == -2 && player == 0)
            printf("Invalid move\n");
         else if(Tablero[(Posy-1)+PosyPawn][Posx-1]->type == symbol && Tablero[Posy-1][Posx-1]->initpos == 1){
            if((Tablero[(Posy-1)+1][Posx-1]->type == symbol && player == 0) || (Tablero[(Posy-1)-1][Posx-1]->type == symbol && player == 1)){
               Tablero[(Posy-1)+PosyPawn][Posx-1]->type = pawn;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyPawn][Posx-1]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               Tablero[Posy-1][Posx-1]->initpos = 0;
               PrintBoard(Tablero);
               (*error)++;
               move++;
            }
            else
               printf("Invalid move\n");
         }
         else
            printf("Invalid move\n");
      }
      else
         printf("Invalid move\n");
               
   }
}


void Rook(Piece* Tablero[8][8], int Posx, int Posy, int player, int* error){
   int PosyRook;
   int PosxRook;
   int move = 0;

   printf("Selection: Rook\n");
   while(move != 1){
      printf("Move position X: ");
      scanf("%d", &PosxRook);
      printf("Move position Y: ");
      scanf("%d", &PosyRook);

      if((PosxRook+Posx > 0 && PosxRook+Posx < 9) && PosyRook == 0){
         if(Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->type == symbol || (Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->type != symbol && Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->player != player)){
            int val = 0;
            if(PosxRook > 0){
               for(int i = 1; i < PosxRook; i++){
                  if(Tablero[(Posy-1)+PosyRook][(Posx-1)+i]->type != symbol){
                     val = 1;
                     printf("Invalid move\n");
                     break;
                  }
               }
               if(val != 1){
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->type = rook;
                  Tablero[Posy-1][Posx-1]->type = symbol;
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->player = player;
                  Tablero[Posy-1][Posx-1]->player = 3;
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->initpos = 0;
                  Tablero[Posy-1][Posx-1]->initpos = 0;
                  move++;
                  (*error)++;
                  PrintBoard(Tablero);
               }
            }
            else{
               for(int i = -1; i > PosxRook; i--){
                  if(Tablero[(Posy-1)+PosyRook][(Posx-1)+i]->type != symbol){
                     val = 1;
                     printf("Invalid move\n");
                     break;
                  }
               }
               if(val != 1){
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->type = rook;
                  Tablero[Posy-1][Posx-1]->type = symbol;
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->player = player;
                  Tablero[Posy-1][Posx-1]->player = 3;
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->initpos = 0;
                  Tablero[Posy-1][Posx-1]->initpos = 0;
                  move++;
                  (*error)++;
                  PrintBoard(Tablero);
               }
            }
         }
         else
            printf("Invalid move\n");
      }
      else if((PosyRook+Posy > 0 && PosyRook+Posy < 9) && PosxRook == 0){
         if(Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->type == symbol || (Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->type != symbol && Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->player != player)){
            int val = 0;
            if(PosyRook > 0){
               for(int j = 1; j < PosyRook; j++){
                  if(Tablero[(Posy-1)+j][(Posx-1)+PosxRook]->type != symbol){
                     val = 1;
                     printf("Invalid move\n");
                     break;
                  }
               }
               if(val != 1){
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->type = rook;
                  Tablero[Posy-1][Posx-1]->type = symbol;
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->player = player;
                  Tablero[Posy-1][Posx-1]->player = 3;
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->initpos = 0;
                  Tablero[Posy-1][Posx-1]->initpos = 0;
                  move++;
                  (*error)++;
                  PrintBoard(Tablero);
               }
            }
            else{
               for(int j = -1; j > PosyRook; j--){
                  if(Tablero[(Posy-1)+j][(Posx-1)+PosxRook]->type != symbol){
                     val = 1;
                     printf("Invalid move\n");
                     break;
                  }
               }
               if(val != 1){
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->type = rook;
                  Tablero[Posy-1][Posx-1]->type = symbol;
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->player = player;
                  Tablero[Posy-1][Posx-1]->player = 3;
                  Tablero[(Posy-1)+PosyRook][(Posx-1)+PosxRook]->initpos = 0;
                  Tablero[Posy-1][Posx-1]->initpos = 0;
                  move++;
                  (*error)++;
                  PrintBoard(Tablero);
               }
            }
         }
         else
            printf("Invalid Move\n");
      }
      else
         printf("Invalid Move\n");
   }
}


void Bishop(Piece* Tablero[8][8], int Posx, int Posy, int player, int* error){
   int PosyBishop;
   int PosxBishop;
   int move = 0;

   printf("Selection: Bishop\n");
   while(move != 1){
      printf("Move position X: ");
      scanf("%d", &PosxBishop);
      printf("Move position Y: ");
      scanf("%d", &PosyBishop);

      if((PosxBishop > 0 && PosyBishop > 0) && (PosxBishop+Posx > 0 && PosxBishop+Posx < 9) && (PosyBishop+Posy > 0 && PosyBishop+Posy < 9) && (PosxBishop == PosyBishop)){
         if(Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type == symbol || (Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type != symbol && Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->player != player)){
            int r = 1;
            int val = 0;
            for(int i = 1; i < PosyBishop; i++){
               if(Tablero[(Posy-1)+i][(Posx-1)+r]->type != symbol){
                  val = 1;
                  printf("Invalid move\n");
                  break;
               }
               r++;
            }
            if(val != 1){
               Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type = bishop;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
         else
            printf("Invalid Move\n");
      }
      else if((PosxBishop < 0 && PosyBishop > 0) && (PosxBishop+Posx > 0 && PosxBishop+Posx < 9) && (PosyBishop+Posy > 0 && PosyBishop+Posy < 9) && ((PosxBishop * -1) == PosyBishop)){
         if(Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type == symbol || (Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type != symbol && Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->player != player)){
            int r = -1;
            int val = 0;
            for(int i = 1; i < PosyBishop; i++){
               if(Tablero[(Posy-1)+i][(Posx-1)+r]->type != symbol){
                  val = 1;
                  printf("Invalid move\n");
                  break;
               }
               r--;
            }
            if(val != 1){
               Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type = bishop;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
         else
            printf("Invalid Move\n");
      }
      else if((PosxBishop > 0 && PosyBishop < 0) && (PosxBishop+Posx > 0 && PosxBishop+Posx < 9) && (PosyBishop+Posy > 0 && PosyBishop+Posy < 9) && (PosxBishop == (PosyBishop * -1))){
         if(Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type == symbol || (Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type != symbol && Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->player != player)){
            int r = 1;
            int val = 0;
            for(int i = -1; i > PosyBishop; i--){
               if(Tablero[(Posy-1)+i][(Posx-1)+r]->type != symbol){
                  val = 1;
                  printf("Invalid move\n");
                  break;
               }
               r++;
            }
            if(val != 1){
               Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type = bishop;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
         else
            printf("Invalid Move\n");
      }
      else if((PosxBishop < 0 && PosyBishop < 0) && (PosxBishop+Posx > 0 && PosxBishop+Posx < 9) && (PosyBishop+Posy > 0 && PosyBishop+Posy < 9) && (PosxBishop == PosyBishop)){
         if(Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type == symbol || (Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type != symbol && Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->player != player)){
            int r = -1;
            int val = 0;
            for(int i = -1; i > PosyBishop; i--){
               if(Tablero[(Posy-1)+i][(Posx-1)+r]->type != symbol){
                  val = 1;
                  printf("Invalid move\n");
                  break;
               }
               r--;
            }
            if(val != 1){
               Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->type = bishop;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyBishop][(Posx-1)+PosxBishop]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
         else
            printf("Invalid Move\n");
      }
      else{
         printf("Invalid Move\n");
      }
   }
}


void Knight(Piece* Tablero[8][8], int Posx, int Posy, int player, int* error){
   int PosyKnight;
   int PosxKnight;
   int move = 0;

   printf("Selection: Knight\n");
   while(move != 1){
      printf("Move position X: ");
      scanf("%d", &PosxKnight);
      printf("Move position Y: ");
      scanf("%d", &PosyKnight);

      if(((PosxKnight == 1 && PosyKnight == 2) || (PosxKnight == 2 && PosyKnight == 1) || (PosxKnight == 2 && PosyKnight == -1) || (PosxKnight == -1 && PosyKnight == -2) || (PosxKnight == -2 && PosyKnight == -1) || (PosxKnight == -2 && PosyKnight == 1) || (PosxKnight == -1 && PosyKnight == 2) || (PosxKnight == 1 && PosyKnight == -2)) && (PosxKnight+Posx > 0 && PosxKnight+Posx < 9) && (PosyKnight+Posy > 0 && PosyKnight+Posy < 9)){
         if(Tablero[(Posy-1)+PosyKnight][(Posx-1)+PosxKnight]->type == symbol || (Tablero[(Posy-1)+PosyKnight][(Posx-1)+PosxKnight]->type != symbol && Tablero[(Posy-1)+PosyKnight][(Posx-1)+PosxKnight]->player != player)){
            Tablero[(Posy-1)+PosyKnight][(Posx-1)+PosxKnight]->type = knight;
            Tablero[Posy-1][Posx-1]->type = symbol;
            Tablero[(Posy-1)+PosyKnight][(Posx-1)+PosxKnight]->player = player;
            Tablero[Posy-1][Posx-1]->player = 3;
            move++;
            (*error)++;
            PrintBoard(Tablero);
         }
         else
            printf("Invalid Move\n");
      }
      else
         printf("Invalid Move\n");
   }
}


void Queen(Piece* Tablero[8][8], int Posx, int Posy, int player, int* error){
   int PosyQueen;
   int PosxQueen;
   int move = 0;

   printf("Selection: Queen\n");
   while(move != 1){
      printf("Move position X: ");
      scanf("%d", &PosxQueen);
      printf("Move position Y: ");
      scanf("%d", &PosyQueen);

      if((PosxQueen+Posx > 0 && PosxQueen+Posx < 9) && PosyQueen == 0){
         if(Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type == symbol || (Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type != symbol && Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player != player)){
            int val = 0;
            if(PosxQueen > 0){
               for(int i = 1; i < PosxQueen; i++){
                  if(Tablero[(Posy-1)+PosyQueen][(Posx-1)+i]->type != symbol){
                     val = 1;
                     printf("Invalid move\n");
                     break;
                  }
               }
               if(val != 1){
                  Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type = queen;
                  Tablero[Posy-1][Posx-1]->type = symbol;
                  Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player = player;
                  Tablero[Posy-1][Posx-1]->player = 3;
                  move++;
                  (*error)++;
                  PrintBoard(Tablero);
               }
            }
            else{
               for(int i = -1; i > PosxQueen; i--){
                  if(Tablero[(Posy-1)+PosyQueen][(Posx-1)+i]->type != symbol){
                     val = 1;
                     printf("Invalid move\n");
                     break;
                  }
               }
               if(val != 1){
                  Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type = queen;
                  Tablero[Posy-1][Posx-1]->type = symbol;
                  Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player = player;
                  Tablero[Posy-1][Posx-1]->player = 3;
                  move++;
                  (*error)++;
                  PrintBoard(Tablero);
               }
            }
         }
         else
            printf("Invalid move\n");
      }
      else if((PosyQueen+Posy > 0 && PosyQueen+Posy < 9) && PosxQueen == 0){
         if(Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type == symbol || (Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type != symbol && Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player != player)){
            int val = 0;
            if(PosyQueen > 0){
               for(int j = 1; j < PosyQueen; j++){
                  if(Tablero[(Posy-1)+j][(Posx-1)+PosxQueen]->type != symbol){
                     val = 1;
                     printf("Invalid move\n");
                     break;
                  }
               }
               if(val != 1){
                  Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type = queen;
                  Tablero[Posy-1][Posx-1]->type = symbol;
                  Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player = player;
                  Tablero[Posy-1][Posx-1]->player = 3;
                  move++;
                  (*error)++;
                  PrintBoard(Tablero);
               }
            }
            else{
               for(int j = -1; j > PosyQueen; j--){
                  if(Tablero[(Posy-1)+j][(Posx-1)+PosxQueen]->type != symbol){
                     val = 1;
                     printf("Invalid move\n");
                     break;
                  }
               }
               if(val != 1){
                  Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type = queen;
                  Tablero[Posy-1][Posx-1]->type = symbol;
                  Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player = player;
                  Tablero[Posy-1][Posx-1]->player = 3;
                  move++;
                  (*error)++;
                  PrintBoard(Tablero);
               }
            }
         }
         else
            printf("Invalid Move\n");
      }
      else if((PosxQueen > 0 && PosyQueen > 0) && (PosxQueen+Posx > 0 && PosxQueen+Posx < 9) && (PosyQueen+Posy > 0 && PosyQueen+Posy < 9) && (PosxQueen == PosyQueen)){
         if(Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type == symbol || (Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type != symbol && Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player != player)){
            int r = 1;
            int val = 0;
            for(int i = 1; i < PosyQueen; i++){
               if(Tablero[(Posy-1)+i][(Posx-1)+r]->type != symbol){
                  val = 1;
                  printf("Invalid move\n");
                  break;
               }
               r++;
            }
            if(val != 1){
               Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type = queen;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
         else
            printf("Invalid Move\n");
      }
      else if((PosxQueen < 0 && PosyQueen > 0) && (PosxQueen+Posx > 0 && PosxQueen+Posx < 9) && (PosyQueen+Posy > 0 && PosyQueen+Posy < 9) && ((PosxQueen * -1) == PosyQueen)){
         if(Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type == symbol || (Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type != symbol && Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player != player)){
            int r = -1;
            int val = 0;
            for(int i = 1; i < PosyQueen; i++){
               if(Tablero[(Posy-1)+i][(Posx-1)+r]->type != symbol){
                  val = 1;
                  printf("Invalid move\n");
                  break;
               }
               r--;
            }
            if(val != 1){
               Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type = queen;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
         else
            printf("Invalid Move\n");
      }
      else if((PosxQueen > 0 && PosyQueen < 0) && (PosxQueen+Posx > 0 && PosxQueen+Posx < 9) && (PosyQueen+Posy > 0 && PosyQueen+Posy < 9) && (PosxQueen == (PosyQueen * -1))){
         if(Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type == symbol || (Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type != symbol && Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player != player)){
            int r = 1;
            int val = 0;
            for(int i = -1; i > PosyQueen; i--){
               if(Tablero[(Posy-1)+i][(Posx-1)+r]->type != symbol){
                  val = 1;
                  printf("Invalid move\n");
                  break;
               }
               r++;
            }
            if(val != 1){
               Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type = queen;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
         else
            printf("Invalid Move\n");
      }
      else if((PosxQueen < 0 && PosyQueen < 0) && (PosxQueen+Posx > 0 && PosxQueen+Posx < 9) && (PosyQueen+Posy > 0 && PosyQueen+Posy < 9) && (PosxQueen == PosyQueen)){
         if(Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type == symbol || (Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type != symbol && Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player != player)){
            int r = -1;
            int val = 0;
            for(int i = -1; i > PosyQueen; i--){
               if(Tablero[(Posy-1)+i][(Posx-1)+r]->type != symbol){
                  val = 1;
                  printf("Invalid move\n");
                  break;
               }
               r--;
            }
            if(val != 1){
               Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->type = queen;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyQueen][(Posx-1)+PosxQueen]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
         else
            printf("Invalid Move\n");
      }
      else{
         printf("Invalid Move\n");
      }     
   }
}


void King(Piece* Tablero[8][8], int Posx, int Posy, int player, int* error, PosKing* PKing){
   int PosyKing;
   int PosxKing;
   int move = 0;

   printf("Selection: King\n");
   while(move != 1){
      printf("Move position X: ");
      scanf("%d", &PosxKing);
      printf("Move position Y: ");
      scanf("%d", &PosyKing);

      if(((PosxKing == 0 && PosyKing == 1) || (PosxKing == 1 && PosyKing == 1) || (PosxKing == 1 && PosyKing == 0) || (PosxKing == 1 && PosyKing == -1) || (PosxKing == 0 && PosyKing == -1) || (PosxKing == -1 && PosyKing == -1) || (PosxKing == -1 && PosyKing == 0) || (PosxKing == -1 && PosyKing == 1)) && (PosxKing+Posx > 0 && PosxKing+Posx < 9) && (PosyKing+Posy > 0 && PosyKing+Posy < 9)){
         if(Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->type == symbol || (Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->type != symbol && Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->player != player)){
            if(player == 1){
               PKing->WKx = PKing->WKx + PosxKing;
               PKing->WKy = PKing->WKy + PosyKing;
            }
            else{
               PKing->BKx = PKing->BKx + PosxKing;
               PKing->BKy = PKing->BKy + PosyKing;
            }
            Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->type = king;
            Tablero[Posy-1][Posx-1]->type = symbol;
            Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->player = player;
            Tablero[Posy-1][Posx-1]->player = 3;
            Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->initpos = 0;
            Tablero[Posy-1][Posx-1]->initpos = 0;
            move++;
            (*error)++;
            PrintBoard(Tablero);
         }
         else
            printf("Invalid Move\n");
      }
      else if((PosxKing == 2 && PosyKing == 0) && (Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->type == symbol) && (Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing+1]->type == rook && Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing+1]->initpos == 1 && Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing+1]->player == player) && (PosxKing+Posx > 0 && PosxKing+Posx < 9) && (PosyKing+Posy > 0 && PosyKing+Posy < 9) && Tablero[Posy-1][Posx-1]->initpos == 1){
         if((PKing->BKcheck == 1 && player == 0) || (PKing->WKcheck == 1 && player == 1)){
            printf("Invalid move\n");
         }
         if((PKing->BKcheck == 0 && player == 0) || (PKing->WKcheck == 0 && player == 1)){
            int val = 0;
            for(int i = 1; i < PosxKing; i++){
               if(Tablero[(Posy-1)+PosyKing][(Posx-1)+i]->type != symbol){
                  val = 1;
                  printf("Invalid move");
                  break;
               }
            }
            if(val != 1){
               if(player == 1){
                  PKing->WKx = PKing->WKx + PosxKing;
               }
               else{
                  PKing->BKx = PKing->BKx + PosxKing;
               }
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->type = king;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing+1]->type = symbol;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing-1]->type = rook;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->player = player;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing+1]->player = 3;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing-1]->player = player;
               Tablero[Posy-1][Posx-1]->player = 3;
               Tablero[Posy-1][Posx-1]->initpos = 0;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing+1]->initpos = 0;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
      }
      else if((PosxKing == -2 && PosyKing == 0) && (Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->type == symbol) && (Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing-2]->type == rook && Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing-2]->initpos == 1 && Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing-2]->player == player) && (PosxKing+Posx > 0 && PosxKing+Posx < 9) && (PosyKing+Posy > 0 && PosyKing+Posy < 9) && Tablero[Posy-1][Posx-1]->initpos == 1){
         if((PKing->BKcheck == 1 && player == 0) || (PKing->WKcheck == 1 && player == 1)){
            printf("Invalid move\n");
         }
         if((PKing->BKcheck == 0 && player == 0) || (PKing->WKcheck == 0 && player == 1)){
            int val = 0;
            for(int i = -1; i > PosxKing-1; i--){
               if(Tablero[(Posy-1)+PosyKing][(Posx-1)+i]->type != symbol){
                  val = 1;
                  printf("Invalid move");
                  break;
               }
            }
            if(val != 1){
               if(player == 1){
                  PKing->WKx = PKing->WKx + PosxKing;
               }
               else{
                  PKing->BKx = PKing->BKx + PosxKing;
               }
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->type = king;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing+1]->type = rook;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing-2]->type = symbol;
               Tablero[Posy-1][Posx-1]->type = symbol;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing]->player = player;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing+1]->player = player;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing-2]->player = 3;
               Tablero[Posy-1][Posx-1]->player = 3;
               Tablero[Posy-1][Posx-1]->initpos = 0;
               Tablero[(Posy-1)+PosyKing][(Posx-1)+PosxKing-2]->initpos = 0;
               move++;
               (*error)++;
               PrintBoard(Tablero);
            }
         }
      }
      else
         printf("Invalid Move\n");
   }
}


void InitGame(Piece* Tablero[8][8], FILE* Game, FILE* Board, PosKing* PKing){
   int game = 0;
   int Posx, Posy;
	int save;

	int player = PKing->player;

   PrintBoard(Tablero);

   while(game != 1){
		int error = 0;
      if(PKing->BKcheck == 1 && player == 1){
         printf("Checkmate\n");
         printf("----Player 1 (whites) wins----\n");
         break; 
      }
      if(PKing->WKcheck == 1 && player == 0){
         printf("Checkmate\n");
         printf("----Player 2 (blacks) wins----\n");
         break;
      }
      printf("Do you want to save your game ? (Yes = 0) (No = 1)  ");
      scanf("%d", &save);

      if(save == 0){
			char tmproot[1000] = "";
         char fullroot[1000] = "";
         char slot[1];
         printf("Escribe el numero del slot de guardado (Solo poner no. de slot)  ");
         scanf("%s", slot);
			strcat(tmproot, "./Guardado");
         strcat(tmproot, slot);
			strcat(fullroot, tmproot);
         strcat(fullroot, ".bin");
         Game = fopen(fullroot, "wb");
         rewind(Game);
			fwrite(PKing, sizeof(PosKing), 1, Game);
         fclose(Game);
         
         char Boardtmproot[1000] = "";
         char Boardroot[1000] = "";
         strcat(Boardtmproot, "./Tablero");
         strcat(Boardtmproot, slot);
			strcat(Boardroot, Boardtmproot);
         strcat(Boardroot, ".bin");
         Board = fopen(Boardroot,"wb");
         rewind(Board);
         fwrite(Tablero, sizeof(Piece), 1, Board);
         fclose(Board);
         break;
      }
      if(player == 1)
         printf("(Whites) Player 1 -- Move\n");
      else
         printf("(Blacks) Player 2 -- Move\n");
      while(error != 1){
         printf("Piece position X: ");
         scanf("%d", &Posx);
         printf("Piece position Y: ");
         scanf("%d", &Posy);

         if((Posx <= 0 || Posx >= 9) || (Posy <= 0 || Posy >= 9)){
            printf("Invalid position\n");
         }
         else if(Tablero[Posy-1][Posx-1]->type == king && Tablero[Posy-1][Posx-1]->player == player)
         {
            King(Tablero, Posx, Posy, player, &error, PKing);
            PawnCheckBlack(Tablero, PKing);
            KingCheckBlack(Tablero, PKing);
            KnightCheckBlack(Tablero, PKing);
            BQCheckBlack(Tablero, PKing);
            RQCheckBlack(Tablero, PKing);
            PawnCheckWhite(Tablero, PKing);
            KingCheckWhite(Tablero, PKing);
            KnightCheckWhite(Tablero, PKing);
            BQCheckWhite(Tablero, PKing);
            RQCheckWhite(Tablero, PKing);
         }
         else if(Tablero[Posy-1][Posx-1]->type == pawn && Tablero[Posy-1][Posx-1]->player == player)
         {
            Pawn(Tablero, Posx, Posy, player, &error);
            PawnCheckBlack(Tablero, PKing);
            KingCheckBlack(Tablero, PKing);
            KnightCheckBlack(Tablero, PKing);
            BQCheckBlack(Tablero, PKing);
            RQCheckBlack(Tablero, PKing);
            PawnCheckWhite(Tablero, PKing);
            KingCheckWhite(Tablero, PKing);
            KnightCheckWhite(Tablero, PKing);
            BQCheckWhite(Tablero, PKing);
            RQCheckWhite(Tablero, PKing);
         }
         else if(Tablero[Posy-1][Posx-1]->type == rook && Tablero[Posy-1][Posx-1]->player == player)
         {
            Rook(Tablero, Posx, Posy, player, &error);
            PawnCheckBlack(Tablero, PKing);
            KingCheckBlack(Tablero, PKing);
            KnightCheckBlack(Tablero, PKing);
            BQCheckBlack(Tablero, PKing);
            RQCheckBlack(Tablero, PKing);
            PawnCheckWhite(Tablero, PKing);
            KingCheckWhite(Tablero, PKing);
            KnightCheckWhite(Tablero, PKing);
            BQCheckWhite(Tablero, PKing);
            RQCheckWhite(Tablero, PKing);
         }
         else if(Tablero[Posy-1][Posx-1]->type == knight && Tablero[Posy-1][Posx-1]->player == player)
         {
            Knight(Tablero, Posx, Posy, player, &error);
            PawnCheckBlack(Tablero, PKing);
            KingCheckBlack(Tablero, PKing);
            KnightCheckBlack(Tablero, PKing);
            BQCheckBlack(Tablero, PKing);
            RQCheckBlack(Tablero, PKing);
            PawnCheckWhite(Tablero, PKing);
            KingCheckWhite(Tablero, PKing);
            KnightCheckWhite(Tablero, PKing);
            BQCheckWhite(Tablero, PKing);
            RQCheckWhite(Tablero, PKing);
         }
         else if(Tablero[Posy-1][Posx-1]->type == queen && Tablero[Posy-1][Posx-1]->player == player)
         {
            Queen(Tablero, Posx, Posy, player, &error);
            PawnCheckBlack(Tablero, PKing);
            KingCheckBlack(Tablero, PKing);
            KnightCheckBlack(Tablero, PKing);
            BQCheckBlack(Tablero, PKing);
            RQCheckBlack(Tablero, PKing);
            PawnCheckWhite(Tablero, PKing);
            KingCheckWhite(Tablero, PKing);
            KnightCheckWhite(Tablero, PKing);
            BQCheckWhite(Tablero, PKing);
            RQCheckWhite(Tablero, PKing);
         }
         else if(Tablero[Posy-1][Posx-1]->type == bishop && Tablero[Posy-1][Posx-1]->player == player)
         {
            Bishop(Tablero, Posx, Posy, player, &error);
            PawnCheckBlack(Tablero, PKing);
            KingCheckBlack(Tablero, PKing);
            KnightCheckBlack(Tablero, PKing);
            BQCheckBlack(Tablero, PKing);
            RQCheckBlack(Tablero, PKing);
            PawnCheckWhite(Tablero, PKing);
            KingCheckWhite(Tablero, PKing);
            KnightCheckWhite(Tablero, PKing);
            BQCheckWhite(Tablero, PKing);
            RQCheckWhite(Tablero, PKing);
         }
         else
            printf("Error: Esa posición esta vacía o es del otro jugador\n");
      }
      
      if(player == 1){
         player = 0;
			PKing->player = 0;
      }
      else{
         player = 1;
			PKing->player = 1;
      }
   }
}