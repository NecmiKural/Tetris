#include "Board.h"

/* 
======================================                                  
Delete a line of the board by moving all above lines down
 
Parameters:
 
>> pY:        Vertical position in blocks of the line to delete
====================================== 
*/
void Board::DeleteLine(int pY){

    // Moves all the upper lines one row down
    for(int j = pY; j > 0; j--){
        for(int i = 0; BOARD_WIDTH; i++){
            mBoard[i][j] = mBoard[i][j-1];
        }
    }
}