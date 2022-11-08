///////////////////////////////////////////////////////////////////////////////
// Duo Zhang
// CIS 554
// MyCircle
//
// Description: Implementation of class MyTriangle. See MyTriangle.h for details
//
///////////////////////////////////////////////////////////////////////////////
#include "MyCircle.h"

using std::cout;
using std::cin;
using std::endl;



///////////////////////////////////////////////////////////////////////////////
// MyCircle default constructor
///////////////////////////////////////////////////////////////////////////////
MyCircle::MyCircle()
// initialize default rectangle attributes
	: circleradius(WINDOW_MAXY / 4)
{}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::Draw()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::Draw()
{
	// set up attributes of rectangle using FilledShapes
	fs.SetPenColor(borderColor);
	fs.SetBrushColor(fillColor);

	// draw rectangle with set attributes
	// when drawing, take into account the border width by subtracting the border
	// width appropriately from the length and width. that way, the given length
	// and width include the width of the border
	fs.FilledCircle(position, circleradius-2*borderWidth);

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetRadius()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetRadius(unsigned int length)
{
	// need to account for a min length and width based
	// upon the border width
	if (length <= borderWidth * 2) return false;

	// check to make sure the new length is valid based on current position
	// window height, and window width 
	if (length*2 < (GetWindowHeight() - position.y) &&
		length*2 < (GetWindowWidth() - position.x))
	{
		circleradius = length;
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetPosition()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetPosition(POINT & p)
{
	// make sure new position is valid based on current radius,
	// and window size
	if (
		(p.x + circleradius + borderWidth*2) < GetWindowWidth() &&
		(p.x > (circleradius + borderWidth)) &&
		(p.y + circleradius + borderWidth*2) < GetWindowHeight() &&
		(p.y > circleradius+borderWidth)
		)
	{
		position.x = p.x;
		position.y = p.y;
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::GetRadius()
///////////////////////////////////////////////////////////////////////////////
unsigned int MyCircle::GetRadius()
{
	return circleradius;
}
