/*
CSE 554 - Employee.cpp
Author: Duo Zhang
Description:
This file is implement file of class point.
*/#include "Point.h"

Point::Point(int x, int y)//constructor
{
	SetX(x);
	SetY(y);
}

void Point::SetY(int Y)//set y
{
	y = Y;
}

void Point::SetX(int X)//set x
{
	x = X;
}

int Point::GetY()//get y
{
	return y;
}

int Point::GetX()//get x
{
	return x;
}



