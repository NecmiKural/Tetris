#include "Game.h"

void Game::DrawScene ()                                                         //Calls previous objects to draw new scene
{
    DrawBoard ();                                                               // Draw the delimitation lines and blocks stored in the board
    DrawPiece (mPosX, mPosY, mPiece, mRotation);                                // Draw the playing piece
    DrawPiece (mNextPosX, mNextPosY, mNextPiece, mNextRotation);                // Draw the next piece
}

void Game::CreateNewPiece()                                                     //Creates random piece and next piece
{
    // New piece
    mPiece          = mNextPiece;
    mRotation       = mNextRotation;
    mPosX           = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition (mPiece, mRotation);
    mPosY           = mPieces->GetYInitialPosition (mPiece, mRotation);

    // Random next piece
    mNextPiece      = GetRand (0, 6);
    mNextRotation   = GetRand (0, 3);
}

/* 
======================================                                  
Draw piece
 
Parameters:
 
>> pX:        Horizontal position in blocks
>> pY:        Vertical position in blocks
>> pPiece:    Piece to draw
>> pRotation: 1 of the 4 possible rotations
====================================== 
*/
void Game::DrawPiece (int pX, int pY, int pPiece, int pRotation)
{
    color mColor;               // Color of the block 
 
    // Obtain the position in pixel in the screen of the block we want to draw
    int mPixelsX = mBoard->GetXPosInPixels (pX);
    int mPixelsY = mBoard->GetYPosInPixels (pY);

    // Travel the matrix of blocks of the piece and draw the blocks that are filled
    for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {
            // Get the type of the block and draw it with the correct color
            switch (mPieces->GetBlockType (pPiece, pRotation, j, i)){

                case 1: mColor = GREEN; break;  // For each block of the piece except the pivot
                case 2: mColor = BLUE; break;   // For the pivot
            }

            if (mPieces->GetBlockType (pPiece, pRotation, j, i) != 0)
                mIO->DrawRectangle   (mPixelsX + i * BLOCK_SIZE, 
                                    mPixelsY + j * BLOCK_SIZE, 
                                    (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, 
                                    (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, 
                                    mColor);
        }
        
    }
}