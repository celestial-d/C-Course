/////////////////////////////////////////////////////////////////////
// screensaver.cpp
// Author: Joe Waclawski
// Description: Simple screensaver to demonstrate MyRect class
/////////////////////////////////////////////////////////////////////
#include "MyRect.h"
#include "MyTriangle.h"
#include "MyCircle.h"
#include <stdlib.h> // rand and srand
#include <time.h> // time funciton
#include <windows.h>  // POINT object


// how many times will the program cycle
#define PROGRAM_RUN 20

// small delay between drawing rectangles during each run
#define DRAW_DELAY 100

// small delay between each iteration of drawing rectangles
#define ITERATION_DELAY 250

#define NUM_SHAPES 1

// function prototypes
void RandomAttributes(MyRect &);
void RandomAttributes(MyTriangle &);
void RandomAttributes(MyCircle &);

void main()
{
	int shapes; // loop index

	// seed the random number generator
	srand((unsigned int)time(0));

	// allow the user time to move the console window away
	// from the FilledShapes window are
	cout << "Move this window to the lower right of the screen, and press ENTER to continue:\n";
	cin.get();


	// Create the rectangles
	MyRect R[NUM_SHAPES];
	MyTriangle T[NUM_SHAPES];
	MyCircle C[NUM_SHAPES];

	for (int i=0; i<PROGRAM_RUN; i++)
	{
		// clear the window
		// note that I can use ANY instance of a MyRect
		// object to clear the window

		R[0].ClearScreen();	

		// choose random parameters for each rectangle
		for (shapes = 0; shapes < NUM_SHAPES; shapes++)
		{	
			RandomAttributes(R[shapes]);
			RandomAttributes(T[shapes]);
			RandomAttributes(C[shapes]);
		}


		// draw all the shapes
		for (shapes = 0; shapes < NUM_SHAPES; shapes++)
		{	
			R[shapes].Draw();
			T[shapes].Draw();
			C[shapes].Draw();
			if (DRAW_DELAY > 0)
				Sleep(DRAW_DELAY);
		}

		// wait for a little while 
		if (ITERATION_DELAY > 0)
			Sleep(ITERATION_DELAY);
	}

}

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyRect object, and draw it.
// 
// Inputs: MyRect object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void RandomAttributes(MyRect &S)
{
	// needed to draw a filled shape
	POINT p;
	p.x=50;
	p.y=50;

	// define variables that will hold he parameters
	// for the rectangle
	SHAPE_COLOR firstColor=RED;
	SHAPE_COLOR lastColor=PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;
	unsigned int width;

	// reset the rectangle object to some known, legal values
	S.SetPosition(p);
	S.SetLength(S.GetWindowHeight()/10);
	S.SetWidth(S.GetWindowWidth()/10);

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	S.SetBorderColor((SHAPE_COLOR)myPen);
	S.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.

	// length
	do {
		length = 1 + rand() % S.GetWindowHeight();
	} while(!S.SetLength(length));

	// width
	do {
		width = 1 + rand() % S.GetWindowWidth();
	} while(!S.SetWidth(width));

	// position
	do {
		p.x = 1 + rand() % S.GetWindowWidth();
		p.y = 1 + rand() % S.GetWindowHeight();
	} while(!S.SetPosition(p));
}

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyTriangle object, and draw it.
// 
// Inputs: MyTriangle object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void RandomAttributes(MyTriangle &S)
{
	// needed to draw a filled shape
	POINT p;
	p.x=50;
	p.y=50;

	// define variables that will hold he parameters
	// for the rectangle
	SHAPE_COLOR firstColor=RED;
	SHAPE_COLOR lastColor=PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;

	// reset the rectangle object to some known, legal values
	S.SetPosition(p);
	S.SetLength(S.GetWindowHeight()/10);

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	S.SetBorderColor((SHAPE_COLOR)myPen);
	S.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.

	// length
	do {
		length = 1 + rand() % S.GetWindowHeight();
	} while(!S.SetLength(length));

	// position
	do {
		p.x = 1 + rand() % S.GetWindowWidth();
		p.y = 1 + rand() % S.GetWindowHeight();
	} while(!S.SetPosition(p));
}

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyRect object, and draw it.
// 
// Inputs: MyCircle object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void RandomAttributes(MyCircle &S)
{
	// needed to draw a filled shape
	POINT p;
	p.x = 50;
	p.y = 50;

	// define variables that will hold he parameters
	// for the rectangle
	SHAPE_COLOR firstColor = RED;
	SHAPE_COLOR lastColor = PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int radius;


	// reset the rectangle object to some known, legal values
	S.SetPosition(p);
	S.SetRadius(S.GetWindowWidth() / 10);

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	S.SetBorderColor((SHAPE_COLOR)myPen);
	S.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.

	// length
	do {
		radius = 1 + rand() % S.GetWindowHeight();
		radius = radius / 2;
	} while (!S.SetRadius(radius));

	// position
	do {
		p.x = 1 + rand() % S.GetWindowWidth();
		p.y = 1 + rand() % S.GetWindowHeight();
	} while (!S.SetPosition(p));
}

