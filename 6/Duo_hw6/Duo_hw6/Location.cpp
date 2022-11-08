/*
CSE 554 - Employee.cpp
Author: Duo Zhang
Description:
This file is implement file of class location.
*/#include"Location.h"
#include"Point.h"
#include"Set.h"
#include"iostream"


location::location()	
{   
	vector<bool> a = { 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//use to initialize setnew
	vector<bool> b = { 0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 };//use to initialize setsan
	vector<bool> c = { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0 };//use toinitiqalize setlos
	vector<bool> d = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1 };//use to initialize setchi

	setNew = Set(a);//initialize
	setSan = Set(b);//initialize
	setLos = Set(c);//initialize
	setChi = Set(d);//initialize
}

location::LOCATION location::GetLocation(Point & p)
{
	// New York case
	if (setNew.IsMember(p.GetX()) && setNew.IsMember(p.GetY()))
	{
		return NEWYORK;
	}
	// San Francisco case
	if (setSan.IsMember(p.GetX()) && setSan.IsMember(p.GetY()))
	{
		return SANFRANSISCO;
	}
	// Los Angeles case
	if (setLos.IsMember(p.GetX()) && setLos.IsMember(p.GetY()))
	{
		return LOSANGELES;
	}
	// Chicago case
	if (setChi.IsMember(p.GetX())&& setChi.IsMember(p.GetY()))
	{
		return CHICAGO;
	}
	// Not found case
	return NOT_FOUND;
}

