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


/* Parameters:

>> pX:        Horizontal position in blocks
>> pY:        Vertical position in blocks
>> pPiece:    Piece to draw
>> pRotation: 1 of the 4 possible rotations */

void Board::StorePiece (int pX, int pY, int pPiece, int pRotation){                    //Store a piece in the board by filling the blocks
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)
                mBoard[i1][j1] = POS_FILLED;
        }
    }
}


void Board::DeletePossibleLines ()                                                     // we should remove unnecessary lines   >sonradan Board::'a' ihtiyacımız olabilir
{
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        int j = 0;
        while (j < BOARD_WIDTH)
        {
            if (mBoard[j][i] != POS_FILLED)
            break;

            i++;
        }
        if (i == BOARD_WIDTH)

        DeleteLine (i);
    }
}
