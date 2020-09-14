#include "Pieces.h"

/* 
======================================                                  
Return the type of a block (0 = no-block, 1 = normal block, 2 = pivot block)
 
Parameters:
 
>> pPiece:        Piece to draw
>> pRotation: 1 of the 4 possible rotations
>> pX:            Horizontal position in blocks
>> pY:            Vertical position in blocks
====================================== 
*/
int Pieces::GetBlockType (int pPiece, int pRotation, int pX, int pY)
{
    return PiecesArray [pPiece][pRotation][pX][pY];
}
 
 
/* 
======================================                                  
Returns the horizontal displacement of the piece that has to be applied in order to create it in the
correct position.
 
Parameters:
 
>> pPiece:    Piece to draw
>> pRotation: 1 of the 4 possible rotations
====================================== 
*/
int Pieces::GetXInitialPosition (int pPiece, int pRotation)
{
    return PiecesInitialPosition [pPiece][pRotation][0];
}
 
 
/* 
======================================                                  
Returns the vertical displacement of the piece that has to be applied in order to create it in the
correct position.
 
Parameters:
 
>> pPiece:    Piece to draw
>> pRotation: 1 of the 4 possible rotations
====================================== 
*/
int Pieces::GetYInitialPosition (int pPiece, int pRotation)
{
    return PiecesInitialPosition [pPiece][pRotation][1];
}


//Pieces Definition
int PiecesArray[7 /* kind */][4 /* rotation */][5 /* row */][5 /* column */] ={

    //Square
    {
        //1st rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0},    //
            {0, 0, 2, 1, 0},    //* *
            {0, 0, 1, 1, 0},    //* *
            {0, 0, 0, 0, 0}     //
        },
        //2nd rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0},    //
            {0, 0, 2, 1, 0},    //* *
            {0, 0, 1, 1, 0},    //* *
            {0, 0, 0, 0, 0}     //
        },
        //3rd rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0},    //
            {0, 0, 2, 1, 0},    //* *
            {0, 0, 1, 1, 0},    //* *
            {0, 0, 0, 0, 0}     //
        },
        //4th rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0},    //
            {0, 0, 2, 1, 0},    //* *
            {0, 0, 1, 1, 0},    //* *
            {0, 0, 0, 0, 0}     //
        }
    },

    //I
    {
        //1st rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0},    //
            {0, 1, 2, 1, 1},    //* * * *
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0}     //
        },
        //2nd rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 1, 0, 0},    //*
            {0, 0, 2, 0, 0},    //*
            {0, 0, 1, 0, 0},    //*
            {0, 0, 1, 0, 0}     //*
        },
        //3rd rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0},    //
            {1, 1, 2, 1, 0},    //* * * *
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0}     //
        },
        //4th rotation
        {
            {0, 0, 1, 0, 0},    //*
            {0, 0, 1, 0, 0},    //*
            {0, 0, 2, 0, 0},    //*
            {0, 0, 1, 0, 0},    //*
            {0, 0, 0, 0, 0}     //
        }
    },

    //T
    {
        //1st rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 1, 0, 0},    //  *
            {0, 1, 2, 1, 0},    //* * *
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0}     //
        },
        //2nd rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 1, 0, 0},    //*
            {0, 0, 2, 1, 0},    //* *
            {0, 0, 1, 0, 0},    //*
            {0, 0, 0, 0, 0}     //
        },
        //3rd rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 0, 0, 0},    //
            {0, 1, 2, 1, 0},    //* * *
            {0, 0, 1, 0, 0},    //  *
            {0, 0, 0, 0, 0}
        },
        //4th rotation
        {
            {0, 0, 0, 0, 0},    //
            {0, 0, 1, 0, 0},    //  *
            {0, 1, 2, 0, 0},    //* *
            {0, 0, 1, 0, 0},    //  *
            {0, 0, 0, 0, 0}     //
        }
    },

    //N 
    {
        //1st rotation
        {
            {0, 0, 0, 0, 0}, //
            {0, 0, 0, 1, 0}, //      *
            {0, 0, 2, 1, 0}, //    * *
            {0, 0, 1, 0, 0}, //    *
            {0, 0, 0, 0, 0}  //
        },
        //2nd rotation
        {
            {0, 0, 0, 0, 0}, //
            {0, 0, 0, 0, 0}, //
            {0, 1, 2, 0, 0}, //  * *
            {0, 0, 1, 1, 0}, //    * *
            {0, 0, 0, 0, 0}  //
        },
        //3rd rotation
        {
            {0, 0, 0, 0, 0}, //
            {0, 0, 1, 0, 0}, //    *
            {0, 1, 2, 0, 0}, //  * *
            {0, 1, 0, 0, 0}, //  *
            {0, 0, 0, 0, 0}  //
        },
        //4th rotation
        {
            {0, 0, 0, 0, 0}, //
            {0, 1, 1, 0, 0}, //  * *
            {0, 0, 2, 1, 0}, //    * *
            {0, 0, 0, 0, 0}, //
            {0, 0, 0, 0, 0}  //
        }
    },

    // N mirrored
    {
        //1st rotation
        {
            {0, 0, 0, 0, 0}, //
            {0, 0, 1, 0, 0}, //    *
            {0, 0, 2, 1, 0}, //    * *
            {0, 0, 0, 1, 0}, //      * 
            {0, 0, 0, 0, 0}  //
        },
        //2nd rotation
        {
            {0, 0, 0, 0, 0}, //
            {0, 0, 0, 0, 0}, //
            {0, 0, 2, 1, 0}, //    * *
            {0, 1, 1, 0, 0}, //  * *
            {0, 0, 0, 0, 0}  //
        },
        //3rd rotation
        {
            {0, 0, 0, 0, 0}, //
            {0, 1, 0, 0, 0}, //  *
            {0, 1, 2, 0, 0}, //  * *
            {0, 0, 1, 0, 0}, //    *
            {0, 0, 0, 0, 0}  //
        },
        //4th rotation
        {
            {0, 0, 0, 0, 0}, //
            {0, 0, 1, 1, 0}, //    * *
            {0, 1, 2, 0, 0}, //  * *
            {0, 0, 0, 0, 0}, //
            {0, 0, 0, 0, 0}  //
        }
   },

    //L
    {
        //1st rotation
        {
            { 0, 0, 1, 0, 0},  //    *
            { 0, 0, 1, 0, 0},  //    *   
            { 0, 0, 2, 1, 0},  //    *  *
            { 0, 0, 0, 0, 0},  //
            { 0, 0, 0, 0, 0}   //

        },
        //2nd rotation
        {
            { 0, 0, 0, 0, 0},  //    
            { 0, 0, 1, 0, 0},  //       *
            { 1, 1, 2, 0, 0},  // *  *  *
            { 0, 0, 0, 0, 0},  //
            { 0, 0, 0, 0, 0}   //
        },
        //3th rotation
        {
            { 0, 0, 0, 0, 0},  //    
            { 0, 0, 0, 0, 0},  //    
            { 0, 0, 2, 1, 1},  //  *  *  *         
            { 0, 0, 1, 0, 0},  //  *
            { 0, 0, 0, 0, 0}   //
        },
        //4th rotation
        {
            { 0, 0, 0, 0, 0},  //    
            { 0, 0, 0, 0, 0},  //    
            { 0, 1, 2, 0, 0},  //    *  *     
            { 0, 0, 1, 0, 0},  //       *
            { 0, 0, 1, 0, 0}   //       *
        }
    },

    //L mirrored
    {
        //1st rotation
        {
            { 0, 0, 0, 0, 0},  //    
            { 0, 0, 1, 0, 0},  //    *
            { 0, 0, 2, 1, 1},  //    *  *  *
            { 0, 0, 0, 0, 0},  //
            { 0, 0, 0, 0, 0}   //

        },
        //2nd ratation
        {
            { 0, 0, 1, 0, 0},  //    *
            { 0, 0, 1, 0, 0},  //    *
            { 0, 1, 2, 0, 0},  // *  *  
            { 0, 0, 0, 0, 0},  //
            { 0, 0, 0, 0, 0}   //
        },
        //3th rotation
        {
            { 0, 0, 0, 0, 0},  //    
            { 0, 0, 0, 0, 0},  //   
            { 0, 0, 2, 1, 0},  //      *  *  
            { 0, 0, 1, 0, 0},  //      *
            { 0, 0, 1, 0, 0}   //      * 
        },
        //4th rotation
        {
            { 0, 0, 0, 0, 0},  //    
            { 0, 0, 0, 0, 0},  //    
            { 1, 1, 2, 0, 0},  //  *  *  *   
            { 0, 0, 1, 0, 0},  //        *
            { 0, 0, 0, 0, 0}   //
        }
    }
};

