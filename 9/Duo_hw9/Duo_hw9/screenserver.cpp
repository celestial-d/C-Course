/////////////////////////////////////////////////////////////////////
// screenserver.cpp
// Author: Duo Zhang
// Description: Simple screensaver to demonstrate and output every shape
/////////////////////////////////////////////////////////////////////
#include "MyRect.h"
#include "MyTriangle.h"
#include "MyCircle.h"
#include <stdlib.h> // rand and srand
#include <time.h> // time funciton
#include <windows.h>  // POINT object
#include"map"//library
#include<vector>//vector library



// how many times will the program cycle
#define PROGRAM_RUN 50

// small delay between drawing rectangles during each run
#define DRAW_DELAY 100

// small delay between each iteration of drawing rectangles
#define ITERATION_DELAY 250

#define NUM_SHAPES 1

// function prototypes
void RandomAttributes(Shape *p);

void main()
{
	int shapes; // loop index

				// seed the random number generator
	srand((unsigned int)time(0));

	// allow the user time to move the console window away
	// from the FilledShapes window are
	cout << "Move this window to the lower right of the screen, and press ENTER to continue:\n";
	cin.get();
	enum SHAPE_TYPES { RECTANGLE, TRIANGLE, CIRCLE };//use to get map
	map<SHAPE_TYPES, vector<Shape*>> shapemap;//use to get map
	vector<Shape*> rectVector;//create
	vector<Shape*> triangleVector;
	vector<Shape*> circleVector;

	shapemap.insert(pair<SHAPE_TYPES, vector<Shape*>>(RECTANGLE, rectVector));//initial
	shapemap.insert(pair<SHAPE_TYPES, vector<Shape*>>(TRIANGLE, triangleVector));
	shapemap.insert(pair<SHAPE_TYPES, vector<Shape*>>(CIRCLE, circleVector));

	map<SHAPE_TYPES, vector<Shape*>>::iterator maplter;//store
	for (int i = 0; i < PROGRAM_RUN; i++)
	{
		maplter = shapemap.find(RECTANGLE);//store every rectangle
		if (maplter != shapemap.end())
		{
			maplter->second.push_back(new MyRect);
			RandomAttributes(maplter->second.back());
		}
		maplter = shapemap.find(TRIANGLE);//store every triangle
		if (maplter != shapemap.end())
		{
			maplter->second.push_back(new MyTriangle);
			RandomAttributes(maplter->second.back());
		}
		maplter = shapemap.find(CIRCLE);//store every circle
		if (maplter != shapemap.end())
		{
			maplter->second.push_back(new MyCircle);
			RandomAttributes(maplter->second.back());
		}
	}

	for (int i = 0; i < PROGRAM_RUN; i++)//output
	{
		// clear the window
		// note that I can use ANY instance 
		// object to clear the window
		maplter->second.back()->ClearScreen();
		// choose random parameters for each 
		maplter = shapemap.find(TRIANGLE);
		if (maplter != shapemap.end())//if is not null,output triangle
		{
			if (!maplter->second.empty())
			{
				maplter->second.back()->Draw();//output triangle
				delete maplter->second.back();//delate the node
				maplter->second.pop_back();
			}
		}
		maplter = shapemap.find(RECTANGLE);//if is not null, output rectangle
		if (maplter != shapemap.end())
		{
			if (!maplter->second.empty())
			{
				maplter->second.back()->Draw();//output rectangle
				delete maplter->second.back();//delate node
				maplter->second.pop_back();
			}
		}
		maplter = shapemap.find(CIRCLE);
		if (maplter != shapemap.end())//if is not null,output circle
		{
			if (!maplter->second.empty())
			{
				maplter->second.back()->Draw();//output circle
				delete maplter->second.back();//delate node
				maplter->second.pop_back();
			}
		}
		if (DRAW_DELAY > 0)
			Sleep(DRAW_DELAY);//delay
		if (ITERATION_DELAY > 0)
			Sleep(ITERATION_DELAY);

	}

}

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a object, and draw it.
/////////////////////////////////////////////////////////////////////
void RandomAttributes(Shape *S)
{
	// needed to draw a filled shape
	POINT p;
	p.x = 50;
	p.y = 50;

	// define variables that will hold he parameters
	// for the every shape
	SHAPE_COLOR firstColor = RED;
	SHAPE_COLOR lastColor = PURPLE;//initial color
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;
	unsigned int width;
	unsigned int radius;

	MyCircle *c = dynamic_cast<MyCircle *>(S);//downcasting to circle
	MyRect *r = dynamic_cast<MyRect *>(S);//downcasting to rectangle
	MyTriangle *t = dynamic_cast<MyTriangle *>(S);//downcasting to triangle

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	S->SetBorderColor((SHAPE_COLOR)myPen);
	S->SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a circle within the legal
	// limits of the window.
	if (c != 0)
	{
		c->SetPosition(p);
		do {
			radius = 1 + rand() % c->GetWindowHeight();//get radius
		} while (!c->SetRadius(radius));
		do {//position
			p.x = 1 + rand() % c->GetWindowWidth();
			p.y = 1 + rand() % c->GetWindowHeight();
		} while (!c->SetPosition(p));

	}
	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.
	if (r != 0)
	{
		r->SetPosition(p);
		do {
			length = 1 + rand() % r->GetWindowHeight();//get length
		} while (!r->SetLength(length));

		// width
		do {
			width = 1 + rand() % r->GetWindowWidth();//get width
		} while (!r->SetWidth(width));

		// position
		do {
			p.x = 1 + rand() % r->GetWindowWidth();
			p.y = 1 + rand() % r->GetWindowHeight();
		} while (!r->SetPosition(p));
	}
	// stay in each loop until you have chosen random
	// parameters which draw a trinagle within the legal
	// limits of the window.
	if (t != 0)
	{
		t->SetPosition(p);
		do {
			length = 1 + rand() % t->GetWindowHeight();//get length
		} while (!t->SetLength(length));

		// position
		do {
			p.x = 1 + rand() % t->GetWindowWidth();
			p.y = 1 + rand() % t->GetWindowHeight();
		} while (!t->SetPosition(p));
	}
}

