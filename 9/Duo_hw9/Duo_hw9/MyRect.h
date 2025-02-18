///////////////////////////////////////////////////////////////////////////////
// Joe Waclawski
// CIS 554
// MyRect
//
// Description: Interface file for a simple rectangle class. This class will 
//              clients to draw simple rectangles on the screen.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __MY_RECT__
#define __MY_RECT__

// include appropriate prototypes
#include "FilledShapes.h"
#include "Shape.h"
#include <windows.h>

class MyRect : public Shape {

// Public Interace
public:


///////////////////////////////////////////////////////////////////////////////
// Function: Default Constructor
// Purpose: Construct a rectangle.
//
// Inputs: None
// Outputs: None
// 
// Returns: None
///////////////////////////////////////////////////////////////////////////////
MyRect();

///////////////////////////////////////////////////////////////////////////////
// Function: Draw
// Purpose: Draw the rectangle with the current attributes
//
// Inputs: None
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
virtual bool Draw();


///////////////////////////////////////////////////////////////////////////////
// Function: SetLength
// Purpose: Set the length of the rectangle (i.e. in the y direction)
//
// Inputs: int length - desired length of rectangle
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool SetLength(unsigned int length);

///////////////////////////////////////////////////////////////////////////////
// Function: GetLength
// Purpose: Get the length of the rectangle (i.e. in the y direction)
//
// Inputs: None
// Outputs: None
// 
// Returns: current length of rectangle
///////////////////////////////////////////////////////////////////////////////
unsigned int GetLength();

///////////////////////////////////////////////////////////////////////////////
// Function: SetWidth
// Purpose: Set the width of the rectangle (i.e. in the x direction)
//
// Inputs: int width - desired width of rectangle
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool SetWidth(unsigned int width);

///////////////////////////////////////////////////////////////////////////////
// Function: GetWidth
// Purpose: Get the width of the rectangle (i.e. in the x direction)
//
// Inputs: None
// Outputs: None
// 
// Returns: current width of rectangle
///////////////////////////////////////////////////////////////////////////////
unsigned int GetWidth();

///////////////////////////////////////////////////////////////////////////////
// Function: SetPosition
// Purpose: Set the position of the rectangle. This specifies an x,y coordinate
//          of the upper left of the rectangle, inside the border.
//
// Inputs: POINT point - x,y coordinates 
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
virtual bool SetPosition(POINT &point);

// Private Stuff

unsigned int rectLength;
unsigned int rectWidth;

}; // end class MyRect declaration

#endif __MY_RECT__
