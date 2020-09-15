#include "Game.h"

void Game::DrawScene ()                                                         //Calls previous objects to draw new scene
{
    DrawBoard ();                                                               // Draw the delimitation lines and blocks stored in the board
    DrawPiece (mPosX, mPosY, mPiece, mRotation);                                // Draw the playing piece
    DrawPiece (mNextPosX, mNextPosY, mNextPiece, mNextRotation);                // Draw the next piece
}
