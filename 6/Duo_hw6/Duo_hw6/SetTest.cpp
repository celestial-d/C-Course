/*
CSE 554 - Employee.cpp
Author: Duo Zhang
Description:
This file is implement file of class set.
*/
#include"Set.h"//library
#include"iostream"//library
using std::cout;//use cout
using std::endl;//use endl
using std::cin;//use cin

int main()
{
	vector<bool> a = { 1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1 };//get a vector
	vector<bool> b = { 0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1 };
	Set c(a);//copy a to c
	Set d(a);//copy a to d
	Set e(b);
	bool f;//a variable of bool
	int k;
	c.Print();//print setc
	cout << "please input k:";
	cin >> k;//get k
	cout << "the "<< k <<" position is :";
	f = c.IsMember(k);//get k position 
	cout << f << endl;
	e.Print();//print e
    c=c.Union(e);//union c,e
	cout << "after union" << endl;
	c.Print();//print result 
	d = d.Intersection(e);//intersection d,e
	cout << "after intersection" << endl;
	d.Print();//print result
	return 0;
}