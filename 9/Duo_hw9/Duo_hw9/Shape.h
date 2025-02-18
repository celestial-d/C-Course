///////////////////////////////////////////////////////////////////////////////
// Joe Waclawski
// CIS 554
// Shape (abstract class)
//
// Description: Interface file for shape class. This class will the base
//              class for various shapes.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __SHAPE__
#define __SHAPE__

// include appropriate prototypes
#include "FilledShapes.h"
#include <windows.h>

#define WINDOW_MAXX 800
#define WINDOW_MAXY 600
#define DEFAULT_PEN_WIDTH 5

class Shape {

// Public Interace
public:


///////////////////////////////////////////////////////////////////////////////
// Function: Default Constructor
// Purpose: Construct a shape.
//
// Inputs: None
// Outputs: None
// 
// Returns: None
///////////////////////////////////////////////////////////////////////////////
Shape();

///////////////////////////////////////////////////////////////////////////////
// Function: Draw
// Purpose: Draw the rectangle with the current attributes
//
// Inputs: None
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
virtual bool Draw() = 0;

///////////////////////////////////////////////////////////////////////////////
// Function: SetPosition
// Purpose: Set the position. Implementation is Shape specific.
//
// Inputs: POINT point - x,y coordinates 
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
virtual bool SetPosition(POINT &point) = 0;

///////////////////////////////////////////////////////////////////////////////
// Function: GetPosition
// Purpose: Get the position of the rectangle. This specifies an x,y coordinate
//          of the upper left of the rectangle, inside the border.
//
// Inputs: None
// Outputs: None
// 
// Returns: returns current position of rectangle as a POINT
///////////////////////////////////////////////////////////////////////////////
POINT GetPosition();

///////////////////////////////////////////////////////////////////////////////
// Function: GetBorderWidth
// Purpose: Get the Border width of the outline of the rectangle. Note that 
//          the border falls outside of the actual rectangle itself.
//
// Inputs: None
// Outputs: None
// 
// Returns: border width
///////////////////////////////////////////////////////////////////////////////
unsigned int GetBorderWidth();


///////////////////////////////////////////////////////////////////////////////
// Function: SetBorderColor
// Purpose: Set the color of the border (i.e. outline) of the rectangle
//
// Inputs: SHAPE_COLOR color
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool SetBorderColor( SHAPE_COLOR borderColor);

///////////////////////////////////////////////////////////////////////////////
// Function: SetFillColor
// Purpose: Set the color of the fill of the rectangle
//
// Inputs: SHAPE_COLOR color
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool SetFillColor( SHAPE_COLOR fillColor);


///////////////////////////////////////////////////////////////////////////////
// Function: GetWindowWidth
// Purpose: Returns the width of the valid window for drawing rectangles
//
// Inputs: None
// Outputs: None
// 
// Returns: window width
///////////////////////////////////////////////////////////////////////////////
unsigned int GetWindowWidth();

///////////////////////////////////////////////////////////////////////////////
// Function: GetWindowHeight
// Purpose: Returns the length (i.e. height) of the valid window for drawing shape
//
// Inputs: None
// Outputs: None
// 
// Returns: window length
///////////////////////////////////////////////////////////////////////////////
unsigned int GetWindowHeight();


///////////////////////////////////////////////////////////////////////////////
// Function: GetMaxBorderWidth
// Purpose: Returns max width of pen (i.e. border width)
//
// Inputs: None
// Outputs: None
// 
// Returns: maximum border width
///////////////////////////////////////////////////////////////////////////////
unsigned int GetMaxBorderWidth();

///////////////////////////////////////////////////////////////////////////////
// Function: ClearScreen
// Purpose: Allows the user to clear ALL rectangles from the screen. Note
//          that calling this member function of ANY rectangle clears ALL
//          rectangles from the screen.
//
// Inputs: None
// Outputs: None
// 
// Returns: true
///////////////////////////////////////////////////////////////////////////////
bool ClearScreen();

// Private Stuff

protected:

SHAPE_COLOR borderColor;
SHAPE_COLOR fillColor;
unsigned int borderWidth;
POINT position;
FilledShapes fs;

}; // end class Shape declaration

#endif __SHAPE__