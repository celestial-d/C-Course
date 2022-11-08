/*
CSE 554 - Employee.cpp
Author: Duo Zhang
Description:
This file is header file of class set.
*/#pragma once

#include<vector>//library
using std::vector;//use vector

class Set//class set
{
public:
	Set(vector<bool> & v);//constructor
	bool IsMember(int x);		//use to get true or false about the positon
	Set Union(Set & S);			// returns a Set the represents the Union of this set and S
	Set Intersection(Set & S);	//returns a Set that represents the Intersection of this set and S
	void Print();				//print set
private:
	vector<bool> set;//a variable about vector
};