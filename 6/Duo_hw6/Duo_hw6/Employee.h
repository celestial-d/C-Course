
/*
CSE 554 - Employee.cpp
Author: Duo Zhang
Description:
This file is header file of class Employee.
*/
#pragma once

#include"string"
#include"Point.h"//library
using std::string;//use string


class employee//class employee
{
public:
	employee();//constructor
	Point GetCoordinates(Point &pointg);//use to get  point
	void SetCoordinates(Point &points);//use to set point
	string GetName(string & nameg);//use to get name
	void SetName(string & names);//use to set name

private:
	string name;//restore name
	Point point;//use to save point
};