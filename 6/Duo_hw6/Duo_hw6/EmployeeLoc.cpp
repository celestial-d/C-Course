/*
CSE 554 - Employee.cpp
Author: Duo Zhang
Description:
This file is implement file of main.
*/#include"Employee.h"//library
#include"Location.h"//library
#include"Point.h"
#include"Set.h"
#include"iostream"//library
#include"string"

using std::cout;//use cout
using std::cin;//use cin
using std::endl;//use endl

int main()
{
	int n=1;
	int x=0, y=0;
	string name;//get some varibales
	while (n)//circular
	{
		cout << "please enter a name: ";
		cin >> name;//get name
		cout << "please input x positon(-1 to exit): ";
		cin >> x;//get x
		if (x == -1)
		{
			break;//if x=-1 finish circle
		}
		cout << "please input y positon(-1 to exit): ";
		cin >> y;//get y
		if (y == -1)
		{
			break;//if y=-1 finish circle
	    }
		employee staff;//emplyee a object
		staff.SetCoordinates(Point(x, y));//transfer x,y
		staff.SetName(name);//transfer name
		location locate;//object
		switch (locate.GetLocation(staff.GetCoordinates(Point(x, y))))//choose by enum
		{
		case locate.NOT_FOUND://if no found place ,output
			cout << staff.GetName(name) << "'s location " << "is not found" << endl;
			break;
		case locate.NEWYORK://if neyork, output
			cout << staff.GetName(name) << " is in " << "NEWYORK" << endl;
			break;
		case locate.SANFRANSISCO://if san, output
			cout << staff.GetName(name) << " is in " << "SANFRANSISCO" << endl;
			break;
		case locate.LOSANGELES://if los, output
			cout << staff.GetName(name) << " is in " << "LOSANGELES" << endl;
			break;
		case locate.CHICAGO://if chi, output
			cout << staff.GetName(name) << " is in " << "CHICAGO" << endl;
			break;
		default://error other
			cout << "Error of the program";
			break;
		}

	}
		

	return 0;
}