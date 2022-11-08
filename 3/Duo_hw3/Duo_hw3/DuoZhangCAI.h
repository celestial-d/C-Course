//DuoZhangWorker.h
//Duo Zhang
//C++ CIS554
//input and output the salary of different workers
//interface
#pragma once
class CAI//define a class
{
public:  
	CAI();//constructor
	void begin();//use to begin the program
	

private:
	void correctanswer(int n);//use to choose the system answer when answer is correct 
	void wronganswer(int n);//use to choose the system answer when answer is wrong
	void multiplication(); //use to show and get multiplication task
	void division();//use to show and get division task
	void judgediv();//use to judge whether the answer about the division task is right or wrong 
	void judgemul();//use to judge whether the answer about them multiplication task is right or wrong
	int num1, num2;//use to input the task number
	int ans; //use to get the answer about when answer
	int right=0, wrong=0;//use to calculate how many times is right in the fisrt time and how many times is wrong
	float avewrong;//use to calculate the average wrong times 
};