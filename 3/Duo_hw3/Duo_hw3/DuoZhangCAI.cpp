//DuoZhangWorker.h
//Duo Zhang
//C++ CIS554
//input and output the salary of different workers
//declearation

#include"iostream"//basic String library
#include"DuoZhangCAI.h"//basic String library
#include"cstdlib"//basic String library
#include"ctime"//basic String library
//#include "iomanip"//basic String library

using std::cout;//using cout
using std::cin;//using cin
using std::srand;//using srand
//using std::setprecision//using setprecision

CAI::CAI() {}//constructor

void CAI::correctanswer(int n)//use to choose the system answer when answer is correct 
{
	switch (n)//choose which to show
	{
		case 1: cout << "Very good!\n"; break;  //when choose 1 show some
		case 2: cout << "Excellent!\n"; break;//when choose 2 show some
		case 3: cout << "Nice work!\n"; break;//when choose 3 show some
		case 4: cout << "Keep up the good work\n"; break;//when choose 4 show some
		default: break;
	}
}

void CAI::wronganswer(int n)//use to choose the system answer when answer is wrong
{
	switch (n)//choose which to show
	{
		case 1:cout << "No. Please try again.\n"; break;//when choose 1 show some
		case 2: cout << "Wrong. Try once more\n"; break;//when choose 2 show some
		case 3: cout << "Don't give up!\n"; break;//when choose 3 show some
		case 4: cout << "No. Keep trying\n"; break;//when choose 4 show some
		default: break;
	}
}

void CAI::multiplication()//use to show and get multiplication task
{
	int calm;//use to circular
	for (calm=5;calm>0;calm--) //use to get 5 tasks
	{
		num1 = 1+rand() % 9;//get a num randomly
		num2 = 1+rand() % 9;//get a num randomly
		cout << "How much is " << num1 << " times " << num2 << " ?\n";//show question
		cin >> ans;//get answer
		judgemul();	//use to judge
	}
}
void CAI::judgemul()//use to judge whether the answer about them multiplication task is right or wrong
{
	int mark = 1;//use to assure the answer is right or wrong
	if (ans == num1*num2)//if right
	{
		correctanswer((1 + rand() % 4));//show right 
		right++;
	}
	else//otherwise
	{
		while (mark) //use to assure answer
		{
			if (ans == num1*num2) //if right
			{
				correctanswer((1 + rand() % 4));//show right 
				mark = 0;//jump circular
			}
			else
			{
				wronganswer((1 + rand() % 4));//show wrong
				wrong++;
				cin >> ans;//get new answer
			}
		}
	}
}

void CAI::division()//use to show and get division task
{
	int cald ;//use to circular
	for (cald = 5; cald > 0;cald--)//use to get 5 tasks
	{
		num1 = 1+rand() % 9;//get a num randomly
		num2 = 1+rand() % 9;//get a num randomly
		cout << "How much is " << num1 << " divided by " << num2 << " ?\n";//show question
		cin >> ans;//get answer
		judgediv();//use to judge
	}
}

void CAI::judgediv()//use to judge whether the answer about the division task is right or wrong 
{
	int mark = 1;//use to assure the answer is right or wrong
	if (ans == num1/num2)//if right
	{
		correctanswer((1 + rand() % 4));//show right 
		right++;
	}
	else
	{
		while (mark)
		{		
			if (ans == num1/num2)//if right
			{
				correctanswer((1 + rand() % 4));//show right 
				mark = 0;
			}
			else
			{
				wronganswer((1 + rand() % 4));//show wrong
				wrong++;
				cin >> ans;//get new answer
			}
		}
	}
}

void CAI::begin()//use to begin the program
{
	srand(time(0));//use to drive function rand
	division();//use to get task division
	multiplication();//use tp get task multiplication
	avewrong = wrong / (10.0-right);//get average wrong
	cout << "You got " << right << " right on the first try!\n";
	cout << "You took "<<avewrong << " wrong guesses " << ", on average to get each of the other onces correct\n";
}