// Displacement of the piece to the position where it is first drawn in the board when it is created
int PiecesInitialPosition  [7 /*kind */ ][4 /* r2otation */ ][2 /* position */] = {

    //Square
    {
        {-2, -3},   //1st rotation
        {-2, -3},   //2nd rotation
        {-2, -3},   //3rd rotation
        {-2, -3}    //4th rotation
    },

    //I
    {
        {-2, -1},   //1st rotation
        {-1, -4},   //2nd rotation
        {-1, -2},   //3rd rotation
        {-1, -4}    //4th rotation
    },

    //T
    {
        {-1, -2},   //1st rotation
        {-2, -3},   //2nd rotation
        {-1, -3},   //3rd rotation
        {-1, -3}    //4th rotation
    },

    //N
    {
        {-2, -3},   //1st rotation
        {-2, -3},   //2nd rotation
        {-2, -3},   //3rd rotation
        {-2, -2}    //4th rotation
    },
    
    //N mirrored
    {
        {-2, -3},   //1st rotation
        {-2, -3},   //2nd rotation
        {-2, -3},   //3rd rotation
        {-2, -2}    //4th rotation
    },

    //L
    {
        {-2, -2},   //1st rotation
        {-2, -2},   //2nd rotation
        {-3, -2},   //3rd rotation
        {-4, -2}    //4th rotation
    },

    //L mirrored
    {
        {-2, -2},   //1st rotation
        {-2, -2},   //2ndrotation
        {-4, -2},   //3rd rotation
        {-2, -2}    //4th rotation
    }
     

};