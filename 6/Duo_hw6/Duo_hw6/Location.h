/*
CSE 554 - Employee.cpp
Author: Duo Zhang
Description:
This file is header file of class location.
*/#pragma once
#include"Point.h"//library
#include"Set.h"//library
class location//class
{
public:
	enum LOCATION { NOT_FOUND, NEWYORK, SANFRANSISCO, LOSANGELES, CHICAGO };//different location
	location();//constructor
	LOCATION GetLocation(Point &p);//according to the point  get place
private:
	vector<bool> n = {0};//use to initialize
	Set setNew=Set(n);//use to get a set about newyork
	Set setSan=Set(n);//us eto get a set about san
	Set setLos=Set(n);
	Set setChi=Set(n);

};
