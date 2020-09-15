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
