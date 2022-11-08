/*
CSE 554 - Employee.cpp
Author: Duo Zhang
Description:
This file is header file of class point.
*/#pragma once
class Point//class point
{
public:
	Point(int x = 0,int y=0);//constructor
	void SetY(int Y);//use to set y
	void SetX(int X);//use to set x
	int GetY();//use to get y
	int GetX();//use to get x
private:
	int x;//a variable
	int y;//a variable
};