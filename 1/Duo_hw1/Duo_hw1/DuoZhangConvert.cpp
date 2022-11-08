#include "DuoZhangConvert.h"
#include "iostream"



Convert::Convert() {}

void Convert::reveivenum()//get a number
{
	std::cout << "please input a number";
	std::cin >> num;//get a number
}
void Convert::reveivebase()//get a base
{
	std::cout << "please input base";
	std::cin >> base;//get a base
}

void Convert::convert1()// get result
{
	int facto = 1;
	int sum = 0;
	int numtem = num; //define some variables to use
	int remin1 = 0;  //define some basic varibales 
	while (numtem > 0)    //calculte different step
	{
		remin1 = numtem % 10;   //calculate every remains for num1
		facto = facto*base;   //facto use to calculate base power 
		sum = sum + remin1*facto / base; //get every step result
		numtem = numtem / 10;  //change num1 to every step
		
	}

	std::cout << "the result is: " << sum << std::endl; //output the final result
}


int Convert::judgnumber()//judge wthether there is err or not
{
	int remin1 = 0;
	int numtempt=num;//define basic varibles
	while (numtempt > 0)
	{
		remin1 = numtempt % 10;  //calculate every remains
		if (remin1 >= base)
		{
			std::cout << "error!\n";   //judge the base and number is allowed or not
			return 0;                  //if do not allowed return 0
		}
		numtempt = numtempt / 10;    //get every unit
	}
	return 1;      //if allowed return 1
}

