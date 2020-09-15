#ifndef _BOARD_
#define _BOARD_

// ------ Includes -----

#include "Pieces.h"

// ------ Defines -----

#define BOARD_LINE_WIDTH 6          // Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16               // Width and Height of each block of a piece
#define BOARD_POSITION 320          // Center position of the board from the left of the screen
#define BOARD_WIDTH 10              // Board width in blocks
#define BOARD_HEIGHT 20             // Board height in blocks
#define MIN_VERTICAL_MARGIN 20      // Minimum vertical margin for the board limit
#define MIN_HORIZONTAL_MARGIN 20    // Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5              // Number of horizontal and vertical blocks of a matrix piece


// --------------------------------------------------------------------------------
//                                   Board
// --------------------------------------------------------------------------------

class Board
{
    public:

        Board                       (Pieces *pPieces, int pScreenHeight);

        int GetXPosInPixels         (int pPos);
        int GetYPosInPixels         (int pPos);
        bool IsFreeBlock            (int pX, int pY);                               //checks the block is filled or empty.
        bool IsPossibleMovement     (int pX, int pY, int pPiece, int pRotation);    // checks if there is empty block or filled block to fill
        void StorePiece             (int pX, int pY, int pPiece, int pRotation);    //Store a piece in the board by filling the blocks
        void DeletePossibleLines    ();                                             //We should remove unnecessary lines
        bool IsGameOver             ();                                             //Checks If the first line has blocks. IF it has, than game is over

    private:

        enum { POS_FREE, POS_FILLED };          // POS_FREE = 0 free position of the board; POS_FILLED = 1 filled position of the board
        int mBoard [BOARD_WIDTH][BOARD_HEIGHT]; // Board that contains the pieces
        Pieces *mPieces;
        int mScreenHeight;

        void InitBoard();           //Prepares board at init
        void DeleteLine (int pY);   //Deletes a line by moving all above lines down
};


#endif
