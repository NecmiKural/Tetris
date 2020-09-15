#include "Board.h"

/*
======================================
Init the board blocks with free positions
======================================
*/
void Board::InitBoard()
{
    for (int i = 0; i < BOARD_WIDTH; i++){
        for (int j = 0; j < BOARD_HEIGHT; j++){
             mBoard[i][j] = POS_FREE;
        }
    }
}

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


void Board::DeletePossibleLines ()                                                     // we should remove unnecessary lines
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

/*
======================================
Returns 1 (true) if the this block of the board is empty, 0 if it is filled

Parameters:

>> pX:        Horizontal position in blocks
>> pY:        Vertical position in blocks
 ======================================
*/
bool Board::IsFreeBlock (int pX,int pY)
{
     if (mBoard [pX][pY] == POS_FREE) return true; else return false;
     }


   /*
 ======================================
 Check if the piece can be stored at this position without any collision
 Returns true if the movement is  possible, false if it not possible

 Parameters:

 >> pX:        Horizontal position in blocks
 >> pY:        Vertical position in blocks
 >> pPiece:    Piece to draw
 >> pRotation: 1 of the 4 possible rotations
 ======================================
 */
bool Board::IsPossibleMovement (int pX,int pY, int pPiece, int pRotation){
    // Checks collision with pieces already stored in the board or the board limits
    // This is just to check the 5x5 blocks of a piece with the appropriate area in the board
    for(int i1 = pX, i2=0;i1 < pX + PIECE_BLOCKS; i1++,i2++)
    {
        for(int j1 = pY, j2=0;j1 < pY + PIECE_BLOCKS; j1++,j2++){
         // Check if the piece is outside the limits of the board
            if( i1 < 0        ||
                i1  >BOARD_WIDTH - 1        ||
                j1 > BOARD_HEIGHT - 1)
            {
                if(mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0 ){
                    return 0;
                }
            }
         // Check if the piece have collisioned with a block already stored in the map
            if(j1>=0){
                if(( mPieces->GetBlockType(pPiece, pRotation, j2, i2) !=0) &&(!IsFreeBlock(i1,j1))){
                    return false;
                }

            }
        }
    }
    // No collision
    return true;
}

bool Board::IsGameOver(){                                                       //Checks If the first line has blocks. IF it has, than game is over
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (mBoard[i][0] == POS_FILLED)
        return true;
    }
    return false;
}
/* 
======================================                                  
Returns the horizontal position (in pixels) of the block given like parameter
 
Parameters:
 
>> pPos:  Horizontal position of the block in the board
====================================== 
*/
int Board::GetXPosInPixels (int pPos)
{
    return  ( ( BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) ) + (pPos * BLOCK_SIZE) );
}
 
 
/* 
======================================                                  
Returns the vertical position (in pixels) of the block given like parameter
 
Parameters:
 
>> pPos:  Horizontal position of the block in the board
====================================== 
*/
int Board::GetYPosInPixels (int pPos)
{
    return ( (mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE) );
}